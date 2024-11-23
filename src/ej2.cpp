#include <iostream>
#include <string>
using namespace std;

struct Elemento
{
    char prioridad;
    string nombre;
};

void procesarCola(Elemento *cola, int n)
{
    const int NUM_PRIORIDADES = 26;
    Elemento **prioridades = new Elemento *[NUM_PRIORIDADES];
    int *tamanios = new int[NUM_PRIORIDADES]{0};

    for (int i = 0; i < NUM_PRIORIDADES; ++i)
    {
        prioridades[i] = new Elemento[n];
    }

    for (int i = 0; i < n; ++i)
    {
        int index = cola[i].prioridad - 'A';
        if (index >= 0 && index < NUM_PRIORIDADES)
        {
            prioridades[index][tamanios[index]++] = cola[i];
        }
    }

    cout << "\nProcesando en orden de prioridad:\n";
    for (int i = 0; i < NUM_PRIORIDADES; ++i)
    {
        for (int j = 0; j < tamanios[i]; ++j)
        {
            cout << "(" << prioridades[i][j].prioridad << ", \"" << prioridades[i][j].nombre << "\")\n";
        }
    }

    for (int i = 0; i < NUM_PRIORIDADES; ++i)
    {
        delete[] prioridades[i];
    }
    delete[] prioridades;
    delete[] tamanios;
}

int main()
{
    int n;

    cout << "Ingrese la cantidad de elementos en la cola: ";
    cin >> n;

    Elemento *cola = new Elemento[n];

    cout << "Ingrese los elementos de la cola (formato: prioridad(Letra) / nombre):\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> cola[i].prioridad >> cola[i].nombre;
    }

    cout << "\nCola inicial:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "(" << cola[i].prioridad << ", \"" << cola[i].nombre << "\") ";
    }
    cout << endl;

    procesarCola(cola, n);

    delete[] cola;
    return 0;
}