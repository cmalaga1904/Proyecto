#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct Estudiante {
    char nombre[50];
    int codigo;
    float nota;
    struct Estudiante* siguiente;
} Estudiante;

Estudiante* crearEstudiante(char* nombre, int codigo, float nota) {
    Estudiante* nuevo = (Estudiante*)malloc(sizeof(Estudiante));
    strcpy(nuevo->nombre, nombre);
    nuevo->codigo = codigo;
    nuevo->nota = nota;
    nuevo->siguiente = NULL;
    return nuevo;
}
void agregarEstudiante(Estudiante** cabeza) {
    char nombre[50];
    int codigo;
    float nota;

    printf("Ingrese el primer nombre del estudiante: ");
    scanf("%s", nombre);
    printf("Ingrese el código estudiantil: ");
    scanf("%d", &codigo);
    printf("Ingrese la nota del estudiante: ");
    scanf("%f", &nota);

    Estudiante* nuevo = crearEstudiante(nombre, codigo, nota);
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}
    void ordenarPorCodigo(Estudiante** cabeza) {
    int swapped;
    Estudiante *ptr1;
    Estudiante *lptr = NULL;

    if (*cabeza == NULL) return;

    do {
        swapped = 0;
        ptr1 = *cabeza;

        while (ptr1->siguiente != lptr) {
            if (ptr1->codigo > ptr1->siguiente->codigo) {
                int tempCodigo = ptr1->codigo;
                ptr1->codigo = ptr1->siguiente->codigo;
                ptr1->siguiente->codigo = tempCodigo;

                float tempNota = ptr1->nota;
                ptr1->nota = ptr1->siguiente->nota;
                ptr1->siguiente->nota = tempNota;

                char tempNombre[50];
                strcpy(tempNombre, ptr1->nombre);
                strcpy(ptr1->nombre, ptr1->siguiente->nombre);
                strcpy(ptr1->siguiente->nombre, tempNombre);

                swapped = 1;
            }
            ptr1 = ptr1->siguiente;
        }
        lptr = ptr1;
    } while (swapped);
}

void ordenarPorNota(Estudiante** cabeza) {
    int swapped;
    Estudiante *ptr1;
    Estudiante *lptr = NULL;

    if (*cabeza == NULL) return;

    do {
        swapped = 0;
        ptr1 = *cabeza;

        while (ptr1->siguiente != lptr) {
            if (ptr1->nota < ptr1->siguiente->nota) {
                // Intercambiar la nota
                float tempNota = ptr1->nota;
                ptr1->nota = ptr1->siguiente->nota;
                ptr1->siguiente->nota = tempNota;

                // Intercambiar el código
                int tempCodigo = ptr1->codigo;
                ptr1->codigo = ptr1->siguiente->codigo;
                ptr1->siguiente->codigo = tempCodigo;

                // Intercambiar el nombre
                char tempNombre[50];
                strcpy(tempNombre, ptr1->nombre);
                strcpy(ptr1->nombre, ptr1->siguiente->nombre);
                strcpy(ptr1->siguiente->nombre, tempNombre);

                swapped = 1;
            }
            ptr1 = ptr1->siguiente;
        }
        lptr = ptr1;
    } while (swapped);
}
void mayorNota(Estudiante* cabeza) {
    if (cabeza == NULL) return;

    Estudiante* maxEstudiante = cabeza;
    Estudiante* temp = cabeza;

    while (temp != NULL) {
        if (temp->nota > maxEstudiante->nota) {
            maxEstudiante = temp;
        }
        temp = temp->siguiente;
    }

    printf("Estudiante con la mayor nota: %s, Código: %d, Nota: %.2f\n", maxEstudiante->nombre, maxEstudiante->codigo, maxEstudiante->nota);
}

void menorNota(Estudiante* cabeza) {
    if (cabeza == NULL) return;

    Estudiante* minEstudiante = cabeza;
    Estudiante* temp = cabeza;

    while (temp != NULL) {
        if (temp->nota < minEstudiante->nota) {
            minEstudiante = temp;
        }
        temp = temp->siguiente;
    }

    printf("Estudiante con la menor nota: %s, Código: %d, Nota: %.2f\n", minEstudiante->nombre, minEstudiante->codigo, minEstudiante->nota);
}

void promedioNotas(Estudiante* cabeza) {
    if (cabeza == NULL) return;

    int totalEstudiantes = 0;
    float sumaNotas = 0;
    Estudiante* temp = cabeza;

    while (temp != NULL) {
        sumaNotas += temp->nota;
        totalEstudiantes++;
        temp = temp->siguiente;
    }

    float promedio = sumaNotas / totalEstudiantes;
    printf("Promedio de notas del curso: %.2f\n", promedio);
}
void menu(Estudiante** cabeza) {
    int opcion;
    do {
        printf("\nMenu:\n");
        printf("1. Ingresar datos de estudiantes\n");
        printf("2. Ordenar por código estudiantil\n");
        printf("3. Ordenar por nota\n");
        printf("4. Mostrar mayor, menor nota y promedio\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarEstudiante(cabeza);
                break;
            case 2:
                ordenarPorCodigo(cabeza);
                break;
            case 3:
                ordenarPorNota(cabeza);
                break;
            case 4:
                mayorNota(*cabeza);
                menorNota(*cabeza);
                promedioNotas(*cabeza);
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 5);
}

int main() {
    Estudiante* cabeza = NULL;
    menu(&cabeza);
    return 0;
}