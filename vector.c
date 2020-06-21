/**
 * @file vector.c
 * @brief Vector Table
 * @author 
 * @date 
 * @note Referenced STM32F401RE reference manual "DocID025350 Rev 4".
 */

#define EXCEPTION_SIZE 255

typedef void (*FP)(void);

extern void _estack(void);  // スタックの開始アドレス
extern void _startup(void); // スタートアップルーチンの開始アドレス

__attribute__ ((section(".vector")))
const FP _vector_table[EXCEPTION_SIZE] = {
    (FP)_estack,
    (FP)_startup
};
