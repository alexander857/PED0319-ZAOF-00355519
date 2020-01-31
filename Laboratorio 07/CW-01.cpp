#include<iostream>

using namespace std;

struct nodo{
    int n;
    node* next;
};

node* queue(node* list, int n);
void print(node* list, int n);

int main(){
    node* list = NULL;

    for(int i = 0; i <= 20; i++){
        list = queue(list, i);
    }

    nodo* aux = list;

    while(aux->next){
        aux = aux->next;
    }

    aux->next = list;

    print(list, 0, list->n);
    return 0;
}

nodo* queue(node* list, int i, int n){
    node* newNode = new node;

    newNode->n = 
}

void print(node* list, int n){
    if(i == 1 && list->n == n){
        return;
    }
    else{
       cout << list->n << endl;
       print(list->next, 1, n); 
    }
}
