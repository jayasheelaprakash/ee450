/**
 *
 *  EE450 Socket Programming Project 
 *      -A university project
 *
 *  Author M P Vishwas <vishwas.prakasha@gmail.com>
 *
 *  No License; Any body are free to use, edit, and distribute.
 *
 *  util.c contains a utility functions required for the various sources
 *   
 */

#include <util.h>

/**
 *  num2bit10array  - Number to bit stream of length 10
 *
 *  parmas @num     : A number that will be converted to bit stream. Maximum 1 bits as specified in document.
 *
 *  Return value    : A pointer to the bit stream ( character buffer ).
 *
 *  The character buffer hold the value of the recently called number. 
 *  Use any number of times before calling the next value.
 *  Statically allocated memory, no free(3) to be called to this pointer.
 *
 *  Example         :
 *  char * str = num2bit10array(1023);
 *  printf("%s\n", str);
 *
 *  output          : 1111111111
 */
char * num2bit10array( uint16_t num)
{
    static char bits[BITS];
    
    /*Local*/
    int flag = 0;
    int i;
    int j = 0;
    
    memset(bits, '\0', BITS);
    
    for ( i = 9; i >= 0; i-- ) {
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


/**
 *  bit10array2num  - Converts Bit Stream maximum length 10 to a unsigned integer of 16 bits.
 *  
 *  params @start   : A character pointer to where the bit stream starts.
 *  params @end     : A character pointer to where the bit stream ends.
 *
 *  Return Value    : A uint16_t number.
 *
 *  Caution         : This function do not have validation. Kindly provide valid inputs.
 *
 *  Example         :
 *  char * str = "1011010";
 *  uint16_t num = bit10array2num( str, ( str + strlen( str ) - 1 ) );
 *  printf("%d\n", num);
 *
 *  output          : 90
 */


uint16_t bit10array2num(char *start, char *end)
{
    uint16_t num = 0;
    
    while ( start <= end ) {
        num = ( num * 2 ) + ( ( *start ) - '0' );
        start++;
    }
    return num;
}
