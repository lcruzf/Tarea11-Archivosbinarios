#include <iostream>
#include <fstream>
using namespace std;


struct Producto {
    int codigo;
    char nombre[40];
    char categoria[30];
    int stock;
    float precio;
    bool activo;
};

void registrarProducto();
void listarProductos();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {

    int opcion;

    do {

        cout << "\n===============================";
        cout << "\n SISTEMA DE VENTAS E INVENTARIO";
        cout << "\n===============================";

        cout << "\n1. Registrar producto";
        cout << "\n2. Listar productos";
        cout << "\n3. Salir";

        cout << "\n\nSeleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {

            case 1:
                registrarProducto();
                break;

            case 2:
                listarProductos();
                break;

            case 3:
                cout << "\nPrograma finalizado...";
                cout << "\nRealizado por: Luis Fernando Cruz Franco";
                break;

            default:
                cout << "\nOpcion invalida.\n";
        }

    } while(opcion != 3);
}

void registrarProducto() {

    Producto producto;

    ofstream archivo("productos.dat", ios::binary | ios::app);

    if(!archivo) {
        cout << "\nError al abrir el archivo.\n";
        return;
    }

    cout << "\n========== REGISTRO ==========";

    cout << "\nCodigo: ";
    cin >> producto.codigo;
    cin.ignore();

    cout << "Nombre: ";
    cin.getline(producto.nombre, 40);

    cout << "Categoria: ";
    cin.getline(producto.categoria, 30);

    cout << "Stock: ";
    cin >> producto.stock;

    cout << "Precio: ";
    cin >> producto.precio;

    // Activo siempre en true
    producto.activo = true;

    // Guardar en archivo binario
    archivo.write((char*)&producto, sizeof(producto));

    archivo.close();

    cout << "\nProducto registrado correctamente.\n";
}

void listarProductos() {

    Producto p;

    ifstream archivo("productos.dat", ios::binary);

    if(!archivo) {
        cout << "\nNo existe informacion almacenada.\n";
        return;
    }

    cout << "\n========== LISTADO ==========\n";

    while(archivo.read((char*)&p, sizeof(p))) {

        cout << "\n-------------------------";
        cout << "\nCodigo: " << p.codigo;
        cout << "\nNombre: " << p.nombre;
        cout << "\nCategoria: " << p.categoria;
        cout << "\nStock: " << p.stock;
        cout << "\nPrecio: Q" << p.precio;

        if(p.activo == true) {
            cout << "\nActivo: Si";
        } else {
            cout << "\nActivo: No";
        }
    }

    archivo.close();
}