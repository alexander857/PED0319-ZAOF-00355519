#include<iostream>
#include<string>

using namespace std;

struct Address{

    int houseNumber;
    string city, state;
};

struct personalInfo{

    string name;
    int age;
    Address pAdress;
};

void printInfo(personalInfo* pi, int size, int pos);

int main(){
    personalInfo* pData;

    int size = 0;

    cout << "Cantidad de datos a ingresar: "; cin >> size;
    pData = new personalInfo[size];

    for(int i = 0; i < size; i++){
        cout << "Nombre: "; cin >> pData[i].name;
        cout << "Edad: "; cin >> (pData + i) -> age;
         cin.ignore();
        cout << "No. Casa: "; cin >> pData[i].pAdress.houseNumber;
        cin.ignore();
        cout << "Ciudad: "; cin >> (pData + i) -> pAdress.city;
        cin.ignore();
        cout << "Estado: "; cin >> (pData + i) -> pAdress.state;
        

    }

    printInfo(pData, size, 0);

    return 0;
}

void printInfo(personalInfo* pi, int size, int pos){

    if(pos == size){
        return;
    }
    else{
        cout << "Nombre: " << pi[pos].name << endl;
        cout << "Edad: " << pi[pos].age << endl;
        cout << "No. casa: " << pi[pos].pAdress.houseNumber << endl;
        cout << "Ciudad: " << pi[pos].pAdress.city << endl;
        cout << "Estado: " << pi[pos].pAdress.state << endl;
    }

}