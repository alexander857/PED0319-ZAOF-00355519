#include<iostream>
#include<string>
using namespace std;

struct pedido{
    string remitente, destinatario;
    char tipo, modalidad;
    int peso;
    pedido* sig;
};

struct cola{
    pedido elemento;
    cola* sig;
};

cola* queue(cola* c, pedido elemento);

int main(){
    cola* pInicio = NULL;
    pedido aux;
    int opcion = 0;

    do{
        cout << "\nRemitente: "; getline(cin, aux.remitente);
        cout << "Destinatario: "; getline(cin, aux. destinatario);
        cout << "Tipo: "; cin >> aux.tipo; cin.ignore();
        cout << "Modalidad: "; cin >> aux.modalidad; cin.ignore();
        cout << "Peso: "; cin >> aux.peso; cin.ignore();

        pInicio = queue(pInicio, aux);

        cout << "Mas pedidos (1 - Si, 0 - No): "; cin >> opcion; cin.ignore();

    }while(opcion != 0);

    cout << "Total por sus pedidos: " << calcularTotal(pInicio) << endl;
    cout << "Muchas gracias por usar Correos de El Salvador!" << endl;

    return 0;
}

cola* queue(cola* c, pedido elemento){
    cola* nuevo = new cola;

    nuevo->elemento = elemento;
    nuevo->sig = NULL;

    if(!c)
        c = nuevo;
    else{
        cola* aux = c;
        while(aux->sig){
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }

    return c;
}

float calcularTotal(cola* lista){
    if(!lista){
        return 0;
    }
    else{
        float sub = 0;
        switch(lista->elemento.tipo){
            case 'c':
            case 'C':
                switch(lista->modalidad){
                    case 'u':
                    case 'U':
                        sub = 3;
                    break;
                    case 'n':
                    case 'N':
                        sub = 1;
                    break;
                    case 'i':
                    case 'I':
                        sub = 2;
                    break;
                }
            break;
            case 'p':
            case 'P':
                switch(lista->modalidad){
                case 'u':
                case 'U':
                    if(lista->elemento.peso <= 500)
                        sub = 10;
                    else
                        sub = 13
                break;
                case 'n':
                case 'N':
                    if(lista->elemento.peso < 100)
                        sub = 5;
                    else
                        sub = 1;
                break;
                case 'i':
                case 'I':
                    sub = 2;
                break;
            }
        break;
        default: 
            break;
        return sub + calcularTotal(lista->sig);
        
    }

}