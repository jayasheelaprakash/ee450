/**
 *
 *  EE450 Socket Programming Project 
 *      -A university project
 *
 *  Author M P Vishwas <vishwas.prakasha@gmail.com>
 *
 *  No License; Any body are free to use, edit, and distribute.
 *   
 */
 
 
 #ifndef _COMMON_H
 #define _COMMON_H 1
 
/**
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

/**
 * Macro Definitions
 */

/* Maximum 10 bits to represent a number + 1 for null */
#define BITS 11 

/* Maximum 100 line of data may be present in job.txt file */
#define MAX_LINES 100

/* Maximum size of data sent over the socket */
#define MAX_DATA ( MAX_LINE * sizeof(struct line_data) )

/* Error logs*/
#define UNKNOWN_ERROR(s, ...) fprintf(stderr, "ERROR occurred at Line number:"\
                                              " %d in %s\n%s ", __LINE__,\
                                               __FILE__, (s, ##__VA_ARGS__))
                                        
#define KNOWN_ERROR(s) fprintf(stderr, "ERROR occurred at Line number %d "\
                                        "in %s\n%s : %s\n ", __LINE__, __FILE__\
                                        , s, strerror(errno))



/**
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

/**
 *  struct line_data: A structure which storesnthe information present
 *                     in each line, read from the file. Serialised structure 
 *                     on a buffer travel over a socket
 *  Structure Members:
 *  @idx        : Index of the line a.k.a line number starts from 0 (Size:7 bits, Maximum value may be 99).
 *  @operator	: Operation to be performed bitwise-OR or bitwise-AND (Size: 1 bit, 0:OR 1:AND).
 *  @operand1   : First operand( Size:10 bits, Maximum 10 bits given in specification).
 *  @operand2   : Second operand( Size:10 bits, Maximum 10 bits given in specification).
 *  @result     : Result( Size:10 bits, Maximum 10 bits given in specification).
 *  @end        : Indicates no more data present ahead
 */
struct line_data {
    uint64_t idx        : 7;
    uint64_t operator   : 1;
    uint64_t operand1   : 10;
    uint64_t operand2   : 10;
    uint64_t            : 4;
    uint64_t result     : 10;
    uint64_t end        : 1;
    uint64_t            : 21;
};


/**
 *	struct buf_over_socket:	A Structure which is sent over the socket
 *
 *	Structure Members:
 *	@size		: Total size of the data includes @size
 *	@data		: Actual data
 */
struct buf_over_socket {
	size_t size;
	char data[ MAX_DATA];
};

 #endif /* _COMMON_H */
