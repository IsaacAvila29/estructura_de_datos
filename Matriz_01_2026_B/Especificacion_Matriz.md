# Especificación Lógica del TDA Matriz

## Integrantes

- Isaac Avila Saenz (238925)
- Héctor Alejandro Hernández Villanueva (248895)

## Elementos

- **Fila**: Int (número de filas)
- **Columna**: Int (número de columnas)
- **Matriz**: Array bidimensional de Int (datos almacenados)

## Estructura

- Sin relación con otros tipos de datos
- Estructura bidimensional de datos

## Dominio

- Los valores de fila y columna son enteros positivos
- El rango máximo es 10 filas × 10 columnas
- Los elementos de la matriz son valores enteros en el rango [0, 9] (después del llenado aleatorio)
- Fila > 0 y Columna > 0

## Invariante

- El número de filas debe ser mayor a cero
- El número de columnas debe ser mayor a cero
- El número de filas no debe exceder 10
- El número de columnas no debe exceder 10
- La matriz se representa como un arreglo de [fila][columna]

## Operaciones

### Constructor

- **Utilidad**: Inicializa la matriz con dimensiones especificadas
- **Entrada**: Dos valores enteros (filas, columnas)
- **Salida**: Una matriz inicializada
- **Precondición**:
  - filas > 0 y columnas > 0
  - filas ≤ 10 y columnas ≤ 10
- **Postcondición**:
  - La matriz tiene las dimensiones especificadas
  - Los valores se llenan automáticamente con números aleatorios [0, 9]

### llenarMatriz

- **Utilidad**: Llena la matriz con valores aleatorios
- **Entrada**: Ninguna (utiliza el estado actual)
- **Salida**: Ninguna (modifica el estado interno)
- **Precondición**:
  - La matriz debe estar inicializada con dimensiones válidas
  - fila ≤ 10 y columna ≤ 10
- **Postcondición**:
  - Todos los elementos de la matriz contienen valores entre 0 y 9
  - El estado de fila y columna se mantiene

### SumarMatriz

- **Utilidad**: Suma dos matrices
- **Entrada**: Dos matrices (la actual y otra matriz, más una matriz resultado)
- **Salida**: Un booleano (true si la suma es posible, false en caso contrario)
- **Precondición**:
  - Ambas matrices deben estar inicializadas
  - Ambas matrices deben tener las mismas dimensiones (fila y columna)
- **Postcondición**:
  - Las matrices de entrada conservan sus valores
  - La matriz resultado contiene los elementos sumados
  - Si las dimensiones no coinciden, la función retorna false y el resultado no se modifica

### RestarMatriz

- **Utilidad**: Resta dos matrices
- **Entrada**: Dos matrices (la actual y otra matriz, más una matriz resultado)
- **Salida**: Un booleano (true si la resta es posible, false en caso contrario)
- **Precondición**:
  - Ambas matrices deben estar inicializadas
  - Ambas matrices deben tener las mismas dimensiones (fila y columna)
- **Postcondición**:
  - Las matrices de entrada conservan sus valores
  - La matriz resultado contiene los elementos restados (M1 - M2)
  - Si las dimensiones no coinciden, la función retorna false y el resultado no se modifica

### Multiplicar

- **Utilidad**: Multiplica dos matrices
- **Entrada**: Dos matrices (la actual y otra matriz, más una matriz resultado)
- **Salida**: Un booleano (true si la multiplicación es posible, false en caso contrario)
- **Precondición**:
  - Ambas matrices deben estar inicializadas
  - El número de columnas de la primera matriz debe ser igual al número de filas de la segunda matriz
  - columna_M1 == fila_M2
- **Postcondición**:
  - Las matrices de entrada conservan sus valores
  - La matriz resultado tiene dimensiones (fila_M1 × columna_M2)
  - Cada elemento de la matriz resultado es la suma del producto de filas por columnas
  - Si las dimensiones son incompatibles, la función retorna false y el resultado no se modifica

### Imprimir

- **Utilidad**: Mostrar la matriz en formato fila × columna en pantalla
- **Entrada**: Una matriz
- **Salida**: Representación en pantalla de la matriz
- **Precondición**:
  - La matriz debe estar inicializada
  - fila > 0 y columna > 0
- **Postcondición**:
  - No modifica el estado del objeto
  - Los elementos se muestran separados por espacios
  - Cada fila se imprime en una línea diferente
