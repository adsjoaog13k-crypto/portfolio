#include <stdio.h>
#include <string.h>

int main() {

    char filmes[10][50] = {
        "O Rei Leao",
        "Aladdin",
        "A Pequena Sereia",
        "Mulan",
        "Tarzan",
        "Lilo e Stitch",
        "Enrolados",
        "Frozen",
        "Moana",
        "Encanto"
    };

    int i = 0;
    float notas[10] = {0};
    int opcao;
 
    do {
        printf("\n===== CATALOGO DE FILMES DA DISNEY =====\n");
        printf("1 - Listar filmes\n");
        printf("2 - Avaliar filme\n");
        printf("3 - Buscar filmes\n");
        printf("4 - Ver estatisticas\n");
        printf("5 - Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);


        //Opção do menu 1 - listar filmes
        if (opcao == 1) {

            printf("\n===== FILMES =====\n");

            for (i = 0; i < 10; i++) {
                printf("%d - %s\n", i + 1, filmes[i]);
            }
        }

    //Opção do menus 2 - avaliar filmes
    else if (opcao == 2){

        int filmeEscolhido;
        float nota;
        
        printf("\n===== AVALIAR FILMES =====\n");

        for (i = 0; i < 10; i++) {
            printf("%d - %s\n", i + 1, filmes[i]);
        }

        printf("Escolha o filme: ");
        scanf("%d", &filmeEscolhido);

        if(filmeEscolhido >= 1 && filmeEscolhido <= 10){

            printf("\nDigite uma nota de 0 a 10: ");
            scanf("%f", &nota);

            if(nota >= 0 && nota <= 10){

                notas[filmeEscolhido - 1] = nota;

                printf("\nFilme escolhido: %s\n", filmes[filmeEscolhido - 1]);
                printf("Nota registrada: %.2f\n", nota);
            }
            else{
                printf("Nota invalida! Digite uma nota de 0 a 10.\n");
            }
        } else{
            printf("Filme invalido.\n");
        }
    }

    //Opção do menu 3 - buscar filmes
    else if (opcao == 3){
    	
        char busca[50];
        int encontrado = 0;
        
        printf("\n===== BUSCAR FILME =====\n");
        
        printf("Digite o nome do filme: ");
        scanf(" %[^\n]", busca);
        
        for(i = 0; i <10;i++){
            
            if(strcmp(filmes[i], busca) == 0){
                printf("Filme encontrado: %s, sua nota e: %.2f\n", filmes[i], notas[i]);
                encontrado = 1;	
            }
        }
            if(encontrado == 0){
                printf("Filme nao encontrado!\n");
            }	
            
    }

    //Opção do menu 4 - estatísticas das notas dos filmes
    else if (opcao == 4){

        int avaliados = 0;
        float soma = 0;
        float media;
        float maior = 0;
        float menor = 10;

        printf("\n===== ESTATISTICAS =====\n");

        for(i = 0; i < 10; i++){
            if(notas[i] > 0) {

                avaliados++;
                soma += notas[i];

                if (notas[i] > maior){
                    maior = notas[i];
                }

                if (notas[i] < menor){
                    menor = notas[i];
                }
            }
        }
        if (avaliados > 0){

        media = soma / avaliados;

        printf("Filmes avaliados: %d\n", avaliados);
        printf("Media das notas: %.2f\n", media);
        printf("Maior nota: %.2f\n", maior);
        printf("Menor nota: %.2f\n", menor);

        }else{
            printf("Nenhum filme foi avaliado ainda!\n");
        }
    }
        
    //Opção do menu 5 - encerramento do programa
    } while (opcao != 5);        
    printf("Agradecemos por usar nosso programa! :)");
    
    return 0;
}
