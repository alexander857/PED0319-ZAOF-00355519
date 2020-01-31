#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

enum genero{a, b, c, d};

struct canciones{
    string titulo, cantante;
    generon gen;
    int duracion;
};

typedef canciones T;

void imprimirMenu();
void buscarElemento(vector<T> canciones, queue<T>* cola, string unTitulo);

int main(){
    T aux;
    vector<T> lista;
    queue<T> triste, feliz, dormir;

    int opcion = 0, auxNum = 0;
    string unTitulo;
    do{
        imprimirMenu(); cin >> opcion; cin.ignore();

        switch(opcion){
            case 1: 
                cout << "Titulo: "; getline(cin, aux.titulo);
                cout << "Cantante: "; getline(cin, aux.cantante);
                cout << "Genero (1 - a, 2 - b, 3 - c, 4 - d):";
                cin >> auxNum; cin.ignore(); auxNum--;
                aux.gen = genero(auxNum);
                aux.duracion = 0;
                do{
                    cout << "Duracion: "; cin >> aux.duracion; cin.ignore();
                }while(aux.duracion <= 0);
                lista.push_back_(aux);    
            break;
            case 2:
                cout << "\nCancion a eliminar: "; getline(cin, unTitulo);
                for(auto iter = lista.begin(); iter != lista.end(); ++iter){
                    if(iter->titulo.compare(unTitulo) == 0){
                        iter = lista.erase(iter);
                    }
                    else
                        iter++;
                } 
            break;
            case 3:
                for(T elemento : lista){
                    cout << elemento.cantante << endl;
                    cout << elemento.titulo << endl;
                    cout << elemento.duracion << endl;
                    switch(elemento.gen){
                        case a: cout << "a"; break;
                        case b: cout << "b"; break;
                        case c: cout << "c"; break;
                        case d: cout << "d"; break;
                    }
                    cout << endl;
                } 
            break;
            case 4:
                cout << "\nCancion a buscar: "; getline(cin, unTitulo);
                cout << "Agregar en (1 - Triste, 2 - Feliz, 3 - Dormir)";
                cin >> auxNum; cin.ignore();
                switch(auxNum){
                    case 1: buscarElemento(lista, &triste, unTitulo); break;
                    case 2: buscarElemento(lista, &feliz, unTitulo); break;
                    case 3: buscarElemento(lista, &dormir, unTitulo); break;
                }
            break;
        }
    }while();
}

void imprimirMenu(){
    cout << "1-Agregar cancion" << endl;
    cout << "2-Eliminar cancion" << endl;
    cout << "3-Mostrar canciones" << endl;
    cout << "4-Buscar la cancion" << endl;
    cout << "0-Salir" << endl;
    cout << "Opcion: ";
}

void buscarElemento(vector<T> canciones, queue<T>* cola, string unTitulo){
    for(T elemento : canciones){
        if(elemento.titulo.compare(unTitulo) == 0){
            cout << "\nCancion encontrada" << endl;
            (*cola).push(elemento);
            return;
        }
    }
    cout << "\nCancion no encontrada" << endl;
}