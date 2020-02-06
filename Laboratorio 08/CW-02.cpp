#include<iostream>
#include<string>
using namespace std;

struct node{
    string word;
    node* left, *right;
};

//prototipos
node* createLeaf(string word);
void insertInTree(node** pTree, string word);
void preOrder(node* pTree);
void postOrder(node* pTree);
void inOrder(node* pTree);

int main(){
    node* pTree = NULL;
    //insertando palabras en el arbol
    insertInTree(&pTree, "Hola");
    insertInTree(&pTree, "Pupusas");
    insertInTree(&pTree, "Codigo");
    insertInTree(&pTree, "Adios");
    insertInTree(&pTree, "F");

    //mostrando el arbol
    cout << "\nImprimendo en preOrder" << endl;
    preOrder(pTree); cout << endl << endl;
    cout << "\nImprimendo en inOrder" << endl;
    inOrder(pTree); cout << endl << endl;
    cout << "\nImprimendo en postOrder" << endl;
    postOrder(pTree); cout << endl << endl;

    return 0;
}

node* createLeaf(string word){
    node* leaf = new node;
    leaf -> word = word;
    leaf -> left = NULL;
    leaf -> right = NULL;

    return leaf;
}

void insertInTree(node** pTree, string word){
    if(!*pTree){
        *pTree = createLeaf(word);
    }
    else{
        if(word.compare((*(*pTree)).word) <= 0){
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
        cout << pTree -> word << "\t";
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
        cout << pTree -> word << "\t";
    }
}

void inOrder(node* pTree){
    if(!pTree){
        return;
    }
    else{
        inOrder(pTree->left);
        cout << pTree -> word << "\t";
        inOrder(pTree->right);
    }
}