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
 
/**
 *	This file gives a MACRO for the port numbers for socket
 *
 */


#ifndef _USER_DATA_
#define _USER_DATA 1

/* USC_ID*/
#define USC_ID 121 

/* OR server port*/
#define OR_UDP ( 21000 + USC_ID )

/* AND server port*/
#define AND_UDP ( 22000 + USC_ID )

/* EDGE server TCP port*/
#define EDGE_TCP ( 23000 + USC_ID )

/* EDGE server UDP port*/
#define EDGE_UDP ( 24000 + USC_ID )

#endif /* _USER_DATA*/
