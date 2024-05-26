#include <iostream>
#include "C:/Program Files/MySQL/MySQL Server 8.0/include/mysql.h"	       //Ruta donde se encuenta la bliblioteca mysql.h
#include "C:/Program Files/MySQL/MySQL Server 8.0/include/mysqld_error.h"  //Ruta donde se encuenta la bliblioteca mysql.h
using namespace std; 

class conexion{

public: 

void conexion_db(MYSQL *objDatos);

};

void conexion::conexion_db(MYSQL *objDatos){   
 if(mysql_real_connect(objDatos,"127.0.0.1", "root", "Axe$3128", "db_gasolinera", 3306, NULL, 0)){
 	cout<<"\n";
}else{
 	cout<<"Conexion fallida \n"<<mysql_error(objDatos);
 }
}	
