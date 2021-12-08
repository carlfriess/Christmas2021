#include <msp430.h>                      // Generic MSP430 Device Include
#include "driverlib.h"                   // MSPWare Driver Library
#include "captivate.h"                   // CapTIvate Touch Software Library
#include "CAPT_App.h"                    // CapTIvate Application Code
#include "CAPT_BSP.h"                    // CapTIvate EVM Board Support Package

#include <charlieplex.h>

extern const struct effect one_by_one;

extern const struct effect bubble;
extern const struct effect spin;
extern const struct effect twinkle;
extern const struct effect spiral;

const struct effect *effects[] = {&bubble, &spin, &twinkle, &spiral};

void mainButtonHandler(tSensor* pSensor)
{
    // Check if the main button is being touched
    if (pSensor->bSensorTouch) {

        // Choose an effect at random
        const struct effect *effect = effects[rand() & 3];

        // Play back the effect eight times
        int i;
        for (i = 0; i < 8; ++i) play_effect(effect);
    }
}

void main(void)
{
	// Initialize the MCU
	// BSP_configureMCU() sets up the device IO and clocking
	// The global interrupt enable is set to allow peripherals
	// to wake the MCU.
	WDTCTL = WDTPW | WDTHOLD;
	BSP_configureMCU();
	__bis_SR_register(GIE);

	srand(2);

	// Register the callback for the main button
    MAP_CAPT_registerCallback(
        &mainButton,
        &mainButtonHandler
    );

	// Start the CapTIvate application
	CAPT_appStart();

	// Background Loop
	while(1)
	{
		// Run the CapTIvate application handler.
		CAPT_appHandler();

		// Go to sleep if there is nothing left to do
		CAPT_appSleep();
		
	}

}
