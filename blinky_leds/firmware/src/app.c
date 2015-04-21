

#include "app.h"



// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.
    
    Application strings and buffers are be defined outside this structure.
*/

APP_DATA appData;



unsigned int i = 0;


// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback funtions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    /* Put the application into its initial state */
    appData.state = APP_STATE_COUNT;
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{
   /* Take appropriate action, depending on the current state. */
    switch (appData.state)
    {

        /* Application is stuck in a counting loop. */
        case APP_STATE_COUNT:
        {
            /* Keep incrementing the count if it's less than the blink delay */
            if (i < APP_LED_BLINK_DELAY)
            {
                /* Increment count. */
                i++;
            }

            else
            {
                /* If count is reached, switch states */
                appData.state = APP_STATE_BLINK_LED;
            }

            break;
        }

        /* Toggle the LED and switch back to the delay loop. */
        case APP_STATE_BLINK_LED:
        {
            /* Toggle LED */
            BSP_LEDToggle(BSP_LED_3);

            /* Put the application back to the count state */
            appData.state = APP_STATE_COUNT;
            //PLIB_PORTS_PinToggle (PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_7);
            /* Restart count. */
            i = 0;

            break;
        }

        /* Should not come here during normal operation */
        default:
        {
            PLIB_ASSERT(false , "unknown application state");

            break;
        }

    }
}
 

/*******************************************************************************
 End of File
 */

