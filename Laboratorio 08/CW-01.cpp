#include<iostream>
using namespace std;

struct node{
    int n;
    node* left, * right;
};

node* createLeaf(int);
void inserInTree(node**, int);
void preOrder(node* pTree);
void postOrder(node* pTree);
void inOrder(node* pTree);

int main(){
    node* pTree = NULL;
    //insertando elementos al arbol
    inserInTree(&pTree, 12);
    inserInTree(&pTree, 22);
    inserInTree(&pTree, 8);
    inserInTree(&pTree, 15);
    inserInTree(&pTree, 1);
    inserInTree(&pTree, 0);
    inserInTree(&pTree, 27);

    cout << "\nImprimendo en preOrder" << endl;
    preOrder(pTree); cout << endl << endl;
    cout << "\nImprimendo en inOrder" << endl;
    inOrder(pTree); cout << endl << endl;
    cout << "\nImprimendo en postOrder" << endl;
    postOrder(pTree); cout << endl << endl;

    return 0;
}

node* createLeaf(int n){
    node* leaf = new node;
    leaf -> n = n;
    leaf -> left = NULL;
    leaf -> right = NULL;

    return leaf;
}

void inserInTree(node** tree, int n){
    if(!(*tree)){
        *tree = createLeaf(n);
    }
    else{
        if(n <= (*(*tree)).n){
            inserInTree(&(*(*tree)).left, n);
        }
        else{
            inserInTree(&(*(*tree)).right, n);
        }
    }
}

void preOrder(node* pTree){
    if(!pTree){
        return;
    }
    else{
        cout << pTree -> n << "\t";
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
        cout << pTree -> n << "\t";
    }
}

void inOrder(node* pTree){
    if(!pTree){
        return;
    }
    else{
        inOrder(pTree->left);
        cout << pTree -> n << "\t";
        inOrder(pTree->right);
    }
}