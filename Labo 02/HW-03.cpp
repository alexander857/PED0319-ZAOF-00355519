//SUELDO DEVENGADO DE UNA PERSONA EN LOS AÑOS QUE LLEVA LABORANDO

#include<iostream>
#include<string>

using namespace std;

struct VendorData{
	
	int DUI;
	string name;
	int YearHired;
	int salary;
	
};

void Data();

//int AccruedSalary(VendorData AcSalary);

int main(){
	//declaracion de variables
	VendorData vendor;
	int NumberVendor;
	
	//pedimos numero de vendedores que ingresara
	cout << "Numero de vendedores a ingresar: "; cin >> NumberVendor;
	cin.ignore();
	
	//pidiendo datos de los vendedores
	do{
		
		cout << "\nINGRESE DATOS DE UN VENDEDOR\n" << endl;
		
		cout << "Nombre: "; getline(cin, vendor.name);
		
		cout << "DUI: "; cin >> vendor.DUI;
		
		cout << "Salario mensual: "; cin >> vendor.salary;
		
		cout << "Anos laborados: "; cin >> vendor.YearHired;
        cin.ignore();
		
        NumberVendor--;

	}while(NumberVendor > 0);
	

	


	
	cout << vendor.name << endl;

	return 0;	
}