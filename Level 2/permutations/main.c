#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void swap(char *x, char *y)
{
	char tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void permute(char *str, int start_pos, int end_pos)
{
	if (start_pos == end_pos)
	{
		puts(str);
		return ;
	}
	for (int i = start_pos; i <= end_pos; i++)
	{
		swap((str + start_pos), (str + i));
		permute(str, start_pos + 1, end_pos);
		swap((str + start_pos), (str + i));
	}
}

int main(void) 
{
	char str[] = "abc";
    permute(str, 0, strlen("abc") - 1);
    return (0);
}

