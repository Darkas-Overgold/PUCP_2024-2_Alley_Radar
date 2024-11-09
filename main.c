#include <stdint.h>
//#include "tm4c123gh6pm.h"
//#include "driverlib/pin_map.h"
//#include "driverlib/sysctl.h"
//#include "driverlib/pwm.h"
//#include "driverlib/gpio.h"
//#include "driverlib/timer.h" 
// Definiciones para el servomotor y sensor ultrasónico
#define SERVO_PWM_FREQUENCY 50  // Frecuencia de 50 Hz para el servomotor
#define TRIGGER_PIN GPIO_PIN_1  // Pin PE1 para el trigger
#define ECHO_PIN GPIO_PIN_2     // Pin PE2 para el echo 
void setupServo(void);
void setupUltrasonicSensor(void);
void moveServo(uint32_t angle);
uint32_t readUltrasonicDistance(void); 
int main(void) {
    // Configurar el reloj del sistema a 50 MHz
    //SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ); 
    // Configurar el servomotor y el sensor ultrasónico
    setupServo();
    setupUltrasonicSensor(); 
    uint32_t distance;
    uint32_t angle = 0; 
    while (1) {
        // Mover el servomotor y leer la distancia
        moveServo(angle);
        distance = readUltrasonicDistance(); 
        // Imprimir la distancia (esto se enviaría a través de UART para mostrar en la interfaz web)
        printf("Angle: %d° Distance: %d cm\n", angle, distance); 
        // Incrementar el ángulo
        angle += 10;
        if (angle >= 180) {
            angle = 0;
        } 
        SysCtlDelay(2000000);  // Retardo para permitir el movimiento del servomotor
    }
} 
// Configura el PWM para el servomotor
/*void setupServo(void) {
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);
    GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_6);
    GPIOPinConfigure(GPIO_PB6_M0PWM0); 
    PWMClockSet(PWM0_BASE, PWM_SYSCLK_DIV_64);
    PWMGenConfigure(PWM0_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_0, SysCtlClockGet() / (64 * SERVO_PWM_FREQUENCY));
    /*PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, 0);
    PWMGenEnable(PWM0_BASE, PWM_GEN_0);
    PWMOutputState(PWM0_BASE, PWM_OUT_0_BIT, true);*/
//}*/
// Configura el sensor ultrasónico (puedes ajustar el temporizador según sea necesario)
/*void setupUltrasonicSensor(void) {
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, TRIGGER_PIN);
    GPIOPinTypeGPIOInput(GPIO_PORTE_BASE, ECHO_PIN);
} */
// Mueve el servomotor a un ángulo específico
/*void moveServo(uint32_t angle) {
    uint32_t pulseWidth = (angle * 5 / 180) + 5;  // Calcular el ancho de pulso
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, pulseWidth);
} */
// Lee la distancia del sensor ultrasónico
//uint32_t readUltrasonicDistance(void) {
    /*uint32_t distance; 
    GPIOPinWrite(GPIO_PORTE_BASE, TRIGGER_PIN, TRIGGER_PIN);
    SysCtlDelay(160);  // Retardo para el trigger
    GPIOPinWrite(GPIO_PORTE_BASE, TRIGGER_PIN, 0); 
    while (GPIOPinRead(GPIO_PORTE_BASE, ECHO_PIN) == 0) {}  // Espera el echo
    uint32_t start = TimerValueGet(TIMER0_BASE, TIMER_A);   // Inicia la medición 
    while (GPIOPinRead(GPIO_PORTE_BASE, ECHO_PIN) != 0) {}  // Espera a que el echo termine
    uint32_t end = TimerValueGet(TIMER0_BASE, TIMER_A);     // Termina la medición 
    distance = (end - start) * 0.034 / 2;  // Calcula la distancia
    return distance;
} */