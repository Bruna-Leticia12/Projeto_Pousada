//
// Created by bru-leticia on 23/11/23.
//
#include "funcaoHotel.h"

// Função para realizar uma reserva
void fazerReserva(Reserva* reservas, int* totalReservas) {

    // Geração de um número de quarto aleatório
    int numeroQuarto = (rand() % 10) + 1;
    int numHospedes;

    // Verificação da capacidade máxima de reservas
    if (*totalReservas < MAX_RESERVAS) {

        // Leitura do nome do hóspede, número de pessoas e dias de reserva
        printf("Digite qual o nome do hóspede: \n");
        fgets(reservas[*totalReservas].hospede, 100, stdin);

        // Remoção do caractere de nova linha (\n) se estiver presente
        reservas[*totalReservas].hospede[strcspn(reservas[*totalReservas].hospede, "\n")] = '\0';
        printf("Digite quantas pessoas ficarão hospedadas: \n");
        scanf("%d", &numHospedes);
        reservas[*totalReservas].numHospedes = numHospedes;
        printf("Digite qual número de dias que deseja ficar hospedado: \n");
        scanf("%d", &reservas[*totalReservas].diasReservados);
        reservas[*totalReservas].statusReserva = 2;
        reservas[*totalReservas].numeroQuarto = numeroQuarto;
        cadastroHospedes(&reservas[*totalReservas]);
        (*totalReservas)++;
        printf("Reserva realizada para o quarto %d, informe o número do quarto no check-in\n", numeroQuarto);
    }
    else {
        printf("Não foi possível realizar sua reserva, a pousada está lotada!!\n");
    }
}

// Função para realizar o check-in de um hóspede
void realizarCheckIn(Reserva* reservas, int totalReservas) {
    int numeroQuarto;

    // Leitura do número do quarto da reserva para realizar o check-in
    printf("Digite o número do quarto da reserva para realizar o check-in: ");
    scanf("%d", &numeroQuarto);

    // Busca pela reserva correspondente ao quarto
    for (int i = 0; i < totalReservas; i++) {
        if (reservas[i].numeroQuarto == numeroQuarto && reservas[i].statusReserva == 2) {
            char resposta[3];

            // Confirmação do nome da reserva
            printf("Reserva realizada em nome de %s, está correto? (Digite 'S' para Sim ou 'N' para Não): ", reservas[i].hospede);
            scanf("%s", resposta);

            // Conversão para maiúsculas usando toupper
            resposta[0] = toupper(resposta[0]);

            // Verificação da confirmação
            if (strcmp(resposta, "S") == 0) {
                reservas[i].statusReserva = 1;
                //reservaEncontrada.statusReserva = 1;
                printf("Check-in realizado com sucesso para o quarto %d. Bem Vindo a Pousada LIBÉLULA, %s!\n", numeroQuarto, reservas[i].hospede);
                return;
            }
            else {
                printf("Check-in não realizado! Confirme o número do quarto e o nome da reserva, depois tente novamente.\n");
                return;
            }
        }
    }
    printf("Nenhuma reserva encontrada para o quarto %d. Confirme o número do quarto e tente novamente.\n", numeroQuarto);
}

// Função para calcular o valor total das diárias de uma reserva
float calcularValorDiarias(Reserva* reserva) {
    float valorTotal = 0.0;

    // Cálculo do valor total das diárias
    valorTotal = reserva->diasReservados * DIARIA_BASE;

    // Adicional por pessoa, se mais de uma pessoa estiver hospedada
    if (reserva->numHospedes > 1) {
        valorTotal += (reserva->numHospedes - 1) * ADICIONAL_POR_PESSOA * reserva->diasReservados;
    }
    return valorTotal;
}

// Função para exibir o menu do frigobar e calcular o valor total do consumo
float menuFrigobar() {
    float totalConsumo = 0.0;
    char opcao;

    // Exibição do menu do frigobar
    printf("\n==================== MENU FRIGOBAR ====================\n");
    printf("1.\tÁgua.......................................R$ 5.00\n");
    printf("2.\tAmendoim...................................R$ 6.00\n");
    printf("3.\tCerveja....................................R$ 9.00\n");
    printf("4.\tChocolate..................................R$ 7.50\n");
    printf("5.\tRefrigerante...............................R$ 6.80\n");
    printf("6.\tSnack......................................R$ 10.00\n");
    printf("0.\tSair do menu\n");
    printf("=======================================================\n");

    // Loop para escolha dos itens do frigobar
    do {
        printf("\nEscolha uma opção referente ao consumo: \n");
        scanf(" %c", &opcao);

        // Switch para lidar com as opções do frigobar
        switch (opcao) {
            case '1':
                totalConsumo += 5.00;
                break;
            case '2':
                totalConsumo += 6.00;
                break;
            case '3':
                totalConsumo += 9.00;
                break;
            case '4':
                totalConsumo += 7.50;
                break;
            case '5':
                totalConsumo += 6.80;
                break;
            case '6':
                totalConsumo += 10.00;
                break;
            case '0':
                printf("Fechando a conta...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente!\n");
        }
    } while (opcao != '0');

    return totalConsumo;
}

// Função para realizar o check-out de um hóspede
void realizarCheckOut(Reserva* reservas, int totalReservas) {
    int numeroQuarto;

    // Leitura do número do quarto para realizar o check-out
    printf("Digite o número do quarto para realizar o check-out: \n");
    scanf("%d", &numeroQuarto);

    // Busca pela reserva correspondente ao quarto
    for (int i = 0; i < totalReservas; i++) {
        if (reservas[i].numeroQuarto == numeroQuarto && reservas[i].statusReserva == 1) {
            char respostaConsumo;

            // Pergunta sobre o consumo durante a estadia
            printf("Houve algum consumo durante a estadia? ('S' para Sim ou 'N' para Não): \n");
            scanf(" %c", &respostaConsumo);

            // Conversão para maiúsculas usando toupper
            respostaConsumo = toupper(respostaConsumo);

            // Verificação da resposta
            if (toupper(respostaConsumo) == 'S') {
                float valorDiarias = calcularValorDiarias(&reservas[i]);
                float valorConsumo = menuFrigobar();
                float valorTotal = valorDiarias + valorConsumo;

                // Exibição da nota fiscal
                printf("\n===================== NOTA FISCAL =====================\n");
                printf("\n");
                printf("Valor total das diárias:...................R$ %.2f\n", valorDiarias);
                printf("Valor total do consumo frigobar:...........R$ %.2f\n", valorConsumo);
                printf("Valor total a pagar:.......................R$ %.2f\n", valorTotal);
                printf("\n");
                printf("=======================================================\n");
            }
            else {

                // Exibição do valor total das diárias sem consumo
                float valorDiarias = calcularValorDiarias(&reservas[i]);
                printf("Valor total das diárias: R$ %.2f\n", valorDiarias);

                /// Exibição da nota fiscal sem consumo
                printf("\n===================== NOTA FISCAL =====================\n");
                printf("\n");
                printf("Valor total das diárias:...................R$ %.2f\n", valorDiarias);
                printf("\n");
                printf("=======================================================\n");
            }

            // Mensagem de check-out realizado
            printf("\nCheck-out realizado para o quarto %d. Obrigado %s por se hospedar na Pousada LIBÉLULA, volte sempre!!\n", numeroQuarto, reservas[i].hospede);
            reservas[i].statusReserva = 0;
            return;
        }
    }

    // Mensagem de erro se nenhuma reserva válida for encontrada para o quarto
    printf("Não foi possível encontrar uma reserva válida para o quarto %d. Check-out não realizado, confirme o número do quarto e tente novamente.\n", numeroQuarto);
}

// Função para visualizar o estado atual das reservas nos quartos
void visualizarReservas(Reserva* reservas, int totalReservas) {
    printf("\n================ OCUPAÇÃO DOS QUARTOS ================\n");

    // Loop para percorrer os quartos de 1 a 10
    for (int i = 1; i <= 10; i++) {
        int quartoEncontrado = 0;

        // Loop para buscar a reserva correspondente ao quarto
        for (int j = 0; j < totalReservas; j++) {
            if (reservas[j].numeroQuarto == i) {
                quartoEncontrado = 1;

                // Exibição do estado do quarto (livre, reservado, check-in realizado)
                printf("Quarto %d: ", i);
                if (reservas[j].statusReserva == 0) {
                    printf("Livre\n");
                }
                else if (reservas[j].statusReserva == 2) {
                    printf("Reservado para %s por %d dias\n", reservas[j].hospede, reservas[j].diasReservados);
                }
                else {
                    printf("Check-in realizado para %s por %d dias\n", reservas[j].hospede, reservas[j].diasReservados);
                }
                break;
            }
        }

        // Se nenhum quarto correspondente foi encontrado, exibe que o quarto está livre
        if (!quartoEncontrado) {
            printf("Quarto %d: Livre\n", i);
        }
    }
    printf("======================================================\n");
}

// Função para cadastrar informações adicionais do hóspede
void cadastroHospedes(Reserva* reserva) {

    // Leitura de informações como CPF, DDD, telefone e cidade do hóspede
    printf("DADOS DO CADASTRO\n");
    scanf("%*c");

    printf("CPF: ");
    fgets(reserva->cpf, 17, stdin);
    reserva->cpf[strcspn(reserva->cpf, "\n")] = '\0';

    printf("DDD: ");
    fgets(reserva->DDD, 6, stdin);
    reserva->DDD[strcspn(reserva->DDD, "\n")] = '\0';

    printf("Telefone: ");
    fgets(reserva->telefone, 15, stdin);
    reserva->telefone[strcspn(reserva->telefone, "\n")] = '\0';

    printf("Cidade: ");
    fgets(reserva->cidade, 100, stdin);
    reserva->cidade[strcspn(reserva->cidade, "\n")] = '\0';

    printf("Hóspede cadastrado com sucesso!\n");
}
