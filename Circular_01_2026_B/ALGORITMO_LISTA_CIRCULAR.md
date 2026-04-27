# Algoritmo — Lista Circular Simplemente Ligada

---

## ¿Qué es una Lista Circular?

Una lista ligada normal se ve así:

```
[10] --> [20] --> [30] --> NULL
```

Una lista **circular** no termina en NULL. El último nodo apunta de regreso al primero:

```
[10] --> [20] --> [30]
  ^                 |
  └─────────────────┘
```

Esto permite recorrer la lista indefinidamente sin llegar a un "final muerto".

---

## La decisión de diseño: el puntero `final`

Podrías guardar un puntero al **primer** nodo, pero esta implementación guarda un puntero al **último**:

```
        final
          ↓
[10] --> [20] --> [30]
  ^                 |
  └─────────────────┘
```

¿Por qué? Porque con `final` tienes acceso **O(1)** a ambos extremos:

- **Último nodo** → `final`
- **Primer nodo** → `final->siguiente`

Si guardaras solo el primero, llegar al último costaría recorrer toda la lista — **O(n)**.

---

## Estado inicial: lista vacía

```cpp
LCircular() { final = NULL; }
```

```
final = NULL   →  lista vacía
```

---

## `Empty()` — ¿está vacía?

```cpp
bool LCircular::Empty() {
    return (!final);
}
```

**Algoritmo:** Si `final` es NULL, no hay ningún nodo. Devuelve `true`.

```
final == NULL  →  true   (vacía)
final != NULL  →  false  (tiene al menos un nodo)
```

---

## `InsertarInicio()` — insertar al frente

El nuevo nodo se convierte en el **primero** de la lista. Como `final->siguiente` siempre es el primero, solo hay que actualizar ese enlace.

### Caso 1: lista vacía

```
Antes:   final = NULL

Paso 1: Crear nodo con dato=10
        nuevo → [10 | sig=?]

Paso 2: nuevo->siguiente = nuevo   (apunta a sí mismo)
        nuevo → [10 | sig=nuevo]

Paso 3: final = nuevo
        final → [10 | sig=→sí mismo]

Después:
        ┌──────────┐
        │    ↓     │
        └── [10] ──┘
              ↑
            final
```

### Caso 2: ya existen nodos — insertar 20 con lista [10]

```
Antes:
        ┌──────────┐
        │    ↓     │
        └── [10] ──┘
              ↑
            final

Paso 1: Crear nuevo nodo (20)
        nuevo = new Nodo(20, final->siguiente)
                              ↑
                        final->siguiente = [10]  (el primer nodo)
        Entonces: nuevo → [20 | sig=[10]]

Paso 2: final->siguiente = nuevo
        [10]->siguiente = [20]

Después:
        final
          ↓
    ┌─── [10] ←─────────┐
    │                    │
    └──► [20] ───────────┘
         (nuevo primero)

   Recorrido: 20 -> 10 -> 20 -> ... (circular)
```

### Insertar 30 con lista [20 → 10]

```
Antes:
  final=[10], primer nodo=[20]

Paso 1: nuevo = new Nodo(30, final->siguiente)
        nuevo → [30 | sig=[20]]   (apunta al primer nodo actual)

Paso 2: final->siguiente = nuevo
        [10]->siguiente = [30]

Después:
  final=[10]
  [10] → [30] → [20] → [10] → ...

  Imprime: 30 -> 20 -> 10 -> (regresa al inicio)
```

> **Nota:** `InsertarInicio` inserta en la posición [0], pero como `final` no cambia, los nuevos elementos aparecen al principio cuando recorres desde `final->siguiente`.

---

## `Imprimir()` — recorrer la lista

```cpp
Nodo* actual = final->siguiente;  // empezar desde el primer nodo
do {
    cout << actual->dato << " -> ";
    actual = actual->siguiente;
} while (actual != final->siguiente);  // parar cuando vuelvas al inicio
```

**¿Por qué `do-while` y no `while`?**

Con un `while` normal:

```
while (actual != final->siguiente) { ... }
```

La condición se checa ANTES de entrar. En el primer paso `actual == final->siguiente`, así que **nunca entraría** al loop.

Con `do-while`, el cuerpo se ejecuta al menos una vez antes de checar la condición.

**Traza con lista [30 → 20 → 10]:**

```
actual = final->siguiente = [30]   (primer nodo)

Iteración 1: imprime 30, actual = [20]
             ¿actual == [30]? NO → continuar

Iteración 2: imprime 20, actual = [10]
             ¿actual == [30]? NO → continuar

Iteración 3: imprime 10, actual = [30]   (vuelve al inicio)
             ¿actual == [30]? SÍ → detener

Salida: 30 -> 20 -> 10 -> (regresa al inicio)
```

---

## `Buscar()` — encontrar un nodo

```cpp
Nodo* actual = final->siguiente;  // primer nodo
do {
    if (actual->dato == elDato) return actual;  // encontrado
    actual = actual->siguiente;
} while (actual != final->siguiente);
return NULL;  // no encontrado
```

**Devuelve un puntero** al nodo encontrado (no solo `true/false`), porque `InsertarDespues` necesita saber **dónde** está ese nodo en memoria para enlazar el nuevo ahí.

**Traza buscando 20 en [30 → 20 → 10]:**

```
actual = [30] → dato=30 ≠ 20 → avanzar
actual = [20] → dato=20 = 20 → ENCONTRADO, return [20]
```

**Traza buscando 55:**

```
actual = [30] → 30 ≠ 55 → avanzar
actual = [20] → 20 ≠ 55 → avanzar
actual = [10] → 10 ≠ 55 → avanzar
actual = [30] == final->siguiente → STOP
return NULL
```

---

## `InsertarDespues()` — insertar después de un valor

```cpp
bool LCircular::InsertarDespues(tipodato referencia, tipodato elDato)
```

**Algoritmo:**

1. Buscar el nodo con valor `referencia`
2. Crear el nuevo nodo, apuntando al siguiente del nodo de referencia
3. Hacer que el nodo de referencia apunte al nuevo
4. Si la referencia era el último nodo, actualizar `final`

**Traza: insertar 99 después del 20 en [30 → 20 → 10]:**

```
Paso 1: Buscar(20) → devuelve puntero a [20]
        nodoRef = [20 | sig=[10]]

Paso 2: nuevo = new Nodo(99, nodoRef->siguiente)
        nuevo → [99 | sig=[10]]

Paso 3: nodoRef->siguiente = nuevo
        [20]->siguiente = [99]

Resultado: [30] → [20] → [99] → [10] → [30] → ...
           Imprime: 30 -> 20 -> 99 -> 10 -> (regresa al inicio)

Paso 4 (verificar): nodoRef ([20]) == final ([10])? NO
                    → final no cambia
```

**Si inserto después del último nodo (ej. después del 10):**

```
nodoRef = [10] = final

nuevo → [99 | sig=[30]]   (apunta al primero)
[10]->siguiente = [99]
nodoRef == final → SÍ → final = nuevo = [99]

Resultado: [30] → [20] → [10] → [99] → [30] → ...
           final ahora apunta a [99]
```

---

## `Borrar()` — eliminar un nodo por valor

Este es el más complejo. Necesitas dos punteros: el nodo actual y el anterior, porque para desconectar un nodo debes hacer que el **anterior** salte sobre él.

```
Antes de borrar [20]:
[30] → [20] → [10] → [30]
  ↑anterior  ↑actual

Después:
[30] → [10] → [30]   (el [20] se saltó)
```

**Tres casos:**

### Caso 1: único nodo en la lista

```
final → [20 | sig=→sí mismo]

actual == final && actual->siguiente == actual → SÍ

final = NULL
delete actual

Resultado: lista vacía
```

### Caso 2: borrar un nodo intermedio o el primero

```
Lista: [30] → [20] → [10] → [30]  (final=[10])
Borrar 20.

anterior = [10] (final, el que está "antes" del primero en el círculo)
actual   = [30] (primer nodo, final->siguiente)

Iter 1: actual->dato=30 ≠ 20 → anterior=[30], actual=[20]
Iter 2: actual->dato=20 = 20 → BORRAR

  anterior->siguiente = actual->siguiente
  [30]->siguiente = [10]

  ¿actual ([20]) == final ([10])? NO → final no cambia

  delete [20]

Resultado: [30] → [10] → [30]  (final=[10])
```

### Caso 3: borrar el último nodo (`final`)

```
Lista: [30] → [20] → [10] → [30]  (final=[10])
Borrar 10.

anterior = [10] (final), actual = [30]  al inicio
...recorre hasta llegar a [10]...
anterior = [20], actual = [10]

actual->dato=10 = 10 → BORRAR

  anterior->siguiente = actual->siguiente
  [20]->siguiente = [30]   (el que era final->siguiente, el primero)

  ¿actual ([10]) == final ([10])? SÍ → final = anterior = [20]

  delete [10]

Resultado: [30] → [20] → [30]  (final=[20])
```

---

## `~LCircular()` — destructor

Se ejecuta **automáticamente** cuando el objeto `lista` deja de existir (al terminar `main`). Libera toda la memoria de todos los nodos.

```cpp
Nodo* primero = final->siguiente;
Nodo* actual  = primero;
Nodo* temp;
do {
    temp   = actual;        // guardar referencia antes de avanzar
    actual = actual->siguiente;
    delete temp;            // liberar el nodo
} while (actual != primero); // hasta que la vuelta se complete
final = NULL;
```

**¿Por qué guardar `temp`?**

```
Si haces: delete actual; actual = actual->siguiente;
                                  ↑
                         CRASH: actual ya fue eliminado,
                         no puedes leer su campo siguiente
```

Por eso primero guardas `temp = actual`, avanzas `actual`, y luego eliminas `temp`.

---

## Complejidad de cada operación

| Operación           | Complejidad | ¿Por qué?                     |
| ------------------- | ----------- | ----------------------------- |
| `Empty()`           | O(1)        | Solo checa si `final == NULL` |
| `InsertarInicio()`  | O(1)        | Solo redirige 2 punteros      |
| `Imprimir()`        | O(n)        | Recorre todos los nodos       |
| `Buscar()`          | O(n)        | En el peor caso recorre todos |
| `InsertarDespues()` | O(n)        | Necesita buscar primero       |
| `Borrar()`          | O(n)        | Necesita buscar el nodo       |
| `~LCircular()`      | O(n)        | Elimina todos los nodos       |

---

## Flujo completo del `main`

```
1. lista.InsertarInicio(10)
   Lista: [10]  final=[10]

2. lista.InsertarInicio(20)
   Lista: [20] → [10]  final=[10]

3. lista.InsertarInicio(30)
   Lista: [30] → [20] → [10]  final=[10]

4. lista.Imprimir()
   Salida: 30 -> 20 -> 10 -> (regresa al inicio)

5. lista.InsertarDespues(20, 99)
   Lista: [30] → [20] → [99] → [10]  final=[10]

6. lista.Imprimir()
   Salida: 30 -> 20 -> 99 -> 10 -> (regresa al inicio)

7. lista.Buscar(20)  → devuelve puntero a [20] → true → "ENCONTRADO"
   lista.Buscar(55)  → devuelve NULL           → false → "NO encontrado"

8. lista.Borrar(99)
   Lista: [30] → [20] → [10]  final=[10]

9. lista.Imprimir()
   Salida: 30 -> 20 -> 10 -> (regresa al inicio)

10. return EXIT_SUCCESS → el objeto lista muere → ~LCircular() libera [30],[20],[10]
```
