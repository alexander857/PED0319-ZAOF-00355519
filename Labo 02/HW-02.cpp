//DATOS DE UNA PERSONA Y VER SI DEBE ESTAR JUBILADA O NO

#include<iostream>
#include<string>

using namespace std;

//registro de datos de una persona
struct PersonalInformation{
	
	string name;
	float salary;
	int age;
	int workingYear;
	
};

//prototipos de funciones
int RetiredPerson(PersonalInformation RePerson, int m); //retorna si la persona debe estar jubilada o no
int ManOrWomen(); //retorna si el usuario es hombre o mujer 


int main(){
	//declaracion de variables
	PersonalInformation data;
	int n = 0, m = 0;
	
	m = ManOrWomen(); //llamamos a la funcion que retorna 1 si el usuario es hombre o 2 si es mujer y se le pasa el dato
	cin.ignore();     //a la funcion que verifica si deberia jubilarse o no segun los años de jubilacion que le tocan
	
	//pidiendo los datos de la persona
	cout << "\nINGRESE LOS DATOS DE UNA PERSONA\n" << endl;
	
	cout << "Nombre: ";
	getline(cin, data.name);
	cout << "Salario: ";
	cin >> data.salary;
	cout << "Edad: ";
	cin >> data.age;
	cout << "Anos laborales: ";
	cin >> data.workingYear;
	
	n = RetiredPerson(data,m);  //se llama a la funcion y n recibe lo que retorna (1 si la persona debe jubilarse y 0 si no)
	cout << endl;
	
	//verificando si debe estar o no jubilada
	if(n == 1){
		
		cout << data.name << " debe estar jubilado/a" << endl;
		
	}
	else{
		
		cout << data.name << " no debe estar jubilado/a" << endl;
		
	}
	
	return 0;
}

//funcion para verificar si la persona deberia estar jubilada o no segun años laborales
int RetiredPerson(PersonalInformation RePerson, int m){
	//declaracion de variables
	int Years = 0;
	
	//se identifica a los años de jubilacion segun si es hombre o mujer el usuario
	if(m == 1){
		Years = 60;
	}
	else{
		Years = 55;
	}
	
	if(RePerson.age >= Years){ //si la edad del usuario es mayor al limite para jubilarse retorna 1 la funcion
		
		return 1; //debe estar jubilado
		
	}
	else{
		
		return 0; //no debe estar jubilado
		
	}
	
}

//funcion para ver si el usuario es hombre o mujer
int ManOrWomen(){
	//declaracion de variables
	int option;
	
	//pedimos al usuario que sexo es
	cout << "INGRESE SU SEXO:\n " << endl;
	cout << "1-Hombre\n2-Mujer\n" << endl;
	
	cout << "Opcion: "; cin >> option;
		
	return option;
}