//NOTAS DE 20 PERSONAS EN UN ARREGLO

#include<iostream>

using namespace std;

int main(){
	float notas[20];
	
	for(int i = 0; i < 20; i++){
		
		cout << "Nota de persona " << i + 1 <<": "; cin >> notas[i];
		
	}
	
	for(int i = 0; i < 20; i++){
		
		cout << "Nota " << i + 1 <<":\t" << notas[i] << "\n";
		
	}
	
	return 0;
}