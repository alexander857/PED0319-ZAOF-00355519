//datos de una parsona, nombre y apellido y numero de dui

#include<iostream>
#include<string>
using namespace std;

struct data{
    string name;
    int dui;
};

typedef data T;

struct node{
    T info;
    node* left, *right;
};

//prototipos
node* createLeaf(T x);
void insertInTree(node** pTree, string word);
void preOrder(node* pTree);
void postOrder(node* pTree);
void inOrder(node* pTree);

int main(){
    node* pTree = NULL;
    T x;
    //insertando palabras en el arbol
    cout << "\nIngrese su nombre completo: "; getline(cin, x.name);
    cout << "Ingrese su DUI: "; cin >> x.dui; cin.ignore();

    //mostrando el arbol
 /*   cout << "\nImprimendo en preOrder" << endl;
    preOrder(pTree); cout << endl << endl;
    cout << "\nImprimendo en inOrder" << endl;
    inOrder(pTree); cout << endl << endl;
    cout << "\nImprimendo en postOrder" << endl;
    postOrder(pTree); cout << endl << endl;*/

    return 0;
}

node* createLeaf(T x){
    node* leaf = new node;
    leaf -> info = x;
    leaf -> left = NULL;
    leaf -> right = NULL;

    return leaf;
}

void insertInTree(node** pTree, T x){
    if(!*pTree){
        *pTree = createLeaf(x);
    }
    else{
        if(x.compare((*(*pTree)).info.name) <= 0){
            insertInTree(&(*(*pTree)).left, word);
        }
        else{
            insertInTree(&(*(*pTree)).right, word);
        }
    }
}

void preOrder(node* pTree){
    if(!pTree){
        return;
    }
    else{
        cout << pTree -> info.name << "\t";
        preOrder(pTree->left);
        preOrder(pTree->right);
    }
}

void postOrder(node* pTree){
    if(!pTree){
        return;
    }
    else{
        postOrder(pTree->left);
        postOrder(pTree->right);
        cout << pTree -> info.name << "\t";
    }
}

void inOrder(node* pTree){
    if(!pTree){
        return;
    }
    else{
        inOrder(pTree->left);
        cout << pTree -> info.name << "\t";
        inOrder(pTree->right);
    }
}