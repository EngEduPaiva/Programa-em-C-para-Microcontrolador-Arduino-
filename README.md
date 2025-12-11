## Exemplo de Programa em C para Microcontrolador (Arduino)
Este código simula a lógica de um CLP para controlar um motor usando três botões: START, STOP e um LED que representa o MOTOR (com contato de selo). 

## Princípios de Funcionamento
Ciclo Infinito (loop()): A função loop() do Arduino funciona como o ciclo de varredura (scan cycle) contínuo de um CLP, executando repetidamente as três fases: leitura de entradas, execução da lógica e atualização de saídas.
Mapeamento de E/S: Define-se quais pinos do microcontrolador serão usados como entradas (INPUT_PULLUP) e saídas (OUTPUT).

Lógica de Controle: A seção principal implementa a lógica booleana usando operadores C (|| para OR, && para AND, ! para NOT), análogo aos contatos e bobinas em um diagrama Ladder. 

Para projetos mais avançados, que buscam uma emulação mais fiel de um ambiente de programação Ladder, existem ferramentas e bibliotecas como o OpenPLC, que compilam o código Ladder em código C para ser executado em microcontroladores como o Arduino ou Raspberry Pi.