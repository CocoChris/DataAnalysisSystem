#pragma once 
#pragma execution_character_set("utf-8")

#include <iostream>
#include <mysql.h>
#include <string>
#include <vector>
#include <string.h>
#include <cstring>

using namespace std;

class MySQLManager
{
public:
	/*
	* Init MySQL
	* @param hosts:         Host IP address
	* @param userName:      Login UserName
	* @param password:      Login Password
	* @param dbName:        Database Name
	* @param port:          Host listen port number
	*/
	MySQLManager(std::string hosts, std::string userName, std::string password, std::string dbName, unsigned int port);
	~MySQLManager();

	void initConnection();

	/*
	* Making query from database
	* @param mysql:        MySQL Object
	* @param sql:          Running SQL command
	*/
	bool runSQLCommand(std::string sql);

	/*
	* Insert
	* @param sql: ִSQL syntax
	* @return: number of rows inserted
	*/
	unsigned int insert(std::string sql);

	/*
	* Destroy MySQL object
	* @param mysql:        MySQL object
	*/
	void destroyConnection();

	bool getConnectionStatus();

	vector<vector<string>> getResult();

protected:
	void setUserName(std::string userName);
	void setHosts(std::string hosts);
	void setPassword(std::string password);
	void setDBName(std::string dbName);
	void setPort(unsigned int port);

private:
	bool IsConnected;
	vector<vector<string>> resultList;
	MYSQL mySQLClient;
	unsigned int DEFAULTPORT;
	char* HOSTS;
	char* USERNAME;
	char* PASSWORD;
	char* DBNAME;
};