//pila de cajas de Amazon
//peso, contenido, destino

#include<iostream>
#include<stack>
#include<string>

using namespace std;

struct pack{
    string content, address;
    flat weigth;
};

int main(){
    stack <pack> st;
    int option = 0;
    pack aux;

    do{
        cout << "Peso: "; cin >> aux.weigth; cin.ignore();
        cout << "Contenido: "; getline(cin, aux.content);
        cout << "Destino: "; getline(cin, aux.address);

        st.push(aux);

        cout << "Ingresar mas datos (1 = si, 0 = no): "; cin >> option;
        cin,ignore();

    }while(option != 0);

    aux = st.top();

    cout << "Peso: "; << aux.weigth << endl;
    cout << "Contenido: " << aux.content << endl;
    cout << "Destino: " << aux.address << endl;

    return 0;
}