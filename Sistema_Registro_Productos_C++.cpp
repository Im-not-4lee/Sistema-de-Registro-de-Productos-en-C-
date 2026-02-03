// Elaborado Por: Alejandro Herrera Ballestas		

#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
using namespace std;

struct producto {
	char name[100];
	float price;
	int cantidad;
};

struct registro{
	int id;
	char cadena[20];
};

void registrar_leer() {
	producto p;
	cout << "\t====BIENVENIDO AL SISTEMA DE REGISTRO====\n";
	ofstream archivo("productos.bin", ios::app | ios::binary);
	if(!archivo)	{
		cout << "No se encontro el archivo\n";
	}	
	cin.ignore();
	cout << "Ingrese el nombre del producto: \n";
	cin.getline(p.name,100);
	cout << "Ingrese el precio del producto: \n";
	cin >> p.price;
	cout << "Ingrese el stock del producto: \n";
	cin >> p.cantidad;
	
	archivo.write(reinterpret_cast<char*>(&p), sizeof (producto));
	archivo.close();
	
	cout << "PRODUCTO EXITOSAMENTE REGISTRADO\n";
	system("pause");
	system("cls");
	
	char c;
	cout << "¿Desea ver los productos registrados?('Y' o 'N'): "; cin >> c;
	
	if ((c == 'Y') || (c == 'y'))	{
		ifstream arch("productos.bin", ios::binary);
		if (!arch)	{
			cout << "No se encontro el archivo\n";
		}
		while(arch.read(reinterpret_cast<char*>(&p), sizeof (producto)))	{
			cout << "Nombre del producto: " << p.name << endl;
			cout << "Precio del producto: " << p.price << endl;
			cout << "Stock del producto: " << p.cantidad << endl;
 		}
 		arch.close();
	}else{
		return;
	}
}

void registrobinario()	{
	registro r;
	int contador = 0;
	ifstream registro_dat("texto.dat",ios::binary);
	if (!registro_dat)	{
		cout << "Error al abrir el archivo!\n";
	}
	while(registro_dat.read(reinterpret_cast<char*>(&r), sizeof (registro))){
		contador++;
	}
	registro_dat.close();
	cout << "\nTOTAL DE REGISTROS: " << contador << endl;
}


int main()	{
	
	int op;
	cout << "PARCIAL TIPO 1 | Archivos de Texto + Binarios (Nivel Medio)" << endl;
	system("pause");
	system("cls");
	
	do{
		cout << "\t====MENU====\n";
		cout << "1. Registrar y leer productos de una tienda\n";
		cout << "2. Contar registros en un archivo binario\n";
		cout << "3. Salir\n";
		cout << "Seleccione una opcion: "; cin >> op;
		system("pause");
		system("cls");
		
		switch (op){
			case 1:
				registrar_leer();
				system("pause");
				system("cls");
				break;
			case 2:
				registrobinario();
				system("pause");
				system("cls");
				break;
			case 3:
				cout << "Saliendo del programa..." << endl;

				return 0;
				break;
			default: 
				cout << "Opcion invalida...Intentelo de nuevo..." << endl;
				
				break;
		}
	}while(op != 3);
	
	return 0;
}
