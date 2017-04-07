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
  
#include <client.h>

/**
 *
 *	A main() for client side.
 *
 *	Usage	:	$ ./client <input_file>
 *	Example	:	$ ./client job.txt
 *
 */

int main( int argc, char * argv[] )
{
	static struct buf_over_socket buf = { 0 };
	
	/*Local*/
	int status = 0;
	int server_sock = 0;
	size_t data_size = 0;
	struct sockaddr_in server_addr = { 0 };
	socklen_t socklen = sizeof( struct sockaddr_in );
	
	/* Arguments must be two including executable name */
	if ( argc != 2 ) {
		fprintf(stderr, "Usage	:	$ ./%s <input_file>\n"
						"Example	:	$ ./%s job.txt\n", argv[0], argv[0]);
		exit(EXIT_FAILURE);
	}
	
	/* Create Socket-TCP */
	
	server_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP );
	if ( server_sock ) {
		KNOWN_ERROR("socket()");
		exit(EXIT_FAILURE);
	}
	
	/* Fill Server address */
	
	server_addr.sin_family 		= PF_INET;
	server_addr.sin_port 		= EDGE_TCP;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	/* Connect to  EDGE server */
	
	status = connect( server_sock, (struct sockaddr  *) & server_addr, socklen );
	if( status ) {
		KNOWN_ERROR("socket()");
		exit(EXIT_FAILURE);
	}
	
	printf("The client is up and running\n");
	
	/* Read data from file */
	data_size = read_lines_from_file( argc[1], &( buf.data ) );
	
	if ( data_size == 0 ) {
		UNKNOWN_ERROR("No data fetched from File %s or invalid File Format", 
						argv[1] );
		exit( EXIT_FAILURE );
	}
	
	buf.size = (data_size * sizeof( struct line_data) ) + sizeof(size_t);
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	return 0;
}

