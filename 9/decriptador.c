#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    FILE* texto = fopen("message.en", "r");
    if (texto == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    
    FILE* dec = fopen("saida.txt", "w");
    if (dec == NULL) {
        perror("Error opening output file");
        fclose(texto);
        return EXIT_FAILURE;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), texto) != EOF) {
        
        fputs(buffer, dec);
    }

    fclose(texto);
    fclose(dec);
}