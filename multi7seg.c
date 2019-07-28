#include <mega32.h>
#include <delay.h>

#define data_ddr DDRC
#define data_port PORTC
#define control_ddr DDRD
#define control_port PORTD

char digit_cathode[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
int i;
char x, y, z, w;


void main(void) {

    data_ddr=0xFF;
    control_ddr=0x0F;

  		i=3475;
        w=i%10;
  		i=i/10; 
        z=i%10;
        i=i/10;
        y=i%10;
        x=i/10;    

	while (1) {   
        
  		    control_port=0b00001110; 
  		    data_port=~digit_cathode[x];
            delay_ms(10); 
            control_port=0b00001101;      
            data_port=~digit_cathode[y];
            delay_ms(10);
   		    control_port=0b00001011;
  		    data_port=~digit_cathode[z];
            delay_ms(10); 
            control_port=0b00000111; 
            data_port=~digit_cathode[w];
            delay_ms(10);
  	}
}