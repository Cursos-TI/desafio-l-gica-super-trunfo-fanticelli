#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//função para atributos.
const char* nomesAtributos[] = {
    "",
    "População",
    "Área",
    "PIB",
    "Pontos Turisticos",
    "Densidade demográfica"
};

//função para limpar buffer de entrada.
void limparBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);    
};

//struct de dados para calculo.
struct dadosCalculados {
    float PIBperCapta, densidadePopulacional;
};
    
//Definindo struct das cartas.
struct Carta {
    char estado, cidade[50];
    float area, PIB;
    int pontosTuristicos;
    unsigned long int populacao;
    struct dadosCalculados resultados; 
};

//struct para armazenamento do resultado do supe poder para comparação.
struct dadosSuperPoder {
    float superCarta1, superCarta2;
};

struct ResultadoRodada {
    float somaCarta1;
    float somaCarta2;
};

//Receber valor dos atributos para soma.
float obterValorAtributo(const struct Carta* carta, int tipoAtributo) {
    switch (tipoAtributo) {
        case 1: return (float)carta->populacao;
        case 2: return carta->area;
        case 3: return carta->PIB;
        case 4: return (float)carta->pontosTuristicos;
        case 5: return carta->resultados.densidadePopulacional;
        default: return 0.0f;
    }
}

//função para comparação de atributo.
void compararAtributo(const struct Carta* carta1, const struct Carta* carta2, int tipoAtributo){
    const char* resultadoComparacao;

    //exibe o nome do atributo.
    printf("------------------------------------\n");
    printf("   ------------%s----------\n", nomesAtributos[tipoAtributo]);
    printf("|| %s X %s\n", carta1->cidade, carta2->cidade);

    switch (tipoAtributo){
        
        //População.
        case 1: //recebendo ponteiro.
            printf("|| A Carta 1 possui: %lu hab\n", carta1->populacao);
            printf("|| A Carta 2 possui: %lu hab\n", carta2->populacao);

            resultadoComparacao = (carta1->populacao > carta2->populacao) ? "\nCarta 1 venceu!!" : 
            (carta2->populacao > carta1->populacao) ? "\nCarta 2 venceu!!" :
            "Empate";
        break;

        //area.
        case 2: 
            printf("|| A Carta 1 possui: %.2f km²\n", carta1->area);
            printf("|| A Carta 2 possui: %.2f km²\n", carta2->area);

            resultadoComparacao = (carta1->area > carta2->area) ? "\nCarta 1 venceu!!" :
            (carta2->area > carta1->area) ? "\nCarta 2 venceu!!" :
            "Empate";
        break;

        //PIB
        case 3:
            printf("|| A Carta 1 possui: %.2f reais\n", carta1->PIB);
            printf("|| A Carta 2 possui: %.2f reais\n", carta2->PIB);
            
            resultadoComparacao = (carta1->PIB > carta2->PIB) ? "\nCarta 1 venceu!!" :
            (carta2->PIB > carta1->PIB) ? "\nCarta 2 venceu!!" :
            "Empate";
        break;

        //Pontos Turisticos
        case 4:
            printf("|| A Carta 1 possui: %d Pontos Turisticos\n", carta1->pontosTuristicos);
            printf("|| A Carta 2 possui: %d Pontos Turisticos\n", carta2->pontosTuristicos);

            resultadoComparacao = (carta1->pontosTuristicos > carta2->pontosTuristicos) ? "\nCarta 1 venceu!!" :
            (carta2->pontosTuristicos > carta1->pontosTuristicos) ? "\nCarta 2 venceu!!" :
            "Empate";
        break;

        //densidade.
        case 5:
            printf("|| A Carta 1 possui: %.2f hab/km²\n", carta1->resultados.densidadePopulacional);
            printf("|| A Carta 2 possui: %.2f hab/km²\n", carta2->resultados.densidadePopulacional);

            resultadoComparacao = (carta1->resultados.densidadePopulacional < carta2->resultados.densidadePopulacional) ? "\nCarta 1 venceu!!" :
            (carta2->resultados.densidadePopulacional < carta1->resultados.densidadePopulacional) ? "\nCarta 2 venceu!!" :
            "Empate";
        break;

        default:
            printf(" Opção inválida!");
        break;
    }
    printf("-----------%s------------\n", resultadoComparacao);
    printf("------------------------------------");
}

int main() {
    struct Carta carta1, carta2;
    struct dadosSuperPoder resultadoComparacaoSuper;
    int escolhaMenu, escolhaComparacao1, escolhaComparacao2;

    printf("  Bem vindo ao Super-Trunfo\n");
    printf(" Vamos cadastrar suas cartas!\n");
    
    // Cadastro das Cartas:
    //ENTRADA DA PRIMEIRA CARTA.
    printf("\n --- Carta 1 ---\n");

    printf(" Digite a letra do estado (A-H): ");
    scanf(" %c", &carta1.estado); //lê somente 1 caractere.
    carta1.estado = toupper(carta1.estado); //converte caractere minusculo em maiusculo.
    limparBuffer();

    printf(" Digite o nome da cidade: ");
    scanf(" %[^\n]", carta1.cidade); //lê até o user apertar enter.
    limparBuffer();

    printf(" Digite a quantidade de habitantes (sem pontos): ");
    scanf("%lu", &carta1.populacao);
    limparBuffer();

    printf(" Digite o tamanho da área em km² (sem pontos): ");
    scanf("%f", &carta1.area);
    limparBuffer();

    printf(" Digite o PIB (sem pontos e sem centavos): ");
    scanf("%f", &carta1.PIB);
    limparBuffer();

    printf(" Digite a quantidade de pontos turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);
    limparBuffer();

    //ENTRADA DA SEGUNDA CARTA.
    printf("\n --- Carta 2 ---\n");

    printf(" Digite a letra do estado (A-H): ");
    scanf(" %c", &carta2.estado); //lê somente 1 caractere.
    carta2.estado = toupper(carta2.estado); //converte caractere minusculo em maiusculo.
    limparBuffer();

    printf(" Digite o nome da cidade: ");
    scanf(" %[^\n]", carta2.cidade); //lê até o user apertar enter.
    limparBuffer();

    printf(" Digite a quantidade de habitantes (sem pontos): ");
    scanf("%lu", &carta2.populacao);
    limparBuffer();

    printf(" Digite o tamanho da área em km² (sem pontos): ");
    scanf("%f", &carta2.area);
    limparBuffer();

    printf(" Digite o PIB (sem pontos e sem centavos): ");
    scanf("%f", &carta2.PIB);
    limparBuffer();

    printf(" Digite a quantidade de pontos turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);
    limparBuffer();

    system("clear"); //limpando o terminal.

    //Calculo PIB e Densidade da Carta 1.
    carta1.resultados.PIBperCapta = carta1.PIB / carta1.populacao; //PIB per Capta.
    carta1.resultados.densidadePopulacional = (float)carta1.populacao / carta1.area; //Densidade Populacional.

    //Calculo PIB e Densidade da Carta 2.
    carta2.resultados.PIBperCapta = carta2.PIB / carta2.populacao; //PIB per Capta.
    carta2.resultados.densidadePopulacional = (float)carta2.populacao / carta2.area; //Densidade Populacional.

    //Calculo do super poder.
    resultadoComparacaoSuper.superCarta1 = carta1.area + carta1.PIB + carta1.populacao + carta1.pontosTuristicos + carta1.resultados.PIBperCapta + carta1.resultados.densidadePopulacional;
    resultadoComparacaoSuper.superCarta2 = carta2.area + carta2.PIB + carta2.populacao + carta2.pontosTuristicos + carta2.resultados.PIBperCapta + carta2.resultados.densidadePopulacional;
    
    //loop do menu.
    do{
        system("clear"); //limpa o terminal toda volta ao menu.
       
        printf(" Escolha uma opção: \n");
        printf(" 1. Mostrar informações cadastradas\n");
        printf(" 2. Escolher atributos para comparação\n");
        printf(" 3. Comparar todos os atributos\n");
        printf(" 0. Finalizar programa\n");

        printf("\n --> ");
        scanf("%d", &escolhaMenu);
        limparBuffer();

        system("clear");

        switch (escolhaMenu){
            case 1:
                //EXIBIÇÃO DA PRIMEIRA CARTA.
                printf("-------------------------------------------\n");
                printf("            --- Carta 1 ---\n");
                printf("|| Estado: %c\n", carta1.estado);
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
                printf("|| Super Poder: %.f\n", resultadoComparacaoSuper.superCarta1); // Exibindo o super poder
                printf("--------------------------------------------\n");


                //EXIBIÇÃO DA SEGUNDA CARTA.
                printf("\n--------------------------------------------\n");
                printf("            --- Carta 2 ---\n");
                printf("|| Estado: %c\n", carta2.estado);
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
                printf("|| Super Poder: %.f\n", resultadoComparacaoSuper.superCarta2); // Exibindo o super poder.
                printf("--------------------------------------------\n");

                printf("\n Pressione ENTER para voltar ao menu..\n");
                limparBuffer(); //limpa o buffer.
            break;
            
            case 2:
                //ESCOLHA DO PRIMEIRO ATRIBUTO DE COMPARAÇÃO.
                printf(" Escolha o primeiro atributo para comparação das cartas: \n");
                printf(" 1. População \n");
                printf(" 2. Área \n");
                printf(" 3. PIB \n");
                printf(" 4. Número de pontos turisticos \n");
                printf(" 5. Densidade demografica \n");

                printf("\n");
                printf(" --> ");
                scanf("%d", &escolhaComparacao1);
                limparBuffer();


                //ESCOLHA DO SEGUNDO ATRIBUTO DE COMPARAÇÃO.
                printf("\n Escolha o segundo atributo para comparação das cartas: \n");
                
                // Exibe as opções, excluindo a primeira escolha
                if (escolhaComparacao1 != 1) printf(" 1. População \n");
                if (escolhaComparacao1 != 2) printf(" 2. Área \n");
                if (escolhaComparacao1 != 3) printf(" 3. PIB \n");
                if (escolhaComparacao1 != 4) printf(" 4. Número de pontos turísticos \n");
                if (escolhaComparacao1 != 5) printf(" 5. Densidade demográfica \n");

                printf("\n");
                printf(" --> ");
                scanf("%d", &escolhaComparacao2);
                limparBuffer();

                system("clear"); //limpar terminal.

                 // Chamadas para a nova função de comparação
                compararAtributo(&carta1, &carta2, escolhaComparacao1);
                printf("\n");
                compararAtributo(&carta1, &carta2, escolhaComparacao2);
                printf("\n");

                //soma e comparação dos atributos.
                printf("\n Pressione ENTER para calcular..\n");
                getchar();
                system("clear"); //limpar teminal.
                
                struct ResultadoRodada resultadosDaRodada;

                resultadosDaRodada.somaCarta1 = 0.0f;
                resultadosDaRodada.somaCarta2 = 0.0f;

                //soma da carta 1.
                resultadosDaRodada.somaCarta1 += obterValorAtributo(&carta1, escolhaComparacao1);
                resultadosDaRodada.somaCarta1 += obterValorAtributo(&carta1, escolhaComparacao2);

                //soma da carta 2.
                resultadosDaRodada.somaCarta2 += obterValorAtributo(&carta2, escolhaComparacao1);
                resultadosDaRodada.somaCarta2 += obterValorAtributo(&carta2, escolhaComparacao2);

                printf("----------- Resultado Final ------------\n");
                printf("\n Soma dos atributos de %s:\n %.2f\n", carta1.cidade, resultadosDaRodada.somaCarta1);
                printf("\n Soma dos atributos de %s:\n %.2f\n", carta2.cidade, resultadosDaRodada.somaCarta2);
                printf("--------------------------------------\n");

                if (resultadosDaRodada.somaCarta1 > resultadosDaRodada.somaCarta2) {
                    printf("\n %s venceu a rodada com a maior soma!\n", carta1.cidade);
                } else if (resultadosDaRodada.somaCarta2 > resultadosDaRodada.somaCarta1) {
                    printf("\n %s venceu a rodada com a maior soma!\n", carta2.cidade);
                } else {
                    printf("\n A rodada terminou em Empate!\n");
                }
                
                printf("\n");
                printf(" Pressione ENTER para voltar ao menu..\n");
                limparBuffer();
            break;

            case 3:
                printf("|| População: %s\n",
                carta1.populacao > carta2.populacao ? "Carta 1 venceu!!" :
                (carta2.populacao > carta1.populacao ? "Carta 2 venceu!!" : "Empate!"));
                
                printf("|| Área: %s\n",
                carta1.area > carta2.area ? "Carta 1 venceu!!" : 
                (carta2.area > carta1.area ? "Carta 2 venceu!!" : "Empate!"));
                
                printf("|| PIB: %s\n",
                carta1.PIB > carta2.PIB ? "Carta 1 venceu!!" : 
                (carta2.PIB > carta1.PIB ? "Carta 2 venceu!!" : "Empate!"));
            
                printf("|| Pontos Turisticos: %s\n",
                carta1.pontosTuristicos > carta2.pontosTuristicos ? "Carta 1 venceu!!" : 
                (carta2.pontosTuristicos > carta1.pontosTuristicos ? "Carta 2 venceu!!" : "Empate!"));
                
                // a carta com o menor valor vence
                printf("|| Densidade Populacional: %s\n",
                carta1.resultados.densidadePopulacional < carta2.resultados.densidadePopulacional ? "Carta 1 venceu!!" :
                (carta2.resultados.densidadePopulacional < carta1.resultados.densidadePopulacional ? "Carta 2 venceu!!" : "Empate!"));
                
                printf("|| PIB per Capta: %s\n",
                carta1.resultados.PIBperCapta > carta2.resultados.PIBperCapta ? "Carta 1 venceu!!" : 
                (carta2.resultados.PIBperCapta > carta1.resultados.PIBperCapta ? "Carta 2 venceu!!" : "Empate!"));
                
                printf("|| Super Poder: %s\n",
                resultadoComparacaoSuper.superCarta1 > resultadoComparacaoSuper.superCarta2 ? "Carta 1 venceu!!" : 
                (resultadoComparacaoSuper.superCarta2 > resultadoComparacaoSuper.superCarta1 ? "Carta 2 venceu!!" : "Empate!"));

                printf("\n");
                printf(" Pressione ENTER para voltar ao menu..\n");
                limparBuffer();
            break;
            
            default:
                printf("Opção Inválida!");
            break;
        }
    } while (escolhaMenu != 0); //Finaliza loop do menu.    
    
    return 0;
}