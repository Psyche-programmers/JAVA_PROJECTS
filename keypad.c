#include <mega32.h>
#include <alcd.h>
#define keypad_ddr DDRB
#define keypad_port PORTB
#define input_data PINB

void main(void)
{
keypad_ddr=0xF0;
// Alphanumeric LCD initialization
// Connections are specified in the
// Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
// RS - PORTA Bit 0
// RD - PORTA Bit 1
// EN - PORTA Bit 2
// D4 - PORTA Bit 4
// D5 - PORTA Bit 5
// D6 - PORTA Bit 6
// D7 - PORTA Bit 7
// Characters/line: 16
lcd_init(16);

while (1)
      {
      // Place your code here
                keypad_port=0b11101111;
                lcd_gotoxy(0,0);  
                         
                if (input_data.0==0)         
                    lcd_putsf("1");
                if (input_data.1==0)
                    lcd_putsf("4");
                if (input_data.2==0)         
                    lcd_putsf("7");
                if (input_data.3==0)
                    lcd_putsf("*");

                keypad_port=0b11011111;
                lcd_gotoxy(0,0);  
                         
                if (input_data.0==0)         
                    lcd_putsf("2");
                if (input_data.1==0)
                    lcd_putsf("5");
                if (input_data.2==0)         
                    lcd_putsf("8");
                if (input_data.3==0)
                    lcd_putsf("0");

                keypad_port=0b10111111;
                lcd_gotoxy(0,0);
                if (input_data.0==0)
                    lcd_putsf("3");
                if (input_data.1==0)
                    lcd_putsf("6");
                if (input_data.2==0)
                    lcd_putsf("9");
                if (input_data.3==0)
                    lcd_putsf("#");

                keypad_port=0b01111111;      
                lcd_gotoxy(0,0);
                if (input_data.0==0)
                    lcd_putsf("A");
                if (input_data.1==0)
                    lcd_putsf("B");
                if (input_data.2==0)
                    lcd_putsf("C");
                if (input_data.3==0)
                    lcd_putsf("D");             
       }
}

