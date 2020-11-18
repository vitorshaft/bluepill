#include <MapleFreeRTOS821.h>

#include <TMP1075.h>
#include <Arduino.h>

#define BOARD_LED_PIN PC13
#define LED_PIN PB11


TwoWire wire = Wire;
TMP1075::TMP1075 tmp1075 = TMP1075::TMP1075(wire);
 
static void task1(void *pvParameters) {

    
  for (;;) {
      vTaskDelay(1000);
      tmp1075.setConversionTime(TMP1075::ConversionTime220ms);
      //Serial.print(tmp1075.getTemperatureCelsius());
      //Serial.print("\n");
      //digitalWrite(BOARD_LED_PIN, HIGH);
      //vTaskDelay(1000);
      //digitalWrite(BOARD_LED_PIN, LOW);
  }
}
 
static void task2(void *pvParameters) {
  for (;;) {
      vTaskDelay(200);
      digitalWrite(LED_PIN, HIGH);
      vTaskDelay(200);
      digitalWrite(LED_PIN, LOW);
  }
}
 
void setup() 
{
  //pinMode(BOARD_LED_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  //Serial.begin(115200);
  tmp1075.begin();
  xTaskCreate(task2,"Task1",
              configMINIMAL_STACK_SIZE,NULL,tskIDLE_PRIORITY + 2,NULL);
  xTaskCreate(task1,"Task1",
              configMINIMAL_STACK_SIZE,NULL,tskIDLE_PRIORITY + 2,NULL);
  vTaskStartScheduler();
}
 
void loop() 
{
}
