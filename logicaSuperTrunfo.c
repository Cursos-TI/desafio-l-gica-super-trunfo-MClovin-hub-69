#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Variáveis da Carta 1
    char estado1;
    char codigo1[10];
    char nome1[50];
    int populacao1;
    float area1, pib1;
    int pontosTuristicos1;
    float densidade1, pibPerCapita1;

    // Variáveis da Carta 2
    char estado2;
    char codigo2[10];
    char nome2[50];
    int populacao2;
    float area2, pib2;
    int pontosTuristicos2;
    float densidade2, pibPerCapita2;

    int opcao1, opcao2; // atributos escolhidos
    float valor1 = 0, valor2 = 0;
    int vencedor = 0; // 0 = empate, 1 = carta1, 2 = carta2

    printf("*** Desafio Final - Super Trunfo! ***\n\n");

    // Entrada de Dados da Carta 1
    printf("Digite o estado da Carta 1: ");
    scanf(" %c", &estado1);

    printf("Digite o código da Carta 1: ");
    scanf("%s", codigo1);

    printf("Digite o nome da cidade da Carta 1: ");
    scanf(" %[^\n]", nome1);

    printf("Digite a população da cidade da Carta 1: ");
    scanf("%d", &populacao1);

    printf("Digite a área da cidade da Carta 1 (em km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB da cidade da Carta 1 (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Digite o número de pontos turísticos da Carta 1: ");
    scanf("%d", &pontosTuristicos1);

    // Cálculos da Carta 1
    densidade1 = (float) populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1;

    // Entrada de Dados da Carta 2
    printf("\nDigite o estado da Carta 2: ");
    scanf(" %c", &estado2);

    printf("Digite o código da Carta 2: ");
    scanf("%s", codigo2);

    printf("Digite o nome da cidade da Carta 2: ");
    scanf(" %[^\n]", nome2);

    printf("Digite a população da cidade da Carta 2: ");
    scanf("%d", &populacao2);

    printf("Digite a área da cidade da Carta 2 (em km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB da cidade da Carta 2 (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Digite o número de pontos turísticos da Carta 2: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculos da Carta 2
    densidade2 = (float) populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;

    // Exibição das cartas
    printf("\n--- Carta 1 ---\n");
    printf("Estado: %c | Código: %s | Cidade: %s\n", estado1, codigo1, nome1);
    printf("População: %d | Área: %.2f km² | PIB: %.2f bi\n", populacao1, area1, pib1);
    printf("Pontos Turísticos: %d | Densidade: %.2f hab/km² | PIB per capita: %.2f\n",
           pontosTuristicos1, densidade1, pibPerCapita1);

    printf("\n--- Carta 2 ---\n");
    printf("Estado: %c | Código: %s | Cidade: %s\n", estado2, codigo2, nome2);
    printf("População: %d | Área: %.2f km² | PIB: %.2f bi\n", populacao2, area2, pib2);
    printf("Pontos Turísticos: %d | Densidade: %.2f hab/km² | PIB per capita: %.2f\n",
           pontosTuristicos2, densidade2, pibPerCapita2);

    // Menu de escolha dos atributos
    printf("\nEscolha o primeiro atributo para comparação:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade (menor vence)\n6 - PIB per Capita\n");
    scanf("%d", &opcao1);

    printf("Escolha o segundo atributo (em caso de empate):\n");
    scanf("%d", &opcao2);

    // Comparação pelo 1º atributo
    switch(opcao1) {
        case 1: valor1 = populacao1; valor2 = populacao2; break;
        case 2: valor1 = area1; valor2 = area2; break;
        case 3: valor1 = pib1; valor2 = pib2; break;
        case 4: valor1 = pontosTuristicos1; valor2 = pontosTuristicos2; break;
        case 5: valor1 = -densidade1; valor2 = -densidade2; break; // menor vence
        case 6: valor1 = pibPerCapita1; valor2 = pibPerCapita2; break;
        default: printf("Opção inválida! Usando População.\n");
                 valor1 = populacao1; valor2 = populacao2; break;
    }

    if(valor1 != valor2) {
        vencedor = (valor1 > valor2) ? 1 : 2;
    } else {
        // Empatou -> comparar pelo 2º atributo
        switch(opcao2) {
            case 1: valor1 = populacao1; valor2 = populacao2; break;
            case 2: valor1 = area1; valor2 = area2; break;
            case 3: valor1 = pib1; valor2 = pib2; break;
            case 4: valor1 = pontosTuristicos1; valor2 = pontosTuristicos2; break;
            case 5: valor1 = -densidade1; valor2 = -densidade2; break;
            case 6: valor1 = pibPerCapita1; valor2 = pibPerCapita2; break;
            default: printf("Opção inválida! Usando População.\n");
                     valor1 = populacao1; valor2 = populacao2; break;
        }
        if(valor1 != valor2) {
            vencedor = (valor1 > valor2) ? 1 : 2;
        }
    }

    // Resultado final
    printf("\n### Resultado Final ###\n");
    if(vencedor == 0) {
        printf("Empate total!\n");
    } else {
        printf("Carta %d venceu!\n", vencedor);
        printf("Atributo decisivo: %d\n", (valor1 != valor2) ? opcao1 : opcao2);
    }

    return 0;
}