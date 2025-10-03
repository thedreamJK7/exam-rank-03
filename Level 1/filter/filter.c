#define _GNU_SOURCE
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char const **argv)
{
	int bytes_read;
	char *buffer;
	int capacity = BUFFER_SIZE;
	int	buffer_size = 0;

	if (argc != 2 || !(*argv) || argv[1][0] == '\0')
		return (1);
	int	len_arg = strlen(argv[1]);
	buffer = malloc(sizeof(char) * 4096);
	if (!buffer)
		return (perror("Error"), 1);
	while (bytes_read = read(0, buffer, sizeof(char) * capacity))
	{
		
	}
	if (bytes_read < 0)
	{
		perror("Error");
		free(buffer);
		return (1);
	}
	char *tmp = buffer;
	while (memmem(buffer, strlen(buffer), argv[1], len_arg))
	{
		char *to_needle = memmem(buffer, strlen(buffer), argv[1], len_arg);
		for (size_t i = 0; i < len_arg; i++)
			to_needle[i] = '*';
		buffer += len_arg;
	}
	printf("%s", tmp);
	return (0);
}
