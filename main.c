#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "alumno.h"

#define DIM 100

int cargaAlumnos (stAlumno a[], int v, int dim);
void muestraAlumnos (stAlumno a[], int v);
stAlumno buscaMenorLegajo (stAlumno a[], int v);
int buscaPosMenorLegajo (stAlumno a[], int v);
stAlumno buscaMenorApellido (stAlumno a[], int v);
stAlumno buscaPorLegajo (stAlumno a[], int v, int legajo);
int ingresarLegajo();
void ordenarPorSeleccion (stAlumno a[], int v);
void intercambio(stAlumno *a, stAlumno *b);

int main()
{
    stAlumno alumnos [DIM];
    int vAlumnos = 0;
    stAlumno alumnoMenorApellido;
    stAlumno alumnoMenorLegajo;
    stAlumno alumnoABuscar;

    vAlumnos = cargaAlumnos (alumnos, vAlumnos, DIM);

    printf("\n Datos: \n");
    muestraAlumnos(alumnos, vAlumnos);

    alumnoMenorApellido = buscaMenorApellido(alumnos, vAlumnos);
    if (alumnoMenorApellido.legajo > -1){
            printf("\nEl alumno con menor apellido: \n");
            muestraUnAlumno(alumnoMenorApellido);
    }

    alumnoMenorLegajo = alumnos[buscaPosMenorLegajo(alumnos, vAlumnos)];
    printf("\nEl alumno con menor legajo: \n");
    muestraUnAlumno(alumnoMenorLegajo);

    getch();
    system("cls");
    int legajo = ingresarLegajo();

    alumnoABuscar = buscaPorLegajo(alumnos, vAlumnos, legajo);
    if (alumnoABuscar.legajo > -1){
            printf("\nEl alumno que corresponde al legajo %d es: \n", legajo);
            muestraUnAlumno(alumnoABuscar);
    } else {
        printf("\nNo existe alumno para ese legajo.");
    }

    getch();
    system("cls");

    stAlumno alumnosOrdenados [DIM];
    int vAlumnosOrdenados = 0;

    ordenarPorSeleccion(alumnos, vAlumnos);
    printf("\n Datos ordenados por legajo: \n");
    muestraAlumnos(alumnos, vAlumnos);


    return 0;
}

int cargaAlumnos (stAlumno a[], int v, int dim)
{
    char opcion = 0;

    while(opcion != 27 && v < dim){
        a[v] = cargaUnAlumno();
        v++;
        printf("\nESC para salir o cualquier tecla para continuar... \n");
        opcion = getch();
        system("cls");
    }

    return v;
}
void muestraAlumnos (stAlumno a[], int v)
{
    for(int i = 0; i < v; i++){
        muestraUnAlumno(a[i]);
    }
}
stAlumno buscaMenorLegajo (stAlumno a[], int v)
{
    stAlumno alumnoMenor;
    alumnoMenor.legajo = -1;
    int i = 0;
    if(v > 0){
        alumnoMenor = a[i];
        i++;
        while (i < v){
                if(a[i].legajo < alumnoMenor.legajo){
                    alumnoMenor = a[i];
                }
                i++;
        }
    }

    return alumnoMenor;
}
int buscaPosMenorLegajo (stAlumno a[], int v)
{
    int pos = 0;
    int posMenor = pos;
    pos++;
    while (pos < v){
        if (a[pos].legajo < a[posMenor].legajo){
            posMenor = pos;
        }
        pos++;
    }

    return posMenor;
}
stAlumno buscaMenorApellido (stAlumno a[], int v)
{
    stAlumno alumnoMenor;
    alumnoMenor.legajo = -1;

    int i = 0;
    if(v > 0){
        alumnoMenor = a[i];
        i++;
        while (i < v){
                if(strcmp (a[i].apellido, alumnoMenor.apellido) < 0){
                    alumnoMenor = a[i];
                }
                i++;
        }
    }

    return alumnoMenor;
}
stAlumno buscaPorLegajo (stAlumno a[], int v, int legajo)
{
    stAlumno alumnoABuscar;
    alumnoABuscar.legajo = -1;
    int i = 0;

    while (i < v){
            if(a[i].legajo = legajo){
            alumnoABuscar = a[i];
            }
            i++;
        }

    return alumnoABuscar;
}
int ingresarLegajo ()
{
    int legajo = 0;
    printf("Ingrese el numero de legajo a buscar: \n");
    scanf("%d", &legajo);
    system("cls");

    return legajo;
}
//4.Hacer una funci�n que ordene el arreglo de alumnos por medio del m�todo de selecci�n.
//El criterio de ordenaci�n es el n�mero de matr�cula.
void intercambio(stAlumno *a, stAlumno *b)
{
    stAlumno aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void ordenarPorSeleccion (stAlumno a[], int v)
{
    int posMenor;
    int i = 0;
    while(i < v -1){
            printf("%d", i);
        posMenor = buscaPosMenorLegajo(a, v);
        printf("\nantes\n");
        muestraUnAlumno(a[posMenor]);
        muestraUnAlumno(a[i]);
        intercambio(&a[posMenor], &a[i]);
        printf("\ndespues\n");
        muestraUnAlumno(a[posMenor]);
        muestraUnAlumno(a[i]);
        i++;
    }
}
