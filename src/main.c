#include <avr/io.h>
#include <avr/interrupt.h>

void initializePorts( void );


//int gCounter = 0;

int main() {

    // setup timer0
    // ensure countera0 is not doing anything
    //TCCR1A = 0x00; //Does this really need anything?
    // and timer1b with 1024 prescaler
    TCCR1B |= 0x04;
    // enable timrsk1 timer overflow interrupt
    TIMSK1 = (1 << TOIE1);

    initializePorts();

    // set global interrupt enable
    SREG |= (1 << 7);
    

    while( 1 ) {
    //    if(gCounter >= 5) {
    //        PORTB = ~PORTB;
    //        gCounter = 0;
    //    }
    }

    return 0;
}


void initializePorts( void ) {

    DDRB = 0xFF; PORTB = 0x00;

    return;
}


ISR(TIMER1_OVF_vect) {
    
    //gCounter++;

    PORTB = ~PORTB;
}
