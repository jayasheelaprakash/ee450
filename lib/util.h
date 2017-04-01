/*******************************************************************************
 *
 *  EE450 Socket Programming Project 
 *      -A university project
 *
 *  Author M P Vishwas <vishwas.prakasha@gmail.com>
 *
 *  No License; Any body are free to use, edit, and distribute.
 *   
 ******************************************************************************/

#ifndef _UTIL_H
#define _UTIL_H 1

/*
 * Includes
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

/*
 * Macro Definitions
 */

/* Maximum 10 bits to represent a number + 1 null */
#define BITS 11 

#define LOG_ERROR(s, ...) fprintf(strerr, "ERROR occurred at Line number %d"\
                                        "in %s\n%s ", __LINE__, __FILE__, s,\
                                        ##__VA_ARGS__)
                                        
/*
 *  Function Decelerations
 */

char * num2bit10array( uint16_t );
uint16_t bit10array2num(char *, char *);


#endif /* _UTIL_H */
