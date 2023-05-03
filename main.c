#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int cargarArreglo(int arreglo[], int dim);
int validacion(int nota);
int pasarPila(Pila *pila1, int arreglo[], int validos);
int buscarMayorNota(int arreglo[], int validos);
void pasarPila2(Pila *A, Pila *B);
int pasarArreglo(Pila *pilaB, int arreglo[], int dim);
int main()
{

    int arreglo[99];
    int arregloPila[99];
    int validos;
    int mayorNota;
    Pila pila1, aux, aux2;
    inicpila(&pila1);
    inicpila(&aux);
    inicpila(&aux2);



//    validos = cargarArreglo(arreglo, 99);
//    mostrarArreglo(arreglo, validos);

//    pasarPila(&pila1, arreglo, validos);
//    printf("\n DESAPROBADOS: \n");
//    mostrar(&pila1);

//    mayorNota = buscarMayorNota(arreglo, validos);
//    printf("La nota mayor es: %d", mayorNota);

    pasarPila2(&aux, &aux2);
    mostrar(&aux2);
    validos = pasarArreglo(&aux2, arregloPila, 99);
    mostrarArreglo(arregloPila, validos);
    mostrar(&aux2);
}

int cargarArreglo(int arreglo[], int dim)
{

    int i = 0;
    char letra = 's';
    int flag = 0;
    int num;


    while(letra == 's' && i<dim)
    {

        printf("Ingrese su nota c:  ");
        fflush(stdin);
        scanf("%i", &num );

        flag = validacion(num);

        if (flag == 1)
        {

            printf("La nota fue ingresada\n");
            arreglo[i] = num;

            printf("Presiona 's' para continuar");
            fflush(stdin);
            scanf("%c", &letra);

            i++;

        }
        else
        {

            printf("La nota que ingresaste no es valida\n");

        }

    }

    return i;
}

int validacion(int nota)
{

    int flag;

    if (nota >= 0 && nota<=10)
    {

        flag = 1;

    }
    else
    {

        flag = 0;

    }
    return flag;
}

void mostrarArreglo(int arreglo[], int cantidad)
{

    int i = 0;

    while(i<cantidad)
    {

        printf("| %i |", arreglo[i]);

        i++;
    }

}

int pasarPila(Pila *pila1, int arreglo[], int validos)
{

    Pila pila2,aux;
    inicpila(&pila2);
    inicpila(&aux);

    int aux2;
    int i = 0;

    while(i<validos)
    {

        aux2 = arreglo[i];

        if(aux2 <= 5)
        {

            apilar(pila1, aux2);

        }
        else
        {

            apilar(&pila2, aux2);
        }

        i++;

    }
    printf("\n APROBADOS:\n");
    mostrar(&pila2);
}

int buscarMayorNota(int arreglo[], int validos)
{

    int i = validos-1;
    int mayor = 0;
    while(i > 0)
    {



        if(mayor < arreglo[i])
        {

            mayor = arreglo[i];

        }

        i--;

    }

    return mayor;
}



void pasarPila2(Pila *A, Pila *B)
{

    Pila C;
    inicpila(&C);
    int num;
    char letra = 's';

    while(letra == 's')
    {

        printf("Ingresa el dato a la pila");
        fflush(stdin);
        scanf("%d", &num);

        if(num%2 == 0 && num%10 != 0)
        {

            apilar(B, num);

        }
        else if(num%10 == 0)
        {

            apilar(A, num);

        }
        else
        {

            apilar(&C, num);

        }

        printf("Presiona 's' para continuar");
        fflush(stdin);
        scanf("%c", &letra);
    }

//    mostrar(A);
//    mostrar(B);
//    mostrar(&C);
}

int pasarArreglo(Pila *B, int arreglo[], int dim)
{

    Pila aux,aux2;
    inicpila(&aux);
    inicpila(&aux2);

    int i = 0;

    while(i<dim && !pilavacia(B)    )
    {
        if(tope(B) >= 4 && tope(B) <= 48 )
        {

            arreglo[i] = tope(B);
            apilar(&aux,desapilar(B));
            i++;
        }
        else
        {

            apilar(&aux, desapilar(B));

        }
    }

    while (!pilavacia(&aux))
    {
        apilar(B,desapilar(&aux));
    }
    return i;
}
