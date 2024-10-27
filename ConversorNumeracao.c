#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

void mostrarMenu();
void decimalparatudo(int decimal);
void binarioparatudo(char binario[]);
void octalparatudo(char octal[]);
void hexaparatudo(char hexa[]);
void decimalparabinario(int decimal);
void decimalparaoctal(int decimal);
void decimalparahexa(int decimal);
int binarioparadecimaletudo(const char *binario);
int octalparadecimaletudo(const char *octal);
int hexaparadecimaletudo(const char *hexa);
int validarBinario(const char *binario);

void mostrarMenu() {
    printf("-----------------------------Menu-------------------------------- \n\n");
    printf("1 - Decimal para todas as bases \n");
    printf("2 - Binario para todas as bases \n");
    printf("3 - Octal para todas as bases \n");
    printf("4 - Hexadecimal para todas as bases \n");
    printf("5 - Sair \n");
}

void decimalparatudo(int decimal) {
    if (decimal == 0) {
        printf("Binario: 0\n");
        printf("Octal: 0\n");
        printf("Hexadecimal: 0\n");
    } else {
        decimalparabinario(decimal);
        decimalparaoctal(decimal);
        decimalparahexa(decimal);
    }
}

void binarioparatudo(char binario[]) {
    if (validarBinario(binario)) {
        if (strcmp(binario, "0") == 0) { //sophia, lembra: compara duas strings e retorna um valor inteiro
            printf("Decimal: 0\n");
            printf("Octal: 0\n");
            printf("Hexadecimal: 0\n");
        } else {
            int decimal = binarioparadecimaletudo(binario);
            printf("\nEm decimal: %d\n", decimal);
            decimalparatudo(decimal); 
        }
    } else {
        printf("Numero binario invalido.\n");
    }
}

int validarBinario(const char *binario) {
    for (int i = 0; i < strlen(binario); i++) {
        if (binario[i] != '0' && binario[i] != '1') {
            return 0; // A string não é um número binário válido
        }
    }
    return 1; // sophia, se todos os caracteres forem 0 ou 1 msm, a string é um num binário válido
}


void octalparatudo(char octal[]) {
    if (strcmp(octal, "0") == 0) { 
        printf("Decimal: 0\n");
        printf("Binario: 0\n");
        printf("Hexadecimal: 0\n");
    } else {
        int decimal = octalparadecimaletudo(octal);
        printf("\nEm decimal: %d\n", decimal);
        decimalparatudo(decimal);
    }
}

void hexaparatudo(char hexa[]) {
    if (strcmp(hexa, "0") == 0) {
        printf("Decimal: 0\n");
        printf("Binario: 0\n");
        printf("Octal: 0\n");
    } else {
        int decimal = hexaparadecimaletudo(hexa);
        printf("\nEm decimal: %d\n", decimal);
        decimalparatudo(decimal);
    }
}

void decimalparabinario(int decimal) {
    int binario[32], i = 0, j;
    while (decimal > 0) {
        binario[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }
    printf("Em binario: ");
    for (j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]); //imprimir a ordem contráriaaaaa
    }
    printf("\n");
}

void decimalparaoctal(int decimal) {
    int octal[32], i = 0, j;
    while (decimal > 0) {
        octal[i] = decimal % 8;
        decimal = decimal / 8;
        i++;
    }
    printf("Em octal: ");
    for (j = i - 1; j >= 0; j--) {
        printf("%d", octal[j]);
    }
    printf("\n");
}

void decimalparahexa(int decimal) {
    char hexa[32];
    int i = 0, j;
    while (decimal > 0) {
        int temporario = decimal % 16;
        if (temporario < 10) {
            hexa[i] = temporario + '0';
        } else {
            hexa[i] = temporario - 10 + 'A'; //volta aqui sophiaaaaaaaaaaaaaaa
                                            //Verifica se o dígito é menor que 10. 
											//se for, converte para caractere 0 a 9. caso contrário, converte para uma letra A a F.
        }
        decimal = decimal / 16;
        i++;
    }
    printf("Em hexadecimal: ");
    for (j = i - 1; j >= 0; j--) {
        printf("%c", hexa[j]);
    }
    printf("\n");
}

int binarioparadecimaletudo(const char *binario) {
    int tamanho = strlen(binario);
    int decimal = 0;

    for (int i = 0; i < tamanho; i++) {
        if (binario[tamanho - 1 - i] == '1') {
            decimal += pow(2, i);
        }
    }
    return decimal;
}

int octalparadecimaletudo(const char *octal) {
    int decimal = strtol(octal, NULL, 8); //lembra que esse strtol converte uma string para um valor inteiro longo 
    return decimal;
}

int hexaparadecimaletudo(const char *hexa) {
    int decimal = strtol(hexa, NULL, 16);
    return decimal;
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    int opcaoMenu, decimal;
    char octal[50], binario[50], hexa[32];

    do {
        printf("\nOie! Esse e o Conversor de bases da Sophia! :) \n\n");

        mostrarMenu();

        printf("\nDigite o numero correspondente a opcao desejada: ");
        scanf("%d", &opcaoMenu);

        system("cls");

        switch (opcaoMenu) {
            case 1:
                printf("\n\nDigite o numero decimal: ");
                scanf("%d", &decimal);
                system("cls");
                printf("O decimal %d convertido para todas as bases: \n\n", decimal);
                decimalparatudo(decimal);
                system("pause");
                system("cls");
                break;

            case 2:
                printf("\n\nDigite o numero binario: ");
                scanf("%s", binario);
                system("cls");
                printf("O binario %s convertido para todas as bases: \n\n", binario);
                binarioparatudo(binario);
                system("pause");
                system("cls");
                break;

            case 3:
                printf("\n\nDigite o numero octal: ");
                scanf("%s", octal);
                system("cls");
                printf("O octal %s convertido para todas as bases: \n\n", octal);
                octalparatudo(octal);
                system("pause");
                system("cls");
                break;

            case 4:
            printf("\n\nDigite o numero hexadecimal: ");
            scanf("%s",hexa);
            system("cls");
            printf("O hexadecimal %s convertido para todas as bases: \n\n",hexa);
            hexaparatudo(hexa);
            system("pause");
            system("cls");
            break;
            

        case 5:
            printf("Tchauzinho ;)\n");
            break;

        default:
            printf("Opcao invalida! Tente novamente.\n");
            break;
    }

}while(opcaoMenu != 5);

    return 0;
}
//compilador: DevC++ ; Sistema operacional utilizado: Windows