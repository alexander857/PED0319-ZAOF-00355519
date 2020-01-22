//suma recursiva de costos y precios de venta de electrodomesticos

#include<iostream>
#include<string>

using namespace std;

//registro de electrodomesticos
struct HomeAppliances{
	
	string name;
	float cost;
	float salePrice;
	
};

//prototipo de funcion que retorna la suma de costos o precio de venta
float SumCostOrSalePrice(HomeAppliances* array, int size, float suma, int aux, bool flag);

int main(){
	//declaracion de variables
	bool flag = false; //bandera
	int size = 0, i = 0, option = 0;
	
	cout << "Ingrese la cantidad de electrodomesticos: "; cin >> size;
	
	//reservando espacio de memoria para el arreglo de registros
	HomeAppliances *Array;
	
	Array = new HomeAppliances[size];
	
	//llenando arreglo
	cout << "\nIngrese los datos de cada electrodomestico: \n";
	
	for(int i = 0; i < size; i++){
		
		cin.ignore();
		cout << "\nNombre: "; 
		getline(cin, Array[i].name);
		cout << "Costo: ";
		cin >> Array[i].cost;
		cout << "Precio de venta: ";
		cin >> Array[i].salePrice;
		
	}
	
	//se elije que suma quiere ver el usuario y asi cambiara de estado al bandera
	cout << "\nQue suma desea ver?:\n";
	cout << "1-Suma de los costos\n2-Suma de los precios de venta\n";
	cout << "Opcion: "; cin >> option;
	
	if(option == 1){
		flag = true;
	}
	
	//se muestra la suma que retorna la funcion, segun la suma que se eligio ver
	cout << "\nLa suma es: " << SumCostOrSalePrice(Array, size, 0, 0, flag) << endl;
	
	return 0;
}

//funcion que calcula la suma de los costos y precios de venta 
float SumCostOrSalePrice(HomeAppliances* array, int size, float suma, int aux, bool flag){
	
	if(aux >= size){ //caso base
		return suma;
	}
	else if(flag == true && aux < size){
		
		suma += array[aux].cost;  //se almacena en suma el costo de un electrodomestico en la posicion de aux
		SumCostOrSalePrice(array, size, suma, aux + 1, flag); //llamada recursiva
		
	}
	else if(flag == false && aux < size){
		
		suma += array[aux].salePrice; //se almacena en suma el precio de venta de un electrodomestico en la posicion de aux
		SumCostOrSalePrice(array, size, suma, aux + 1, flag); //llamada recursiva
		
	}
	
}