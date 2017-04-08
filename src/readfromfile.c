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

#include "readfromfile.h"

/**
 *	read_lines_from_file	- Read the data in file line by line and fills the structure and serialise it to buf
 *
 *	params @file_name		: File name of the input file example `job.txt'
 *	params @buf				: pointer to the buffer to sent over socket
 *
 *  Return Value			: integer, number of lines read
 *
 */

int read_lines_from_file(char* file_name, void * buf)
{
	int idx = 0;
	FILE *fh = NULL;
	char *end = NULL;
	char *start = NULL;
	struct line_data local = { 0 };
	struct line_data *ptr_buf = buf;
	char line[ MAX_CHARS_LINE] = { '\0' };
	struct line_data *ptr_line_data = &local;
	size_t size = sizeof(struct line_data);
	
	/* open the file */
	
	fh = fopen(file_name, "r");
	if ( !fh ) {
		KNOWN_ERROR("fopen() failed");
		exit(EXIT_FAILURE);
	}
	
	/* read each line from file and fill the structure and serialise */
	while ( fgets( line, MAX_CHARS_LINE, fh ) ) {
		/* operator*/
		if ( line[0] == 'a' ) {
			local.operator = AND;
		} else {
			local.operator = OR;
		}
		
		/* operand1 */
		start = strchr( line, ',' ) + 1;
		end = strchr( start, ',' ) -1;
		local.operand1 = bit10array2num(start, end);
		
		/* operand2 */
		start = end + 2;
		end = start + strcspn(start, "\n\0") - 1;
		
		local.operand2 = bit10array2num(start, end);
		
		/* index */
		local.idx = idx;
		
		/* copy the data to buf*/
		memcpy( ptr_buf + idx , ptr_line_data, size );
		
		/* update for next entry */
		idx++;
		memset( line, '\0', MAX_CHARS_LINE );
		memset( ptr_line_data, '\0', size );
	}
	
	/* update end pointer in the structure ``A Catch" */
	
	(ptr_buf + idx - 1) -> end = 1;
	
	return idx;
}
