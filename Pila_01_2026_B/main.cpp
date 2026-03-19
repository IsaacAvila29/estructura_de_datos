// Practica Pila
// Isaac Avila Saenz 238925
// Héctor Alejandro Hernández Villanueva 248895
#include <iostream>
#include <limits>

#include "pila.h"

using namespace std;

void limpiarEntrada()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int leerEntero(const char* mensaje)
{
	int valor;
	while (true)
	{
		cout << mensaje;
		cin >> valor;

		if (!cin.fail())
		{
			limpiarEntrada();
			return valor;
		}

		cout << "Entrada invalida. Intenta nuevamente.\n";
		limpiarEntrada();
	}
}

void mostrarMenu()
{
	cout << "\n===== MENU PILA =====\n";
	cout << "1. Push (apilar)\n";
	cout << "2. Pop (desapilar)\n";
	cout << "3. Ver tope\n";
	cout << "4. Mostrar contenido de la pila\n";
	cout << "5. Mostrar estado (Empty/Full)\n";
	cout << "6. Cargar varios datos\n";
	cout << "0. Salir\n";
}

void pushDato(Pila& pila)
{
	tipodato dato = leerEntero("Dato a apilar: ");
	if (pila.Push(dato))
		cout << "✓ Dato " << dato << " apilado correctamente.\n";
	else
		cout << "✗ ERROR: No se pudo apilar - La pila esta LLENA (maximo " << MAX << " elementos).\n";
}

void popDato(Pila& pila)
{
	tipodato dato;
	if (pila.Pop(dato))
		cout << "✓ Dato desapilado: " << dato << "\n";
	else
		cout << "✗ ERROR: No se pudo desapilar - La pila esta VACIA.\n";
}

void verTope(Pila& pila)
{
	tipodato dato;
	if (pila.Vertope(dato))
		cout << "✓ Dato en el tope: " << dato << "\n";
	else
		cout << "✗ ERROR: No se puede ver el tope - La pila esta VACIA.\n";
}

void mostrarEstado(Pila& pila)
{
	cout << "\n===== ESTADO DE LA PILA =====\n";
	cout << "¿Vacia?: " << (pila.Empty() ? "SI (true)" : "NO (false)") << "\n";
	cout << "¿Llena?:  " << (pila.Full() ? "SI (true)" : "NO (false)") << "\n\n";
}

void mostrarContenido(Pila& pila)
{
	if (pila.Empty())
	{
		cout << "La pila esta vacia.\n";
		return;
	}

	Pila auxiliar;
	tipodato dato;

	cout << "Tope -> Base: ";
	while (pila.Pop(dato))
	{
		cout << dato << ' ';
		auxiliar.Push(dato);
	}
	cout << "\n";

	// Restaurar la pila original
	while (auxiliar.Pop(dato))
		pila.Push(dato);
}

void inicializarPila(Pila& pila)
{
	int cantidad = leerEntero("Cuantos datos deseas cargar?: ");
	if (cantidad <= 0)
	{
		cout << "Cantidad invalida.\n";
		return;
	}

	for (int i = 0; i < cantidad; ++i)
	{
		tipodato dato = leerEntero("Dato: ");
		if (!pila.Push(dato))
		{
			cout << "La pila se lleno. No se pueden agregar mas datos.\n";
			break;
		}
	}
	cout << "Pila inicializada con datos.\n";
}

void cargarVarios(Pila& pila)
{
	int cantidad = leerEntero("Cuantos datos deseas intentar apilar?: ");
	if (cantidad <= 0)
	{
		cout << "Cantidad invalida.\n";
		return;
	}

	for (int i = 0; i < cantidad; ++i)
	{
		tipodato dato = leerEntero("Dato: ");
		if (!pila.Push(dato))
		{
			cout << "La pila se lleno. No se pueden agregar mas datos.\n";
			break;
		}
	}
}

int main()
{
	Pila pila;
	int opcion;

	inicializarPila(pila);

	do
	{
		mostrarMenu();
		opcion = leerEntero("Selecciona una opcion: ");

		switch (opcion)
		{
			case 1:
				pushDato(pila);
				break;
			case 2:
				popDato(pila);
				break;
			case 3:
				verTope(pila);
				break;
			case 4:
				mostrarContenido(pila);
				break;
			case 5:
				mostrarEstado(pila);
				break;
			case 6:
				cargarVarios(pila);
				break;
			case 0:
				cout << "Saliendo del programa...\n";
				break;
			default:
				cout << "Opcion invalida.\n";
				break;
		}
	} while (opcion != 0);

	return 0;
}
