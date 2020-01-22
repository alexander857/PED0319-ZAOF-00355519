#include<iostream>
#include<cmath>

using namespace std;

struct monomio{

    float coef, exp;

};

float evaluate(monomio* array, int size, int aux);

int main(){
    int size = 0;
    cin >> size;

    monomio* array;
    array = new monomio[size];

    for(int i = 0; i < size; i++){
        cin >> array[i].coef >> array[i].exp;
    }

    cout << evaluate(array, size, 0) << endl;

    return 0;
}

float evaluate(monomio* array, int size, int aux){

    if(aux == size){
        return 0;
    }
    else{
        return pow(array[aux].coef, array[aux].exp) + evaluate(array, size, aux + 1);
    }

}