#include <charlieplex.h>

#include <stddef.h>
#include <msp430.h>


#define DELAY   128


void play_effect(const struct effect *effect) {

    size_t frame;
    uint16_t i;

    for (frame = 0; frame < effect->num_frames; frame++) {
        for (i = effect->iterations[frame]; i > 0; i--) {
            charlieplex(effect->bitmaps + frame * 7);
        }
    }

}


void charlieplex(const uint8_t *bitmap) {

    // D1
    if (bitmap[0] & 0x01) {
        P1DIR = 0x03;
        P1OUT = 0x02;
        P2DIR = 0x00;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D2
    if (bitmap[0] & 0x02) {
        P1DIR = 0x05;
        P1OUT = 0x04;
        P2DIR = 0x00;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D3
    if (bitmap[0] & 0x04) {
        P1DIR = 0x09;
        P1OUT = 0x08;
        P2DIR = 0x00;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D4
    if (bitmap[0] & 0x08) {
        P1DIR = 0x41;
        P1OUT = 0x40;
        P2DIR = 0x00;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D5
    if (bitmap[0] & 0x10) {
        P1DIR = 0x81;
        P1OUT = 0x80;
        P2DIR = 0x00;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D6
    if (bitmap[0] & 0x20) {
        P1DIR = 0x01;
        P1OUT = 0x00;
        P2DIR = 0x01;
        P2OUT = 0x01;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D7
    if (bitmap[0] & 0x40) {
        P1DIR = 0x01;
        P1OUT = 0x00;
        P2DIR = 0x02;
        P2OUT = 0x02;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    P1DIR = 0x00;
    P1OUT = 0x00;
    P2DIR = 0x00;
    P2OUT = 0x00;
    // D8
    if (bitmap[0] & 0x80) {
        P1DIR = 0x03;
        P1OUT = 0x01;
        P2DIR = 0x00;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D9
    if (bitmap[1] & 0x01) {
        P1DIR = 0x06;
        P1OUT = 0x04;
        P2DIR = 0x00;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D10
    if (bitmap[1] & 0x02) {
        P1DIR = 0x0a;
        P1OUT = 0x08;
        P2DIR = 0x00;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D11
    if (bitmap[1] & 0x04) {
        P1DIR = 0x42;
        P1OUT = 0x40;
        P2DIR = 0x00;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D12
    if (bitmap[1] & 0x08) {
        P1DIR = 0x82;
        P1OUT = 0x80;
        P2DIR = 0x00;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D13
    if (bitmap[1] & 0x10) {
        P1DIR = 0x02;
        P1OUT = 0x00;
        P2DIR = 0x01;
        P2OUT = 0x01;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D14
    if (bitmap[1] & 0x20) {
        P1DIR = 0x02;
        P1OUT = 0x00;
        P2DIR = 0x02;
        P2OUT = 0x02;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    P1DIR = 0x00;
    P1OUT = 0x00;
    P2DIR = 0x00;
    P2OUT = 0x00;
    // D15
    if (bitmap[1] & 0x40) {
        P1DIR = 0x05;
        P1OUT = 0x01;
        P2DIR = 0x00;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D16
    if (bitmap[1] & 0x80) {
        P1DIR = 0x06;
        P1OUT = 0x02;
        P2DIR = 0x00;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D17
    if (bitmap[2] & 0x01) {
        P1DIR = 0x0c;
        P1OUT = 0x08;
        P2DIR = 0x00;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D18
    if (bitmap[2] & 0x02) {
        P1DIR = 0x44;
        P1OUT = 0x40;
        P2DIR = 0x00;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D19
    if (bitmap[2] & 0x04) {
        P1DIR = 0x84;
        P1OUT = 0x80;
        P2DIR = 0x00;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D20
    if (bitmap[2] & 0x08) {
        P1DIR = 0x04;
        P1OUT = 0x00;
        P2DIR = 0x01;
        P2OUT = 0x01;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D21
    if (bitmap[2] & 0x10) {
        P1DIR = 0x04;
        P1OUT = 0x00;
        P2DIR = 0x02;
        P2OUT = 0x02;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    P1DIR = 0x00;
    P1OUT = 0x00;
    P2DIR = 0x00;
    P2OUT = 0x00;
    // D22
    if (bitmap[2] & 0x20) {
        P1DIR = 0x09;
        P1OUT = 0x01;
        P2DIR = 0x00;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D23
    if (bitmap[2] & 0x40) {
        P1DIR = 0x0a;
        P1OUT = 0x02;
        P2DIR = 0x00;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D24
    if (bitmap[2] & 0x80) {
        P1DIR = 0x0c;
        P1OUT = 0x04;
        P2DIR = 0x00;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D25
    if (bitmap[3] & 0x01) {
        P1DIR = 0x48;
        P1OUT = 0x40;
        P2DIR = 0x00;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D26
    if (bitmap[3] & 0x02) {
        P1DIR = 0x88;
        P1OUT = 0x80;
        P2DIR = 0x00;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D27
    if (bitmap[3] & 0x04) {
        P1DIR = 0x08;
        P1OUT = 0x00;
        P2DIR = 0x01;
        P2OUT = 0x01;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D28
    if (bitmap[3] & 0x08) {
        P1DIR = 0x08;
        P1OUT = 0x00;
        P2DIR = 0x02;
        P2OUT = 0x02;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    P1DIR = 0x00;
    P1OUT = 0x00;
    P2DIR = 0x00;
    P2OUT = 0x00;
    // D29
    if (bitmap[3] & 0x10) {
        P1DIR = 0x41;
        P1OUT = 0x01;
        P2DIR = 0x00;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D30
    if (bitmap[3] & 0x20) {
        P1DIR = 0x42;
        P1OUT = 0x02;
        P2DIR = 0x00;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D31
    if (bitmap[3] & 0x40) {
        P1DIR = 0x44;
        P1OUT = 0x04;
        P2DIR = 0x00;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D32
    if (bitmap[3] & 0x80) {
        P1DIR = 0x48;
        P1OUT = 0x08;
        P2DIR = 0x00;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D33
    if (bitmap[4] & 0x01) {
        P1DIR = 0xc0;
        P1OUT = 0x80;
        P2DIR = 0x00;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D34
    if (bitmap[4] & 0x02) {
        P1DIR = 0x40;
        P1OUT = 0x00;
        P2DIR = 0x01;
        P2OUT = 0x01;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D35
    if (bitmap[4] & 0x04) {
        P1DIR = 0x40;
        P1OUT = 0x00;
        P2DIR = 0x02;
        P2OUT = 0x02;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    P1DIR = 0x00;
    P1OUT = 0x00;
    P2DIR = 0x00;
    P2OUT = 0x00;
    // D36
    if (bitmap[4] & 0x08) {
        P1DIR = 0x81;
        P1OUT = 0x01;
        P2DIR = 0x00;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D37
    if (bitmap[4] & 0x10) {
        P1DIR = 0x82;
        P1OUT = 0x02;
        P2DIR = 0x00;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D38
    if (bitmap[4] & 0x20) {
        P1DIR = 0x84;
        P1OUT = 0x04;
        P2DIR = 0x00;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D39
    if (bitmap[4] & 0x40) {
        P1DIR = 0x88;
        P1OUT = 0x08;
        P2DIR = 0x00;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D40
    if (bitmap[4] & 0x80) {
        P1DIR = 0xc0;
        P1OUT = 0x40;
        P2DIR = 0x00;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D41
    if (bitmap[5] & 0x01) {
        P1DIR = 0x80;
        P1OUT = 0x00;
        P2DIR = 0x01;
        P2OUT = 0x01;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D42
    if (bitmap[5] & 0x02) {
        P1DIR = 0x80;
        P1OUT = 0x00;
        P2DIR = 0x02;
        P2OUT = 0x02;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    P1DIR = 0x00;
    P1OUT = 0x00;
    P2DIR = 0x00;
    P2OUT = 0x00;
    // D43
    if (bitmap[5] & 0x04) {
        P1DIR = 0x01;
        P1OUT = 0x01;
        P2DIR = 0x01;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D44
    if (bitmap[5] & 0x08) {
        P1DIR = 0x02;
        P1OUT = 0x02;
        P2DIR = 0x01;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D45
    if (bitmap[5] & 0x10) {
        P1DIR = 0x04;
        P1OUT = 0x04;
        P2DIR = 0x01;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D46
    if (bitmap[5] & 0x20) {
        P1DIR = 0x08;
        P1OUT = 0x08;
        P2DIR = 0x01;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D47
    if (bitmap[5] & 0x40) {
        P1DIR = 0x40;
        P1OUT = 0x40;
        P2DIR = 0x01;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D48
    if (bitmap[5] & 0x80) {
        P1DIR = 0x80;
        P1OUT = 0x80;
        P2DIR = 0x01;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D49
    if (bitmap[6] & 0x01) {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x03;
        P2OUT = 0x02;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    P1DIR = 0x00;
    P1OUT = 0x00;
    P2DIR = 0x00;
    P2OUT = 0x00;
    // D50
    if (bitmap[6] & 0x02) {
        P1DIR = 0x01;
        P1OUT = 0x01;
        P2DIR = 0x02;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D51
    if (bitmap[6] & 0x04) {
        P1DIR = 0x02;
        P1OUT = 0x02;
        P2DIR = 0x02;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D52
    if (bitmap[6] & 0x08) {
        P1DIR = 0x04;
        P1OUT = 0x04;
        P2DIR = 0x02;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D53
    if (bitmap[6] & 0x10) {
        P1DIR = 0x08;
        P1OUT = 0x08;
        P2DIR = 0x02;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    // D54
    if (bitmap[6] & 0x20) {
        P1DIR = 0x40;
        P1OUT = 0x40;
        P2DIR = 0x02;
        P2OUT = 0x00;
    } else {
        P1DIR = 0x00;
        P1OUT = 0x00;
        P2DIR = 0x00;
        P2OUT = 0x00;
    }

    __delay_cycles(DELAY);

    P1DIR = 0x00;
    P1OUT = 0x00;
    P2DIR = 0x00;
    P2OUT = 0x00;

}
