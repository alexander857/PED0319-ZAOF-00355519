#include<iostream>
#include<string>

using namespace std;

struct data{
	string name, lastname, dui;
};

typedef data D;

struct node{
	D info;
	node *left, *right;	
};

//prototipos
node* createLeaf(D aux);
void insertInTree(node** pTree, D aux);
void preOrder(node* pTree);
void postOrder(node* pTree);
void inOrder(node* pTree);

int main(){
	node* pTree = NULL;
	D aux;
	bool follow = true;
	
	do{
		int option = 0;
		cout << "\n1-Ingresar datos\n";
		cout << "2-Datos ordenados por apellido\n";
		cout << "3-Salir\n";
		cout << "Opcion: "; cin >> option; cin.ignore();
		
		switch(option){
			case 1:
				cout << "\nIngrese sus nombres: "; getline(cin, aux.name);
				cout << "Ingrese sus apellidos: "; getline(cin, aux.lastname);
				cout << "Ingrese su DUI: "; getline(cin, aux.dui);
				insertInTree(&pTree, aux);
			break;
			case 2:
				cout << "\nNombres ingresados:\n";
				inOrder(pTree); 
			break;
			case 3: follow = false; break;
		}
		
	}while(follow);
	
	
	return 0;
}

node* createLeaf(D info){
    node* leaf = new node;
    leaf -> info = info;
    leaf -> left = NULL;
    leaf -> right = NULL;

    return leaf;
}

void insertInTree(node** pTree, D info){
    if(!*pTree){
        *pTree = createLeaf(info);
    }
    else{
        if(info.lastname.compare((*(*pTree)).info.lastname) <= 0){
            insertInTree(&(*(*pTree)).left, info);
        }
        else{
            insertInTree(&(*(*pTree)).right, info);
        }
    }
}

void inOrder(node* pTree){
    if(!pTree){
        return;
    }
    else{
        inOrder(pTree->left);
        cout << pTree -> info.name << " ";
        cout << pTree -> info.lastname << ", DUI: ";
        cout << pTree -> info.dui << endl;
        inOrder(pTree->right);
    }
}