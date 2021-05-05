/*
 * superman.c
 *
 * Created: 05/05/2021 1:53:30 pm
 * Author : Sebastian Santos
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

unsigned int sec;
unsigned char digit;
char key;

int main(void)
{
    while (1) 
    {
		light();
    }
}
int light(void)
{
		int i;
		digit = 0x04;
		for (i = 0; i < 3; i++)
		{
		    DDRB = 0xff;
		    PORTB = ~digit;
			if (i == 0){
				while (sec != 30){
					_delay_ms(1000);
					sec++;
				}
				sec = 0;
			}
			if (i == 1){
				while (sec != 4){
					_delay_ms(1000);
					sec++;
				}
				sec = 0;
			}
			if (i == 2){
				while (sec != 20){
					_delay_ms(1000);
					sec++;
				}
				sec = 0;
			}
			digit>>=1;
		}
}