#ifndef GET_NEXT_LINE_H 
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 4096
#endif

#define BLOCK_SIZE 4096

typedef struct s_string
{
	char *str;
	size_t	len;
	size_t	capa;
}			t_string;

typedef struct s_buffer
{
	int		n;
	char	*bufp;
	char	buffer[BUFFER_SIZE];
}		t_buffer;

char	*get_next_line(int fd);

#endif