/*******************************************************************************
 *
 *  EE450 Socket Programming Project 
 *      -A university project
 *
 *  Author M P Vishwas <vishwas.prakasha@gmail.com>
 *
 *  No Lisence; Any body are free to use, edit, and distribute.
 *
 *  util.c contains a utility functions required for the various sources
 *   
 ******************************************************************************/

#include <util.h>

/*******************************************************************************



*******************************************************************************/
char * num2bit10array( uint16_t num)
{
    static char bits[BITS];
    
    /*Local*/
    int flag = 0;
    int i;
    int j = 0;
    
    memset(bits, '\0', BITS);
    
    for ( i = 9; i > 0; i-- ) {
        if ((1<<i) & num ) {
            bits[j++] = '1';
            flag = 1;
        } else {
            if ( flag ) {
                bits[j++] = '0';
            }
        }
    }
    return bits;
    
}



uint16_t bit10array2num(char *start, char *end)
{
    uint16_t num = 0;
    
    while ( start <= end ) {
        num = ( num * 2 ) + ( ( *start ) - '0' );
        start++;
    }
    return num;
}
