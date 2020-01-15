//RAICES DE UN POLINOMIO GRADO 2

#include<iostream>
#include<math.h> //para ocupar las funciones de operaciones matematicas
#include<iomanip> //para ocupar las funciones de trabajar solo con una determinada cantidad de decimales (setprecision)

using namespace std;

struct PolynomialData{ //registro de los datos de un polinomio grado 2. 
	
	int a, b, c;   //Variables a, b y c que ingresa el usuairo
	
};

//prototipo de las funciones utilizadas
int Calculations(PolynomialData Calculation, float& X1, float& X2); 

int main(){
	//declaracion de variables
	PolynomialData data;
	int n = 0;
	float X1 = 0, X2 = 0;
	
	//se piden los datos al usuario. Las variables a, b y c de un polinomio
	cout << "FORMULA GENERAL\n" << endl;
	
	cout << "Ingrese el valor de a: "; cin >> data.a;
	cout << "Ingrese el valor de b: "; cin >> data.b;
	cout << "Ingrese el valor de c: "; cin >> data.c;
	
	n = Calculations(data,X1,X2); //se hace una llamada a la funcion que realiza los calculos
	
	
	//condiciones segun lo que retorne la funcion y mostrar los valores finales de X
	if(n == 1){ //si ha retornado 1 es porque el polinomio no tiene solucion ya sea numeros negativos en la raiz o denominador 0
		
		cout << "\nEL POLINOMIO NO TIENE SOLUCION!!" << endl;
		
	}
	else if(n == 0){ //si es posible sacar una raiz retorna 0, que habran dos soluciones de X+ y X-
		
		cout << "\nHAY DOS RAICES EN EL POLINOMIO: \n" << endl;
		cout << "Los valores de X1 y X2 son: " << endl;
		cout << "X1 = : " << fixed << setprecision(2) << X1 << endl; //setprecision para trabajar solo con 2 decimales
		cout << "X2 = : " << fixed << setprecision(2) << X2 << endl;
		
	}
	else if(n == -1){ //si se retorna -1 es porque en la raiz dion 0, entonces solo hay una solucion que es la division
		
		cout << "\nHAY UNA RAIZ EN EL POLINOMIO: \n" << endl;
		cout << "El valor de X es: " << endl;
		cout << "X = : " << fixed << setprecision(2) << X1 << endl;
		
	}
	
	return 0;
}

//Funcion que hace los procesos de la formula general
int Calculations(PolynomialData Calculation, float& X1, float& X2){
	//declaracion de variables
	int R = 0, InsideRoot = 0, error = 0; 
	float SquareRoot = 0;
	
	//se calcula el cuadrado de b dentro de la razi
	R = pow(Calculation.b,2);
	
	//variable InsideRoot resibe lo que da en el proceso dentro de la raiz. (b*b) - 4ac
	InsideRoot = R - 4 * Calculation.a  * Calculation.c;
	
	//si el resultado dentro de la raiz es negativo o si el usuario ingresa 0 en la variable a. Se retora el 1 que no hay solucion
	if(InsideRoot < 0 || Calculation.a == 0){
		
		error = 1;
		
	}
	else if(InsideRoot > 0){ //si el resultado es positivo se hace el siguiente proceso
		
		SquareRoot = sqrt(InsideRoot); //lo que dio dentro de la raiz se le saca la raiz cuadrada
		
		//se sacan los dos valores de X+ y X-
		X1 = - Calculation.b + SquareRoot;  //-b + el resultado de la raiz cuadrada
		X2 = - Calculation.b - SquareRoot; //-b - el resultado de la raiz cuadrada
		
		//los reusultados anteriores de X1 y X2 se dividen entre 2a para sacar el resultado final
		X1 /= 2 * Calculation.a; 
		X2 /= 2 * Calculation.a;
		
		error = 0; //retornamos el 0 de que hubo dos soluciones
		
	}
	else if(InsideRoot == 0){ //si dontro de la raiz da 0, la raiz sera 0 tambien
		
		//solo quedaria dividir -b/2a
		X1 = - Calculation.b; 
		X1 /= 2 * Calculation.a;
		
		error = -1; //retornamos -1 que hubo una sola solucion
		
	}
	
	return error;	//retornamos el valor segun lo que haya sucedido
}