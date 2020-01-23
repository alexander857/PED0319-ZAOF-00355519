//datos de productos en una pila

#include<iostream>
#include<string>
#include<stack>

using namespace std;

//registro de los productos
struct products{
	string name;
	float price;
	int StockQuantity;
};

int main(){
	//variables declardas
	stack<products> PRODUCTS;
	products aux;
	int option = 1;
	
	//llenando la pila
	while(option != 2){
		
		cout << "\nNombre del producto: "; getline(cin, aux.name);
		cout << "Precio del producto: "; cin >> aux.price; cin.ignore();
		cout << "Cantidad en Stock: "; cin >> aux.StockQuantity; cin.ignore();
		
		PRODUCTS.push(aux);
		
		cout << "\nQuiere ingresar otro producto?\n";
		cout << "1-Si\n2-No\n";
		cout << "Opcion: "; cin >> option; cin.ignore();
		
		if(option != 1 && option != 2){
			cout << "\nEsa opcion no esta disponible" << endl;
			break;
		}
		
	}
	
	//mostrando los productos y sacandolos de la pila
	while(!PRODUCTS.empty()){
		
		aux = PRODUCTS.top();
		
		cout << "\nNombre del producto: " << aux.name << endl;
	    cout << "Precio: " << aux.price << endl;
	    cout << "Cantidad en Stock: " << aux.StockQuantity << endl;
	    
	    PRODUCTS.pop();		
	}
	
	return 0;
}