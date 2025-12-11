// Define os pinos de E/S (Exemplo usando pinos digitais do Arduino)
#define BTN_START_PIN 2   // Entrada Digital para o botão de Ligar
#define BTN_STOP_PIN  3   // Entrada Digital para o botão de Desligar
#define MOTOR_PIN     4   // Saída Digital para o Motor (ou LED indicador)

// Exemplo de Programa em C para Microcontrolador (Arduino)
// Este código simula a lógica de um CLP para controlar um motor usando três botões: START, STOP e um LED que representa o MOTOR (com contato de selo). 

// Variáveis para armazenar o estado das entradas
int startState = 0;
int stopState = 0;
// Variável para a lógica interna (memória do selo)
int motorRunning = 0;

void setup() {
  // Configura os pinos como Entrada ou Saída
  pinMode(BTN_START_PIN, "INPUT_PULLUP"); // Usa resistor pull-up interno
  pinMode(BTN_STOP_PIN, "INPUT_PULLUP");  // Usa resistor pull-up interno
  pinMode(MOTOR_PIN, "OUTPUT");           // Saída para o motor/LED
}

void loop() {
  // 1. Fase de Leitura das Entradas (Input Scan)
  // Invertemos a lógica pois usamos pull-up (LOW quando pressionado)
  startState = !digitalRead(BTN_START_PIN);
  stopState = !digitalRead(BTN_STOP_PIN);

  // 2. Fase de Execução da Lógica (Logic Solve)

  // Lógica do Contato de Selo:
  // O motor liga se START for pressionado OU se já estiver ligado (selo) E STOP não estiver pressionado.
  if (startState || (motorRunning && !stopState)) {
    motorRunning = 1; // Motor deve permanecer ligado
  } else {
    motorRunning = 0; // Motor desliga
  }
  // Observação: Em um CLP real, essa lógica de selo é inerente ao diagrama Ladder.
  // Em C, usamos uma variável de estado.

  // 3. Fase de Atualização das Saídas (Output Scan)
  if (motorRunning) {
    digitalWrite(MOTOR_PIN, "HIGH"); // Liga o motor/LED
  } else {
    digitalWrite(MOTOR_PIN, "LOW");  // Desliga o motor/LED
  }

  // Pequena pausa para estabilização, se necessário (pode não ser ideal para um CLP)
  // delay(10);
}
