# C++ para JS/React devs — Lista Circular

> Todo comparado con JavaScript para que tenga sentido inmediato.

---

## 1. El sistema de archivos: `.h` y `.cpp`

En JS/React divides tu código en módulos:

```js
// MiClase.js  ← definición + implementación juntas
export class MiClase { ... }
```

En C++ **se separan obligatoriamente** en dos archivos:

| Archivo | Qué contiene | Equivalente JS |
|---------|-------------|----------------|
| `.h` (header) | La "firma" de la clase: qué métodos existen, qué tipos tiene | Como un archivo de tipos TypeScript (`.d.ts`) |
| `.cpp` | La implementación real de cada método | El archivo `.js` con la lógica |

```cpp
// circular.h  ← solo DECLARA que existe InsertarInicio
bool InsertarInicio(tipodato);

// circular.cpp ← IMPLEMENTA qué hace InsertarInicio
bool LCircular::InsertarInicio(tipodato elDato) { ... }
```

**¿Por qué?** El compilador necesita saber la "forma" de una clase antes de usarla. El `.h` actúa como contrato.

---

## 2. `#include`, `#ifndef`, `#define` — los guardias del header

```cpp
#ifndef LCIRCULAR_H   // "Si NO está definido LCIRCULAR_H..."
#define LCIRCULAR_H   // "...defínelo (para que no entre dos veces)"
  // ...todo el código del header...
#endif
```

**Equivalente en JS:** `import` en JS es inteligente y no importa dos veces. En C++, si incluyes el mismo `.h` desde varios archivos, sin estos guardias el compilador recibiría la misma clase declarada varias veces y explotaría. Esto evita eso.

```cpp
#include "circular.h"   // incluye TU archivo (ruta relativa, comillas)
#include <iostream>     // incluye librería del sistema (ángulos)
```

En JS sería:
```js
import { algo } from './circular'   // tu archivo
import React from 'react'           // librería externa
```

---

## 3. `typedef` — alias de tipos

```cpp
typedef int tipodato;
```

En JS/TS sería:
```ts
type tipodato = number;
```

Sirve para que si mañana cambias la lista de `int` a `float`, solo cambias **una línea** en el `.h` y todo se actualiza.

---

## 4. Clases en C++ vs JS

En JS:
```js
class Nodo {
  constructor(dato) {
    this.dato = dato;
    this.siguiente = null;
  }
}
```

En C++:
```cpp
class Nodo {
    tipodato dato;       // atributo privado por defecto
    Nodo* siguiente;     // puntero al siguiente nodo
    Nodo(tipodato elDato); // constructor
};
```

**Diferencias clave:**

| Concepto | JavaScript | C++ |
|----------|-----------|-----|
| Visibilidad por defecto | `public` | `private` |
| Declarar secciones | no necesario | `public:` / `private:` |
| Constructor | `constructor()` | mismo nombre que la clase |
| Destructor | no existe (GC) | `~NombreClase()` |
| Herencia múltiple | no | sí |

---

## 5. `public` y `private`

```cpp
class LCircular {
    Nodo* final;   // PRIVADO (sin public:, todo es private por defecto)

public:            // a partir de aquí, TODO es público
    bool Empty();
    bool InsertarInicio(tipodato);
};
```

En JS/TS sería:
```ts
class LCircular {
  #final: Nodo | null;   // privado con #

  isEmpty(): boolean { ... }       // público
  insertAtStart(d: number) { ... } // público
}
```

---

## 6. Punteros — el concepto más ajeno para un JS dev

En JavaScript **nunca ves la memoria**. El runtime la maneja solo.  
En C++ tú decides exactamente dónde vive cada dato.

### Variable normal vs puntero

```cpp
int numero = 5;     // el valor 5 está guardado en una cajita llamada "numero"
int* ptr = &numero; // ptr guarda la DIRECCIÓN de esa cajita (como un GPS)
```

```
Memoria RAM:
┌────────────┐        ┌────────────┐
│  numero    │  0x42  │    ptr     │
│    5       │◄───────│   0x42     │
└────────────┘        └────────────┘
```

En JS, cada objeto ya ES un puntero implícito:
```js
const obj = { dato: 5 };  // obj guarda una referencia (puntero interno) al objeto
```

### El `*` y el `&`

```cpp
int* ptr;       // * en la declaración = "esto es un puntero"
int x = *ptr;   // * en uso = "dame el VALOR al que apunta" (desreferenciar)
int* p = &x;    // & = "dame la DIRECCIÓN de esta variable"
```

### El operador `->`

```cpp
Nodo* nodo = new Nodo(10);
nodo->dato      // accede al campo dato del Nodo apuntado
(*nodo).dato    // exactamente lo mismo, pero más feo
```

`->` = "ve a donde apunta el puntero y dame ese campo".

---

## 7. `new` y `delete` — la memoria manual

En JS/TS:
```js
const nodo = new Nodo(10);  // se crea en memoria
// cuando nadie lo usa, el Garbage Collector lo borra solo ♻️
```

En C++:
```cpp
Nodo* nodo = new Nodo(10);  // se crea en el HEAP (memoria dinámica)
delete nodo;                // TÚ lo borras. Si no, memory leak 💀
```

**El heap** es una zona de memoria que persiste mientras tú no la liberes. Por eso existe el **destructor** `~LCircular()`: se llama automáticamente cuando el objeto muere, y libera todos los nodos con `delete`.

```cpp
LCircular::~LCircular()
{
    // Recorre todos los nodos y hace delete de cada uno
    // Sin esto, cada Nodo quedaría en memoria para siempre
}
```

En React no tienes esto porque el GC de JavaScript lo hace por ti.

### ¿Por qué `Nodo*` y no solo `Nodo`?

```cpp
class Nodo {
    Nodo siguiente;  // ❌ ERROR: tamaño infinito, no puede existir
    Nodo* siguiente; // ✅ OK: el puntero siempre mide lo mismo (8 bytes en 64-bit)
};
```

Un nodo no puede "contener" a otro nodo (sería infinito), pero sí puede guardar **la dirección** de otro nodo.

---

## 8. Constructores en C++ — la initialization list

En JS:
```js
constructor(dato, siguiente = null) {
  this.dato = dato;
  this.siguiente = siguiente;
}
```

En C++ hay dos formas:

```cpp
// Forma 1: asignación dentro del cuerpo (como en JS)
Nodo::Nodo(tipodato elDato) {
    dato = elDato;
    siguiente = NULL;
}

// Forma 2: initialization list (más eficiente en C++)
Nodo::Nodo(tipodato elDato, Nodo* elSiguiente)
    : dato(elDato), siguiente(elSiguiente) {}
//    ↑ inicializa directamente, sin pasar por asignación
```

La forma con `:` (initialization list) es preferida porque inicializa los atributos directamente en lugar de crearlos vacíos y luego asignarlos.

---

## 9. `NULL` vs `nullptr`

```cpp
Nodo* ptr = NULL;    // C clásico: NULL es simplemente el número 0
Nodo* ptr = nullptr; // C++ moderno: es explícitamente "puntero nulo"
```

En JS es `null`. Aquí el código usa `NULL` porque sigue el estilo de la maestra (C clásico).

---

## 10. `friend class` — rompiendo el encapsulamiento

```cpp
class Nodo {
    friend class LCircular;  // LCircular puede acceder a TODO lo privado de Nodo
    tipodato dato;           // privado, pero LCircular lo puede leer/escribir
    Nodo* siguiente;         // igual
};
```

En JS no existe este concepto. Es como decir: "Solo esta clase específica tiene acceso a mis partes privadas, nadie más".

Sin `friend`, `LCircular` no podría hacer `nodo->dato` ni `nodo->siguiente` porque son privados.

---

## 11. `do { } while` — el loop que aparece mucho aquí

En una lista circular **no puedes usar un `while` normal** al inicio porque el primer nodo ya cumple la condición de parada. Necesitas ejecutar el cuerpo al menos una vez:

```cpp
Nodo* actual = final->siguiente; // primer nodo
do {
    cout << actual->dato;
    actual = actual->siguiente;
} while (actual != final->siguiente); // para cuando vuelves al inicio
```

En JS sería:
```js
let actual = this.final.siguiente;
do {
  console.log(actual.dato);
  actual = actual.siguiente;
} while (actual !== this.final.siguiente);
```

---

## 12. La estructura de la Lista Circular

Visualización de cómo queda en memoria con 3 nodos (10, 20, 30):

```
        ┌──────────────────────────────────┐
        ▼                                  │
    ┌───────┐     ┌───────┐     ┌───────┐  │
    │  30   │────►│  20   │────►│  10   │──┘
    └───────┘     └───────┘     └───────┘
        ▲
      final
```

- `final` apunta siempre al **último** nodo insertado
- `final->siguiente` apunta siempre al **primero**
- El último nodo apunta de vuelta al primero → círculo

### Comparado con un array de JS

```js
// En JS, una lista circular sería algo así:
const lista = [30, 20, 10];
// Para ir al "siguiente" del último: lista[(i + 1) % lista.length]
```

La diferencia es que en C++ los nodos viven en posiciones **aleatorias** de la memoria, no contiguas. Solo los punteros los conectan.

---

## 13. Separación `Clase::Metodo` en el `.cpp`

En JS:
```js
class LCircular {
  empty() { return this.final === null; }
}
```

En C++, los métodos se implementan **fuera** de la clase, y usas `::` para decir "este método pertenece a esta clase":

```cpp
// En el .h solo se declara:
bool Empty();

// En el .cpp se implementa:
bool LCircular::Empty() {
//   ↑ "el método Empty que pertenece a LCircular"
    return (!final);
}
```

`::` es el **operador de resolución de ámbito** (scope resolution operator). En JS sería como el `.` pero para clases, no instancias.

---

## 14. `using namespace std`

```cpp
#include <iostream>
using namespace std;

cout << "Hola";  // sin esto tendría que ser std::cout << "Hola";
```

En JS sería como hacer un import global:
```js
import * as std from 'iostream';
// con "using namespace std" es como hacer todo accesible directamente
```

`cout` es el equivalente a `console.log`. `<<` es el operador para "enviar" datos al output.

---

## Resumen rápido

| Concepto C++ | Equivalente JS/TS |
|---|---|
| `Nodo*` | referencia a objeto (implícita en JS) |
| `new Nodo(x)` | `new Nodo(x)` (igual, pero en JS el GC lo borra) |
| `delete nodo` | no existe en JS (GC automático) |
| `nodo->campo` | `nodo.campo` (JS siempre usa `.`) |
| `~LCircular()` | no existe en JS |
| `.h` / `.cpp` | todo junto en `.js` / `.ts` |
| `typedef int tipodato` | `type tipodato = number` |
| `NULL` / `nullptr` | `null` |
| `friend class X` | no existe en JS |
| `::` | `.` para clases (no instancias) |
| `private:` por defecto | `public` por defecto |
