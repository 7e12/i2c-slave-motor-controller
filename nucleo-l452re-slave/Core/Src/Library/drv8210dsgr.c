/**
 * @author:  7e12
 * @file:    drv8210dsgr.c
 * @date:    20 Jul 2021
 * @version: v1.0.0
 * @brief:   Nucleo-L452RE I2C slave motor controller - brushed DC motor library
**/

#include "drv8210dsgr.h"

// APIs function declarations
void DRV8210DSGR_init(DRV8210DSGR_ClassTypeDef *self, DRV8210DSGR_PinsTypeDef *pin);

void DRV8210DSGR_run(DRV8210DSGR_ClassTypeDef *self, uint16_t runMode);
void DRV8210DSGR_brake(DRV8210DSGR_ClassTypeDef *self);
uint16_t DRV8210DSGR_getRunMode(DRV8210DSGR_ClassTypeDef *self);

// Motor driver module APIs declaration
static DRV8210DSGR_APIsTypeDef DRV8210DSGR_1_APIs = {
    .init       = DRV8210DSGR_init,

    .run        = DRV8210DSGR_run,
    .brake      = DRV8210DSGR_brake,
    .getRunMode = DRV8210DSGR_getRunMode,
};

static DRV8210DSGR_APIsTypeDef DRV8210DSGR_2_APIs = {
    .init       = DRV8210DSGR_init,

    .run        = DRV8210DSGR_run,
    .brake      = DRV8210DSGR_brake,
    .getRunMode = DRV8210DSGR_getRunMode,
};

// Motor driver module class declaration
DRV8210DSGR_ClassTypeDef DRV8210DSGR_1 = {
    .api = &DRV8210DSGR_1_APIs,
};

DRV8210DSGR_ClassTypeDef DRV8210DSGR_2 = {
    .api = &DRV8210DSGR_2_APIs,
};

// Initialize the motor driver module
void DRV8210DSGR_init(DRV8210DSGR_ClassTypeDef *self, DRV8210DSGR_PinsTypeDef *pin) {
    self->pin = pin;
    self->runMode = MODE_BRAKE;
};

// Run the motor driver module in input mode
void DRV8210DSGR_run(DRV8210DSGR_ClassTypeDef *self, uint16_t runMode) {
    self->runMode = runMode;

    HAL_GPIO_WritePin(self->pin->pinPhasePort, self->pin->pinPhasePin, runMode - 1);
    osDelay(100);
    HAL_GPIO_WritePin(self->pin->pinEnablePort, self->pin->pinEnablePin, 1);
    osDelay(100);
};

// Brake the motor driver module
void DRV8210DSGR_brake(DRV8210DSGR_ClassTypeDef *self) {
    HAL_GPIO_WritePin(self->pin->pinEnablePort, self->pin->pinEnablePin, 0);
    osDelay(100);
    self->runMode = MODE_BRAKE;
};

// Get run mode of the motor driver module
uint16_t DRV8210DSGR_getRunMode(DRV8210DSGR_ClassTypeDef *self) {
    return self->runMode;
};
