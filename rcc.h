/**
 * @file rcc.h
 * @brief 
 * @author 
 * @date 
 */

#ifndef __RCC_H__
#define __RCC_H__

#include "types.h"

typedef struct {
    uint32_t CR;
    uint32_t PLLCFGR;
    uint32_t CFGR;
    uint32_t CIR;
    uint32_t AHB1RSTR;
    uint32_t AHB2RSTR;
    uint32_t : 32U;
    uint32_t : 32U;
    uint32_t APB1RSTR;
    uint32_t APB2RSTR;
    uint32_t : 32U;
    uint32_t : 32U;
    uint32_t AHB1ENR;
    uint32_t AHB2ENR;
    uint32_t : 32U;
    uint32_t : 32U;
    uint32_t APB1ENR;
    uint32_t APB2ENR;
    uint32_t : 32U;
    uint32_t : 32U;
    uint32_t AHB1LPENR;
    uint32_t AHB2LPENR;
    uint32_t : 32U;
    uint32_t : 32U;
    uint32_t APB1LPENR;
    uint32_t APB2LPENR;
    uint32_t : 32U;
    uint32_t : 32U;
    uint32_t BDCR;
    uint32_t CSR;
    uint32_t : 32U;
    uint32_t : 32U;
    uint32_t SSCGR;
    uint32_t PLLI2SCFGR;
    uint32_t : 32U;
    uint32_t : 32U;
    uint32_t DCKCFGR;
} rcc_base_t;

#define RCC ((rcc_base_t *)0x40023800)

#endif //__RCC_H__