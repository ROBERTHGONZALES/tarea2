#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int tamanoalfabeto, longitudmaxima;

    cout << "INGRESE EL NUMERO DE ALFABETOS : ";
    cin >> tamanoalfabeto;
    cout << "INGRESE LA LONGITUD MAXIMA DEL LENGUAJE : ";
    cin >> longitudmaxima;

    vector<char> alfabeto(tamanoalfabeto);
    cout << "INGRESE LOS ALFABETOS DEL LENJUAJE: ";
    for (int i = 0; i < tamanoalfabeto; ++i) {
        cin >> alfabeto[i];
    }

    int totalcombinaciones = 0;

    for (int longitud = 1; longitud <= longitudmaxima; ++longitud) {
        cout << "COMBINACIONES DE LONGITUD  " << longitud << ":" << endl;

        int combinacionesporLongitud = 1;

        string combinacion(longitud, alfabeto[0]);

        while (true) {
            cout << combinacionesporLongitud << ". " << combinacion << endl;

            int j = longitud - 1;
            while (j >= 0 && combinacion[j] == alfabeto[tamanoalfabeto - 1]) {
                combinacion[j--] = alfabeto[0]; 
            }

            if (j < 0) break;

            int index = 0;
            while (combinacion[j] != alfabeto[index]) {
                index++;
            }
            combinacion[j] = alfabeto[index + 1];

            totalcombinaciones++;
            combinacionesporLongitud++;
        }
    }

    cout << "EL NUMERO TOTAL DE COMBINACIONES ES : " << totalcombinaciones << endl;

    return 0;
}

