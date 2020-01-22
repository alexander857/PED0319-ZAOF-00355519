//Invirtiendo los digitos de un numero de forma recursiva

#include<iostream>

using namespace std;

//prototipo de la fucnion
int ReverseANumber(int num, int NumberInvested, int rest);

int main(){
	int num = 0, NumberInvested = 0;
	
	//pedimos un numero al usuario
	cout << "Ingrese un numero natural: "; cin >> num;
	
	//mostramos lo que retorna la funcion
	cout << "Numero invertido: " << ReverseANumber(num, NumberInvested, 0) << endl;
	
	return 0;
}

//funcion que invierte el numero
int ReverseANumber(int num, int NumberInvested, int rest){
	
	if(num == 0){ //caso base
		
		return NumberInvested;
		
	}
	else{
		
		rest = num % 10; //tomamos el resto del numero al dividirlo entre 10
		num /= 10;      //tomamos el cociente 
		NumberInvested = (NumberInvested * 10) + rest; //numero invertido sera numtiplicarlo * 10 y sumarle el resto 
		
		ReverseANumber(num, NumberInvested, 0); //se hace la llamada recursiva para repetir el proceso
		
	}
	
}