# Especificación Lógica — TDA Conjunto

Autores:

- Isaac Avila Saenz (238925)
- Héctor Alejandro Hernández Villanueva (248895)

Descripción

- Implementación del TDA `Conjunto` para elementos enteros (tipo `typeinfo` definido como `int`).
- Conjunto implementado sobre un arreglo estático con capacidad `maxCard = 10` y una cardinalidad `card` que indica el número de elementos almacenados.

Elementos

- Numerador: No aplica (este TDA es de conjuntos).
- Elemento base: `typeinfo` (definido como `int` en [Conjunto.h](Conjunto_01_2026_B/Conjunto.h)).

Estructura de datos

- Internamente: `typeinfo elementos[maxCard];` y `unsigned short int card;`.
- Capacidad máxima: `maxCard` (10).
- Representación: los `card` primeros elementos del arreglo contienen los elementos del conjunto en orden arbitrario (sin duplicados).

Dominio

- Cada elemento es un entero (`int`).
- `card` ∈ [0, maxCard].

Invariantes

- `0 ≤ card ≤ maxCard`.
- Los elementos en posiciones `[0 .. card-1]` son distintos (no hay duplicados).
- El arreglo puede contener basura fuera del rango válido, pero se ignora porque `card` limita el acceso.

Operaciones (especificación lógica y correspondencia con la implementación)

1. Constructor

- Nombre: `Conjunto()`
- Utilidad: Inicializa un conjunto vacío.
- Entrada: ninguna.
- Salida: un `Conjunto` con `card = 0`.
- Precondición: ninguna.
- Postcondición: `card == 0`.

2. Member

- Prototipo (en lógica): `bool Member(typeinfo elDato) const`
- Utilidad: Determina si `elDato` pertenece al conjunto.
- Entrada: un `typeinfo`.
- Salida: `true` si existe, `false` en caso contrario.
- Precondición: ninguna.
- Postcondición: no modifica el conjunto.
- Implementación: recorre `elementos[0..card-1]` y compara igualdad.

3. AddElem

- Prototipo: `bool AddElem(typeinfo elDato)`
- Utilidad: Añade `elDato` al conjunto si no está y hay espacio.
- Entrada: `elDato`.
- Salida: `true` si se inserta correctamente; `false` si el elemento ya existe o el conjunto está lleno.
- Precondición: ninguna (la función verifica capacidad y membresía).
- Postcondición: si retorna `true` entonces `Member(elDato)` es `true` y `card` incrementó en 1; si retorna `false` el conjunto no cambia.

4. RmvElem

- Prototipo: `bool RmvElem(typeinfo elDato)`
- Utilidad: Elimina `elDato` del conjunto si existe.
- Entrada: `elDato`.
- Salida: `true` si se eliminó; `false` si no existía.
- Precondición: ninguna.
- Postcondición: si retorna `true`, `Member(elDato)` es `false` y `card` decrementó en 1; la eliminación se realiza reemplazando el elemento eliminado por el último elemento del arreglo (`elementos[--card]`).

5. Copy

- Prototipo: `void Copy(Conjunto& otro)`
- Utilidad: Copia el contenido del argumento `otro` en el conjunto destino (`this`).
- Entrada: referencia a otro `Conjunto`.
- Salida: ninguna (efecto en el receptor).
- Precondición: ninguna (se asume que `otro.card ≤ maxCard`).
- Postcondición: `card == otro.card` y para todo i en [0..card-1] `elementos[i] == otro.elementos[i]`.

6. Equal

- Prototipo: `bool Equal(Conjunto otro)`
- Utilidad: Indica si dos conjuntos contienen exactamente los mismos elementos (orden no importa).
- Entrada: otro `Conjunto` (por valor en la implementación actual).
- Salida: `true` si los conjuntos son iguales; `false` en caso contrario.
- Precondición: ninguna.
- Postcondición: no modifica los conjuntos.
- Implementación: compara `card` y verifica que cada elemento del primer conjunto pertenezca al segundo.

7. Print

- Prototipo: `bool Print()`
- Utilidad: Muestra el contenido del conjunto en el formato `{ a, b, c }`.
- Entrada: el conjunto implícito (`this`).
- Salida: `true` si tiene elementos y muestra la representación; `false` si está vacío (muestra `{ }`).
- Precondición: ninguna.
- Postcondición: no modifica el conjunto.

8. Intersect

- Prototipo: `void Intersect(const Conjunto Conj2, Conjunto& Result)`
- Utilidad: Calcula la intersección `Result = this ∩ Conj2`.
- Entrada: otro `Conjunto` (`Conj2`) y un `Conjunto& Result` para almacenar el resultado.
- Salida: `Result` modificado con la intersección.
- Precondición: `Result` tiene capacidad `maxCard` suficiente para contener la intersección (siempre true porque maxCard es el mismo).
- Postcondición: `Result` contiene sólo los elementos comunes a ambos conjuntos.
- Implementación: recorre `elementos[0..card-1]` y añade a `Result` los elementos que `Conj2.Member(...)` confirme.

9. Union

- Prototipo: `bool Union(Conjunto Conj2, Conjunto& Result)`
- Utilidad: Calcula la unión `Result = this ∪ Conj2`.
- Entrada: otro `Conjunto` y `Result` por referencia.
- Salida: `true` (implementación actual siempre retorna `true`).
- Precondición: la unión debe caber en `Result` (si la suma de cardinalidades excede `maxCard` algunos elementos no pueden añadirse; la implementación no comprueba de forma explícita ese caso aparte de `AddElem`).
- Postcondición: `Result` contiene todos los elementos que aparecen en al menos uno de los conjuntos.
- Implementación: copia `*this` a `Result` y luego añade aquellos elementos de `Conj2` que no estén ya presentes.

Complejidad (costes aproximados)

- `Member`: O(card) (búsqueda lineal).
- `AddElem`: O(card) por la comprobación `Member`, más O(1) para insertar.
- `RmvElem`: O(card) para localizar y eliminar.
- `Copy`: O(card_dest)` (copia de arreglo).
- `Equal`: O(card \* card') en el peor caso (cada elemento se busca en el otro conjunto).
- `Intersect`/`Union`: O(card \* card2)`por búsquedas repetidas con`Member`.

Notas de implementación y recomendaciones

- Actualmente `Conjunto.cpp` está incluido desde `main.cpp` mediante `#include "Conjunto.cpp"`. Es preferible compilar `Conjunto.cpp` por separado y enlazar objetos, por ejemplo:

```sh
# Compilar por separado
g++ -c Conjunto_01_2026_B/Conjunto.cpp -o Conjunto_01_2026_B/Conjunto.o
g++ -c Conjunto_01_2026_B/main.cpp -o Conjunto_01_2026_B/main.o
g++ Conjunto_01_2026_B/main.o Conjunto_01_2026_B/Conjunto.o -o Conjunto_01_2026_B/main
```

- `Equal` recibe el argumento por valor; para evitar copias innecesarias, es mejor recibirlo por `const Conjunto&`.
- `Print` devuelve `bool` indicando si imprimió o no; típicamente `void` sería suficiente, pero la implementación actual usa `bool` para indicar si estaba vacío.

Archivos relevantes

- [Conjunto.h](Conjunto_01_2026_B/Conjunto.h)
- [Conjunto.cpp](Conjunto_01_2026_B/Conjunto.cpp)
- [main.cpp](Conjunto_01_2026_B/main.cpp)

Ejemplo de uso

1. Ejecutar el binario y usar el menú interactivo para insertar y operar con conjuntos.
2. Operación típica: seleccionar `1) AddElem`, elegir `Conjunto1`, introducir `5`, comprobar `C1: { 5 }`.

Cambio realizado

- Esta especificación lógica adapta la estructura del TDA Racional que suministraste a la implementación real del TDA `Conjunto` presente en esta práctica.

---

Generado automáticamente para la práctica `Conjunto_01_2026_B`.
