#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gerarSenha() {
    return rand() % 100 + 1; 
}

// Função principal
int main() {
    char resposta;
    int guiche = 1; 
    
   
    srand(time(NULL));
    
    do {
        printf("Deseja retirar uma senha? (s ou n): ");
        scanf(" %c", &resposta);
        
        if (resposta == 's' || resposta == 'S') {
            int senha = gerarSenha();
            printf("Senha: %d | Guichê: %d\n", senha, guiche);
            guiche++; 
        }
        
    } while (resposta == 's' || resposta == 'S'); 
    
    printf("obrigado!\n");
    
    return 0;
}
