#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista()
{
   List* L = create_list();

   int X; // limitador

   for (X = 0 ; X <= 10 ; X++)
   {
      int *ptr_a_elemento = malloc(sizeof(int)); // Puntero que el cual almacenara la lista
      *ptr_a_elemento = X;
      pushBack(L , ptr_a_elemento);
   }
   
   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L)
{
   
   int Z, sumatoria = 0; // Variables necesarias
   int *dato = first(L); // Primer dato

   for(Z = 0 ; Z < get_size(L) ; Z++)
   {
      sumatoria += *dato;
      dato = next(L); // Siguiente dato hasta que no haya mas
   }
   
   return sumatoria;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List *L, int elem)
{

   int *dato = first(L);

   while (dato != NULL)
   {
      if (*dato == elem)
      {
         popCurrent(L);
      }
      dato = next(L);
   }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2)
{
   
   Stack *Aux = create_stack();
   
   void *Elemento;
   
   while ((Elemento = pop(P1)) != NULL)
   {
      push(Aux, Elemento);
   }
   
   while((Elemento = pop(Aux)) != NULL)
   {
      push(P1, Elemento);
      push(P2, Elemento);
   }
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena)
{
   Stack *Pila = create_stack();
   int H;
   char *temp;
   
   for (H = 0 ; cadena[H] != '\0' ; H++)
   {
      if(cadena[H] == 40 || cadena[H] == 91 || cadena[H] == 123)
      {
         char *temp = malloc(sizeof(char));
         *temp = cadena[H];
         
         push(Pila,temp);
      }
      else if(cadena[H] == 41 || cadena[H] == 93 || cadena[H] == 125)
      {
         char *temp = top(Pila);
         if (temp == NULL) return 0;

         if((cadena[H] == 41 && *temp != 40) || (cadena[H] == 93 && *temp != 91) || (cadena[H] == 125 && *temp != 123))
            return 0;
      }
      pop(Pila);
      free(temp);
   }
   
   if (top(Pila) == NULL) return 1;
   
   return 0;
}

