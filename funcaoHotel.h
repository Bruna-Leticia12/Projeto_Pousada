//
// Created by bru-leticia on 23/11/23.
//

#ifndef PROJETOHOTEL_FUNCAOHOTEL_H
#define PROJETOHOTEL_FUNCAOHOTEL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RESERVAS 10
#define DIARIA_BASE 180.00
#define ADICIONAL_POR_PESSOA 50.00

/** Definição da estrutura Reserva */
typedef struct {
    int numeroQuarto;
    char hospede[100];
    char nomeCompleto[100];
    char cpf[17];
    char DDD[6];
    char telefone[15];
    char cidade[100];
    int statusReserva;
    int diasReservados;
    int numHospedes;
} Reserva;

/**
 * Função para realizar uma reserva
 * void: Indica que a função não retorna nenhum valor
 * fazerReserva: É o nome da função
 * (Reserva* reservas, int* totalReservas): Sãs parâmetros da função.
 * Reserva* reservas: Ponteiro para a estrutura Reserva. A função espera receber como argumento um endereço de memória onde está armazenada uma variável do tipo Reserva.
 * int* totalReservas: Ponteiro para um inteiro. A função espera receber o endereço de memória de uma variável inteira que será usada para rastrear o número total de reservas.
 */
void fazerReserva(Reserva* reservas, int* totalReservas);


/**
 * Função para realizar o check-in de um hóspede
 * void: Indica que a função não retorna nenhum valor
 * realizarCheckIn: É o nome da função
 * (Reserva* reservas, int* totalReservas): Sãs parâmetros da função.
 * Reserva* reservas: Ponteiro para a estrutura Reserva. A função espera receber como argumento um endereço de memória onde está armazenada uma variável do tipo Reserva.
 * int* totalReservas: Ponteiro para um inteiro. A função espera receber o endereço de memória de uma variável inteira que será usada para rastrear o número total de reservas.
 */
void realizarCheckIn(Reserva* reservas, int totalReservas);


/**
 * Função para calcular o valor total das diárias de uma reserva
 * float: Indica que a função retorna um valor do tipo ponto flutuante.
 * calcularValorDiarias: É o nome da função
 * (Reserva* reserva): É o parâmetro da função.
 * Reserva* reserva: Ponteiro para a estrutura Reserva. Função espera receber como argumento o endereço de memória onde está armazenada uma variável do tipo Reserva.
 * Este ponteiro permite que a função acesse os dados da estrutura de reserva para calcular o valor das diárias.
 */
float calcularValorDiarias(Reserva* reserva);


/**
 * Função para exibir o menu do frigobar e calcular o valor total do consumo
 * float: Indica que a função retorna um valor do tipo ponto flutuante, que representa o total do consumo no frigobar.
 * menuFrigobar: É o nome da função
 * (): Parênteses vazios: Indica que a função não aceita nenhum parâmetro de entrada.
 * Função que trata de interações diretas com o usuário que permiti que a escolha dos itens e calcular, o custo total com base nas escolhas do usuário.
 */
float menuFrigobar();


/**
 * Função para realizar o check-out de um hóspede
 * void: Indica que a função não retorna nenhum valor
 * realizarCheckOut: É o nome da função
 * (Reserva* reservas, int* totalReservas): Sãs parâmetros da função.
 * Reserva* reservas: Ponteiro para a estrutura Reserva. A função espera receber como argumento um endereço de memória onde está armazenada uma variável do tipo Reserva.
 * int* totalReservas: Ponteiro para um inteiro. A função espera receber o endereço de memória de uma variável inteira que será usada para rastrear o número total de reservas.
 */
void realizarCheckOut(Reserva* reservas, int totalReservas);

/**
 * Função para visualizar o estado atual das reservas nos quartos
 * void: Indica que a função não retorna nenhum valor
 * visualizarReservas: É o nome da função
 * (Reserva* reservas, int* totalReservas): Sãs parâmetros da função.
 * Reserva* reservas: Ponteiro para a estrutura Reserva. A função espera receber como argumento um endereço de memória onde está armazenada uma variável do tipo Reserva.
 * int* totalReservas: Ponteiro para um inteiro. A função espera receber o endereço de memória de uma variável inteira que será usada para rastrear o número total de reservas.
 */
void visualizarReservas(Reserva* reservas, int totalReservas);


/**
 * Função para cadastrar informações adicionais do hóspede
 * void: Indica que a função não retorna nenhum valor
 * cadastroHospedes: É o nome da função
 * (Reserva* reserva): É o parâmetro da função.
 * Reserva* reservas: Ponteiro para a estrutura Reserva. A função espera receber como argumento um endereço de memória onde está armazenada uma variável do tipo Reserva.
 * Permite que a função acesse e modifique os dados da estrutura de reserva para realizar o cadastro do hóspede, informações adicionais como CPF, DDD, telefone e cidade, e armazenar essas informações na estrutura Reserva.
 */
void cadastroHospedes(Reserva* reserva);

#endif //PROJETOHOTEL_FUNCAOHOTEL_H
