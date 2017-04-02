3/**
 *
 *  EE450 Socket Programming Project 
 *      -A university project
 *
 *  Author M P Vishwas <vishwas.prakasha@gmail.com>
 *
 *  No License; Any body are free to use, edit, and distribute.
 *   
 */
 
#ifndef _READFROMFILE_H
#define _READFROMFILE_H 1

/**
 * Includes
 */
 
#include <common.h>
 
 
/**
 * Macro Definitions
 */

/* Maximum 26 character in a single line can be + 1 for null*/
#define MAX_CHARS_LINE 27

/**
 *  Function Decelerations
 */

int read_lines_from_file(char*, void *);
