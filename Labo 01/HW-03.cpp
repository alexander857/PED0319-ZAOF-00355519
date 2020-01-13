//MULTIPLOS DE 7 EN UN ARREGLO CON ALEATORIOS DEL 1 AL 75

#include<iostream> //para usar las entradas y salidas 
#include<time.h>  //para iniciar en el tiempo de la maquina
#include<stdlib.h> //para los numeros random

using namespace std;

//prototipo de la funcion
void FullArray(int arreglo[15]); //donde se llena el arreglo con numeros aleatorios
int MultipleOfSeven(int array[15]); //donde se buscan los multiplos de 7

int main(){
	//variables declaradas
	int array[15], sum = 0;
	
	//llamando a la funcion
	FullArray(array);
	sum = MultipleOfSeven(array);
	
	//imprimiendo el arreglo
	cout<<"Arreglo: \n"<<endl;
	for(int i=0;i<15;i++){
		cout<<array[i]<<" ";
	}
	cout<<"\n"<<endl;
	
	//suma de todos los multiplos de 7 que hay en el arreglo
	cout<<"Suma de los multiplos de 7 que estan en el arreglo: "<<sum<<endl;
	return 0;
}

//funcion donde se llena el arreglo con numeros aleatorios
void FullArray(int array[15]){
	srand(time(NULL)); //para que se generen numeros aleatorios diferentes al ejecutar el programa
	
	//llenando el arreglo con numeros aleatorios
	for(int i=0;i<15;i++){
		
		array[i] = 1 + rand()% 75;
		
	}
		
}

//funcion que busca los multiplos de 7 en el arreglo
int MultipleOfSeven(int array[15]){
	int suma = 0; //donde se acumulan todos los numeros multiplos de 7
	
	//buscando multiplos de 7 en el arreglo
	for(int i=0;i<15;i++){
		
		if(array[i]%7 == 0){
			
			suma += array[i];
			
		}
		
	}
	return suma;
}