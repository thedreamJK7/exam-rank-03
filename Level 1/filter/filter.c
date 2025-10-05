#define _GNU_SOURCE
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

#define BUFFER_SIZE 10

int main(int argc, char const **argv)
{
	int bytes_read;
	char *buffer;
	int capacity = BUFFER_SIZE;
	int	buffer_size = 0;

	if (argc != 2 || !(*argv) || argv[1][0] == '\0')
		return (1);
	int	len_arg = strlen(argv[1]);
	buffer = malloc(sizeof(char) * capacity);
	if (!buffer)
		return (perror("Error"), 1);
	int size = 0;
	while ((bytes_read = read(0, buffer + size, capacity - size)) > 0)
	{
		size += bytes_read;
		if (size >= capacity - 1)
		{
			capacity *= 2;
			buffer = realloc(buffer, capacity);
			if (!buffer)
			{
				perror("Error");
				return (1);
			}
		}
	}
	if (bytes_read < 0)
	{
		perror("Error");
		free(buffer);
		return (1);
	}
	char *tmp = buffer;
	char *to_needle;
	while ((to_needle = memmem(tmp, size - (tmp - buffer), argv[1], len_arg)))
	{
		for (size_t i = 0; i < len_arg; i++)
			to_needle[i] = '*';
		tmp = to_needle + len_arg;
	}
	write(1, buffer, size);
	free(buffer);
	return (0);
}
