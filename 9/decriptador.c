#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

void permuta(const char *str, int tam, int bytes, int *flag);

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
    int bytes = sizeof(*hash);

    while (encontrada == 0)
    {
        for (int i = 0; i < tam; i++){
            permuta("0123456789abcdefghijklmnopqrstuvwxyz", tam, bytes, &encontrada);
            }   
            tam++;
            if(tam == 3){
                encontrada = 1;
            }      
        }
    return 0;       
}


void permuta(const char *str, int tam, int bytes, int *flag){
    int len = strlen(str);
    int *num = (int *) calloc(36 , sizeof(int));
    //char tdper[7];
    char *resultado = (char *) malloc(tam * sizeof(char));

    if (resultado == NULL) {
        perror("Erro ao alocar memoria");
        exit(EXIT_FAILURE);
    }

    while(num[tam] == 0){
        for (int i = 0; i < len; i++){
            
            int k = tam - 1;

            for(int j = 0; j < len; j++){
                resultado[k] = str[num[j]]; 
                k--;
            }

            resultado[tam] = 0;
            char *temp = strcat("za",resultado);
            printf("%s\n", temp);
            // Usar o SHA256 aqui

            num[0]++;
        }
    for ( int i = 0; i < tam; i++ ) {
        if ( num[i] == 36 ) {
            num[i] = 0 ;
            num[i+1]++ ;
        }
    }
    }

    //return *resultado;
}


