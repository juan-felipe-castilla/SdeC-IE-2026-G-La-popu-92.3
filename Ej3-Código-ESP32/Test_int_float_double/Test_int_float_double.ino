#include <Arduino.h>

const unsigned long ITERACIONES = 71990000UL; 

void setup() {
  setCpuFrequencyMhz(240); // ajustamos la freq de la ESP
  Serial.begin(115200);

  while (!Serial) { delay(10); } // aseguramos la conexion serial

  delay(2000); 
  
  Serial.println("=========================================");
  Serial.println("  BENCHMARK DE RENDIMIENTO - ESP32       ");
  Serial.println("=========================================");
  Serial.print("Frecuencia CPU: ");
  Serial.print(getCpuFrequencyMhz());
  Serial.println(" MHz");
  Serial.printf("Iteraciones por prueba: %lu\n\n", ITERACIONES);

  // ----------------------------------------------------
  // PRUEBA 1: Suma de Enteros (uint32_t)
  // ----------------------------------------------------
  Serial.println("1. Iniciando prueba de ENTEROS (uint32_t)...");
  
  volatile uint32_t suma_int = 0;
  unsigned long inicio_int = millis();

  for (unsigned long i = 0; i < ITERACIONES; i++) {
    suma_int += 1;
  }

  unsigned long tiempo_int = millis() - inicio_int;
  float segundos_int = tiempo_int / 1000.0;

  Serial.printf("   -> Completado en: %lu ms (%.2f segundos)\n", tiempo_int, segundos_int);
  Serial.printf("   -> Resultado final: %u\n\n", suma_int);


  // ----------------------------------------------------
  // PRUEBA 2: Suma de Flotantes (float - 32 bits)
  // ----------------------------------------------------
  Serial.println("2. Iniciando prueba de FLOATS (32 bits)...");

  volatile float suma_float = 0.0f;
  unsigned long inicio_float = millis();

  for (unsigned long i = 0; i < ITERACIONES; i++) {
    suma_float += 1.0001f;
  }

  unsigned long tiempo_float = millis() - inicio_float;
  float segundos_float = tiempo_float / 1000.0;

  Serial.printf("   -> Completado en: %lu ms (%.2f segundos)\n", tiempo_float, segundos_float);
  Serial.printf("   -> Resultado final: %.2f\n\n", suma_float);


  // ----------------------------------------------------
  // PRUEBA 3: Suma de Doble Precisión (double - 64 bits)
  // ----------------------------------------------------
  Serial.println("3. Iniciando prueba de DOUBLES (64 bits)...");

  volatile double suma_double = 0.0;
  unsigned long inicio_double = millis();

  for (unsigned long i = 0; i < ITERACIONES; i++) {
    suma_double += 1.0001;
  }

  unsigned long tiempo_double = millis() - inicio_double;
  float segundos_double = tiempo_double / 1000.0;

  Serial.printf("   -> Completado en: %lu ms (%.2f segundos)\n", tiempo_double, segundos_double);
  Serial.printf("   -> Resultado final: %.4f\n\n", suma_double);

  Serial.println("=========================================");
  Serial.println("Pruebas finalizadas.");
}

void loop() {
  
}