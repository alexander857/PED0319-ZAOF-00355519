//Fibonacci con recursion

#include <iostream>
using namespace std;

int fibonacci(int n);

int main() {
    int num = 0;
    
    //pedimos un numero al usuario
    cout << "Ingrese un numero: "; cin >> num;
    
   	//mostramos el resultado
    cout << "Resultado: " << fibonacci(num) << endl;
}

int fibonacci(int num){
    if(num <= 1){
    	
        return 1;
        
    }
	else{
        int x = fibonacci(num - 2);
        int y = fibonacci(num - 1);       
          
        return x + y;
    }
}