#include <effect.h>
#include <stdint.h>
#include <stddef.h>
#include <msp430.h> 


#define DELAY   10

static void play_effect(const struct effect *effect);
static void charlieplex(const uint8_t *bitmap);

const uint16_t iterations[] = { 128, 128 };
const uint8_t bitmap[] = {
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

const struct effect blink = {
    .bitmaps = bitmap,
    .iterations = iterations,
    .num_frames = 2,
};

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;       // Disable the GPIO power-on default high-impedance mode
                                // to activate previously configured port settings
	
	for (;;) {
	    play_effect(&blink);
	}

	return 0;
}

static void play_effect(const struct effect *effect) {

    size_t frame;
    uint16_t i;

    for (frame = 0; frame < effect->num_frames; frame++) {
        for (i = effect->iterations[frame]; i > 0; i--) {
            charlieplex(effect->bitmaps + frame * 7);
        }
    }

}

static void charlieplex(const uint8_t *bitmap) {

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

}
