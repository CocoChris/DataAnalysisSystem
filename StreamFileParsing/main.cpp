#include <iostream>
#include "Decode.h"
#include "MySQLManager.h"
#pragma warning(disable:4996)
using namespace std;

 int main()
 {
     Decoder decoder;
     //decoder.read("flow.dat");
     decoder.read("./flowdata/flow20170829.dat");
     
     //decoder.decodePackageHeader();
     //decoder.decodeFieldHeader();
     //decoder.decodeOrder();
     decoder.decode();

    /*MySQLManager *testsql = new MySQLManager("120.27.123.235", "root", "root", "test", 3306); 
    testsql->initConnection();
    if (testsql->getConnectionStatus())
    {
        cout << "Connect successfully." << endl;
        int id = 8;
		double score = 91.7;
		//string sql = "insert into score values(6, 'Steven', %f)" % score;
		//string sql = "select * from score ";
        char sql[1024];
        //sprintf(sql, "insert into score values(6, 'Steven', '%f')", score);
        sprintf(sql, "insert into score (id) values('%d')", id);
        
		//cout << testsql->runSQLCommand(sql) << endl;
		cout << sql << endl;
		cout << testsql->insert(sql) << endl;
    }
    else
    {
        cout << "Failed to connect." << endl;
    }*/

    



    system("pause");
    return 0;
 }