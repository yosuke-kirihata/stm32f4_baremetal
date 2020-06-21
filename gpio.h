/**
 * @file gpio.h
 * @brief 
 * @author 
 * @date 
 */

#ifndef __GPIO_H__
#define __GPIO_H__

#include "types.h"

typedef volatile struct {
    uint32_t MODER;    //0x00
    uint32_t OTYPER;   //0x04 Push-Pull/Opendrain
    uint32_t OSPEEDER; //0x08
    uint32_t PUPDR;    //0x0c
    uint32_t IDR;      //0x10
    uint32_t ODR;      //0x14
    uint32_t BSRR;     //0x18
    uint32_t LCKR;     //0x1c
    uint32_t AFRL;     //0x20 Alternate Function
    uint32_t AFRH;     //0x24
} gpio_base_t;


#define GPIO_A ((gpio_base_t *)0x40020000)
#define GPIO_B ((gpio_base_t *)0x40020400)
//:

#endif //__GPIO_H__