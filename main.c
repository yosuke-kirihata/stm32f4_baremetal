/**
 * @file main.c
 * @brief main function
 * @author 
 * @date 
 */
#include "types.h"
#include "rcc.h"
#include "gpio.h"

extern uint32_t __idata_start__, __data_start__, __data_end__, __bss_start__, __bss_end__;

int main(void);


/**
 * @brief スタートアップルーチン
 * @note RAM領域を初期化してmain関数を実行
 */
void startup(void) {
    uint8_t *p_src = 0;
    uint8_t *p_dst = 0;

    // ROM領域からRAM領域へ変数初期値を展開
    p_dst = (uint8_t*)&__data_start__;
    p_src = (uint8_t*)&__idata_start__;
    while(p_dst < (uint8_t*)&__data_end__) {
        *p_dst++ = *p_src++;
    }

    // 初期値を持たない変数の0初期化
    p_dst = (uint8_t*)&__bss_start__;
    while(p_dst < (uint8_t*)&__bss_end__) {
        *p_dst++ = 0;
    }

    main();

    while(1);
}

/**
 * @brief メイン関数
 */
int main(void) {
    uint32_t temp;

    int32_t i = -1;     // 初期値が設定されるかを確認
    i = 0;              // スタック上の変数が変更できるかを確認

    /* 最低限の初期化処理 */
    // AHB有効化
    RCC->AHB1ENR    = 0x0001;// GPIOAへクロックを供給
    
    /* PA5の初期設定 */
    temp = GPIO_A->MODER;    // Read
    temp |= (0x01 << 10);    // Modify(Output)
    GPIO_A->MODER = temp;    // Write
    //GPIO_A->MODER = 0x0400;
    GPIO_A->OTYPER = 0x0000; // プッシュプル
    GPIO_A->PUPDR  = 0x0000; // プルアップ,ダウンなし
    GPIO_A->ODR    = 0x0000; // 出力ON

    while(1) {
        /* Blink(PA5) */
        for (i = 0; i < 100000; i++) {} // 時間待ち
        GPIO_A->ODR |= (1 << 5); // 点灯
        for (i = 0; i < 100000; i++) {} // 時間待ち
        GPIO_A->ODR ^= (1 << 5); // 消灯
    }

}
