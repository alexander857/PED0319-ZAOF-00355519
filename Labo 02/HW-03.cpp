//SUELDO DEVENGADO DE UNA PERSONA EN LOS AÑOS QUE LLEVA LABORANDO

#include<iostream>
#include<string>

using namespace std;

struct VendorData{
	
	int DUI;
	string name;
	int YearHired;
	float salary;
	
};

void Data();

float AccruedSalary(VendorData AcSalary);

int main(){
	//declaracion de variables
	VendorData vendor;
	int NumberVendor;
    float TotalSalary = 0;
	
	//pedimos numero de vendedores que ingresara
	cout << "Numero de vendedores a ingresar: "; cin >> NumberVendor;
	cin.ignore();
	
	//pidiendo datos de los vendedores
	do{
		
		cout << "\nINGRESE DATOS DE UN VENDEDOR\n" << endl;
		
		cout << "Nombre: "; getline(cin, vendor.name);
		
		cout << "DUI: "; cin >> vendor.DUI;
		
		cout << "Salario mensual: "; cin >> vendor.salary;
		
		cout << "Año en que fue contratado: "; cin >> vendor.YearHired;
        cin.ignore();
		
        TotalSalary = AccruedSalary(vendor);

        cout << "El salario devengado en los años que lleva trabajando " << vendor.name << " es de: $" << TotalSalary << endl;

        NumberVendor--;

	}while(NumberVendor > 0);
	

	return 0;	
}

float AccruedSalary(VendorData AcSalary){
	
	float FinalSalary = 0;
    int YearsWorked = 0, MonthsWorked = 0;
	
	YearsWorked = 2020 - AcSalary.YearHired;
	
	MonthsWorked = YearsWorked * 12;
	
	FinalSalary = AcSalary.salary * MonthsWorked;
	
	return FinalSalary;
}