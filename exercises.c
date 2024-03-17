#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/
int findMax(int arr[], int size) 
{     
  int max = arr[0];
  for (int i = 1; i < size; i++)
    {
      if (arr[i] > max)
      {
        max = arr[i];
      }
    }
  return max; 
}

/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int arr[], int size) 
{
  int i, temp;
  for (i = 0; i < size / 2; i++)
     {
       temp = arr[i];
       arr[i] = arr[size - 1 - i];
       arr[size - 1 - i] = temp;
     }
}

/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
*/
int *filterEvenNumbers(int arr[], int size, int *newSize) 
{
    int pares = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            pares++;
        }
    }

    int *arrpares = (int *)malloc(pares * sizeof(int));
    if (arrpares == NULL) exit(EXIT_FAILURE);
    
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            arrpares[index] = arr[i];
            index++;
        }
    }

    *newSize = pares; 
    return arrpares;
}

/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado.
*/
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int result[]) 
{
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) 
    {
        if (arr1[i] <= arr2[j]) 
        {
            result[k] = arr1[i];
            i++;
        } else 
        {
            result[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < size1) 
    {
        result[k] = arr1[i];
        i++;
        k++;
    }

    while (j < size2) 
    {
        result[k] = arr2[j];
        j++;
        k++;
    }
}


/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/
int checkSorted(int arr[], int size) 
{
    int asc = 1, desc = 1;

    for (int i = 0; i < size - 1; i++) 
    {
        if (arr[i] > arr[i + 1]) 
        {
            asc = 0;
            break;
        }
    }

    for (int i = 0; i < size - 1; i++) 
    {
        if (arr[i] < arr[i + 1]) 
        {
            desc = 0;
            break;
        }
    }

    if (asc) 
    {
        return 1; // Orden ascendente
    } else if (desc) {
        return -1; // Orden descendente
    } else {
        return 0; // No ordenado
    }
}

/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.
*/

typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;
  int anioPublicacion;
} Libro;

void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor, int anioNacimiento, int anioPublicacion) 
{
    // Copiar el título del libro
    strcpy(libro->titulo, titulo);

    // Copiar el nombre del autor del libro
    strcpy(libro->autor.nombre, nombreAutor);

    // Asignar el año de nacimiento del autor
    libro->autor.anioNacimiento = anioNacimiento;

    // Asignar el año de publicación del libro
    libro->anioPublicacion = anioPublicacion;
}

/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
  */

typedef struct nodo {
  int numero;
  struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;

Nodo *crearListaEnlazada(int arr[], int size) 
{
    Nodo *primero = NULL; // Inicializamos el puntero al primer nodo como NULL
    Nodo *actual = NULL; // Creamos un puntero auxiliar

    // Recorremos el arreglo para crear los nodos
    for (int i = 0; i < size; i++) {
        // Creamos un nuevo nodo
        Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
        if (nuevoNodo == NULL) exit(EXIT_FAILURE);
        // Asignamos el valor del número del arreglo al nuevo nodo
        nuevoNodo->numero = arr[i];
        // El siguiente del nuevo nodo será el actual cabeza de la lista
        nuevoNodo->siguiente = NULL;

        // Si la lista está vacía, el nuevo nodo será el primer nodo
        if (primero == NULL) {
            primero = nuevoNodo;
        } else {
            // Si la lista no está vacía, el siguiente del nodo actual será el nuevo nodo
            actual->siguiente = nuevoNodo;
        }
        // Actualizamos el puntero auxiliar para apuntar al nuevo nodo
        actual = nuevoNodo;
    }

    // Devolvemos el puntero al primer nodo de la lista
    return primero;
}
