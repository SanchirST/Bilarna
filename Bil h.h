#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define AGE 10
#define MAX 10
#define NAME 30
#define REG 10
#define NOLL 0
#define TRUE 1
#define VAL 3

typedef struct person{
    char firstname[NAME];
    char lastname[NAME];
    int age;
}person;

typedef struct fordon{
    char type[MAX];
    char brand[MAX];
    char plate[REG];
    person p;
}fordon;

void READLINE(char*string, int size);
void ADD(fordon*lista, int *count);
void DEL(fordon*lista, int *count);
void SORT(fordon*lista, int *count);
void FIND(fordon*lista, int *count);
void PRINT(fordon*lista, int *count);
void file_startup(fordon* lista, int *count);
void file_shutdown(fordon* lista, int *count);