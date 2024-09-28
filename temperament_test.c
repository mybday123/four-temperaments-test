/*
*    temperament_test.c - THE TEMPERAMENTS TEST
*
*    THIS PROGRAM IS MADE AND WRITTEN BY:
*    1. Gilbert Owen
*    2. Raden Zahra Auliya Marissa Solihin
*    3. Dirga Yuza
*    4. Zefanya Felicita Adithya
*    5. Shafiya Ramadhani Kanata
*/

#include <stdio.h>
#define CLEAR_SCREEN "\e[1;1H\e[2J"

int main(void) {
    printf(CLEAR_SCREEN);
    puts("*************************************************************************************");
    puts("Selamat Datang di Tes Kepribadian The Four Temperaments!");
    puts("Tekan Enter untuk melanjutkan, Tekan CTRL+C Kapan Saja untuk Memberhentikan Tes.");
    puts("*************************************************************************************");
 
    while (getchar() != '\n') {
        getchar();
    }

    puts("Melanjutkan...");
    return 0;
}