#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

char *permuta(const char *str, int tam);

int main(){
    FILE* texto = fopen("key_for_rsa_public.hash", "r");
    if (texto == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    
    char hash[45];

    
    fread(hash, 1, 45, texto);
    hash[44] = '\0'; 
    
    printf("Hash: %s\n", hash);
    fclose(texto);
    char dec[8]; 
    int encontrada = 0;
    int tam = 1;


    while (encontrada == 0)
    {
        for (int i = 0; i < tam; i++){
            //dec = strcat("za", permuta("0123456789abcdefghijklmnopqrstuvwxyz", tam));
            }         
        }       

        

        tam++;

}


char *permuta(const char *str, int tam){
    int *num = (int *) calloc(tam+1 , sizeof(int));
    //char tdper[7];
    char *resultado = (char *) malloc(tam * sizeof(char));
    int len = strlen(str);
    int k = tam - 1;

    if (resultado == NULL) {
        perror("Erro ao alocar memoria");
        exit(EXIT_FAILURE);
    }

    while(num[tam] == 0){
        for (int i = 0; i < len; i++){
            for(int j = 0; j < tam; j++){
                resultado[k] = str[num[j]]; 
                k--;
            }

            resultado[tam] = 0;
            printf("%s\n", resultado);

            num[0]++;
        }
    for ( int i = 0; i < tam; i++ ) {
        if ( num[i] == 36 ) {
            num[i] = 0 ;
            num[i+1]++ ;
        }
    }
    }

    return *resultado;
}


