#include <iostream>
#include <cmath>
using namespace std;

void circulo(float radio, float &resultado);
void triangulo(float base, float altura, float &resultado);
void cuadrado(float lado, float &resultado);

void intercambio1(int primero, int segundo);
void intercambio2(int &primero, int &segundo);

int main()
{
    int opcion;
    float radio, base, altura, lado, resultado;

    do
    {
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

        switch (opcion)
        {
        case 1:
            cout << "\n--- AREA DEL CIRCULO ---" << endl;
            cout << "Ingrese el radio: ";
            cin >> radio;
            circulo(radio, resultado);
            cout << "El area del circulo es: " << resultado << endl;
            break;

        case 2:
            cout << "\n--- AREA DEL TRIANGULO ---" << endl;
            cout << "Ingrese la base: ";
            cin >> base;
            cout << "Ingrese la altura: ";
            cin >> altura;
            triangulo(base, altura, resultado);
            cout << "El area del triangulo es: " << resultado << endl;
            break;

        case 3:
            cout << "\n--- AREA DEL CUADRADO ---" << endl;
            cout << "Ingrese el lado: ";
            cin >> lado;
            cuadrado(lado, resultado);
            cout << "El area del cuadrado es: " << resultado << endl;
            break;

        case 4:
        {
            int a = 10, b = 20;
            cout << "\n--- EJEMPLO DE INTERCAMBIO ---" << endl;
            cout << "Valores iniciales: a = " << a << ", b = " << b << endl;

            intercambio1(a, b);
            cout << "Despues de intercambio1 (por valor): a = " << a << ", b = " << b << endl;
            cout << "(Los valores NO cambiaron)" << endl;

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

    } while (opcion != 5);

    return 0;
}

void circulo(float radio, float &resultado)
{
    const float PI = 3.14159;
    resultado = PI * radio * radio;
}

void triangulo(float base, float altura, float &resultado)
{
    resultado = (base * altura) / 2;
}

void cuadrado(float lado, float &resultado)
{
    resultado = lado * lado;
}

void intercambio1(int primero, int segundo)
{
    int aux;
    aux = primero;
    primero = segundo;
    segundo = aux;
}

void intercambio2(int &primero, int &segundo)
{
    int aux;
    aux = primero;
    primero = segundo;
    segundo = aux;
}