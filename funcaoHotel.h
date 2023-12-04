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

// Definição da estrutura Reserva
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

// Função para realizar uma reserva
void fazerReserva(Reserva* reservas, int* totalReservas);

// Função para realizar o check-in de um hóspede
void realizarCheckIn(Reserva* reservas, int totalReservas);

// Função para calcular o valor total das diárias de uma reserva
float calcularValorDiarias(Reserva* reserva);

// Função para exibir o menu do frigobar e calcular o valor total do consumo
float menuFrigobar();

// Função para realizar o check-out de um hóspede
void realizarCheckOut(Reserva* reservas, int totalReservas);

// Função para visualizar o estado atual das reservas nos quartos
void visualizarReservas(Reserva* reservas, int totalReservas);

// Função para cadastrar informações adicionais do hóspede
void cadastroHospedes(Reserva* reserva);

#endif //PROJETOHOTEL_FUNCAOHOTEL_H
