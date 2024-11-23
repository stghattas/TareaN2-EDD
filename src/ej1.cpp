#include <iostream>
using namespace std;

void invertirPila(int *pila, int tamanio)
{
    int *pilaInvertida = new int[tamanio];

    for (int i = 0; i < tamanio; ++i)
    {
        pilaInvertida[i] = pila[tamanio - i - 1];
    }

    for (int i = 0; i < tamanio; ++i)
    {
        pila[i] = pilaInvertida[i];
    }

    delete[] pilaInvertida;
}

int main()
{
    int n;

    cout << "Ingrese la cantidad de elementos que tendra la pila: ";
    cin >> n;

    int *pila = new int[n];

    cout << "Ingrese los elementos de la pila (de abajo hacia arriba):\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> pila[i];
    }

    cout << "\nPila original:\n";
    for (int i = n - 1; i >= 0; --i)
    {
        cout << pila[i] << " ";
    }
    cout << endl;

    invertirPila(pila, n);

    cout << "\nPila invertida:\n";
    for (int i = n - 1; i >= 0; --i)
    {
        cout << pila[i] << " ";
    }
    cout << endl;

    delete[] pila;
    return 0;
}