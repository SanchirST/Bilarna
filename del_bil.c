#include "Bil.h"

//**********************INPUT*****************************
void READLINE(char*string, int size){
  
  fgets(string, size, stdin);
  if(string[strlen(string)-1] == '\n'){
    string[strlen(string) - 1] = NOLL;
  }
  return;
}

//**********************ADD*******************************
void ADD(fordon* lista, int *count) {
    
    printf("----------------------------------------------\n");
    printf("Ange fordon typ:");
    READLINE(lista[*count].type, NAME);
    
    printf("Ange fordon märke:");
    READLINE(lista[*count].brand, NAME);

    printf("Ange fordon register:");
    READLINE(lista[*count].plate, NAME);
    
    printf("Ange ägare förnamn:");
    READLINE(lista[*count].p.firstname, NAME);
    
    printf("Ange ägare efternamn:");
    READLINE(lista[*count].p.lastname, NAME);
 
    char temp[AGE];
    printf("Ange ägare ålder:");
    READLINE(temp, AGE);
    lista[*count].p.age = atoi(temp);

    printf("----------------------------------------------\n");
    printf("\n");
    
    return;
    
}
//**********************DEL********************************
void DEL(fordon* lista, int *count){
    
    int m;
    char radera[VAL];
    
    printf("--------------------------------------------------------\n");
    printf("Vilken fordon vill du tabort: ");
    READLINE(radera, VAL);
    
    m=atoi(radera);
    
    if ( m < 1 || m > *count) {
        printf("--------------------------------------------------------\n");
        perror("Ogiltigt val. Ange ett giltigt fordon att ta bort.\n");
        printf("--------------------------------------------------------\n");
        return;
    }
    
    for (int i = m - 1; i < *count - 1; i++) {
        lista[i] = lista[i + 1];
    }
    
    *count = *count - 1;
    printf("Fordonet har tagits bort.\n");
    printf("---------------------------------------------------------\n");
    printf("\n");
}
//*********************SORT*********************************
void SORT(fordon* lista, int *count){
  int stopp = NOLL;
  fordon swap;
    
  for(int v = NOLL; v < *count; v++)
  {
    for(int w = NOLL; w < *count - 1; w++)
    {
      if(strcmp(lista[w].brand,lista[w+1].brand) > NOLL)
      {
        swap = lista[w+1];
        lista[w+1] = lista[w];
        lista[w] = swap;
        stopp = TRUE;
      }
    }

     if(stopp == NOLL)
     {
       break;
     }
  }
    printf("-----------------------------------\n");
    printf("Sorterad!\n");
    printf("------------------------------------\n");
    printf("\n");
}
//*********************FIND*********************************
void FIND(fordon* lista, int *count){
    
    char find[VAL];
    
    printf("Vilken fordon vill du söka efter?\n");
    printf("Ditt val: ");
    READLINE( find, VAL);
    
    int finding = atoi(find);
    
    if(finding >*count || finding < 1){
        printf("---------------------------------------------\n");
        printf("Finns ingen fordon i detta postion\n");
        printf("-----------------------------------------------\n");
    } else {
        printf("----------------------------------------------------\n");
        printf("Namn: %s ",lista[finding-1].p.firstname);
        printf("%s\n",lista[finding-1].p.lastname);
        printf("Ålder: %d\n", lista[finding-1].p.age);
        printf("Fordonstyp: %s\n",lista[finding-1].type);
        printf("Märke: %s\n",lista[finding-1].brand);
        printf("Registreringsnummer: %s\n",lista[finding-1].plate);
        printf("-----------------------------------------------------\n");
  }
}
//*********************PRINT*********************************
void PRINT(fordon*lista,int *count) {
    
    for (int l = NOLL; l < *count; l++) {
        printf("----------------------------------------\n");
        printf("Registrerade fordon\n");
        printf("ID %d\n", l + 1 );
        printf("Ägare: %s ", lista[l].p.firstname);
        printf("%s\n", lista[l].p.lastname);
        printf("Ålder: %d\n", lista[l].p.age);
        printf("Typ: %s\n", lista[l].type);
        printf("Märke: %s\n", lista[l].brand);
        printf("Register: %s\n", lista[l].plate);
        printf("------------------------------------\n");
    printf("\n");
        
    }
}
//*******************START**********************************
void file_startup(fordon* lista, int *count) {
    // Kontrollerar om "Bilregister.txt" tillgängligt
    if (access("Bilregister.txt", F_OK) != 0) {
        for (int i = 0; i < MAX; i++) {
            strcpy(lista[i].type, "empty");
            strcpy(lista[i].brand, "empty");
            strcpy(lista[i].plate, "empty");
            strcpy(lista[i].p.firstname, "empty");
            strcpy(lista[i].p.lastname, "empty");
            lista[i].p.age = 0;
        }

        FILE *pF = fopen("Bilregister.txt", "w");
        if (pF == NULL) {
            printf("Could not open Bilregister.txt");
            return;
        }
        for (int i = 0; i < MAX; i++) {
            fprintf(pF, "%s\n", lista[i].type);
            fprintf(pF, "%s\n", lista[i].brand);
            fprintf(pF, "%s\n", lista[i].plate);
            fprintf(pF, "%s\n", lista[i].p.firstname);
            fprintf(pF, "%s\n", lista[i].p.lastname);
            fprintf(pF, "%d\n", lista[i].p.age);
            fprintf(pF, "\n");
        }
        fclose(pF);
        printf("Registry file not found! Empty registry created\n");
    } else {
        FILE *pF = fopen("Bilregister.txt", "r");
        if (pF == NULL) {
            printf("Could not open Bilregister.txt\n");
            return;
        }
        int i = 0;
        while (fscanf(pF, "%s", lista[i].type) != EOF) {
            fscanf(pF, "%s", lista[i].brand);
            fscanf(pF, "%s", lista[i].plate);
            fscanf(pF, "%s", lista[i].p.firstname);
            fscanf(pF, "%s", lista[i].p.lastname);
            fscanf(pF, "%d", &lista[i].p.age);
            fscanf(pF, "\n");
            i++;
        }
        fclose(pF);
        *count = i;
        printf("Registry file successfully imported!\n");
    }
}

//***********************AVSLUTA*************************************
void file_shutdown(fordon* lista, int *count) {
    FILE *pF = fopen("Bilregister.txt", "w");
    if (pF == NULL) {
        printf("Could not open Bilregister.txt to save changes\n");
        return;
    } else {
        for (int i = 0; i < *count; i++) {
            fprintf(pF, "%s\n", lista[i].type);
            fprintf(pF, "%s\n", lista[i].brand);
            fprintf(pF, "%s\n", lista[i].plate);
            fprintf(pF, "%s\n", lista[i].p.firstname);
            fprintf(pF, "%s\n", lista[i].p.lastname);
            fprintf(pF, "%d\n", lista[i].p.age);
            fprintf(pF, "\n");
        }
        fclose(pF);
        printf("Registry saved!\n");
    }
}