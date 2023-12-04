
# Sistema de Reservas - Pousada
## Contexto
### Este projeto foi desenvolvido como parte dos requisitos da disciplina de Linguagem de Programação do Curso de Análise e Desenvolvimento de Sistemas da Faculdade de Tecnologia de Mogi Mirim e teve como objetivo proporcionar a prática e aplicação dos conceitos aprendidos em sala de aula, abordando temas como estruturas de controle, funções e manipulação de dados por meio da linguagem C.
### Como Utilizar
#### Ao iniciar o programa, o menu principal será apresentado, permitindo que o usuário insira o número da opção desejada e, em seguida, pressione a tecla 'Enter' para dar continuidade ao processo, seguindo as instruções fornecidas pelo programa para cada operação.
### Funcionalidades
O menu principal foi projetado para oferecer uma experiência simples e intuitiva aos usuários. Ao iniciá-lo, será exibida uma mensagem de boas vindas, conforme segue abaixo:
***"Seja Bem Vindo à Pousada LIBÉLULA!"***
Em seguida o usuário poderá realizar sua escolha de acordo com as opções indicadas, conforme demonstrado:
0. Sair
1. Realizar o cadastro da Reserva
2. Realizar Check-In
3. Realizar Check-Out
4. Visualizar Reservas da Pousada   
   Ao escolher a opção "1" do menu, o sistema permite que o usuário faça uma reserva. Para isto, deverá fornecer informações tais como nome e sobrenome, número de pessoas, número de dias de permanência na pousada, CPF, DDD e telefone.
   O cadastro será realizado, a reserva registrada no sistema e um número de quarto livre será atribuído. Posteriormente, a mensagem abaixo será exibida:  
   ***"Reserva realizada para o quarto [NÚMERO], informe o número do quarto no check-in"***
   No entanto, o sistema está apto a verificar automaticamente se a capacidade máxima de reservas foi atingida, isto é, 10 quartos. Caso exceda este limite, a mensagem abaixo será exibida:
   ***"Não foi possível realizar sua reserva, a pousada está lotada!!***
   Ao escolher a opção "2", será possível realizar o check-in para a reserva existente.
   O usuário informa o número do quarto indicado inicialmente, em seguida o sistema pedirá que confirme os detalhes exibidos, conforme mensagem demontrada abaixo:
   ***"Reserva realizada em nome de [NOME DO USUÁRIO], está correto? (Digite 'S' para Sim ou 'N' para Não):"***
   O sistema aceitará as entradas 'S' e 'N' independentemente de estarem em maiúsculo ou minúsculo.
   Se confirmado, o status da reserva será atualizado e a mensagem abaixo será exibida:
   ***"Check-in realizado com sucesso para o quarto [NÚMERO DO QUARTO]. Bem Vindo a Pousada LIBÉLULA, [NOME DO USUÁRIO]!"***
   Em caso negativo, o sistema exibirá a mensagem abaixo e o usuário será convidado a verificar as informações novamente:
   ***"Check-in não realizado! Confirme o número do quarto e o nome da reserva, depois tente novamente."***
   Neste momento do check-in, caso o usuário entre com o número incorreto do quarto, será exibida a mensagem:
   ***"Nenhuma reserva encontrada para o quarto [NÚMERO DO QUARTO]. Confirme o número do quarto e tente novamente."***
   Ao escolher a opção "3", o sistema permitirá realizar o check-out, no entanto apenas se houve check-in e somente para o quarto ocupado, o qual deverá ser indicado corretamente pelo usuário.
   Neste instante, o usuário será questionado quanto ao possível consumo de itens do frigobar, devendo responder com "S" para *Sim* ou "N" para *Não*, novamente podendo ser em maiúsculo ou minúsculo. Em caso positivo, serão exibidos o menu e a mensagem abaixo:
   ==================== MENU FRIGOBAR ====================
0. Sair do menu
1. Água.......................................R$ 5.00
2. Amendoim...................................R$ 6.00
3. Cerveja....................................R$ 9.00
4. Chocolate..................................R$ 7.50
5. Refrigerante...............................R$ 6.80
6. Snack......................................R$ 10.00
   =======================================================
   ***"Escolha uma opção referente ao consumo:"***
   Deste modo, o usuário deverá indicar quais foram os itens consumidos de acordo com o número correspondente do menu frigobar, para que assim o sistema calcule os gastos e some-os com o valor da estadia. Em caso de consumo duplicado de itens, será necessário inserir as opções correspondentes de forma repetida.
   Logo após a indicação de consumo, o usuário deverá digitar a opção "0" para fechar a conta, assim, uma nota fiscal será exibida contendo a somatória das diárias e do consumo:
   ***===================== NOTA FISCAL =====================***

***Valor total das diárias:...................R$ 00,00***   
***Valor total do consumo frigobar:...........R$ 00,00***  
***Valor total a pagar:.......................R$ 00,00***     
***=======================================================***
Caso o usuário indique que não houve consumo de itens do frigobar, será exibida a nota fiscal contendo somente o valor da estadia, de acordo o número de dias de permanência na pousada, conforme demonstrado abaixo:
***"Valor total das diárias: R$ 00,00"***
***===================== NOTA FISCAL =====================***
***Valor total das diárias:...................R$ 00,00***
***=======================================================***
Em ambas as opções (com ou sem consumo), ao fechar a conta, o status da reserva será atualizado para "check-out realizado", sendo exibida a mensagem abaixo:
***"Check-out realizado para o quarto [NÚMERO DO QUARTO]. Obrigado [NOME DO USUÁRIO] por se hospedar na Pousada LIBÉLULA, volte sempre!!"***
No entanto, caso o usuário entre com o número incorreto do quarto no momento do check-out, será exibida a mensagem:
***"Não foi possível encontrar uma reserva válida para o quarto [NÚMERO DO QUARTO]. Check-out não realizado, confirme o número do quarto e tente novamente."***
Ao escolher a opção "4" será exibida uma lista de todas as reservas e vagas livres existentes na pousada, incluindo o nome dos hóspedes e status de ocupação do quarto no momento. Abaixo o exemplo de exibição deste item do menu:
***================ OCUPAÇÃO DOS QUARTOS ================***
***Quarto 1: Livre***  
***Quarto 2: Reservado para [HÓSPEDE 1] por [NÚMERO] dias***  
***Quarto 3: Check-in realizado para [HÓSPEDE 2] por [NÚMERO] dias***  
***Quarto 4: Livre***  
***Quarto 5: Livre***  
***Quarto 6: Reservado para [HÓSPEDE 3] por [NÚMERO] dias***  
***Quarto 7: Check-in realizado para [HÓSPEDE 4] por [NÚMERO] dias***  
***Quarto 8: Livre***  
***Quarto 9: Livre***  
***Quarto 10: Livre***
Ao escolher a opção "0" do menu principal, o programa será encerrado e será exibida a mensagem:
***"Saindo do menu... Até logo!!".***
De forma geral, espera-se que o usuário insira corretamente os números correspondentes às opções do menu principal. Caso uma entrada inválida seja detectada, será solicitado ao usuário que tente novamente, sendo exibida a mensagem abaixo:
***"Está opção está inválida!! Vamos tentar novamente."***
## Authors
- [@bruna leticia](https://github.com/)
- [@bruna marques](https://github.com/)
- [@NathAssis](https://github.com/NathAssis)
