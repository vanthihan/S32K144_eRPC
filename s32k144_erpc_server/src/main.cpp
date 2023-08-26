/*
 * main implementation: use this 'C++' sample to create your own application
 *
 */

#include "S32K144.h"
#include <stdio.h>


#include "lib/Caculator.h"

using namespace erpc_server;

int main()
{
    printf ("Program started\n");

    Caculator caculator;

    int add_value = caculator.add(5, 6);

    printf("add_value = %d\n", add_value);

    PCC->PCCn[PCC_PORTD_INDEX] = 0x40000000;
    PORTD->PCR[15] = 0x00000100;
    PTD->PDDR = 0x00008000; /*output*/

	int counter = 0x00;
    for(;;) {

    	printf("Super Loop... = %d\n", caculator.getCounterValue());
    	PTD->PDOR = 0;
    	PTD->PDOR = 0x00008000;
    	caculator.setCounterValue(++counter);
    }

    return 0;
}



