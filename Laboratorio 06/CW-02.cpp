#include<iostream>
#include<string>
#include<cctype>
using namespace std;

struct node{
    string product;
    float price;
    node* next;
};

node* addElement(node* list, string product, int price);
string convertString(string product);
void printMenu();
int searchStock(node* list, string product);

int main(){
    node* list = NULL;
    string product = " ";
    float price = 0;
    int option = 0;
    int auxStock = 0;

    do{
        printMenu(); cin >> option; cin.ignore();

        switch(option){
            case 1:
                cout << "Ingrese los datos del producto" << endl;
                cout << "Nombre: "; cin >> product;
                cout << "Precio: "; cin >> price;
                product = convertString(product);
                list = addElement(list, product, price);
            break;
            case 2:
                cout << "\nIngrese el producto a buscar" << endl;
                cout << "Producto: "; cin >> product;
                product = convertString(product);

                auxStock = searchStock(list, product);

                (auxStock == 0) ? cout << "\nSin Stock" : cout << "\nCantidad en stock: " << auxStock;
            break;
            case 0:
                cout << "\nSaliendo..." << endl;
            break;
        }

    }while(option != 0);

    return 0;
}

void printMenu(){
    cout << "\nMENU PRINCIPAL" << endl;
    cout << "1.\tAgregar producto" << endl;
    cout << "2.\tBuscar producto" << endl;
    cout << "0.\tSalir" << endl;
}

//pasando palabra a mayusculas letra por letra
string convertString(string product){
    string aux = " ";

    for(int i = 0; i < product.length(); i++){
        aux += toupper(product[i]);
    }

    return aux;
}

node* addElement(node* list, string product, int price){
    node* newNode = new node;
    newNode -> price = price;
    newNode -> product = product;
    newNode -> next = NULL;

    if(!list){
        list = newNode;
    }
    else{
        node* aux = list;

        while(aux -> next != NULL)
            aux = aux -> next;
        
        aux -> next = newNode;
    }
    return list;
}

int searchStock(node* list, string product){
    if(!list)
        return 0;
    else{
        if(product.compare(list -> product) == 0)
            return 1 + searchStock(list -> next, product);
        
        else
            return 0 + searchStock(list -> next, product);
    }
}