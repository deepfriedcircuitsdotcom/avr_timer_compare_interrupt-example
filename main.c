#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER0_COMPA_vect) {
    PORTB ^= (1<<0);      //toggle PORTB0
    TCNT0 = 0;            //reset timer/counter0 to 0
}

ISR(TIMER1_COMPA_vect) {
    PORTB ^= (1<<1);      //toggle PORTB1
    TCNT1 = 0;            //reset timer/counter1 to 0
}

int main(void) {

    DDRB |= (1<<0);        //set PORTB0 as output
    PORTB &= ~(1<<0);      //clear PORTB0
    DDRB |= (1<<1);        //set PORTB1 as output
    PORTB &= ~(1<<1);      //clear PORTB0

    /* Timer/Counter0 (8bit) */
    TCCR0B |= (1<<CS00);   //timer 0 no prescaler
    OCR0A = 100;           //output compare register
    TIMSK0 |= (1<<OCIE0A); //timer/counter 0 overflow interrupt enable
    
    /* Timer/Counter1 (16bit) */
    TCCR1B |= (1<<CS10);   //timer 1 no prescaler
    OCR1A = 100;           //output compare register
    TIMSK1 |= (1<<OCIE1A); //timer/counter 0 overflow interrupt enable
    

    sei();                 //set global interrupt

    while(1) 
    {

    }

}
