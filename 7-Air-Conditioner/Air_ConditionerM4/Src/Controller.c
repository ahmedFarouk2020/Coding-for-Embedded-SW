/*
 * Controller.c (PollClient)
 *
 *  Created on: Apr 20, 2022
 *      Author: Farouk
 */

#include "Controller.h"
#include "PWMTimer.h"

#include "USART.h" // for debugging

const float32_type Kp = 0.1;
const float32_type Ki = 0.01;
const float32_type Kd = 0;

static float32_type MaxActuatingSig;
static float32_type DesiredTemprature;
volatile float32_type ActualTemprature;
volatile float32_type Error[2];
volatile float32_type ActuatingSig;

void Controller_Init(void)
{
    // initialize all variables
    ActualTemprature = 0.0;
    DesiredTemprature = 30.0;
    Error[0] = 30.0;
    Error[1] = 30.0;
    ActuatingSig = 0.0;
}

void Controller_CalculateActuateSig(void)
{
    ActuatingSig = (Kp * (double)Error[0] + Kd*(double)(Error[0]-Error[1]) + Ki*(double)(Error[0]+Error[1]) );
    if (ActuatingSig < 0.0)
    {
        ActuatingSig = 0.0;
    }
    ActuatingSig = (MaxActuatingSig < ActuatingSig) ? MaxActuatingSig : ActuatingSig;
}

float32_type Controller_MapToPwmLevels(void)
{
    /* output_start + slope * (input - input_start) */
    return ((0.73 - 0) / ((double)MaxActuatingSig - 0) * (double)ActuatingSig);
}

void Controller_SetDesiredTemp(unsigned char temp)
{
    DesiredTemprature = (float32_type)temp;
}

void Controller_Manage(void)
{
    MaxActuatingSig = (Kp * DesiredTemprature) + (Ki * 2 * DesiredTemprature);

    // get the new value of the error
    Error[0] = (double)DesiredTemprature - (double)ActualTemprature;

    USART_Transmit("Error[0]: ");
    USART_Transmit(convertIntegerToString((uint16_type)Error[0]));
    USART_Transmit("\r");

    Controller_CalculateActuateSig();


    float32_type duty_cycle = Controller_MapToPwmLevels();

    // generate a PWM signal with this duty_cycle
    SetDutyCycle(duty_cycle);

    // update the error
    Error[1] = Error[0];
}
























