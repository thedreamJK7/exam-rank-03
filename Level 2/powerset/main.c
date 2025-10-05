#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	if (argc < 2)
		return (1);
	int target = atoi(argv[1]), a[100], subset[100], n = argc - 2;
	for (size_t i = 0; i < n; i++)
		a[i] = atoi(argv[i + 2]);
	
	return (0);
}
