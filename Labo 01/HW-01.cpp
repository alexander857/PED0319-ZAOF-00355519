//SUMA DE LOS NUMEROS PRIMOS QUE HAY ENTRE 1 Y 100

#include<iostream> //para las entradas y salidas

using namespace std;

//prototipo
int sum(); //suma todos los primos entre 1 y 100 y devuelve ese valor

int main(){
	int sum1 = 0;
	
	//la variable sum recibe lo que retorna la funcion sum
	sum1 = sum(); 
	
	//se imprime en pantalla la suma de los primos entre 1 y 100
	cout<<"La suma de los primos entre 1 y 100 es: "<<sum1<<endl;
	
	
	return 0;
}

//funcion que devuelve la suma de los primos entre 1 y 100
int sum(){
	//variables locales de la funcion sum
	int suma = 0, num = 0;
	bool primo;
	
	for(int i = 2;i <= 100;i++){ /*i empieza en 2 ya que el 1 no es primo y dividivo entre 2 daria diferente de 0 y el programa diria que si lo es. El 0 tampoco es primo y el programa
									lo tomaria como primo*/
		
		num = 2;
		primo = true;
		
		//ciclo que verifica si el numero en el arreglo es primo o no
		while(primo == true && num < i){
			
			if(i%num == 0){
				primo = false; //si el numero no es primo
			}
			else{
				num += 1; //si el numero es primo
			}
			
		}
		if(primo == true){
			suma += i;     //la variable suma va acumulando todos los numeros primos
		}
	}
	return suma; //se devuelve la suma de los primos
}