//NOMBRE COMPLETO DE N CLIENTES DE UN NEGOCIO

#include<iostream>
#include<string.h>

using namespace std;


int main(){
	//declarasion de variables
	int size = 0;
	string customers;
	
	cout << "Ingrese el numero de clientes: "; cin >> size; //se pide los clientes a ingresar
	cout << endl;
	
	
	
	int* array;
	
	array = new int[size]; //se reserva el espacio en memoria para el numero de clientes a ingresar
	
	//se piden los nombres de los empleados tantos como espacio se haya reservado
	for(int i = 0; i < size; i++){
		
		cout << "Cliente " << i + 1 << ": ";
		getline(cin, customers);
		cin.ignore();
				
	}
	
	
	return 0;
}