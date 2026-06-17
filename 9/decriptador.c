#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/evp.h>

void permuta(const char *str, int tam,const char *hash, int *flag);
int comparar(const char *tentativa,const char *hash_V);

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
    int encontrada = 0;
    int tam = 1;

    while (encontrada == 0 && tam <= 6){
        printf("Testando sufixos de tamanho: %d...\n", tam);
        permuta("0123456789abcdefghijklmnopqrstuvwxyz", tam, hash, &encontrada);
        tam++;
    }

    return 0;       
}


void permuta(const char *str, int tam, const char *hash, int *flag){
    int len = strlen(str);
    int *num = (int *) calloc((tam + 1) , sizeof(int));
    int k;
    char *resultado = (char *) malloc((tam + 1)* sizeof(char));

    if (resultado == NULL) {
        perror("Erro ao alocar memoria");
        exit(EXIT_FAILURE);
    }

    while(num[tam] == 0 && *flag == 0){
      
        for(int j = 0, k = tam - 1; j < tam; j++){
            resultado[k] = str[num[j]]; 
            k--;
        }

        resultado[tam] = 0;
        char temp[9] = "za";
        strcat(temp, resultado);
        
        if (comparar(temp, hash)) {
            *flag = 1;
            printf("\n>>> SUCESSO! Senha encontrada: %s <<<\n", temp);
        }


        num[0]++;
        for ( int i = 0; i < tam; i++ ) {
            if ( num[i] == len ) { // Correção: compara com 'len' em vez de 36 fixo
                num[i] = 0 ;
                num[i+1]++ ;
            }
        }
    }
    free (num);
    free (resultado);
    
}

int comparar(const char *tentativa,const char *hash_V){
    unsigned char hash_binario[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char *)tentativa, strlen(tentativa), hash_binario);

    char hash_base64[64];
    int base64_len = EVP_EncodeBlock((unsigned char *)hash_base64, hash_binario, SHA256_DIGEST_LENGTH);
    hash_base64[base64_len] = '\0'; // Terminador de string em C

    if (strcmp(hash_base64, hash_V) == 0) {
        return 1; // Sucesso!
    }
    return 0;

    if (strcmp(hash_base64, hash_V) == 0) {
        printf("Senha encontrada: %s\n", tentativa);
        exit(0); 
    }
    return 0;
}

