//NUMEROS DEL 1 AL 9 EN UNA MATRIZ

#include<iostream>

using namespace std;

int main(){
	
	int aux = 1;
	int Matriz[3][3];
	
	for(int i = 0; i < 3; i++){
		
		for(int j = 0; j < 3; j++){
			
			Matriz[i][j] = aux++;
			
		}		
	}
	
	for(int i = 0; i < 3; i++){
		
		for(int j = 0; j < 3; j++){
			
			cout << Matriz[i][j] << "\t";
			
		}
		cout << "\n";		
	}
	
	
	return 0;
}