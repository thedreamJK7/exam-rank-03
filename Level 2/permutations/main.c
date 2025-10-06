#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void swap(char *str, int i, int j)
{
	char tmp;
	tmp = str[i];
	str[i] = str[j];
	str[j] = tmp;
}

int strsorted(char *str, int strlen) {
	for (int i = 0; i < strlen - 1; i++) {
		if (str[i + 1] < str[i])
			return 0;
	}
	return 1;
}

void strsort(char *str, int strlen) {
	for (int i = 0; i < strlen - 1; i++) {
		for (int j = i + 1; j < strlen; j++) {
			if (str[i] > str[j])
				swap(str, i, j);
			if (strsorted(str, strlen))
				return;
		}
	}
}

void permute(char *str, int start_pos, int strlen)
{
	if (start_pos == strlen )
	{
		puts(str);
		return ;
	}
	for (int i = start_pos; i < strlen; i++)
	{
		char *new = strdup(str);
		swap(new, start_pos, i);
		strsort(new + start_pos + 1, strlen - start_pos - 1);
		permute(new, start_pos + 1, strlen);
		free(new);
	}
}

int main(void) 
{
	char str[] = "123";
    permute(str, 0, strlen(str));
    return (0);
}

