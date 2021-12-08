#include <msp430.h>                      // Generic MSP430 Device Include
#include "driverlib.h"                   // MSPWare Driver Library
#include "captivate.h"                   // CapTIvate Touch Software Library
#include "CAPT_App.h"                    // CapTIvate Application Code
#include "CAPT_BSP.h"                    // CapTIvate EVM Board Support Package

#include <charlieplex.h>

extern const struct effect one_by_one;

extern const struct effect bubble;
extern const struct effect sequence;
extern const struct effect spin;
extern const struct effect twinkle;

void mainButtonHandler(tSensor* pSensor)
{
    if (pSensor->bSensorTouch) {
        play_effect(&bubble);
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
