#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct Nodo {
    T dato;
    int prioridad;
    Nodo* siguiente;

    Nodo(T d, int p) : dato(d), prioridad(p), siguiente(nullptr) {}
};

template <typename T>
class ColaPrioridad {
private:
    Nodo<T>* frente;

public:
    ColaPrioridad() : frente(nullptr) {}

    ~ColaPrioridad() {
        while (frente) {
            Nodo<T>* temp = frente;
            frente = frente->siguiente;
            delete temp;
        }
    }

    void insertar(const T& dato, int prioridad) {
        Nodo<T>* nuevo = new Nodo<T>(dato, prioridad);

        if (!frente || prioridad < frente->prioridad) {
            nuevo->siguiente = frente;
            frente = nuevo;
            return;
        }

        Nodo<T>* actual = frente;
        while (actual->siguiente && actual->siguiente->prioridad <= prioridad) {
            actual = actual->siguiente;
        }

        nuevo->siguiente = actual->siguiente;
        actual->siguiente = nuevo;
    }

    void eliminar() {
        if (!frente) {
            cout << "La cola esta vacia.\n";
            return;
        }

        Nodo<T>* temp = frente;
        frente = frente->siguiente;
        delete temp;
    }

    T obtenerFrente() const {
        if (!frente) {
            throw runtime_error("La cola esta vacia.");
        }
        return frente->dato;
    }

    void mostrar() const {
        Nodo<T>* actual = frente;
        while (actual) {
            cout << "(" << actual->dato << ", prioridad: " << actual->prioridad << ") -> ";
            actual = actual->siguiente;
        }
        cout << "NULL\n";
    }

    bool estaVacia() const {
        return frente == nullptr;
    }
};

int main() {
    ColaPrioridad<string> cola;

    int opcion;
    do {
        cout << "\n1. Insertar elemento\n";
        cout << "2. Eliminar elemento de mayor prioridad\n";
        cout << "3. Mostrar cola\n";
        cout << "4. Salir\n";
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string dato;
                int prioridad;
                cout << "Ingrese el dato: ";
                cin.ignore();
                getline(cin, dato);
                cout << "Ingrese la prioridad (menor valor = mayor prioridad): ";
                cin >> prioridad;
                cola.insertar(dato, prioridad);
                break;
            }
            case 2: {
                try {
                    cout << "Eliminando el elemento de mayor prioridad: " << cola.obtenerFrente() << "\n";
                    cola.eliminar();
                } catch (const runtime_error& e) {
                    cout << e.what() << "\n";
                }
                break;
            }
            case 3: {
                cout << "Cola de prioridad:\n";
                cola.mostrar();
                break;
            }
            case 4:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente.\n";
        }
    } while (opcion != 4);

    return 0;
}