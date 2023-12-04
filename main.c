#include <stdio.h>

#include "funcaoHotel.h"

int main() {

    // Declaração de variáveis
    Reserva reservas[MAX_RESERVAS];  // Array para armazenar as reservas
    int totalReservas = 0;  // Contador para acompanhar o número total de reservas
    int opcao;

    // Loop do menu principal
    do {

        // Exibição do menu
        printf("\n");
        printf("*******************************************************\n");
        printf("\nSeja Bem Vindo a Pousada LIBÉLULA\n");
        printf("\n");
        printf("No menu abaixo você encontrará as opções disponíveis\n");
        printf("\n======================== MENU ========================\n");
        printf("1.\tRealizar o cadastro da Reserva\n");
        printf("2.\tRealizar Check-In\n");
        printf("3.\tRealizar Check-Out\n");
        printf("4.\tVisualizar Reservas da Pousada\n");
        printf("0.\tSair\n");
        printf("======================================================\n");

        printf("\nEscolha uma opção que deseja: ");
        // Leitura da opção do usuário
        scanf("%d", &opcao);
        scanf("%*c");

        // Switch para lidar com as opções do menu
        switch (opcao) {
            case 1:
                fazerReserva(reservas, &totalReservas);
                break;
            case 2:
                realizarCheckIn(reservas, totalReservas);
                break;
            case 3:
                realizarCheckOut(reservas, totalReservas);
                break;
            case 4:
                visualizarReservas(reservas, totalReservas);
                break;
            case 0:
                printf("Saindo do menu... Até logo!!\n");
                break;
            default:
                printf("Está opção está inválida!! Vamos tentar novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}

