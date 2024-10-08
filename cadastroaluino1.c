#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gerarSenha() {
    return rand() % 100 + 1; 
}

// main
int main() {
    char resposta;
    int guiche = 1; 
    
    srand(time(NULL));  //gerador de números aleatórios
    
    do {
        printf("Deseja retirar uma senha? (s ou n): ");
        scanf(" %c", &resposta);
        
        if (resposta == 's' || resposta == 'S') {
            char tipo;
            int senha = gerarSenha();
            
            printf("Tipo de paciente (c para comum, p para preferencial): ");
            scanf(" %c", &tipo);
            
            if (tipo == 'c' || tipo == 'C') {
                printf("Senha: C%d | Guichê: %d\n", senha, guiche);
            } else if (tipo == 'p' || tipo == 'P') {
                printf("Senha: P%d | Guichê: %d\n", senha, guiche);
            } else {
                printf("Tipo de paciente inválido.\n");
                continue;  
            }
            
            guiche++;  
        }
        
    } while (resposta == 's' || resposta == 'S'); 
    
    printf("Obrigado!\n");
    
    return 0;
}
