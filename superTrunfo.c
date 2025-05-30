#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//struct de dados para calculo.
struct dadosCalculados {
    float PIBperCapta, densidadePopulacional;
};
    
//Definindo struct das cartas.
struct Carta {
    char estado, cidade[50], codigoCarta[4];
    float area, PIB;
    int pontosTuristicos;
    unsigned long int populacao;
    struct dadosCalculados resultados; 
};

//struct para armazenamento do resultado do supe poder para comparação.
struct dadosSuperPoder {
    float superCarta1, superCarta2;
};

int main() {
    struct Carta carta1, carta2;
    struct dadosSuperPoder resultadoComparacao;
    int pontosCarta1 = 0, pontosCarta2 = 0;
    int escolha;

    printf(" Bem vindo ao Super-Trunfo\n");
    printf(" Vamos cadastrar suas cartas!\n");
    
    // Cadastro das Cartas:
    //ENTRADA DA PRIMEIRA CARTA.
    printf("\n --- Carta 1 ---\n");

    printf(" Digite a letra do estado (A-H): ");
    scanf(" %c", &carta1.estado); //lê somente 1 caractere.
    carta1.estado = toupper(carta1.estado); //converte caractere minusculo em maiusculo.

    printf(" Digite o nome da cidade: ");
    scanf(" %[^\n]", carta1.cidade); //lê até o user apertar enter.

    printf(" Digite a quantidade de habitantes (sem pontos): ");
    scanf("%d", &carta1.populacao);

    printf(" Digite o tamanho da área em km² (sem pontos): ");
    scanf("%f", &carta1.area);

    printf(" Digite o PIB (sem pontos e sem centavos): ");
    scanf("%f", &carta1.PIB);

    printf(" Digite a quantidade de pontos turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    printf(" Digite o código da carta: ");
    scanf("%3s", carta1.codigoCarta); //limitando caracteres para evitar buffer overflow.

    //ENTRADA DA SEGUNDA CARTA.
    printf("\n --- Carta 2 ---\n");

    printf(" Digite a letra do estado (A-H): ");
    scanf(" %c", &carta2.estado); //lê somente 1 caractere.
    carta2.estado = toupper(carta1.estado); //converte caractere minusculo em maiusculo.

    printf(" Digite o nome da cidade: ");
    scanf(" %[^\n]", carta2.cidade); //lê até o user apertar enter.

    printf(" Digite a quantidade de habitantes (sem pontos): ");
    scanf("%lu", &carta2.populacao);

    printf(" Digite o tamanho da área em km² (sem pontos): ");
    scanf("%f", &carta2.area);

    printf(" Digite o PIB (sem pontos e sem centavos): ");
    scanf("%f", &carta2.PIB);

    printf(" Digite a quantidade de pontos turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    printf(" Digite o código da carta: ");
    scanf("%3s", carta2.codigoCarta); //limitando caracteres para evitar buffer overflow.

    system("clear"); //limpando o terminal.

    //Calculo PIB e Densidade da Carta 1.
    carta1.resultados.PIBperCapta = carta1.PIB / carta1.populacao; //PIB per Capta.
    carta1.resultados.densidadePopulacional = (float)carta1.populacao / carta1.area; //Densidade Populacional.

    //Calculo PIB e Densidade da Carta 2.
    carta2.resultados.PIBperCapta = carta2.PIB / carta2.populacao; //PIB per Capta.
    carta2.resultados.densidadePopulacional = (float)carta2.populacao / carta2.area; //Densidade Populacional.

    //Calculo do super poder.
    resultadoComparacao.superCarta1 = carta1.area + carta1.PIB + carta1.populacao + carta1.pontosTuristicos + carta1.resultados.PIBperCapta + carta1.resultados.densidadePopulacional;
    resultadoComparacao.superCarta2 = carta2.area + carta2.PIB + carta2.populacao + carta2.pontosTuristicos + carta2.resultados.PIBperCapta + carta2.resultados.densidadePopulacional;
        
    // Exibição dos Dados das Cartas:
    //EXIBIÇÃO DA PRIMEIRA CARTA.
    printf("-------------------------------------------\n");
    printf("            --- Carta 1 ---\n");
    printf("|| Estado: %c\n", carta1.estado);
    printf("|| Código: %s\n", carta1.codigoCarta);
    printf("|| Nome da Cidade: %s\n", carta1.cidade);
    printf("|| População: %lu habitantes\n", carta1.populacao);
    printf("|| Área: %.2f km²\n", carta1.area);

    //Identificação das casas milhões/bilhões.
    printf("|| PIB: %.2f %s de reais\n", 
        carta1.PIB >= 1000000000 ? carta1.PIB / 1000000000 : 
           (carta1.PIB >= 1000000 ? carta1.PIB / 1000000 : carta1.PIB),
           carta1.PIB >= 1000000000 ? "bilhões" : 
           (carta1.PIB >= 1000000 ? "milhões" : "reais"));

    printf("|| Pontos Turísticos: %d\n", carta1.pontosTuristicos);
    printf("|| PIB per Capta: %.2f reais\n", carta1.resultados.PIBperCapta);
    printf("|| Densidade Populacional: %.2f hab/km²\n", carta1.resultados.densidadePopulacional);
    printf("|| Super Poder: %.f\n", resultadoComparacao.superCarta1); // Exibindo o super poder
    printf("--------------------------------------------\n");


    //EXIBIÇÃO DA SEGUNDA CARTA.
    printf("\n--------------------------------------------\n");
    printf("            --- Carta 2 ---\n");
    printf("|| Estado: %c\n", carta2.estado);
    printf("|| Código: %s\n", carta2.codigoCarta);
    printf("|| Nome da Cidade: %s\n", carta2.cidade);
    printf("|| População: %lu habitantes\n", carta2.populacao);
    printf("|| Área: %.2f km²\n", carta2.area);

    //Identificação das casas milhões/bilhões.
    printf("|| PIB: %.2f %s de reais\n", 
        carta2.PIB >= 1000000000 ? carta2.PIB / 1000000000 : 
           (carta2.PIB >= 1000000 ? carta2.PIB / 1000000 : carta2.PIB),
           carta2.PIB >= 1000000000 ? "bilhões" : 
           (carta2.PIB >= 1000000 ? "milhões" : "reais"));
    
    printf("|| Pontos Turísticos: %d\n", carta2.pontosTuristicos);
    printf("|| PIB per Capta: %.2f reais\n", carta2.resultados.PIBperCapta);
    printf("|| Densidade Populacional: %.2f hab/km²\n", carta2.resultados.densidadePopulacional);
    printf("|| Super Poder: %.f\n", resultadoComparacao.superCarta2); // Exibindo o super poder.
    printf("--------------------------------------------\n");
    printf("\n");

    printf("Escolha um atributo para comparação das cartas: \n");
    printf("1. População \n");
    printf("2. Área \n");
    printf("3. PIB \n");
    printf("4. Número de pontos turisticos \n");
    printf("5. Densidade demografica \n");
    printf("6. Comparação total \n");

    printf("\n--> ");
    scanf("%d", &escolha);

    system("clear");//limpar terminal.

    //população.
    const char* resultadoPopulacao;
        if(carta1.populacao > carta2.populacao){
        pontosCarta1++;
        resultadoPopulacao = "Carta 1 venceu!! (1)";
    }else{
        pontosCarta2++;
        resultadoPopulacao = "Carta 2 venceu!! (0)";
    }

    //area.
    const char* resultadoArea;
    if(carta1.area > carta2.area){
        pontosCarta1++;
        resultadoArea = "Carta 1 venceu!! (1)";
    }else{
        pontosCarta2++;
        resultadoArea = "Carta 2 venceu!! (0)";
    }

    //PIB.
    const char* resultadoPIB;
    if(carta1.PIB > carta2.PIB){
        pontosCarta1++;
        resultadoPIB = "Carta 1 venceu!! (1)";
    }else{
        pontosCarta2++;
        resultadoPIB = "Carta 2 venceu!! (0)";
    }

    //pontos turisticos.
    const char* resultadoPontosTuristicos;
    if(carta1.pontosTuristicos > carta2.pontosTuristicos){
        pontosCarta1++;
        resultadoPontosTuristicos = "Carta 1 venceu!! (1)";
    }else{
        pontosCarta2++;
        resultadoPontosTuristicos = "Carta 2 venceu!! (0)";
    }

    //densidade demografica.
    const char* resultadoDensidade;
    if(carta1.resultados.densidadePopulacional < carta2.resultados.densidadePopulacional){
        pontosCarta1++;
        resultadoDensidade = "Carta 1 venceu!! (1)";
    }else{
        pontosCarta2++;
        resultadoDensidade = "Carta 2 venceu!! (0)";
    }

    switch (escolha)
    {
    case 1:
        printf("------ Resultado da comparação ------\n");
        printf("\n Comparação Populacional\n");
        printf(" %s - %s\n", &carta1.cidade, &carta2.cidade);
        printf(" A Carta 1 possui: %lu hab/km²\n", carta1.populacao);
        printf(" A Carta 2 possui: %lu hab/km²\n", carta2.populacao);
        printf("\n-----------------------------\n");
        printf("    %s\n", resultadoPopulacao);
        printf("------------------------------\n");
        break;
    
    case 2:
        printf("------ Resultado da comparação ------\n");
        printf("\n Comparação da Área\n");
        printf(" %s - %s\n", &carta1.cidade, &carta2.cidade);
        printf(" A Carta 1 possui: %.2f km²\n", carta1.area);
        printf(" A Carta 2 possui: %.2f km²\n", carta2.area);
        printf("\n-----------------------------\n");
        printf("    %s\n", resultadoArea);
        printf("-----------------------------\n");
        break;

    case 3:
        printf("------ Resultado da comparação ------\n");
        printf(" Comparação do PIB\n");
        printf(" %s - %s\n", &carta1.cidade, &carta2.cidade);
        printf(" A Carta 1 possui: %.2f reais\n", carta1.PIB);
        printf(" Carta 2 possui: %.2f reais",  carta2.PIB);
        printf("\n-----------------------------\n");
        printf("    %s\n", resultadoPIB);
        printf("-----------------------------\n");
        break;

    case 4:
        printf("------ Resultado da comparação ------\n");
        printf(" Comparação Pontos Turisticos\n");
        printf(" %s - %s\n", &carta1.cidade, &carta2.cidade);
        printf(" A Carta 1 possui: %d Pontos Turisticos", carta1.pontosTuristicos); 
        printf(" A Carta 2 possui: %d Pontos Turisticos\n", carta2.pontosTuristicos);
        printf("\n-----------------------------\n");
        printf("    %s\n", resultadoPontosTuristicos);
        printf("-----------------------------\n");
        break;

    case 5:
        printf("------ Resultado da comparação ------\n");
        printf(" Comparação Densidade demografica\n");
        printf(" %s - %s\n", &carta1.cidade, &carta2.cidade);
        printf(" A Carta 1 possui: %.2f hab/km²", carta1.resultados.densidadePopulacional);
        printf(" A Carta 2 possui: %.2f hab/km²\n", carta2.resultados.densidadePopulacional);
        printf("\n-----------------------------\n");
        printf("   %s\n", resultadoDensidade);
        printf("-----------------------------\n");
        break;

    case 6:
        printf("------ Comparação das Cartas ------\n");
        printf(" População: %s\n",
                carta1.populacao > carta2.populacao ? "Carta 1 venceu!! (1)" :
                (carta2.populacao > carta1.populacao ? "Carta 2 venceu!! (0)" : "Empate!"));
        printf(" Área: %s\n",
                carta1.area > carta2.area ? "Carta 1 venceu!! (1)" : 
                (carta2.area > carta1.area ? "Carta 2 venceu!! (0)" : " Empate!"));
        printf(" PIB: %s\n",
                carta1.PIB > carta2.PIB ? "Carta 1 venceu!! (1)" : 
                (carta2.PIB > carta1.PIB ? "Carta 2 venceu!! (0)" : "Empate!"));
        printf(" Pontos Turisticos: %s\n",
                carta1.pontosTuristicos > carta2.pontosTuristicos ? "Carta 1 venceu!! (1)" : 
                (carta2.pontosTuristicos > carta1.pontosTuristicos ? "Carta 2 venceu!! (0)" : "Empate!"));
        printf(" Densidade Populacional: %s\n",
                carta1.resultados.densidadePopulacional < carta2.resultados.densidadePopulacional ? "Carta 1 venceu!! (1)" :
                (carta2.resultados.densidadePopulacional < carta1.resultados.densidadePopulacional ? "Carta 2 venceu!! (0)" : "Empate!"));
        printf(" PIB per Capta: %s\n",
                carta1.resultados.PIBperCapta > carta2.resultados.PIBperCapta ? "Carta 1 venceu!! (1)" : 
                (carta2.resultados.PIBperCapta > carta1.resultados.PIBperCapta ? "Carta 2 venceu!! (0)" : "Empate!"));
        printf(" Super Poder: %s\n",
                resultadoComparacao.superCarta1 > resultadoComparacao.superCarta2 ? "Carta 1 venceu!! (1)" : 
                (resultadoComparacao.superCarta2 > resultadoComparacao.superCarta1 ? "Carta 2 venceu!! (0)" : "Empate!"));
        printf("\n");
        printf(" --- Resultado Final ---\n");
        printf("A Carta 1 fez: %d pontos.\n", pontosCarta1);
        printf("A Carta 2 fez: %d pontos.\n", pontosCarta2);

        //determinando o vencedor.
        if(pontosCarta1 > pontosCarta2){
            printf("\n---------------------------------");
            printf("\nA carta 1 venceu com %d pontos!!\n", pontosCarta1);
            printf("\---------------------------------\n");
        }else if (pontosCarta2 > pontosCarta1){
            printf("\n---------------------------------");
            printf("\nA carta 2 venceu com %d pontos!!\n", pontosCarta2);
            printf("\---------------------------------\n");
        }else{
        //Desempate das cartas.
        printf("\nEmpate de pontos!!\n");
        printf("Super Poder Carta 1: %2.f\n", resultadoComparacao.superCarta1);
        printf("Super Poder Carta 2: %2.f\n", resultadoComparacao.superCarta2);

        if (resultadoComparacao.superCarta1 > resultadoComparacao.superCarta2){
            printf("\nA Carta 1 ganhou no Super Poder!!\n");
        }else{
            printf("\nA Carta 2 ganhou no Super Poder!!\n");
        }

    default:
        printf("Opção Inválida!\n");
        break;
    }
    }
    return 0;
}