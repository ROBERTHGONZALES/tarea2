#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream archivo("pruebaprograma1.txt");
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    vector<int> numeros;
    int numero;
    while (archivo >> numero) {
        numeros.push_back(numero);
    }
    archivo.close();

    if (numeros.empty()) {
        cerr << "EL ARCHIVO ESTA VACIO." << endl;
        return 1;
    }

    int suma = 0;
    for (int num : numeros) {
        suma += num;
    }

    double promedio = suma / numeros;

    ofstream resultado("resultado.txt");
    if (!resultado.is_open()) {
        cerr << "No se pudo abrir el archivo de salida." << endl;
        return 1;
    }

    resultado << "El promedio de los numeros en el archivo es: " << promedio << endl;

    resultado.close();

    cout << "El resultado se ha escrito en el archivo 'resultado.txt'." << endl;

    return 0;
}

