#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char	*get_next_line(int fd);

int main(void)
{
    int fd = open("no_newline.txt", O_RDONLY); // open file for reading
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("> %s", line);  // output line
        free(line);          // free returned line
    }
    //	close(fd); // close the file
    return (0);
}