//VERIFICAR SI UNA CADENA ES SOLO CARACTERES, NUMEROS O ALFANUMERICA

#include<iostream> //entradas y salidas
#include<string> //para usar las cadenas de string

using namespace std;
bool VerifyNumber(string&);

//prototipos de las funciones
int VerifyString(string&);

int main(){
	//declaracion de variables
	string STRING;
	int A = 0;
	
	//pidiendo al usuario que digite la cadena
	cout<<"Ingrese una frase: ";cin>>STRING;
	cout<<"\n"<<endl;
	
	//se llama a la funcion y A recibe lo que esta retorna	
	A = VerifyString(STRING);
	
	//verificando lo que ha retornado la funcion
	if(A == 1){
		cout<<"Es una cadena numerica"<<endl;
	}
	else if(A==0){
		cout<<"Es una cadena alfanumerica"<<endl;
	}
	else{
		cout<<"Es una cadena de letras"<<endl;
	}
	
	return 0;
}

//funcion que verifica si la cadena es solo caracteres, numeros o ambos
int VerifyString(string& STRING){
	int n = 0, m = 0, p = 0;
	
	
	for(int i=0;i<STRING.length();i++){
		
		if(STRING[i] >='0' && STRING[i] <= '9'){ //si el caracter esta entre el rango 0 y 9 es un numero
		
			n++;     //si n aumenta es porque se encontro un numero
			
		}
		else if(STRING[i] >= 'a' && STRING[i] <= 'z'){ //si el caracter esta entre a y z es una letra
			if(n==0){  //si n sigue en 0 es porque no hay un numero entonces m seguira aumentando
				m++;
			}
			else{  //si ya se encontro un numero, de una ves retorna 0 para decir que ya es una cadena alfanumerica
				return 0;
			}
		}
		
	}
	if(n==0){
		return -1; //si n se mantiene en 0 es porque la cadena solo tenia letras porque nunca aumento n
	}
	else if(m==0){
		return 1; //si m se mantiene en 0 es porque solo habia numeros porque nunca aumento m
	}
	
}