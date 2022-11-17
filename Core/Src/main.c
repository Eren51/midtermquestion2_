#define RCC_ENABLE 0x40023830
#define GPIO 0x40022000
#define GPIODMOD_REG 0x40020C00
#define GPIO_OUTPIN 0x40020C14
#define ALLED_OPEN (1<<12) | (1<<15) | (1<<13) | (1<<14)
#define CLOSELEDS ~((1<<12) | (1<<15) | (1<<13) | (1<<14))
#define DURUNCU 1<<13
#define KAPATDURUNCU ~(1<<13)
#define YESIL 1<<12
#define KAPATYESIL ~(1<<12)
//kırmızı led 14 / 15 mavi / 12 yeşil / 13 orange
#include <stdio.h>
void init_leds ();
void turn_name_on();
void turn_surname_on();
void turn_name_off();
void turn_surname_off();
void delay1();
void delay2();
int main()
{
	int i ;
    init_leds();
    delay1();
    for(i=0;i<4;i++){
        turn_name_on();
        turn_name_off();
    }
    for(i=0;i<6;i++){
        turn_surname_on();
        turn_surname_off();
    }


}



void init_leds(){

    *((unsigned volatile int *)RCC_ENABLE)|=0x00000009; //A VE D
    *((unsigned volatile int *)GPIODMOD_REG)|=0x05000001; // 13 ve 12 pinleri açıldı

    *((unsigned volatile int *)GPIO_OUTPIN)&=CLOSELEDS;

}
void turn_name_on(){

        *((unsigned volatile int *)GPIO_OUTPIN)|=DURUNCU;
        delay1();

}
void turn_name_off(){

    *((unsigned volatile int *)GPIO_OUTPIN)&=KAPATDURUNCU;
    delay2();

}
void turn_surname_on(){

    *((unsigned volatile int *)GPIO_OUTPIN)|=YESIL;
        delay1();

}
void turn_surname_off(){

    *((unsigned volatile int *)GPIO_OUTPIN)&=KAPATYESIL;
    delay2();

}
void delay1(){

for(int i=0;i<36000000;i++){

}
}
void delay2(){
for(int i=0;i<18000000;i++){

}
}
