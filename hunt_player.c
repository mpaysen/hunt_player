#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void printBanner() {
    printf("                   _       _________      _______           _______           ______   _______           _       \n");
    printf("|\\     /||\\     /|( (    /|\\__   __/     (  ____ \\|\\     /|(  ___  )|\\     /|(  __  \\ (  ___  )|\\     /|( (    /|\n");
    printf("| )   ( || )   ( ||  \\  ( |   ) (    _   | (    \\/| )   ( || (   ) || )   ( || (  \\  )| (   ) || )   ( ||  \\  ( |\n");
    printf("| (___) || |   | ||   \\ | |   | |   (_)  | (_____ | (___) || |   | || | _ | || |   ) || |   | || | _ | ||   \\ | |\n");
    printf("|  ___  || |   | || (\\ \\) |   | |        (_____  )|  ___  || |   | || |( )| || |   | || |   | || |( )| || (\\ \\) |\n");
    printf("| (   ) || |   | || | \\   |   | |    _         ) || (   ) || |   | || || || || |   ) || |   | || || || || | \\   |\n");
    printf("| )   ( || (___) || )  \\  |   | |   (_)  /\\____) || )   ( || (___) || () () || (__/  )| (___) || () () || )  \\  |\n");
    printf("|/     \\|(_______)|/    )_)   )_(        \\_______)|/     \\|(_______)(_______)(______/ (_______)(_______)|/    )_)\n");
    printf("\n");
}

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void shuffleArray(char **array, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = getRandomNumber(0, i);
        char *temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int isNameInList(char **array, int size, char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(array[i], name) == 0) {
            return 1;
        }
    }
    return 0; 
}

int main() {
    srand(time(NULL));

    printBanner();

    int n;
    printf("Geben Sie die Anzahl der Namen ein: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Ungültige Eingabe für die Anzahl der Namen.\n");
        return 1; 
    }

    char **names = (char **)malloc(n * sizeof(char *));

    printf("Geben Sie die Namen ein:\n");
    for (int i = 0; i < n; i++) {
        names[i] = (char *)malloc(100 * sizeof(char));

        do {
            scanf("%s", names[i]);

            
            if (isNameInList(names, i, names[i])) {
                printf("Der Name ist bereits vorhanden. Bitte geben Sie einen anderen Namen ein.\n");
            }
        } while (isNameInList(names, i, names[i]));
    }

    int repeat;
    do {
        
        shuffleArray(names, n);

        
        int groupSize;
        printf("Geben Sie die Größe der Gruppen ein: ");
        scanf("%d", &groupSize);

        printf("\nErgebnis:\n");

        int remaining = n;
        for (int i = 0; i < n; i += groupSize) {
            printf("Gruppe:");
            for (int j = i; j < i + groupSize && j < n; j++) {
                printf(" %s", names[j]);
            }
            printf("\n");
            remaining -= groupSize;
        }

        
        printf("\nMöchten Sie die Namen erneut mischen? (1 für Ja, 0 für Nein): ");
        scanf("%d", &repeat);

    } while (repeat);

    for (int i = 0; i < n; i++) {
        free(names[i]);
    }
    free(names);

    return 0;
}
