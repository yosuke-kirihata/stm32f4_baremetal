/**
 * @file main.c
 * @brief main function
 * @author 
 * @date 
 */
#include "types.h"

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

    /* TODO:最低限の初期化処理 */

    while(1) {

    }

}
