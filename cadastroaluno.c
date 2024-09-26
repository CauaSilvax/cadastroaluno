#include <stdio.h>
#include <string.h>

// Model
struct Atendente {
    int matricula;
    char nome[50];
    char login[6];
    char senha[6];
};

char nome_arquivo[50];

// Funções de controle de propriedades
void carregarPropriedades() {
    FILE *file = fopen("propriedades.txt", "r");
    if (file) {
        fscanf(file, "[nome_arquivo = %49s]", nome_arquivo);
        fclose(file);
    } else {
        printf("Erro ao carregar o arquivo de propriedades.\n");
        strcpy(nome_arquivo, "atendente.txt");
    }
}

// Função para incluir atendente
void incluirAtendente(struct Atendente atendente) {
    FILE *file = fopen(nome_arquivo, "a");
    if (file) {
        fprintf(file, "%05d;%s;%s;%s\n", atendente.matricula, atendente.nome, atendente.login, atendente.senha);
        fclose(file);
        printf("Atendente cadastrado com sucesso!\n");
    } else {
        printf("Erro ao abrir o arquivo.\n");
    }
}

// Função para alterar atendente
int alterarAtendente(struct Atendente* atendente, int matricula) {
    if (matricula == atendente->matricula) {
        getchar();
        printf("Digite o novo nome: ");
        fgets(atendente->nome, sizeof(atendente->nome), stdin);
        printf("Digite o novo login: ");
        scanf("%s", atendente->login);
        printf("Digite a nova senha: ");
        scanf("%s", atendente->senha);
        printf("Dados alterados com sucesso!\n");
        return 1;
    }
    return 0;
}

// Função para excluir atendente
int excluirAtendente(struct Atendente* atendente, int matricula) {
    if (matricula == atendente->matricula) {
        atendente->matricula = 0;
        printf("Atendente excluído com sucesso!\n");
        return 1;
    }
    return 0;
}

// Função para consultar atendente
int consultarAtendente(struct Atendente atendente, int matricula) {
    if (matricula == atendente.matricula) {
        printf("\nAtendente encontrado!\n");
        printf("Matrícula: %05d\n", atendente.matricula);
        printf("Nome: %s", atendente.nome);
        printf("Login: %s\n", atendente.login);
        printf("Senha: %s\n", atendente.senha);
        return 1;
    }
    return 0;
}

// Controller e View
int main() {
    struct Atendente atendente = {0};
    int opcao, matriculaDigitada;

    carregarPropriedades();

    printf("Sistema de Cadastro de Atendente\n");

    do {
        printf("\n1. Incluir Atendente\n");
        printf("2. Alterar Atendente\n");
        printf("3. Excluir Atendente\n");
        printf("4. Consultar Atendente\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a matrícula (5 dígitos): ");
                scanf("%d", &atendente.matricula);
                getchar();
                printf("Digite o nome do atendente: ");
                fgets(atendente.nome, sizeof(atendente.nome), stdin);
                printf("Digite o login (5 dígitos): ");
                scanf("%s", atendente.login);
                printf("Digite a senha (5 dígitos): ");
                scanf("%s", atendente.senha);
                incluirAtendente(atendente);
                break;

            case 2:
                printf("Digite a matrícula para alterar: ");
                scanf("%d", &matriculaDigitada);
                if (!alterarAtendente(&atendente, matriculaDigitada)) {
                    printf("Atendente não encontrado!\n");
                }
                break;

            case 3:
                printf("Digite a matrícula para excluir: ");
                scanf("%d", &matriculaDigitada);
                if (!excluirAtendente(&atendente, matriculaDigitada)) {
                    printf("Atendente não encontrado!\n");
                }
                break;

            case 4:
                printf("Digite a matrícula para consultar: ");
                scanf("%d", &matriculaDigitada);
                if (!consultarAtendente(atendente, matriculaDigitada)) {
                    printf("Atendente não encontrado!\n");
                }
                break;

            case 5:
                printf("Desligando.......\n");
                break;

            default:
                printf("Opção inválida. Escolha um número entre 1-5\n");
        }
    } while (opcao != 5);

    return 0;
}
