//SUELDO DEVENGADO DE UNA PERSONA EN LOS AÑOS QUE LLEVA LABORANDO

#include<iostream>
#include<string>

using namespace std;

struct VendorData{ //registro de los datos que se le pide a cada vendedor
	
	int DUI;
	string name;
	int YearHired;
	float salary;
	
};

//prototipos de funciones
float AccruedSalary(VendorData AcSalary); //funcion que calcula el sueldo devengado

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
		
		cout << "Nombre: "; getline(cin, vendor.name); //nombre del vendedor
		
		cout << "DUI: "; cin >> vendor.DUI;      //el dui
		
		cout << "Salario mensual: "; cin >> vendor.salary;   //el salario mensual
		
		cout << "Año en que fue contratado: "; cin >> vendor.YearHired;  //el año en que fue contratado
        cin.ignore();
		
        TotalSalary = AccruedSalary(vendor); //se llama a la funcion que calcula el sueldo devengado

        //se muestra el sualdo que ha devengado en todos los años que lleva laborando
        cout << "El salario devengado en los años que lleva trabajando " << vendor.name << " es de: $" << TotalSalary << endl;

        NumberVendor--;

	}while(NumberVendor > 0);
	

	return 0;	
}

//funcion para calcular el sueldo devengado
float AccruedSalary(VendorData AcSalary){
	//declaracion de variables
	float FinalSalary = 0;
    int YearsWorked = 0, MonthsWorked = 0;
	
    //los años laborados seran el año actual menos el año en que fue contratado
	YearsWorked = 2020 - AcSalary.YearHired;
	
    //meses trabajados es los años que lleva trabajando por 12 meses
	MonthsWorked = YearsWorked * 12;
	
    //salario final es el salario mesual ingresado multiplicado por los meses totales que lleva trabajando
	FinalSalary = AcSalary.salary * MonthsWorked;
	
	return FinalSalary; //devolvemos el valor final. El sualdo devengado en los años que lleva trabajando
}