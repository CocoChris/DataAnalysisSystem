#pragma once 
#pragma execution_character_set("utf-8")

#include "MySQLManager.h"

MySQLManager::MySQLManager(std::string hosts, std::string userName, std::string password, std::string dbName, unsigned int port)
{
    IsConnected = false;
    this->setHosts(hosts);
    this->setUserName(userName);
    this->setPassword(password);
    this->setDBName(dbName);
    this->setPort(port);
}

MySQLManager::~MySQLManager()
{
    this->destroyConnection();
}



void MySQLManager::setDBName(string dbName)
{
    if(dbName.empty())
    {
        cout << "DBName is null! Use deflaut value: mysql" << endl;
        this->DBNAME = new char[5];
        strcpy_s(this->DBNAME, 5, "mysql");
		//this->DBNAME = "mysql";
    }
    else
    {
        this->DBNAME = new char[dbName.length()];
        strcpy_s(this->DBNAME, dbName.length()+1, dbName.c_str());
		//this->DBNAME = dbName.c_str();
    }
}

void MySQLManager::setHosts(string hosts)
{
    if ( hosts.empty() )    
    { 
        std::cout << "Hosts is null! Use default value: localhost" << std::endl;    
        this ->HOSTS = new char[9];    
        strcpy_s(this ->HOSTS, 9, "localhost");    
    }    
    else    
    {    
        this ->HOSTS = new char[hosts.length()];    
        strcpy_s(this ->HOSTS, hosts.length()+1, hosts.c_str());    
    }        
}

void MySQLManager::setPassword(string password)    
{
    if ( password.empty() )    
    {    
            std::cout << "Password is null! Used default value: " << std::endl;    
            this ->PASSWORD = new char[1];    
            strcpy_s(this ->PASSWORD, 1, "");    
    }    
    else    
    {    
            this ->PASSWORD = new char[password.length()];    
            strcpy_s(this ->PASSWORD, password.length()+1, password.c_str());    
    }    
}    

void MySQLManager::setPort(unsigned int port)    
{
    if ( port <= 0 )    
    {    
            std::cout << "Port number is null! Used default value: 0" << std::endl;    
            this->DEFAULTPORT = 0;
    }    
    else    
    {    
            this ->DEFAULTPORT = port;    
    }    
}    

void MySQLManager::setUserName(string userName)    
{
    if ( userName.empty() )    
    {    
            std::cout << "UserName is null! Used default value: root" << std::endl;    
            this ->USERNAME = new char[4];    
            strcpy_s(this ->USERNAME, 4, "root");    
    }    
    else    
    {    
            this ->USERNAME = new char[userName.length()];    
            strcpy_s(this ->USERNAME, userName.length()+1, userName.c_str());    
    }    
}    

void MySQLManager::initConnection()
{
    if(IsConnected)
    {
        cout << "Is connected to server!" << endl;
        return;
    }
    mysql_init(&mySQLClient);
    if(!mysql_real_connect(&mySQLClient, HOSTS, USERNAME, PASSWORD, DBNAME, DEFAULTPORT, NULL, 0))
    {
        cout << "Error connection to database: \n" << mysql_error(&mySQLClient) << endl;
		return;
    }
	mysql_set_character_set(&mySQLClient, "gbk");
    IsConnected = true;
}

bool MySQLManager::runSQLCommand(string sql)
{
    if(!IsConnected)
    {
        cout << "not connect to database!" << endl;
        return false;
    }
    if(sql.empty())
    {
        cout << "sql command is null!" << endl;
    }

    MYSQL_RES* res;
    MYSQL_ROW row;

    unsigned int i, j = 0;

    i = mysql_real_query(&mySQLClient, sql.c_str(), (unsigned int)strlen(sql.c_str())); 
    if(i < 0)
    {
        cout << "Error query from database: \n" << mysql_error(&mySQLClient) << endl;
        return false;
    }
    res = mysql_store_result(&mySQLClient);
    vector<string> objectValue;
    while((row = mysql_fetch_row(res)))
    {
        objectValue.clear();
        for(j = 0; j < mysql_num_fields(res); j ++)
        {
            objectValue.push_back(row[j]);
        }
        this->resultList.push_back(objectValue);
    }
    mysql_free_result(res);

    return true;
}

unsigned int MySQLManager::insert(std::string sql)
{
    if(!IsConnected)
    {
        cout << "not connect to database!" << endl;
        return -1;
    }
    if(sql.empty())
    {
        cout << "sql command is null!" << endl;
        return -1;
    }
    int rows = -1;
    int res = mysql_query(&mySQLClient, sql.c_str());
    if(res >= 0)
    {
        rows = mysql_affected_rows(&mySQLClient);
        cout << "Inserted " << rows << " rows\n";
        return rows;
    }
    else
    {
        cout << "Insert error: \n" << mysql_error(&mySQLClient) << endl;
        return -1;
    }
}

vector<vector<string>> MySQLManager::getResult()
{
    return resultList;
}

void MySQLManager::destroyConnection()
{
    mysql_close(&mySQLClient);
    this->IsConnected = false;
}

bool MySQLManager::getConnectionStatus()
{
    return IsConnected;
}