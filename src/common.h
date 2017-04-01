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
 
 
 #ifndef _COMMON_H
 #define _COMMON_H 1
 
 /*
 * Includes
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <stdint.h>

/*
 * Macro Definitions
 */

/* Maximum 10 bits to represent a number + 1 null */
#define BITS 11 

#define LOG_ERROR(s, ...) fprintf(strerr, "ERROR occurred at Line number %d"\
                                        "in %s\n%s ", __LINE__, __FILE__, s,\
                                        ##__VA_ARGS__)

/*
 * Enumeration and structure definitions
 */
 
enum operations {
	OR = 0,
	AND,
};

enum bools {
	false = 0,
	true,
};

/*
 *  struct line_data: A structure which the information present in each line,
 *                     read from the file. Serialised structer on a buffer 
 *                     travel over a socket
 *  Structure Members:
 *  @idx        : Index of the line a.k.a line number starts from 0 (Size:7 bits, Maximum value be 99).
 *  @operation  : Operation to be performed bitwise-OR or bitwise-AND ().
 *  @operand1   : First operand( Size:10bits, Maximun 10 bits given in specification).
 *  @operand2   : Second operand( Size:10bits, Maximun 10 bits given in specification).
 *  @result     : Result( Size:10bits, Maximun 10 bits given in specification).
 *  @end        : Indicates no more data present ahead
 */
struct line_data {
    uint64_t idx        : 7;
    uint64_t opertion   : 1;
    uint64_t operand1   : 10;
    uint64_t operand2   : 10;
    uint64_t            : 4;
    uint64_t result     : 10;
    uint64_t end        : 1;
    uint64_t            : 21;
};

 #endif /* _COMMON_H */
