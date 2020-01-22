#include<iostream>
#include<string>

using namespace std;



struct data{

    string name, report;
    float grade;

};

void fillArray(data* array, int size, int aux);
void printArray(data* array, int size, int aux);

int main(){
    int size = 0;
    cin >> size;
    cin.ignore();

    data* students;
    students = new data[size];

    fillArray(students, size, 0);
    printArray(students, size, 0);

    return 0;
}

void fillArray(data* array, int size, int aux){
    if(size == aux){
        return;
    }
    else{

        cout << "Nombre: "; getline(cin, array[aux].name);
        cout << "Comentarios: "; getline(cin, array[aux].report);
        cout << "Nota: "; cin >> array[aux].grade;
        cin.ignore();

        fillArray(array, size, aux + 1);
    }

}

void printArray(data* array, int size, int aux){
    if(size == aux){
        return;
    }
    else{

        cout << "Nombre: " << array[aux].name << endl;
        cout << "Comentarios: " << array[aux].report << endl;
        cout << "Nota: " << array[aux].grade << endl;
        cin.ignore();

        printArray(array, size, aux + 1);
    }

}