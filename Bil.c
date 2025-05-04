#include "Bil.h"

int main(){
    
        int count = NOLL;
        fordon lista[MAX];
        file_startup(lista, &count);
        int h;
        int val;
    
    while(1){
        printf("1.Lägg till Fordon\n");
        printf("2.Tabort Fordon\n");
        printf("3.Sortera Fordon\n");
        printf("4.Sök efter Fordon\n");
        printf("5.Visa alla Fordon\n");
        printf("0.Avsluta\n");
        while(scanf("%d", &val) != 1){
            
            system("clear");
            scanf("%*s");
            printf("-------------------------------\n");
            printf("ERROR\n");
        printf("1.Lägg till Fordon\n");
        printf("2.Tabort Fordon\n");
        printf("3.Sortera Fordon\n");
        printf("4.Sök efter Fordon\n");
        printf("5.Visa alla Fordon\n");
        printf("0.Avsluta\n");
            
        }
        getchar();
    
        switch(val){
                
        case 1:
            if(count==MAX){
                printf("Fordonsregistret är fullt\n");
                break;
           }
            ADD(lista, &count);
            if(lista[count].p.age == 0){
                printf("Kontrollera ålder!\n");
                count = count-1;
            }
            count++;
            break;
        case 2:
            DEL(lista, &count);
            break;
        case 3:
            SORT(lista, &count);
            break;
        case 4:
            FIND(lista, &count);
            break;
        case 5:
            PRINT(lista, &count);
            break;
        case 0:
            while(0);
            file_shutdown(lista, &count);
            return 0;
            
        default:
            printf("Ange mellan 1-5 och 0 för att avsluta\n");
            break;
    }
    }
    return NOLL;
}