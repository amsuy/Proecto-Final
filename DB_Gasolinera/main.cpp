#include <iostream>
#include "C:/Program Files/MySQL/MySQL Server 8.0/include/mysql.h"	       //Ruta donde se encuenta la bliblioteca mysql.h
#include "C:/Program Files/MySQL/MySQL Server 8.0/include/mysqld_error.h"  //Ruta donde se encuenta la bliblioteca mysqld_error.h
#include <stdlib.h>
#include <fstream>
#include <windows.h>
#include <string>
#include "conexion.h"
#include <iomanip>
#include <sstream> 
#include <cstdlib> // Para system("cls")
#include <cctype>  // Para isdigit
#include <cstdio>  // Para sprintf



using namespace std;

 class data{

public:

//--------------------------AREA DE ADMINISTRADOR--------------------------

// clave administrador por defecto
void verificadoradministrador(MYSQL *objDatos) {
	    system("cls"); // solo funciona en windows
    	string meic;
    	string user;
    	int pass;
    	system("cls");
        	cout << "\n ---VERIFICACION DE INGRESO---" << endl;
        cout << "Ingresa Tu Usuario" << endl;
        cin >> user;
        cout << "Ingresa Tu Password" << endl;
        cin >> pass;

        if (user == meic || pass == 1234) {
            cout << "\n Bienvenido Administrador" << endl;
            system("pause");
        }else{
        	cout<<"ACCESO DENEGADO"<<endl;
        	system("pause");
        	menu_auxiliar_admin(objDatos);
		}
			
}

// menu de administrador   
void menuadministrador(MYSQL *objDatos){
	setlocale(LC_ALL, "");
	char continuar = 's';
	do {
		system("cls");// solo funciona en windows
		setlocale(LC_ALL, "");
        int menuadmin;
        cout<<"\n-------------------------------------"<<endl;
        cout<<"1) Crear Usuario a Consultas"<< endl;
        cout<<"2) Consultar Usuarios de Consultas"<< endl;
        cout<<"3) Borrar Usuario de Consultas"<<endl;
        cout<<"-------------------------------------"<<endl;
        cout<<"4) Crear Usuario a Ventas"<<endl;
        cout<<"5) Consultar Usuario de Ventas"<<endl;
        cout<<"6) Borrar Usuario de Ventas"<<endl;
        cout<<"-------------------------------------"<<endl;
        cout<<"7) Crear Usuario a Mantenimiento"<<endl;
        cout<<"8) Consultar Usuario de Mantenimiento"<<endl;
        cout<<"9) Borrar Usuario de Mantenimiento"<<endl;
        cout<<"-------------------------------------"<<endl;
        cout<<"10) Crear Usuario a Pedido"<<endl;
        cout<<"11) Consultar Usuario de Pedido"<<endl;
        cout<<"12) Borrar Usuario de Pedido"<<endl;
        cout<<"-------------------------------------"<<endl;
        cout<<"13) Crear Usuario a Abastecimiento"<<endl;
        cout<<"14) Consultar Usuario de Abastecimiento"<<endl;
        cout<<"15) Borrar Usuario de Abastecimiento"<<endl;
        cout<<"-------------------------------------"<<endl;
        cout<<"16) Salir del Menu de Administrador"<<endl;
        cout<<"17) Salir del Sistema"<<endl;
        cout<<"-------------------------------------"<<endl;
        cout<< "Elije una Opcion: ";
        cin>>menuadmin;
        switch (menuadmin) {
        case 1:
        system("cls");// solo funciona en windows
        crear_usuario_consulta(objDatos);
        cout << "" << endl;
        break;
        //-----------------
        case 2:
        system("cls");// solo funciona en windows
        consultar_usuarios_area_consultas(objDatos);
        cout<<""<<endl;
        break;
        //-----------------
        case 3:
        system("cls");// solo funciona en windows
        borrar_usuario_consultas(objDatos);
		cout<<""<<endl;	
        break;
        //-----------------
        case 4:
        system("cls");// solo funciona en windows
        crear_usuario_ventas(objDatos);
		cout<<""<<endl;	
        break;
        //-----------------
        case 5:
        system("cls");// solo funciona en windows
        consultar_usuarios_area_ventas(objDatos);
		cout<<""<<endl;	
        break;
        //-----------------
        case 6:
        system("cls");// solo funciona en windows
        borrar_usuario_ventas(objDatos);
		cout<<""<<endl;	
        break;
        //-----------------
        case 7:
        system("cls");// solo funciona en windows
        crear_usuario_mantenimiento(objDatos);
        break;
        //-----------------
        case 8:
        system("cls");// solo funciona en windows
        consultar_usuarios_area_mantenimiento(objDatos);
        break;
        //-----------------
        case 9:
        system("cls");// solo funciona en windows
        borrar_usuario_mantenimiento(objDatos);	
        break;
        //-----------------
        case 10:
        system("cls");// solo funciona en windows
        crear_usuario_pedido(objDatos);
        break;
        //-----------------
        case 11:
        system("cls");// solo funciona en windows
        consultar_usuarios_area_pedido(objDatos);
        break;
        //-----------------
        case 12:
        system("cls");// solo funciona en windows
        borrar_usuario_pedido(objDatos);
        break;
        //-----------------
        case 13:
        system("cls");// solo funciona en windows
        crear_usuario_abas(objDatos);
        break;
        //-----------------
        case 14:
        system("cls");// solo funciona en windows
        consultar_usuarios_area_abas(objDatos);	
        break;
        //-----------------
        case 15:
        system("cls");// solo funciona en windows
        borrar_usuario_abas(objDatos);
        break;
        //-----------------
        case 16:
        system("cls");// solo funciona en windows
        menu_auxiliar_admin(objDatos);	
        break;
        //-----------------
        case 17:
        cout<<"\n---ADIOS---"<<endl;
        exit(0);
        break;
        //-----------------
        default:
        cout << "Opcion Invalida" << endl;
        exit(0);
        }
        cout << "\n Deseas Volver al Menu de Admistrador (S/N)" << endl;
        cin >> continuar;
        if (continuar == 's' || continuar == 'S') {
        cout << "Volviendo al Menu de Administrador" << endl;
        system("pause");
        } else{
        cout << "Gracias pot utilizar nuestro sistema" << endl;
        exit(0);
        }
        system("cls");// solo funciona en windows
        } while (true);
}	
	
// MENU AUXILIAR DE ADMISTRADOR
void menu_auxiliar_admin(MYSQL *objDatos){	
setlocale(LC_ALL, "");
char continuar = 's';
conexion conn;

if(!(objDatos = mysql_init(0))) {
      // Imposible crear el objeto objDatos
      cout << "ERROR: imposible crear el objeto objDatos." << endl;          
      exit(1);
  }
conn.conexion_db(objDatos);
    do {
    	system("cls");
        int opcion;
        cout<<"_______________________________________________________________\n";
        cout<<"|                                                             |\n";
		cout<<"|                    MENU PRINCIPAL                           |\n";
		cout<<"|_____________________________________________________________|\n";
		cout<<"|   1) Administrador                                          |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   2) Consultas                                              |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   3) Ventas                                                 |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   4) Mantenimiento                                          |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   5) Pedido                                                 |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   6) Abastecimiento                                         |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   7) Salir del Sistema                                      |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"Elije una Opcion: ";
        cin>> opcion;

        switch (opcion) {
        case 1:
            verificadoradministrador(objDatos);
            cout<<""<<endl;
            menuadministrador(objDatos);
            break;
        //----------------------
			case 2:
            iniciar_sesion_consulta(objDatos);
            cout << "" << endl;
            menu_area_consultas(objDatos);
            break;
        //----------------------
        case 3:
        	iniciar_sesion_ventas(objDatos);
        	cout << "" << endl;
            menu_area_ventas(objDatos);
            break;
        //----------------------
        case 4:
        	iniciar_sesion_mantenimiento(objDatos);
            cout << "" << endl;
            menu_area_mantenimineto(objDatos);
            break;
        //----------------------
        case 5:
          iniciar_sesion_pedido(objDatos);
          cout << "" << endl;
          menu_area_pedido(objDatos); 
          break;
        //----------------------
        case 6:
          iniciar_sesion_abas(objDatos);
          cout << "" << endl;
          menu_area_abastecimiento(objDatos);
	      break;	
        //----------------------
        case 7:
            cout << "\n Gracias por utilizar nuestro sistema" << endl;
            cout << "Hasta Luego" << endl;
            exit(0);
        default:
            cout << "\n Opcion Incorrecta" << endl;
            break;
        }
        cout << "\n Deseas Volver al Menu Principal (S/N)" << endl;
        cin >> continuar;
        if (continuar == 's' || continuar == 'S') {
            cout << "Volviendo al Menu Principal" << endl;
            system("pause");
        } else {
            cout << "Gracias por utilizar nuestro sistema" << endl;
            exit(0);
        }
        system("cls");
    } while (true);		
}	
	
//--------------------------AREA DE CONSULTAS--------------------------

// verificar si un usuario ya existe en consultas
    bool usuario_existe_consulta(string usuario) {
        ifstream archivo("usuariosconsulta.txt");
        string usuarioGuardado, contrasenaGuardada;
        while (archivo >> usuarioGuardado >> contrasenaGuardada) {
            if (usuario == usuarioGuardado) {
                archivo.close();
                return true;
            }
        }
        archivo.close();
        return false;
    }

// creador de usuario y contrase√±a de consultas
    void crear_usuario_consulta(MYSQL *objDatos) {
    	system("cls"); // solo funciona en windows
        string usuario, contrasena;
        cout << "Ingrese el nombre de usuario: ";
        cin >> usuario;

        if (usuario_existe_consulta(usuario)) {
            cout << "El usuario ya existe." << endl;
            return;
        }

        cout << "Ingrese la contrase√±a: ";
        cin >> contrasena;

        ofstream archivo("usuariosconsulta.txt", ios::app);
        archivo << usuario << " " << contrasena << endl;
        archivo.close();

        cout << "Usuario y password creado exitosamente." << endl;
    }

    // Iniciar sesion de Consultas
    void iniciar_sesion_consulta(MYSQL *objDatos) {
    string usuario, contrasena;
    system("cls"); // solo funciona en windows
    cout<<"----VERIFICACION DE INGRESO----"<<endl;
    cout << "Ingrese el nombre de usuario: ";
    cin >> usuario;
    cout << "Ingrese la contraseÒa: ";
    cin >> contrasena;

    ifstream archivo("usuariosconsulta.txt");
    string usuarioGuardado, contrasenaGuardada;
    bool encontrado = false;
    while(archivo >> usuarioGuardado >> contrasenaGuardada) {
        if (usuario == usuarioGuardado && contrasena == contrasenaGuardada) {
            encontrado = true;
            cout << "\n°Bienvenido " << usuario << "!" << endl;
            break; // Salir del bucle una vez que se haya encontrado una coincidencia
        }
    }
    archivo.close();

    if (!encontrado) {
        cout << "\nNombre de usuario o contraseÒa incorrectos." << endl;
        system("pause");
        system("cls");
        menu_auxiliar_admin(objDatos);
    }
    }

// Consultador de usuario del area de consultas
void consultar_usuarios_area_consultas(MYSQL *objDatos){
	 system("cls"); // solo funciona en windows
        ifstream archivo("usuariosconsulta.txt");
        string usuario, contrasena;
        cout << "Usuarios registrados:" << endl;
        while (archivo >> usuario >> contrasena) {
            cout << "Usuario: " << usuario << ", Contrase√±a: " << contrasena << endl;
        }
        archivo.close();
    }
    
// funcion para borrar usuarios para el area de consultas    
 void borrar_usuario_consultas(MYSQL *objDatos) {
 	 system("cls"); // solo funciona en windows
        string usuario;
        cout << "Ingrese el nombre de usuario a borrar: ";
        cin >> usuario;

        ifstream archivoEntrada("usuariosconsulta.txt");
        ofstream archivoSalida("temp.txt");

        string usuarioGuardado, contrasenaGuardada;
        bool encontrado = false;
        while (archivoEntrada >> usuarioGuardado >> contrasenaGuardada) {
            if (usuario != usuarioGuardado) {
                archivoSalida << usuarioGuardado << " " << contrasenaGuardada << endl;
            } else {
                encontrado = true;
            }
        }
        archivoEntrada.close();
        archivoSalida.close();

        remove("usuariosconsulta.txt");
        rename("temp.txt", "usuariosconsulta.txt");

        if (encontrado) {
            cout << "Usuario borrado correctamente." << endl;
        } else {
            cout << "El usuario no existe." << endl;
        }
    }

// menu de area de consultas
void menu_area_consultas(MYSQL *objDatos){
do{
	system("cls");
	int opcion;
    	cout<<"_______________________________________________________________\n";
        cout<<"|                                                             |\n";
		cout<<"|                    MENU DE CONSULTAS                        |\n";
		cout<<"|_____________________________________________________________|\n";
		cout<<"|   1) Consultar Tipo de Combustibles                         |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   2) Consultar Contenedores                                 |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   3) Consultar Id Clientes                                  |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   4) Consultar Id Personal                                  |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   5) Consultar Informacion de Pedido y Ventas               |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   6) Regresar al Menu Principal                             |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   7) Salir del Sistema                                      |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"Elije una Opcion: ";
	cin>>opcion;
switch(opcion){
case 1:
Consultar(objDatos);	
break;
case 2:
Consultarcontenedor(objDatos);	
break;
case 3:	
consultar_datos_clientes(objDatos);	
break;	
case 4:
consultarDatosIdPersonal(objDatos);	
break;
case 5:
consultarDatosPedidoVentas(objDatos);
break;
case 6:
menu_auxiliar_admin(objDatos);	
break;
case 7:
cout<<"\n ----Adios---- \n";
exit(0);
}
}while(true);
}

//-------------------------AREA DE MANTENIMIENTO-------------------------

void consultardatos(MYSQL *objDatos) {
	 system("cls"); // solo funciona en windows
	MYSQL_RES *res;
	MYSQL_ROW row;

	// Ejecutar la consulta SELECT
	if (mysql_query(objDatos, "SELECT * FROM db_gasolinera.registro")) {
		cout << "Error al ejecutar la consulta: " << mysql_error(objDatos) << endl;
		return;
	}

	// Obtener el resultado de la consulta
	res = mysql_store_result(objDatos);

	if (res) {
		cout << "Datos registrados:" << endl;
		// Iterar sobre los resultados
		while ((row = mysql_fetch_row(res))) {
			cout<<"\n";
			cout << "\n* Codigo: " << row[0];
			cout << "\n* Tipo de mantenimiento: " << row[1];
			cout << "\n* Fecha de mantenimiento: " << row[2];
			cout << "\n* Descripcion: " << row[3]<<endl;
			cout << "* Area de mantenimiento: " << row[4]<<endl;
			cout<<""<<endl;
			cout<<"\n";
		}
		// Liberar la memoria del resultado
		mysql_free_result(res);
	} else {
		cout << "Error al obtener el resultado de la consulta: " << mysql_error(objDatos) << endl;
	}
}

void guardardatos(MYSQL *objDatos){
	system("cls");
		int id_codigo_mantenimiento;
	char tipo_de_mantenimiento[100];
	char fecha_mantenimiento [11] ;
	char descripcion_mantenimiento[400];
	char area_mantenimienro[200];

	bool ProgramIsOpened =true;
	int answer; //to keeo the program opened

	char* consult;
	char* sentence;
	string sentence_aux; // to add data to the table


	while (ProgramIsOpened) {
		cout<< " Ingrese el codigo del mantenimiento"<<endl;
		cin>>id_codigo_mantenimiento;
		cin.ignore(100, '\n');

		cout<<"Ingrese el tipo de mantenimiento que realizo: "<<endl;
		cin.getline(tipo_de_mantenimiento, 100, '\n');

		cout<<"Ingrese la fecha en la que se realizo el mantenimiento: "<<endl;
		cout<<"\nFormato: YY-MM-DD"<<endl;
	 	cout<<"Ejempo: 2024-12-01"<<endl;
		cin.getline(fecha_mantenimiento, 11, '\n');

		cout<<"Ingrese la descripcion del mantenimiento que se realizo: "<<endl;
		cin.getline(descripcion_mantenimiento, 400, '\n');

		cout<<"\nIngrese el area al que se realizo el mantenimiento: "<<endl;
		cin.getline(area_mantenimienro, 200, '\n');
		cout<<endl;

		//setting update

		sentence_aux = "INSERT INTO registro(id_codigo_mantenimiento, tipo_de_mantenimiento, fecha_mantenimiento, descripcion_mantenimiento, area_mantenimienro) VALUES('%d' , '%s' , '%s' , '%s' , '%s')";
		sentence = new char[sentence_aux.length() + 1];
		strcpy(sentence, sentence_aux.c_str()); // we coppy our string statement into a char

		consult= new char[strlen(sentence)+ sizeof(int) + strlen(tipo_de_mantenimiento) +strlen(fecha_mantenimiento) +strlen(descripcion_mantenimiento)+strlen(area_mantenimienro)];
		sprintf(consult, sentence,id_codigo_mantenimiento,tipo_de_mantenimiento, fecha_mantenimiento, descripcion_mantenimiento, area_mantenimienro); // substitutes %d... into actual values

		// make our attemp
		if(mysql_ping(objDatos)) {
			cout<<"Imposible conectar"<<endl;
			cout<<mysql_error(objDatos)<<endl;
		}

		if(mysql_query(objDatos, consult)) {
			cout<<"error "<<mysql_error(objDatos)<<endl;
			rewind(stdin);
			getchar();
		} else {
			cout<<"La informacion de guardo correctamente"<<endl;
		}
		mysql_store_result(objDatos);
       
       char continuar = 's';
       cout<<"Desea Volver a Ingrsar Mas Informacion (S/N)"<<endl;
       cin>>continuar;
       if(continuar == 's' || continuar == 'S'){
       	system("pause");
       	guardardatos(objDatos);
	   }else{
	   	system("pause");
	   	menu_area_mantenimineto(objDatos);
	   }
	}
}

void borrardatos(MYSQL *objDatos){
	 system("cls"); // solo funciona en windows

	 	string borrar_codigo;
	 	
	 	cout<<"ingrese el codigo que desea borrar: "<<endl;
	 	cin>>borrar_codigo;
	
		{
			const char* query;
			string sql;

			query=sql.c_str();
			sql="delete from  registro where id_codigo_mantenimiento = '"+borrar_codigo+"';"; 
			query=sql.c_str();
			mysql_query(objDatos, query);
			cout<<"\nDatos Borrados Exitosamente"<<endl;
		}
		
}

void actualizardatos(MYSQL* objDatos) {
	 system("cls"); // solo funciona en windows
	string id_codigo_mantenimiento;
	char tipo_de_mantenimiento[100];
	char fecha_mantenimiento[11];
	char descripcion_mantenimiento[400];
	char area_mantenimienro[200];

	cout << "Ingrese el codigo del mantenimiento que desea actualizar: " << endl;
	cin >> id_codigo_mantenimiento;
	cin.ignore(100, '\n');

	cout << "Ingrese el nuevo tipo de mantenimiento: " << endl;
	cin.getline(tipo_de_mantenimiento, 100, '\n');

	cout << "Ingrese la nueva fecha de mantenimiento: " << endl;
	cin.getline(fecha_mantenimiento, 11, '\n');

	cout << "Ingrese la nueva descripcion del mantenimiento: " << endl;
	cin.getline(descripcion_mantenimiento, 400, '\n');

	cout << "Ingrese la nueva area de mantenimiento: " << endl;
	cin.getline(area_mantenimienro, 200, '\n');

	string sql = "UPDATE registro SET tipo_de_mantenimiento = '" + string(tipo_de_mantenimiento) +
	             "', fecha_mantenimiento = '" + string(fecha_mantenimiento) +
	             "', descripcion_mantenimiento = '" + string(descripcion_mantenimiento) +
	             "', area_mantenimienro = '" + string(area_mantenimienro) +
	             "' WHERE id_codigo_mantenimiento = '" + id_codigo_mantenimiento + "';";
	const char* query = sql.c_str();
	if (mysql_query(objDatos, query)) {
		cout << "Error al actualizar el registro: " << mysql_error(objDatos) << endl;
	} else {
		cout << "Registro actualizado correctamente" << endl;
	}
}

// menu de area de matenimiento
void menu_area_mantenimineto(MYSQL *objDatos){
	do{
system("cls");
int opcion;
        cout<<"_______________________________________________________________\n";
        cout<<"|                                                             |\n";
		cout<<"|                  MENU DE MANTENIMIENTO                      |\n";
		cout<<"|_____________________________________________________________|\n";
		cout<<"|   1) Crear Registro                                         |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   2) Consultar Registro                                     |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   3) Borrar Registro                                        |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   4) Actualizar Registro                                    |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   5) Regresar al Menu Principal                             |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   6) Salir del Sistema                                     |\n";
		cout<<"|-------------------------------------------------------------|\n";		
        cout<<"    Elije una opcion: ";
cin>>opcion;
switch(opcion){
	case 1:
guardardatos(objDatos);
break;
case 2:
consultardatos(objDatos);	
break;
case 3:
borrardatos(objDatos);	
break;
case 4:
actualizardatos(objDatos);
break;
case 5:
menu_auxiliar_admin(objDatos);
break;
case 6:
cout<<"----Hasta luego"<<endl;
exit(0);	
default:
cout<<"Opcion Incorrecta"<<endl;
}
system("pause");
	}while(true);
}

// verificar si un usuario ya existe en el area de mantenimiento
    bool usuario_existe_mantenimiento(string usuario) {
        ifstream archivo("usuariosmatenimiento.txt");
        string usuarioGuardado, contrasenaGuardada;
        while (archivo >> usuarioGuardado >> contrasenaGuardada) {
            if (usuario == usuarioGuardado) {
                archivo.close();
                return true;
            }
        }
        archivo.close();
        return false;
    }

// creador de usuario y contrase√±a de area de mantenimiento
    void crear_usuario_mantenimiento(MYSQL *objDatos) {
    	 system("cls"); // solo funciona en windows
        string usuario, contrasena;
        cout << "Ingrese el nombre de usuario: ";
        cin >> usuario;

        if (usuario_existe_mantenimiento(usuario)) {
            cout << "El usuario ya existe." << endl;
            return;
        }

        cout << "Ingrese la contrase√±a: ";
        cin >> contrasena;

        ofstream archivo("usuariosmantenimiento.txt", ios::app);
        archivo << usuario << " " << contrasena << endl;
        archivo.close();

        cout << "Usuario y password creado exitosamente." << endl;
    }

    // Iniciar sesion del area de mantenimiento
    void iniciar_sesion_mantenimiento(MYSQL *objDatos) {
        string usuario, contrasena;
        system("cls"); // solo funciona en windows
    cout<<"----VERIFICACION DE INGRESO----"<<endl;
    cout << "Ingrese el nombre de usuario: ";
    cin >> usuario;
    cout << "Ingrese la contraseÒa: ";
    cin >> contrasena;

    ifstream archivo("usuariosmantenimiento.txt");
    string usuarioGuardado, contrasenaGuardada;
    bool encontrado = false;
    while(archivo >> usuarioGuardado >> contrasenaGuardada) {
        if (usuario == usuarioGuardado && contrasena == contrasenaGuardada) {
            encontrado = true;
            cout << "\n°Bienvenido " << usuario << "!" << endl;
            break; // Salir del bucle una vez que se haya encontrado una coincidencia
        }
    }
    archivo.close();

    if (!encontrado) {
        cout << "\nNombre de usuario o contraseÒa incorrectos." << endl;
        system("pause");
        system("cls");
        menu_auxiliar_admin(objDatos);
    }
    }

// Consultador de usuario del area de mantenimiento
void consultar_usuarios_area_mantenimiento(MYSQL *objDatos){
	 system("cls"); // solo funciona en windows
        ifstream archivo("usuariosmantenimiento.txt");
        string usuario, contrasena;
        cout << "Usuarios registrados:" << endl;
        while (archivo >> usuario >> contrasena) {
            cout << "Usuario: " << usuario << ", Contrase√±a: " << contrasena << endl;
        }
        archivo.close();
    }
    
// funcion para borrar usuarios para el area de mantenimiento  
 void borrar_usuario_mantenimiento(MYSQL *objDatos) {
 	 system("cls"); // solo funciona en windows
        string usuario;
        cout << "Ingrese el nombre de usuario a borrar: ";
        cin >> usuario;

        ifstream archivoEntrada("usuariosmantenimiento.txt");
        ofstream archivoSalida("temp.txt");

        string usuarioGuardado, contrasenaGuardada;
        bool encontrado = false;
        while (archivoEntrada >> usuarioGuardado >> contrasenaGuardada) {
            if (usuario != usuarioGuardado) {
                archivoSalida << usuarioGuardado << " " << contrasenaGuardada << endl;
            } else {
                encontrado = true;
            }
        }
        archivoEntrada.close();
        archivoSalida.close();

        remove("usuariosmantenimiento.txt");
        rename("temp.txt", "usuariosmantenimiento.txt");

        if (encontrado) {
            cout << "Usuario borrado correctamente." << endl;
        } else {
            cout << "El usuario no existe." << endl;
        }
    }

//-------------------------AREA DE PEDIDO-------------------------

// menu de area de pedido
void menu_area_pedido(MYSQL *objDatos){
	do{
		system("cls"); //solo funciona en windows
		cout<<"_______________________________________________________________\n";
        cout<<"|                                                             |\n";
		cout<<"|                       MENU DE PEDIDO                        |\n";
		cout<<"|_____________________________________________________________|\n";
		cout<<"|   1) Ingresar Datos De Clientes                             |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   2) Consultar Datos Del Cliente                            |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   3) Ingresar Datos De Proveedores                          |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   4) consultar Datos De Proveedores                         |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   5) Borrar Datos del Clientes                              |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   6) Actualizar datos del Cliente                           |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   7) Actualizar Datos Del Proveedor                         |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   8) Borrar Datos De Proveedor                              |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   9) Consultar Tipo De Combustible                          |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   10) Consultar Cantidad de Contenedores                    |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   11) Regresar al Menu Principal                            |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   12) Salir del Sistema                                     |\n";
		cout<<"|-------------------------------------------------------------|\n";		
        cout<<"    Elije una opcion: ";
int opcion;
cin>>opcion;
switch(opcion) {
case 1:
ingresar_datos_clientes(objDatos);
break;
case 2:
consultar_datos_clientes (objDatos);
break;
case 3:
ingresar_datos_proveedores (objDatos);
break;
case 4:
consultar_datos_proveedores (objDatos);
break;
case 5:
borrar_datos_clientes (objDatos);
break;
case 6:
actualizar_datos_clientes (objDatos);
break;
case 7:
actualizar_datos_proveedores (objDatos);
break;
case 8:
borrar_datos_proveedores (objDatos);
break;
case 9:
Consultar(objDatos);
break;
case 10:
Consultarcontenedor(objDatos);
break;
case 11:
menu_auxiliar_admin(objDatos);
break;
case 12:
cout<<"\n ----ADIOS---\n";
exit(0);
default: 
cout <<"opcion incorrecta"<<endl;
}	
}while(true);
}

// clientes 
void borrar_datos_clientes(MYSQL* objDatos) {
	system("cls");// solo funciona en windosw
    int id;
    cout << "Ingrese el Id del cliente que desea borrar: ";
    cin >> id;

    // Convertir entero a cadena
    stringstream ss;
    ss << id;
    string strId = ss.str();

    string query = "DELETE FROM Id_clientes WHERE Id = " + strId;
    
    if (mysql_query(objDatos, query.c_str())) {
        cerr << "Error: " << mysql_error(objDatos) << endl;
    } else {
        cout << "\nDatos borrados exitosamente." << endl;
    }
    system("pause");
}

void actualizar_datos_clientes(MYSQL* objDatos) {
	system("cls");// solo funciona en windosw
    int id;
    
    struct id_clientes {
        char Nombre[100];
        char Apellido[100];
        char Codigo[100];
        int Telefono;
        char Direccion[150];
    } cliente;

    cin.ignore();
    cout << "\nIngrese el Id del cliente que desea actualizar: ";
    cin >> id;
    cin.ignore();
    cout << "\nIngrese Nombre: "; cin.getline(cliente.Nombre, 100);
    cout << "Ingrese Apellido: "; cin.getline(cliente.Apellido, 100);
    cout << "Ingrese Codigo: "; cin.getline(cliente.Codigo, 100);
    cout << "Ingrese Telefono: "; cin >> cliente.Telefono;
    cin.ignore();
    cout << "Ingrese Direccion: "; cin.getline(cliente.Direccion, 150);

    // Convertir entero a cadena
    stringstream ssId, ssTelefono;
    ssId << id;
    ssTelefono << cliente.Telefono;
    string strId = ssId.str();
    string strTelefono = ssTelefono.str();

    string query = "UPDATE Id_clientes SET Nombre = '" + string(cliente.Nombre) +
                   "', Apellido = '" + string(cliente.Apellido) +
                   "', Codigo = '" + string(cliente.Codigo) +
                   "', Telefono = " + strTelefono +
                   ", Direccion = '" + string(cliente.Direccion) +
                   "' WHERE Id = " + strId;
    
    if (mysql_query(objDatos, query.c_str())) {
        cerr << "Error: " << mysql_error(objDatos) << endl;
    } else {
        cout << "\nDatos actualizados exitosamente." << endl;
    }
    system("pause");
}

void ingresar_datos_clientes(MYSQL* objDatos) {
	system("cls");// solo funciona en windosw
    struct id_clientes {
        char Nombre[100];
        char Apellido[100];
        char Codigo[100];
        int Telefono;
        char Direccion[150];
    } cliente;

    cin.ignore();
    cout << "Ingrese Nombre: " << endl; cin.getline(cliente.Nombre, 100);
    cout << "Ingrese Apellido: " << endl; cin.getline(cliente.Apellido, 100);
    cout << "Ingrese Codigo: " << endl; cin.getline(cliente.Codigo, 100);
    cout << "Ingrese Telefono: " << endl; cin >> cliente.Telefono;
    cin.ignore();
    cout << "Ingrese Direccion: " << endl; cin.getline(cliente.Direccion, 150);

    // Convertir entero a cadena
    stringstream ss;
    ss << cliente.Telefono;
    string strTelefono = ss.str();

    string query = "INSERT INTO Id_clientes (Nombre, Apellido, Codigo, Telefono, Direccion) VALUES ('" +
                   string(cliente.Nombre) + "', '" + string(cliente.Apellido) + "', '" +
                   string(cliente.Codigo) + "', " + strTelefono + ", '" +
                   string(cliente.Direccion) + "')";
    
    if (mysql_query(objDatos, query.c_str())) {
        cerr << "Error: " << mysql_error(objDatos) << endl;
    } else {
        cout << "Datos ingresados exitosamente." << endl;
    }
    system("pause");
}

void consultar_datos_clientes(MYSQL* objDatos) {
	system("cls");// solo funciona en windosw
    if (mysql_query(objDatos, "SELECT * FROM Id_clientes")) {
        cerr << "Error: " << mysql_error(objDatos) << endl;
        return;
    }

    MYSQL_RES* res = mysql_store_result(objDatos);
    if (!res) {
        cerr << "Error: " << mysql_error(objDatos) << endl;
        return;
    }

    MYSQL_ROW row;
    while ((row = mysql_fetch_row(res))) {
        cout<< "\nDatos registrados: \n" << "\nId: " << row[0] << "\n Nombre: " << row[1] << "\n Apellido: " << row[2] << "\n Codigo: " << row[3]
             << "\n Telefono: " << row[4] << "\n Direccion: " << row[5]<< "\n" << endl;
    }

    mysql_free_result(res);
    system("pause");
}

//proveedores
void ingresar_datos_proveedores(MYSQL* objDatos) {
	system("cls");// solo funciona en windosw
    struct id_proveedores {
        char Nombre[100];
        char Apellido[100];
        char Empresa[100];
        char Pais[100];
    } proveedor;

    cin.ignore();
    cout << "\nIngrese Nombre: " << endl; cin.getline(proveedor.Nombre, 100);
    cout << "Ingrese Apellido: " << endl; cin.getline(proveedor.Apellido, 100);
    cout << "Ingrese Empresa: " << endl; cin.getline(proveedor.Empresa, 100);
    cout << "Ingrese Pais: " << endl; cin.getline(proveedor.Pais, 100);

    string query = "INSERT INTO Id_proveedores (Nombre, Apellido, Empresa, Pais) VALUES ('" +
                   string(proveedor.Nombre) + "', '" + string(proveedor.Apellido) + "', '" +
                   string(proveedor.Empresa) + "', '" + string(proveedor.Pais) + "')";
    
    if (mysql_query(objDatos, query.c_str())) {
        cerr << "Error: " << mysql_error(objDatos) << endl;
    } else {
        cout << "\nDatos ingresados exitosamente." << endl;
    }
    system("pause");
}

void borrar_datos_proveedores(MYSQL* objDatos) {
	system("cls");// solo funciona en windosw
    int id;
    cout << "Ingrese el Id del proveedor que desea borrar: ";
    cin >> id;

    // Convertir entero a cadena
    stringstream ss;
    ss << id;
    string strId = ss.str();

    string query = "DELETE FROM Id_proveedores WHERE Id = " + strId;
    
    if (mysql_query(objDatos, query.c_str())) {
        cerr << "Error: " << mysql_error(objDatos) << endl;
    } else {
        cout << "Datos borrados exitosamente." << endl;
    }
    system("pause");
}

void actualizar_datos_proveedores(MYSQL* objDatos) {
	system("cls");// solo funciona en windosw
    int id;
    
    struct id_proveedores {
        char Nombre[100];
        char Apellido[100];
        char Empresa[100];
        char Pais[100];
    } proveedor;

    cout << "\nIngrese el Id del proveedor que desea actualizar: ";
    cin >> id; 
    cin.ignore();
    cout << "\nIngrese Nombre: "; cin.getline(proveedor.Nombre, 100);
    cout << "Ingrese Apellido: "; cin.getline(proveedor.Apellido, 100);
    cout << "Ingrese Empresa: "; cin.getline(proveedor.Empresa, 100);
    cout << "Ingrese Pais: "; cin.getline(proveedor.Pais, 100);

    // Convertir entero a cadena
    stringstream ss;
    ss << id;
    string strId = ss.str();

    string query = "UPDATE Id_proveedores SET Nombre = '" + string(proveedor.Nombre) +
                   "', Apellido = '" + string(proveedor.Apellido) +
                   "', Empresa = '" + string(proveedor.Empresa) +
                   "', Pais = '" + string(proveedor.Pais) +
                   "' WHERE Id = " + strId;
    
    if (mysql_query(objDatos, query.c_str())) {
        cerr << "Error: " << mysql_error(objDatos) << endl;
    } else {
        cout << "\nDatos actualizados exitosamente." << endl;
    }
    system("pause");
}

void consultar_datos_proveedores(MYSQL* objDatos) {
	system("cls");// solo funciona en windosw
    if (mysql_query(objDatos, "SELECT * FROM Id_proveedores")) {
        cerr << "Error: " << mysql_error(objDatos) << endl;
        return;
    }

    MYSQL_RES* res = mysql_store_result(objDatos);
    if (!res) {
        cerr << "Error: " << mysql_error(objDatos) << endl;
        return;
    }

    MYSQL_ROW row;
    while ((row = mysql_fetch_row(res))) {
        cout<< "\nDatos registrados: \n" << "\nId: " << row[0] << "\n Nombre: " << row[1] << "\n Apellido: " << row[2] << "\n Empresa: " << row[3]
             << "\n Pais: " << row[4] <<"\n"<<endl;
    }

    mysql_free_result(res);
    system("pause");
}

// verificar si un usuario ya existe en el area de pedido 
    bool usuario_existe_pedido(string usuario) {
        ifstream archivo("usuariospedido.txt");
        string usuarioGuardado, contrasenaGuardada;
        while (archivo >> usuarioGuardado >> contrasenaGuardada) {
            if (usuario == usuarioGuardado) {
                archivo.close();
                return true;
            }
        }
        archivo.close();
        return false;
    }

// creador de usuario y contrase√±a de area de pedido 
    void crear_usuario_pedido(MYSQL *objDatos) {
    	 system("cls"); // solo funciona en windows
        string usuario, contrasena;
        cout << "Ingrese el nombre de usuario: ";
        cin >> usuario;

        if (usuario_existe_pedido(usuario)) {
            cout << "El usuario ya existe." << endl;
            return;
        }

        cout << "Ingrese la contrase√±a: ";
        cin >> contrasena;

        ofstream archivo("usuariospedido.txt", ios::app);
        archivo << usuario << " " << contrasena << endl;
        archivo.close();

        cout << "Usuario y password creado exitosamente." << endl;
    }

    // Iniciar sesion del area de pedido
void iniciar_sesion_pedido(MYSQL *objDatos) {
	 system("cls"); // solo funciona en windows
    string usuario, contrasena;
    system("cls"); // solo funciona en windows
    cout<<"----VERIFICACION DE INGRESO----"<<endl;
    cout << "Ingrese el nombre de usuario: ";
    cin >> usuario;
    cout << "Ingrese la contraseÒa: ";
    cin >> contrasena;

    ifstream archivo("usuariospedido.txt");
    string usuarioGuardado, contrasenaGuardada;
    bool encontrado = false;
    while(archivo >> usuarioGuardado >> contrasenaGuardada) {
        if (usuario == usuarioGuardado && contrasena == contrasenaGuardada) {
            encontrado = true;
            cout << "\n°Bienvenido " << usuario << "!" << endl;
            break; // Salir del bucle una vez que se haya encontrado una coincidencia
        }
    }
    archivo.close();

    if (!encontrado) {
        cout << "\nNombre de usuario o contraseÒa incorrectos." << endl;
        system("pause");
        system("cls");
        menu_auxiliar_admin(objDatos);
    }
}

// Consultador de usuario del area de pedido
void consultar_usuarios_area_pedido(MYSQL *objDatos){
	 system("cls"); // solo funciona en windows
        ifstream archivo("usuariospedido.txt");
        string usuario, contrasena;
        cout << "Usuarios registrados:" << endl;
        while (archivo >> usuario >> contrasena) {
            cout << "Usuario: " << usuario << ", Contrase√±a: " << contrasena << endl;
        }
        archivo.close();
    }
    
// funcion para borrar usuarios para el area de pedido  
 void borrar_usuario_pedido(MYSQL *objDatos) {
 	 system("cls"); // solo funciona en windows
        string usuario;
        cout << "Ingrese el nombre de usuario a borrar: ";
        cin >> usuario;

        ifstream archivoEntrada("usuariospedido.txt");
        ofstream archivoSalida("temp.txt");

        string usuarioGuardado, contrasenaGuardada;
        bool encontrado = false;
        while (archivoEntrada >> usuarioGuardado >> contrasenaGuardada) {
            if (usuario != usuarioGuardado) {
                archivoSalida << usuarioGuardado << " " << contrasenaGuardada << endl;
            } else {
                encontrado = true;
            }
        }
        archivoEntrada.close();
        archivoSalida.close();

        remove("usuariospedido.txt");
        rename("temp.txt", "usuariospedido.txt");

        if (encontrado) {
            cout << "Usuario borrado correctamente." << endl;
        } else {
            cout << "El usuario no existe." << endl;
        }
    }

//------------------------------AREA DE VENTAS------------------------------

// menu de area de ventas
void menu_area_ventas(MYSQL *objDatos){
	string tipoCombustible, cantidad;
	do{
	system("cls");
     	cout<<"_______________________________________________________________\n";
        cout<<"|                                                             |\n";
		cout<<"|                      MENU DE VENTAS                         |\n";
		cout<<"|_____________________________________________________________|\n";
		cout<<"|   1) Ingresar Id Personal                                   |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   2) Consultar Id Personal                                  |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   3) Ingresar Informacion De Pedido y Ventas                |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   4) Consultar Informacion De Pedido y Ventas               |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   5) Actualizar Id Personal                                 |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   6) Borrar Id Personal                                     |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   7) Borrar Informacion De Pedido y Ventas                  |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   8) Actualizar Informacion de Pedido y Ventas              |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   9) Consultar Tipo de Combustible                          |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   10) Consultar Contenedores                                |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   11) Consultar Datos de Clientes                           |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   12) Venta de Combustible                                  |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   13) Regresal al Menu Principal                            |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   14) Salir del Sistema                                     |\n";
		cout<<"|-------------------------------------------------------------|\n";		
        cout<<"    Elije una opcion: ";
int opcion;
cin>> opcion;

switch(opcion){
 case 1:
    ingresarDatosIdPersonal(objDatos);
    break;
    case 2:
consultarDatosIdPersonal(objDatos);
break;
case 3:
ingresarDatosPedidoVentas(objDatos);
  break;
    case 4:
    consultarDatosPedidoVentas(objDatos);
    break;
    case 5:
    actualizarDatosIdPersonal(objDatos);
    break;
    case 6:
    borrarDatosIdPersonal(objDatos);	
    break;
    case 7:
    borrarDatosPedidoVentas(objDatos);	
    break;
    case 8:
    actualizarDatosPedidoVentas(objDatos);
    break;
    case 9:
    Consultar(objDatos);
    break;
    case 10:
    Consultarcontenedor(objDatos);
    break;
    case 11:
    consultar_datos_clientes(objDatos);
    break;
    case 12:
    //descuentarCombustible(objDatos);
    menu_descuento(objDatos);
    break;
    case 13:
    menu_auxiliar_admin(objDatos);	
    break;
    case 14:
    cout << "Saliendo...\n";
    exit(0);
    break;
    default:
    cout << "Opcion invalida\n";
    break;
    }	
	}while(true);
}

void ingresarDatosIdPersonal(MYSQL *objDatos) {
    setlocale(LC_ALL, "");
    system("cls");
    // DefiniciÛn de estructura
    struct Estudiante {
        char nombre[50];
        char apellido[50];
        int dpi;
    } info;

    cout << "\nIngrese Nombre: ";
    cin >> info.nombre;
    cout << "Ingrese Apellido: ";
    cin >> info.apellido;
    cout << "Ingrese DPI: ";
    cin >> info.dpi;

    char consulta[256];
    sprintf(consulta, "INSERT INTO id_personal (nombre, apellido, dpi) VALUES('%s', '%s', %d)", info.nombre, info.apellido, info.dpi);

    if (mysql_query(objDatos, consulta)) {
        cout << "Error al insertar los datos: " << mysql_error(objDatos) << endl;
    } else {
        cout << "Datos registrados exitosamente" << endl;
    }
    system("pause");
}

void actualizarDatosIdPersonal(MYSQL *objDatos) {
	system("cls");
    int dpi;
    cout << "Ingrese el DPI del registro a actualizar: ";
    cin >> dpi;

    struct Estudiante {
        char nombre[50];
        char apellido[50];
    } info;

    cout << "Ingrese nuevo Nombre: ";
    cin >> info.nombre;
    cout << "Ingrese nuevo Apellido: ";
    cin >> info.apellido;

    char consulta[256];
    sprintf(consulta, "UPDATE id_personal SET nombre='%s', apellido='%s' WHERE dpi=%d", info.nombre, info.apellido, dpi);

    if (mysql_query(objDatos, consulta)) {
        cout << "Error al actualizar los datos: " << mysql_error(objDatos) << endl;
    } else {
        cout << "Datos actualizados exitosamente" << endl;
    }
    system("pause");
}

void consultarDatosIdPersonal(MYSQL *objDatos) {
	system("cls");
	system("cls");
	cout<<"\nDatos Registrados";
	cout<<"\nFormato de Registro: Nombre-Apellido-DPI\n"<<endl;
    if (mysql_query(objDatos, "SELECT * FROM id_personal")) {
        cout << "SELECT failed. Error: " << mysql_error(objDatos) << endl;
        return;
    }
    MYSQL_RES *res = mysql_store_result(objDatos);
    if (res == NULL) {
        cout << "mysql_store_result() failed. Error: " << mysql_error(objDatos) << endl;
        return;
    }
    int num_fields = mysql_num_fields(res);
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(res))) {
        for (int i = 0; i < num_fields; i++) {
            cout << (row[i] ? row[i] : "NULL") << " ";
        }
        cout << endl;
    }
    mysql_free_result(res);
    system("pause");
}

void borrarDatosIdPersonal(MYSQL *objDatos) {
	system("cls");
    int dpi;
    cout << "\nIngrese el DPI del registro a borrar: ";
    cin >> dpi;

    char consulta[256];
    sprintf(consulta, "DELETE FROM id_personal WHERE dpi=%d", dpi);

    if (mysql_query(objDatos, consulta)) {
        cout << "Error al borrar los datos: " << mysql_error(objDatos) << endl;
    } else {
        cout << "Datos borrados exitosamente" << endl;
    }
    system("pause");
}

void consultarDatosPedidoVentas(MYSQL *objDatos) {
	system("cls");
	MYSQL_RES *res;
	MYSQL_ROW row;
	
	
    if (mysql_query(objDatos, "SELECT * FROM pedido_ventas")) {
        cout << "SELECT failed. Error: " << mysql_error(objDatos) << endl;
        return;
    }
    res = mysql_store_result(objDatos);
    cout<<"\t\t\tDatos Registrados"<<endl;
    cout<< "--------------------------------------------------------------------------------"<<endl;
	cout<< left << setw(15) << setfill(' ')<<"ID";
	cout<< left << setw(25) << setfill(' ')<<"Tipo de Combustible";
	cout<< left << setw(20) << setfill(' ')<<"Precio";
	cout<< left << setw(20) << setfill(' ')<<"Cantidad en Galones"<<endl;
	cout<< "---------------------------------------------------------------------------------"<<endl;
   
    
    while ((row = mysql_fetch_row(res))) {
    	
    		cout<< left<< setw(20)<< setfill(' ')<<row[0];	
    		cout<< left<< setw(20)<< setfill(' ')<<row[1];
			cout<< left<< setw(25)<< setfill(' ')<<row[2];
			cout<< left<< setw(20)<< setfill(' ')<<row[3]<<endl;   
			cout<<"---------------------------------------------------------------------------------";
			cout<<endl;
    	
    }
    mysql_free_result(res);
    system("pause");
}

void actualizarDatosPedidoVentas(MYSQL *objDatos) {
	system("cls");
    char id_cliente[50];
    cout << "\nIngrese el ID del cliente del registro a actualizar: ";
    cin >> id_cliente;

    struct Pedido {
        char tipo_combustible[50];
        int precio;
        char cantidad[50];
    } info;

    cout << "\nIngrese nuevo tipo de combustible: ";
    cin >> info.tipo_combustible;
    cout << "\nIngrese nuevo precio: ";
    cin >> info.precio;
    cout << "\nIngrese nueva cantidad: ";
    cin >> info.cantidad;

    char consulta[256];
    sprintf(consulta, "UPDATE pedido_ventas SET tipo_combustible='%s', precio=%d, cantidad='%s' WHERE id_cliente='%s'", info.tipo_combustible, info.precio, info.cantidad, id_cliente);

    if (mysql_query(objDatos, consulta)) {
        cout << "Error al actualizar los datos: " << mysql_error(objDatos) << endl;
    } else {
        cout << "Datos actualizados exitosamente" << endl;
    }
    system("pause");
}

void borrarDatosPedidoVentas(MYSQL *objDatos) {
	system("cls");
    char id_cliente[50];
    cout << "\nIngrese el ID del cliente del registro a borrar: ";
    cin >> id_cliente;

    char consulta[256];
    sprintf(consulta, "DELETE FROM pedido_ventas WHERE id_cliente='%s'", id_cliente);

    if (mysql_query(objDatos, consulta)) {
        cout << "Error al borrar los datos: " << mysql_error(objDatos) << endl;
    } else {
        cout << "Datos borrados exitosamente" << endl;
    }
    system("pause");
}

void Updatecontenedorventassuper(MYSQL* objDatos) {
    system("cls"); // solo funciona en windows
    int n1, n2, resultado;
    string id_editar;

    cout << "Ingrese la cantidad anterior: ";
    cin >> n1;
    cout << "Ingrese la cantidad vendida: ";
    cin >> n2;
    resultado = n1 - n2;
    cout << "Ingrese el ID a editar: ";
    cin >> id_editar;

    // Convertir resultado a string usando stringstream
    stringstream ss;
    ss << resultado;
    string cantidad_super = ss.str();

    // Construir la consulta SQL correctamente
    string sql = "UPDATE contenedor_unidad SET contenedor_super = '" + cantidad_super + "' WHERE idcontenedor_unidad = '" + id_editar + "';";

    // Mostrar la consulta SQL para depuraciÛn
    cout << "Consulta SQL: " << sql << endl;

    const char* query = sql.c_str();
    if (mysql_query(objDatos, query) == 0) {
        cout << "\nRegistro actualizado exitosamente.\n";
    } else {
        cout << "Error al actualizar el registro: " << mysql_error(objDatos) << endl;
    }

    system("pause");
}

void Updatecontenedorventasdiesel(MYSQL* objDatos) {
    system("cls"); // solo funciona en windows
    int n1, n2, resultado;
    string id_editar;

    cout << "Ingrese la cantidad anterior: ";
    cin >> n1;
    cout << "Ingrese la cantidad vendida: ";
    cin >> n2;
    resultado = n1 - n2;
    cout << "Ingrese el ID a editar: ";
    cin >> id_editar;

    // Convertir resultado a string usando stringstream
    stringstream ss;
    ss << resultado;
    string cantidad_disel = ss.str();

    // Construir la consulta SQL correctamente
    string sql = "UPDATE contenedor_unidad SET contenedor_disel = '" + cantidad_disel + "' WHERE idcontenedor_unidad = '" + id_editar + "';";

    // Mostrar la consulta SQL para depuraciÛn
    cout << "Consulta SQL: " << sql << endl;

    const char* query = sql.c_str();
    if (mysql_query(objDatos, query) == 0) {
        cout << "\nRegistro actualizado exitosamente.\n";
    } else {
        cout << "Error al actualizar el registro: " << mysql_error(objDatos) << endl;
    }

    system("pause");
}

void Updatecontenedorventasregular(MYSQL* objDatos) {
    system("cls"); // solo funciona en windows
    int n1, n2, resultado;
    string id_editar;

    cout << "Ingrese la cantidad anterior: ";
    cin >> n1;
    cout << "Ingrese la cantidad vendida: ";
    cin >> n2;
    resultado = n1 - n2;
    cout << "Ingrese el ID a editar: ";
    cin >> id_editar;

    // Convertir resultado a string usando stringstream
    stringstream ss;
    ss << resultado;
    string cantidad_regular = ss.str();

    // Construir la consulta SQL correctamente
    string sql = "UPDATE contenedor_unidad SET contenedor_regular = '" + cantidad_regular + "' WHERE idcontenedor_unidad = '" + id_editar + "';";

    // Mostrar la consulta SQL para depuraciÛn
    cout << "Consulta SQL: " << sql << endl;

    const char* query = sql.c_str();
    if (mysql_query(objDatos, query) == 0) {
        cout << "\nRegistro actualizado exitosamente.\n";
    } else {
        cout << "Error al actualizar el registro: " << mysql_error(objDatos) << endl;
    }

    system("pause");
}

void ingresarDatosPedidoVentas(MYSQL *objDatos) {
	system("cls");
    setlocale(LC_ALL, "");
    // DefiniciÛn de estructura
    struct Pedido {
        char id_cliente[50];
        char tipo_combustible[50];
        int precio;
        char cantidad[50];
    } info;

    cout << "\nIngrese ID del cliente: ";
    cin >> info.id_cliente;
    cout << "\nIngrese tipo de combustible: ";
    cin >> info.tipo_combustible;
    cout << "\nIngrese precio: ";
    cin >> info.precio;
    cout << "\nIngrese cantidad: ";
    cin >> info.cantidad;

    char consulta[256];
    sprintf(consulta, "INSERT INTO pedido_ventas (id_cliente, tipo_combustible, precio, cantidad) VALUES('%s', '%s', %d, '%s')", info.id_cliente, info.tipo_combustible, info.precio, info.cantidad);

    if (mysql_query(objDatos, consulta)) {
        cout << "Error al insertar los datos: " << mysql_error(objDatos) << endl;
    } else {
        cout << "Datos registrados exitosamente" << endl;
    }
    system("pause");
}

// verificar si un usuario ya existe en el area de ventas
    bool usuario_existe_ventas(string usuario) {
        ifstream archivo("usuariosventas.txt");
        string usuarioGuardado, contrasenaGuardada;
        while (archivo >> usuarioGuardado >> contrasenaGuardada) {
            if (usuario == usuarioGuardado) {
                archivo.close();
                return true;
            }
        }
        archivo.close();
        return false;
    }

// creador de usuario y contrase√±a de area de ventas
    void crear_usuario_ventas(MYSQL *objDatos) {
    	 system("cls"); // solo funciona en windows
        string usuario, contrasena;
        cout << "Ingrese el nombre de usuario: ";
        cin >> usuario;

        if (usuario_existe_ventas(usuario)) {
            cout << "El usuario ya existe." << endl;
            return;
        }

        cout << "Ingrese la contrase√±a: ";
        cin >> contrasena;

        ofstream archivo("usuariosventas.txt", ios::app);
        archivo << usuario << " " << contrasena << endl;
        archivo.close();

        cout << "Usuario y password creado exitosamente." << endl;
    }

    // Iniciar sesion del area de ventas
    void iniciar_sesion_ventas(MYSQL *objDatos) {
    system("cls"); // solo funciona en windows
    cout<<"----VERIFICACION DE INGRESO----"<<endl;
    string usuario, contrasena;
    cout << "Ingrese el nombre de usuario: ";
    cin >> usuario;
    cout << "Ingrese la contraseÒa: ";
    cin >> contrasena;

    ifstream archivo("usuariosventas.txt");
    string usuarioGuardado, contrasenaGuardada;
    bool encontrado = false;
    while(archivo >> usuarioGuardado >> contrasenaGuardada) {
        if (usuario == usuarioGuardado && contrasena == contrasenaGuardada) {
            encontrado = true;
            cout << "\n°Bienvenido " << usuario << "!" << endl;
            break; // Salir del bucle una vez que se haya encontrado una coincidencia
        }
    }
    archivo.close();

    if (!encontrado) {
        cout << "\nNombre de usuario o contraseÒa incorrectos." << endl;
        system("pause");
        system("cls");
        menu_auxiliar_admin(objDatos);
    }
}

// Consultador de usuario del area de ventas
void consultar_usuarios_area_ventas(MYSQL *objDatos){
	 system("cls"); // solo funciona en windows
        ifstream archivo("usuariosventas.txt");
        string usuario, contrasena;
        cout << "Usuarios registrados:" << endl;
        while (archivo >> usuario >> contrasena) {
            cout << "Usuario: " << usuario << ", Contrase√±a: " << contrasena << endl;
        }
        archivo.close();
    }
    
// funcion para borrar usuarios para el area de ventas 
 void borrar_usuario_ventas(MYSQL *objDatos) {
 	 system("cls"); // solo funciona en windows
        string usuario;
        cout << "Ingrese el nombre de usuario a borrar: ";
        cin >> usuario;

        ifstream archivoEntrada("usuariosventas.txt");
        ofstream archivoSalida("temp.txt");

        string usuarioGuardado, contrasenaGuardada;
        bool encontrado = false;
        while (archivoEntrada >> usuarioGuardado >> contrasenaGuardada) {
            if (usuario != usuarioGuardado) {
                archivoSalida << usuarioGuardado << " " << contrasenaGuardada << endl;
            } else {
                encontrado = true;
            }
        }
        archivoEntrada.close();
        archivoSalida.close();

        remove("usuariosventas.txt");
        rename("temp.txt", "usuariosventas.txt");

        if (encontrado) {
            cout << "Usuario borrado correctamente." << endl;
        } else {
            cout << "El usuario no existe." << endl;
        }
    }

void menu_descuento(MYSQL * objDatos){
	system("cls");
	int opcion;
	    cout<<"_______________________________________________________________\n";
        cout<<"|                                                             |\n";
		cout<<"|                      MENU DE VENTA                          |\n";
		cout<<"|_____________________________________________________________|\n";
		cout<<"|   1) Venta Super                                            | |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   2) Venta Regular                                          |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   3) Venta Diesel                                           |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   4) Regresar al Menu de Ventas                             |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   5) Regresar al Menu Principal                             |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   6) Salir del Sistema                                      |\n";
		cout<<"|-------------------------------------------------------------|\n";		
        cout<<"    Elije una opcion: ";
        cin>>opcion;
switch(opcion){
	case 1:
	Updatecontenedorventassuper(objDatos);
	break;
	case 2:
	Updatecontenedorventasregular(objDatos);
	break;
	case 3:
	Updatecontenedorventasdiesel(objDatos);
	break;
	case 4:
	menu_area_ventas(objDatos);
	case 5:
	menu_auxiliar_admin(objDatos);
	break;
	case 6:
	cout<<"\n----ADIOS----\n";
	exit(0);
	default:
	cout<<"Elijio una opcion incorrecta"<<endl;
	break;
}
}

//-------------------------AREA DE ABASTECIMIENTO-------------------------

void Ingresa(MYSQL* objDatos){
	 system("cls"); // solo funciona en windows
	 	string tipo_gasolina;
	 	string fecha_ingreso;
	 	
	 	cout<<"ingrese el tipo de Gasolina:\n";
	 	cin.ignore();
	 	getline(cin, tipo_gasolina);
	 /*	cout<<"\nFormato: YY-MM-DD"<<endl;
	 	cout<<"Ejempo: 2024-12-01"<<endl;*/
	 	cout<<"ingrese la fecha:\n";
	 	getline(cin, fecha_ingreso);
	
	
		const char* query;
			string sql;

			query=sql.c_str();
			sql="insert into tipo_gasolina(tipo_gasolina, fecha_ingreso) values('"+tipo_gasolina+"', '"+fecha_ingreso+"');"; 
			query=sql.c_str();
			mysql_query(objDatos, query);
		
		cout<<"\nDatos Ingresados Exitosamente"<<endl;
		system("pause");
}

void Consultar(MYSQL* objDatos){
		system("cls");//solo funciona en windows
		MYSQL_RES *res;
		MYSQL_ROW row;
	
			if (mysql_query(objDatos, "SELECT * FROM tipo_gasolina")){
				cout<<"Error al ejecutar la consulta: " <<mysql_error(objDatos) <<endl;
				
			}
			
			res =mysql_store_result(objDatos);
			
				cout<<"\t\t\tConsultando Datos"<<endl;
				cout<< "-----------------------------------------------------------------"<<endl;
				cout<< left << setw(20) << setfill(' ')<<"Id: ";
				cout<< left << setw(20) << setfill(' ')<<"Tipo de gasolina: ";
				cout<< left << setw(20) << setfill(' ')<<"Fecha de ingreso: "<<endl;
				cout<< "-----------------------------------------------------------------"<<endl;
				while((row = mysql_fetch_row(res))){
		
			cout<< left<< setw(20)<< setfill(' ')<<row[0];	
			cout<< left<< setw(20)<< setfill(' ')<<row[1];
			cout<< left<< setw(20)<< setfill(' ')<<row[2]<<endl;   
			cout<<"-----------------------------------------------------------------";
			cout<<endl;
				}
				mysql_free_result(res);
	
		system("pause");
}

void Update(MYSQL* objDatos) {
	 // solo funciona en windows
    string id_editar;
    string tipo_gasolina; 
    string fecha_ingreso;

    cout << "Ingrese el ID a editar:\n";
    cin >> id_editar;
    cin.ignore();
    cout << "Ingrese el nuevo nombre de Gasolina:\n";
    cin >> tipo_gasolina;
    /*cout<<"\nFormato: YY-MM-DD"<<endl;
	cout<<"Ejempo: 2024-12-01"<<endl;*/
    cout << "Ingrese La Nueva Fecha: \n";
    cin >> fecha_ingreso;

string sql = "UPDATE tipo_gasolina SET tipo_gasolina = '" + tipo_gasolina + "', fecha_ingreso = '" + fecha_ingreso + "' WHERE idtipo_gasolina = '" + id_editar + "';";

        const char* query = sql.c_str();
        if (mysql_query(objDatos, query) == 0) {
            cout << "Registro actualizado exitosamente.\n";
        } else {
            cout << "Error al actualizar el registro: " << mysql_error(objDatos) << endl;
        }

system("pause");


}

void Borrar(MYSQL* objDatos) {
		string id_borrar;
	 	
	 	cout<<"ingrese el ID a borrar:\n";
	 	cin>>id_borrar;

		const char* query;
			string sql;

			query=sql.c_str();
			sql="delete from  tipo_gasolina where idtipo_gasolina = '"+id_borrar+"';"; 
			query=sql.c_str();
			mysql_query(objDatos, query);
}
/*	 system("cls"); // solo funciona en windows
    string id_borrar;
    
    cout << "Ingrese el ID a borrar:\n";
    cin >> id_borrar;

    // Verificar si el ID existe antes de intentar borrar el registro
    string check_query = "SELECT COUNT(*) FROM tipo_gasolina WHERE id = '" + id_borrar + "';";
    const char* check_query_cstr = check_query.c_str();

    if (mysql_query(objDatos, check_query_cstr)) {
        cout << "Error al verificar el ID: " << mysql_error(objDatos) << endl;
        system("pause");
        return;
    }

    MYSQL_RES *result = mysql_store_result(objDatos);
    MYSQL_ROW row = mysql_fetch_row(result);
    int count = atoi(row[0]);
    mysql_free_result(result);

    if (count == 0) {
        cout << "Lo siento, no existe el ID que ingresaste." << endl;
        system("pause");
        return;
    }

    // Si el ID existe, proceder con la eliminaciÛn
    string delete_query = "DELETE FROM tipo_gasolina WHERE id = '" + id_borrar + "';";
    const char* delete_query_cstr = delete_query.c_str();

    if (mysql_query(objDatos, delete_query_cstr)) {
        cout << "Error al borrar el registro: " << mysql_error(objDatos) << endl;
    } else {
        cout << "Datos borrados exitosamente." << endl;
    }

    system("pause");
}*/

void Datomenu(MYSQL* objDatos){
	do{
		int opc;
		system("cls");
			cout<<"*****************************************\n";
			cout<<"|  1) Ingresar Datos                    |\n"; 
			cout<<"-----------------------------------------\n";         
			cout<<"|  2) Consultar Datos                   |\n";
			cout<<"-----------------------------------------\n";
			cout<<"|  3) Actualizar Datos                  |\n";
			cout<<"-----------------------------------------\n";
			cout<<"|  4) Borrar Datos                      |\n";
			cout<<"-----------------------------------------\n";
			cout<<"|  5) Salir                             |\n";
			cout<<"-----------------------------------------\n";
			cout<<"Ingresa la opcion a Realizar: ";
			cin>>opc;
	
		switch(opc){
			case 1:
				system("cls");
				Ingresa(objDatos);
				break;
			case 2:
				system("cls");
				Consultar(objDatos);
				break;
			case 3:
				system("cls");
				Update(objDatos);
				break;
			case 4:
				system("cls");
				Borrar(objDatos);
				break;
			case 5:
				return;
		}
	}while(true);
}

//void de contedor de unidad de medida
void Ingresacontenedor(MYSQL* objDatos){
	 system("cls"); // solo funciona en windows
	 	string cantidad_super;
	 	string cantidad_regular;
	 	string cantidad_disel;
	 	string fecha_ingreso;
	 	
	 	cin.ignore();
	 	cout<<"\ningrese Cantidad de contenedor de super:\n";
	 	getline(cin, cantidad_super);
	 	cout<<"ingrese Cantidad de contenedor de regulado:\n";
	 	getline(cin, cantidad_regular);
	 	cout<<"ingrese Cantidad de contenedor de disel:\n";
	 	getline(cin, cantidad_disel);
	 	cout<<"\nFormato: YY-MM-DD"<<endl;
	 	cout<<"Ejempo: 2024-12-01"<<endl;
	 	cout<<"ingrese la fecha:\n";
	 	getline(cin, fecha_ingreso);
	 	
		const char* query;
			string sql;

			query=sql.c_str();
			sql="insert into contenedor_unidad(contenedor_super, contenedor_regular, contenedor_disel, fecha_ingreso) values('"+cantidad_super+"', '"+cantidad_regular+"', '"+cantidad_disel+"', '"+fecha_ingreso+"');"; 
			query=sql.c_str();
			mysql_query(objDatos, query);
			
		cout<<"\nDatos Ingresados Exitosamente"<<endl;
		system("pause");
}

void Consultarcontenedor(MYSQL* objDatos){
system("cls");//solo funciona en windows
		MYSQL_RES *res;
		MYSQL_ROW row;
	
			if (mysql_query(objDatos, "SELECT * FROM db_gasolinera.contenedor_unidad")){
				cout<<"Error al ejecutar la consulta: " <<mysql_error(objDatos) <<endl;
			
			}
			res =mysql_store_result(objDatos);
			
				cout<<"\t\t\t   Consultando Datos"<<endl;
				cout<<"\t\tLa cantidad esta reflejada en galones"<<endl;
					cout<< "---------------------------------------------------------------------------------------"<<endl;
				cout<< left << setw(20) << setfill(' ')<<"Id: ";
				cout<< left << setw(20) << setfill(' ')<<"Unidad M. Super: ";
				cout<< left << setw(20) << setfill(' ')<<"Unidad M. Regular: ";
				cout<< left << setw(20) << setfill(' ')<<"Unidad M. Disel: ";
				cout<< left << setw(20) << setfill(' ')<<"Fecha de ingreso: "<<endl;
					cout<<"---------------------------------------------------------------------------------------"<<endl;
						
				while((row = mysql_fetch_row(res))){
				
					cout<< left<< setw(20)<< setfill(' ')<<row[0];	
					cout<< left<< setw(20)<< setfill(' ')<<row[1];
					cout<< left<< setw(20)<< setfill(' ')<<row[2];
					cout<< left<< setw(20)<< setfill(' ')<<row[3];
					cout<< left<< setw(20)<< setfill(' ')<<row[4]<<endl;
					cout<<"---------------------------------------------------------------------------------------";
					cout<<endl;
				}
				mysql_free_result(res);
		
	system("pause");
}

void Updatecontenedor(MYSQL* objDatos) {
	 system("cls"); // solo funciona en windows
    string id_editar;
    string cantidad_super; 
    string cantidad_regular;
    string cantidad_disel;
    string fecha_ingreso;

    cout << "Ingrese el ID a editar:\n";
    cin >> id_editar;
    cin.ignore();
    cout << "Ingrese el nueva Cantidad super:\n";
    getline(cin, cantidad_super);
    cout << "Ingrese el nueva cantidad regular:\n";
    getline(cin, cantidad_regular);
    cout << "Ingrese el nueva cantidad disel:\n";
    getline(cin, cantidad_disel);
   /* cout<<"\nFormato: YY-MM-DD"<<endl;
	cout<<"Ejempo: 2024-12-01"<<endl;*/
    cout << "Ingrese La Nueva Fecha: \n";
    getline(cin, fecha_ingreso);

string sql = "UPDATE contenedor_unidad SET contenedor_super = '" + cantidad_super + "', contenedor_regular = '" + cantidad_regular + "', contenedor_disel = '" + cantidad_disel + "', fecha_ingreso = '" + fecha_ingreso + "' WHERE idcontenedor_unidad = '" + id_editar + "';";

        const char* query = sql.c_str();
        if (mysql_query(objDatos, query) == 0) {
            cout << "\nRegistro actualizado exitosamente.\n";
        } else {
            cout << "Error al actualizar el registro: " << mysql_error(objDatos) << endl;
        }

system("pause");

}

void Borrarcontenedor(MYSQL* objDatos) {
	 system("cls"); // solo funciona en windows
    string id_borrar;
    
    cout << "Ingrese el ID a borrar:\n";
    cin >> id_borrar;

    // Verificar si el ID existe antes de intentar borrar el registro
    string check_query = "SELECT COUNT(*) FROM contenedor_unidad WHERE idcontenedor_unidad = '" + id_borrar + "';";
    const char* check_query_cstr = check_query.c_str();

    if (mysql_query(objDatos, check_query_cstr)) {
        cout << "Error al verificar el ID: " << mysql_error(objDatos) << endl;
        system("pause");
        return;
    }

    MYSQL_RES *result = mysql_store_result(objDatos);
    MYSQL_ROW row = mysql_fetch_row(result);
    int count = atoi(row[0]);
    mysql_free_result(result);

    if (count == 0) {
        cout << "Lo siento, no existe el ID que ingresaste." << endl;
        system("pause");
        return;
    }

    // Si el ID existe, proceder con la eliminaciÛn
    string delete_query = "DELETE FROM contenedor_unidad WHERE idcontenedor_unidad = '" + id_borrar + "';";
    const char* delete_query_cstr = delete_query.c_str();

    if (mysql_query(objDatos, delete_query_cstr)) {
        cout << "Error al borrar el registro: " << mysql_error(objDatos) << endl;
    } else {
        cout << "Datos borrados exitosamente." << endl;
    }

    system("pause");
}

void Contenedor(MYSQL* objDatos){
	do{
		int opc;
		system("cls");
		cout<<"*****************************************\n";
		cout<<"|  1) Ingresar Datos                    |\n";
		cout<<"-----------------------------------------\n";
		cout<<"|  2) Existencia de combustible         |\n";
		cout<<"-----------------------------------------\n";
		cout<<"|  3) Actualizar Datos                  |\n";
		cout<<"-----------------------------------------\n";
		cout<<"|  4) Borrar Datos                      |\n";
		cout<<"-----------------------------------------\n";
		cout<<"|  5) Salir                             |\n";
		cout<<"-----------------------------------------\n";
		cout<<"Ingresa la opcion a Realizar: ";
		cin>>opc;
		switch(opc){
			case 1:
				system("cls");
				Ingresacontenedor(objDatos);
				break;
			case 2:
				system("cls");
				Consultarcontenedor(objDatos);
				break;
			case 3:
				system("cls");
				Updatecontenedor(objDatos);
				break;
			case 4:
				system("cls");
				Borrarcontenedor(objDatos);
				break;
			case 5:
				return;
		}
	}while(true);
}

// menu de area de abastecimiento
void menu_area_abastecimiento(MYSQL* objDatos){ 
	int opcion;
	do{
		system("cls");
		cout<<"_______________________________________________________________\n";
		cout<<"|                                                             |\n";
		cout<<"|                    MENU ABASTECIMIENTO                      |\n";
		cout<<"|_____________________________________________________________|\n";
		cout<<"|   1) Tipo de Combustible                                    |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   2) Contenedores, Unidades de Medida                       |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   3) ID Cliente                                             |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   4) ID Proveedores                                         |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   5) Pedidos y ventas                                       |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   6) Dato de Ingreso de Combustible                         |\n";    
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   7) Regresar al Menu Principal                             |\n";  
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   8) Salir del Sistema                                      |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"Ingrese la opcion a realizar ";
		cin>>opcion;
		switch(opcion){
			case 1:
				Datomenu(objDatos);
				break;
			case 2:
				Contenedor(objDatos);
				break;
			case 3:
				consultar_datos_clientes(objDatos);
				break;
			case 4:
				consultar_datos_proveedores (objDatos);
				break;
			case 5:
				consultarDatosPedidoVentas(objDatos);
				break;
			case 6:
				Menu_Contenedor2(objDatos);
				break;
			case 7:	
			    menu_auxiliar_admin(objDatos);
			break;
			case 8:
				cout<<"\n ----ADIOS---- \n";
				exit(0);
		}
	}while(true);
}

// verificar si un usuario ya existe en el area de abastecimiento
bool usuario_existe_abas(string usuario) {
        ifstream archivo("usuariosabas.txt");
        string usuarioGuardado, contrasenaGuardada;
        while (archivo >> usuarioGuardado >> contrasenaGuardada) {
            if (usuario == usuarioGuardado) {
                archivo.close();
                return true;
            }
        }
        archivo.close();
        return false;
    }

// creador de usuario y contrase√±a de area de abastecimiento
void crear_usuario_abas(MYSQL *objDatos) {
	 system("cls"); // solo funciona en windows
        string usuario, contrasena;
        cout << "Ingrese el nombre de usuario: ";
        cin >> usuario;

        if (usuario_existe_abas(usuario)) {
            cout << "El usuario ya existe." << endl;
            return;
        }

        cout << "Ingrese la contrase√±a: ";
        cin >> contrasena;

        ofstream archivo("usuariosabas.txt", ios::app);
        archivo << usuario << " " << contrasena << endl;
        archivo.close();

        cout << "Usuario y password creado exitosamente." << endl;
    }

    // Iniciar sesion del area de abastecimiento
void iniciar_sesion_abas(MYSQL *objDatos) {
    string usuario, contrasena;
    system("cls"); // solo funciona en windows
    cout<<"----VERIFICACION DE INGRESO----"<<endl;
    cout << "Ingrese el nombre de usuario: ";
    cin >> usuario;
    cout << "Ingrese la contraseÒa: ";
    cin >> contrasena;

    ifstream archivo("usuariosabas.txt");
    string usuarioGuardado, contrasenaGuardada;
    bool encontrado = false;
    while(archivo >> usuarioGuardado >> contrasenaGuardada) {
        if (usuario == usuarioGuardado && contrasena == contrasenaGuardada) {
            encontrado = true;
            cout << "\n°Bienvenido " << usuario << "!" << endl;
            break; // Salir del bucle una vez que se haya encontrado una coincidencia
        }
    }
    archivo.close();

    if (!encontrado) {
        cout << "\nNombre de usuario o contraseÒa incorrectos." << endl;
        system("pause");
        system("cls");
        menu_auxiliar_admin(objDatos);
    }
}

// Consultador de usuario del area de abastecimiento
void consultar_usuarios_area_abas(MYSQL *objDatos){
	 system("cls"); // solo funciona en windows
        ifstream archivo("usuariosabas.txt");
        string usuario, contrasena;
        cout << "Usuarios registrados:" << endl;
        while (archivo >> usuario >> contrasena) {
            cout << "Usuario: " << usuario << ", Contrase√±a: " << contrasena << endl;
        }
        archivo.close();
    }
    
// funcion para borrar usuarios para el area de abastecimiento
 void borrar_usuario_abas(MYSQL *objDatos) {
 	 system("cls"); // solo funciona en windows
        string usuario;
        cout << "Ingrese el nombre de usuario a borrar: ";
        cin >> usuario;

        ifstream archivoEntrada("usuariosabas.txt");
        ofstream archivoSalida("temp.txt");

        string usuarioGuardado, contrasenaGuardada;
        bool encontrado = false;
        while (archivoEntrada >> usuarioGuardado >> contrasenaGuardada) {
            if (usuario != usuarioGuardado) {
                archivoSalida << usuarioGuardado << " " << contrasenaGuardada << endl;
            } else {
                encontrado = true;
            }
        }
        archivoEntrada.close();
        archivoSalida.close();

        remove("usuariosabas.txt");
        rename("temp.txt", "usuariosabas.txt");

        if (encontrado) {
            cout << "Usuario borrado correctamente." << endl;
        } else {
            cout << "El usuario no existe." << endl;
        }
    }
	
void Ingresacontenedor2(MYSQL* objDatos) {
    system("cls"); // solo funciona en windows
    
    string cantidad_super;
    string cantidad_regular;
    string cantidad_disel;
    string fecha_ingreso;
    
    cin.ignore();
    cout << "\nIngrese Cantidad de contenedor de super:\n";
    getline(cin, cantidad_super);
    cout << "Ingrese Cantidad de contenedor de regulado:\n";
    getline(cin, cantidad_regular);
    cout << "Ingrese Cantidad de contenedor de disel:\n";
    getline(cin, cantidad_disel);
    cout << "\nFormato: YY-MM-DD" << endl;
    cout << "Ejemplo: 2024-12-01" << endl;
    cout << "Ingrese la fecha:\n";
    getline(cin, fecha_ingreso);
    
    // Construir la consulta SQL correctamente
    string sql = "INSERT INTO contenedor_unidad2 (contenedor_super, contenedor_regular, contenedor_disel, fecha_ingreso) "
                 "VALUES ('" + cantidad_super + "', '" + cantidad_regular + "', '" + cantidad_disel + "', '" + fecha_ingreso + "');";

    // Mostrar la consulta SQL para depuraciÛn
    cout << "Consulta SQL: " << sql << endl;
    
    const char* query = sql.c_str();
    
    if (mysql_query(objDatos, query) == 0) {
        cout << "\nDatos ingresados exitosamente.\n";
    } else {
        cout << "Error al ingresar los datos: " << mysql_error(objDatos) << endl;
    }

    system("pause");
}

void Consultarcontenedor2(MYSQL* objDatos){
system("cls");//solo funciona en windows
		MYSQL_RES *res;
		MYSQL_ROW row;
	
			if (mysql_query(objDatos, "SELECT * FROM db_gasolinera.contenedor_unidad2")){
				cout<<"Error al ejecutar la consulta: " <<mysql_error(objDatos) <<endl;
			
			}
			res =mysql_store_result(objDatos);
			
				cout<<"\t\t\t   Consultando Datos"<<endl;
				cout<<"\t\tLa cantidad esta reflejada en galones"<<endl;
					cout<< "---------------------------------------------------------------------------------------"<<endl;
				cout<< left << setw(20) << setfill(' ')<<"Id: ";
				cout<< left << setw(20) << setfill(' ')<<"Unidad M. Super: ";
				cout<< left << setw(20) << setfill(' ')<<"Unidad M. Regular: ";
				cout<< left << setw(20) << setfill(' ')<<"Unidad M. Disel: ";
				cout<< left << setw(20) << setfill(' ')<<"Fecha de ingreso: "<<endl;
					cout<<"---------------------------------------------------------------------------------------"<<endl;
						
				while((row = mysql_fetch_row(res))){
				
					cout<< left<< setw(20)<< setfill(' ')<<row[0];	
					cout<< left<< setw(20)<< setfill(' ')<<row[1];
					cout<< left<< setw(20)<< setfill(' ')<<row[2];
					cout<< left<< setw(20)<< setfill(' ')<<row[3];
					cout<< left<< setw(20)<< setfill(' ')<<row[4]<<endl;
					cout<<"---------------------------------------------------------------------------------------";
					cout<<endl;
				}
				mysql_free_result(res);
		
	system("pause");
}

void Updatecontenedor2(MYSQL* objDatos) {
	 system("cls"); // solo funciona en windows
    string id_editar;
    string cantidad_super; 
    string cantidad_regular;
    string cantidad_disel;
    string fecha_ingreso;

    cout << "Ingrese el ID a editar:\n";
    cin >> id_editar;
    cin.ignore();
    cout << "Ingrese el nueva Cantidad super:\n";
    getline(cin, cantidad_super);
    cout << "Ingrese el nueva cantidad regular:\n";
    getline(cin, cantidad_regular);
    cout << "Ingrese el nueva cantidad disel:\n";
    getline(cin, cantidad_disel);
   /* cout<<"\nFormato: YY-MM-DD"<<endl;
	cout<<"Ejempo: 2024-12-01"<<endl;*/
    cout << "Ingrese La Nueva Fecha: \n";
    getline(cin, fecha_ingreso);

string sql = "UPDATE contenedor_unidad2 SET contenedor_super = '" + cantidad_super + "', contenedor_regular = '" + cantidad_regular + "', contenedor_disel = '" + cantidad_disel + "', fecha_ingreso = '" + fecha_ingreso + "' WHERE id = '" + id_editar + "';";

        const char* query = sql.c_str();
        if (mysql_query(objDatos, query) == 0) {
            cout << "\nRegistro actualizado exitosamente.\n";
        } else {
            cout << "Error al actualizar el registro: " << mysql_error(objDatos) << endl;
        }

system("pause");

}

void Borrarcontenedor2(MYSQL* objDatos) {
	 system("cls"); // solo funciona en windows
    string id_borrar;
    
    cout << "Ingrese el ID a borrar:\n";
    cin >> id_borrar;

    // Verificar si el ID existe antes de intentar borrar el registro
    string check_query = "SELECT COUNT(*) FROM contenedor_unidad2 WHERE id = '" + id_borrar + "';";
    const char* check_query_cstr = check_query.c_str();

    if (mysql_query(objDatos, check_query_cstr)) {
        cout << "Error al verificar el ID: " << mysql_error(objDatos) << endl;
        system("pause");
        return;
    }

    MYSQL_RES *result = mysql_store_result(objDatos);
    MYSQL_ROW row = mysql_fetch_row(result);
    int count = atoi(row[0]);
    mysql_free_result(result);

    if (count == 0) {
        cout << "Lo siento, no existe el ID que ingresaste." << endl;
        system("pause");
        return;
    }

    // Si el ID existe, proceder con la eliminaciÛn
    string delete_query = "DELETE FROM contenedor_unidad2 WHERE id = '" + id_borrar + "';";
    const char* delete_query_cstr = delete_query.c_str();

    if (mysql_query(objDatos, delete_query_cstr)) {
        cout << "Error al borrar el registro: " << mysql_error(objDatos) << endl;
    } else {
        cout << "Datos borrados exitosamente." << endl;
    }

    system("pause");
}

void Menu_Contenedor2(MYSQL * objDatos){
do{
int opcion;
system("cls");
        cout<<"_______________________________________________________________\n";
        cout<<"|                                                             |\n";
		cout<<"|           MENU DE DATO DE INGRESO DE COMBUSTIBLE            |\n";
		cout<<"|_____________________________________________________________|\n";
		cout<<"|   1) Ingresar Contenedor                                    |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   2) Consultar Contendor                                    |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   3) Borrar Contenedor                                      |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   4) Actualizar Contenedor                                  |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   5) Regresar al Menu Principal                             |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   6) Regresar al Menu de Abastecimiento                     |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   7) Salir del Sistema                                      |\n";
		cout<<"|-------------------------------------------------------------|\n";		
        cout<<"    Elije una opcion: ";
		cin>>opcion;
switch(opcion){
	case 1:
	Ingresacontenedor2(objDatos);	
	break;
	case 2:
	Consultarcontenedor2(objDatos);
	break;
	case 3:
	Borrarcontenedor2(objDatos);
	break;
	case 4:
	Updatecontenedor2(objDatos);	
	break;
	case 5:
	menu_auxiliar_admin(objDatos);
	break;
	case 6:
	menu_area_abastecimiento(objDatos);	
	break;
	case 7:
	cout<<"\n----ADIOS----\n";
	exit(0);
}	
	
}while(true);
}


		
};

//------------------------FUNCION PRINCIPAL------------------------
 
int main() {
MYSQL *objDatos;
data base;
conexion conn;
setlocale(LC_ALL, "");
char continuar = 's';

if(!(objDatos = mysql_init(0))) {
      // Imposible crear el objeto objDatos
      cout << "ERROR: imposible crear el objeto objDatos." << endl;          
      exit(1);
  }
  
conn.conexion_db(objDatos);
do {
	 system("cls"); // solo funciona en windows
setlocale(LC_ALL, "");
        int opcion;
        cout<<"_______________________________________________________________\n";
        cout<<"|                                                             |\n";
		cout<<"|                    MENU PRINCIPAL                           |\n";
		cout<<"|_____________________________________________________________|\n";
		cout<<"|   1) Administrador                                          |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   2) Consultas                                              |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   3) Ventas                                                 |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   4) Mantenimiento                                          |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   5) Pedido                                                 |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   6) Abastecimiento                                         |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"|   7) Salir del Sistema                                      |\n";
		cout<<"|-------------------------------------------------------------|\n";
		cout<<"Elije una Opcion: ";
        cin>> opcion;

        switch (opcion) {
        case 1:
            base.verificadoradministrador(objDatos);
            cout<<""<<endl;
            base.menuadministrador(objDatos);
            break;
        //----------------------
			case 2:
            base.iniciar_sesion_consulta(objDatos);
            cout << "" << endl;
            base.menu_area_consultas(objDatos);
            break;
        //----------------------
        case 3:
        	base.iniciar_sesion_ventas(objDatos);
        	cout << "" << endl;
            base.menu_area_ventas(objDatos);
            break;
        //----------------------
        case 4:
        	base.iniciar_sesion_mantenimiento(objDatos);
            cout << "" << endl;
            base.menu_area_mantenimineto(objDatos);
            break;
        //----------------------
        case 5:
          base.iniciar_sesion_pedido(objDatos);
          cout << "" << endl;
          base.menu_area_pedido(objDatos); 
          break;
        //----------------------
        case 6:
          base.iniciar_sesion_abas(objDatos);
          cout << "" << endl;
          base.menu_area_abastecimiento(objDatos);
	      break;	
        //----------------------
        case 7:
            cout << "\n Gracias por utilizar nuestro sistema" << endl;
            cout << "Hasta Luego" << endl;
            return 0;
        default:
            cout << "\n Opcion Incorrecta" << endl;
            break;
        }
        cout << "\n Deseas Volver al Menu Principal (S/N)" << endl;
        cin >> continuar;
        if (continuar == 's' || continuar == 'S') {
            cout << "Volviendo al Menu Principal" << endl;
            system("pause");
        } else {
            cout << "Gracias por utilizar nuestro sistema" << endl;
            return 0;
        }
        system("cls");
    } while (true);
	return 0;
}
