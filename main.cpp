#include <iostream>
#include "myMySql.h"
#include <mysql.h>

using namespace std;

#pragma comment(lib,"D:\\mysql-8.0.18-winx64\\lib\\libmysql.lib")

int main() {
	const char host[] = "127.0.0.1";
	const char user[] = "root";
	const char pwd[] = "P@ss1234";
	const char db[] = "unicorndbs";

	MYSQL mySql;
	MYSQL_RES *result = NULL;
	MYSQL_ROW row = NULL;;
	MYSQL_FIELD *field = NULL;
	int t;

	mysql_init(&mySql);
	if (mysql_real_connect(&mySql, host, user, pwd, db, 3306, NULL, 0)) {
		t = mysql_query(&mySql, "select * from tblextn");
		if (!t) {
			result = mysql_store_result(&mySql);
			int rowcount = mysql_num_rows(result);
			int fieldcount = mysql_num_fields(result);
			if (result) {
				while (row = mysql_fetch_row(result)) {
					cout << row[0] << endl;
				}
				while (field = mysql_fetch_field_direct(result,1)) {
					cout << field->name << endl;
				}
			}
		}
		else {
			cout << "query sql failed" << endl;
		}
	}
	else {
		cout << "connect failed" << endl;
	}
	if (result != NULL) {
		mysql_free_result(result);
	}
	mysql_close(&mySql);

	system("pause");
	return 0;
}