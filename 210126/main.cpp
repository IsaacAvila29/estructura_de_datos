#include <iostream>
#include <cmath>
using namespace std;

// Prototipos de funciones para calcular áreas
void circulo(float radio, float& resultado);
void triangulo(float base, float altura, float& resultado);
void cuadrado(float lado, float& resultado);

// Prototipos para ejemplo de intercambio
void intercambio1(int primero, int segundo);
void intercambio2(int& primero, int& segundo);

int main() {
    int opcion;
    float radio, base, altura, lado, resultado;
    
    do {
        // Menú principal
        cout << "\n========================================" << endl;
        cout << "   CALCULADORA DE AREAS" << endl;
        cout << "========================================" << endl;
        cout << "1. Calcular area de un circulo" << endl;
        cout << "2. Calcular area de un triangulo" << endl;
        cout << "3. Calcular area de un cuadrado" << endl;
        cout << "4. Ejemplo de intercambio (por valor vs referencia)" << endl;
        cout << "5. Salir" << endl;
        cout << "========================================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                // Círculo
                cout << "\n--- AREA DEL CIRCULO ---" << endl;
                cout << "Ingrese el radio: ";
                cin >> radio;
                circulo(radio, resultado);
                cout << "El area del circulo es: " << resultado << endl;
                break;
                
            case 2:
                // Triángulo
                cout << "\n--- AREA DEL TRIANGULO ---" << endl;
                cout << "Ingrese la base: ";
                cin >> base;
                cout << "Ingrese la altura: ";
                cin >> altura;
                triangulo(base, altura, resultado);
                cout << "El area del triangulo es: " << resultado << endl;
                break;
                
            case 3:
                // Cuadrado
                cout << "\n--- AREA DEL CUADRADO ---" << endl;
                cout << "Ingrese el lado: ";
                cin >> lado;
                cuadrado(lado, resultado);
                cout << "El area del cuadrado es: " << resultado << endl;
                break;
                
            case 4:
                // Ejemplo de intercambio
                {
                    int a = 10, b = 20;
                    cout << "\n--- EJEMPLO DE INTERCAMBIO ---" << endl;
                    cout << "Valores iniciales: a = " << a << ", b = " << b << endl;
                    
                    // Intercambio por valor
                    intercambio1(a, b);
                    cout << "Despues de intercambio1 (por valor): a = " << a << ", b = " << b << endl;
                    cout << "(Los valores NO cambiaron)" << endl;
                    
                    // Intercambio por referencia
                    intercambio2(a, b);
                    cout << "Despues de intercambio2 (por referencia): a = " << a << ", b = " << b << endl;
                    cout << "(Los valores SI cambiaron)" << endl;
                }
                break;
                
            case 5:
                cout << "\nSaliendo del programa..." << endl;
                break;
                
            default:
                cout << "\nOpcion invalida. Intente de nuevo." << endl;
        }
        
    } while(opcion != 5);
    
    return 0;
}

// Función para calcular el área de un círculo
// Parámetros por valor: radio
// Parámetro por referencia: resultado
void circulo(float radio, float& resultado) {
    const float PI = 3.14159;
    resultado = PI * radio * radio;
}

// Función para calcular el área de un triángulo
// Parámetros por valor: base, altura
// Parámetro por referencia: resultado
void triangulo(float base, float altura, float& resultado) {
    resultado = (base * altura) / 2;
}

// Función para calcular el área de un cuadrado
// Parámetros por valor: lado
// Parámetro por referencia: resultado
void cuadrado(float lado, float& resultado) {
    resultado = lado * lado;
}

// Función de intercambio por VALOR
// Los cambios NO se reflejan en las variables originales
void intercambio1(int primero, int segundo) {
    int aux;
    aux = primero;
    primero = segundo;
    segundo = aux;
    // Las variables locales primero y segundo se destruyen al terminar la función
}

// Función de intercambio por REFERENCIA
// Los cambios SI se reflejan en las variables originales
void intercambio2(int& primero, int& segundo) {
    int aux;
    aux = primero;
    primero = segundo;
    segundo = aux;
    // Los cambios permanecen porque se trabaja sobre las variables originales
}