#include <stdio.h>
#include <stdlib.h>

/*
index — hozir ko‘rib turgan element indeksi
sum — hozirgi subset yig‘indisi
subset — hozirgacha tanlangan elementlar
subset_size — nechtasi tanlangan
target — kerakli yig‘indi
*/

void find_subsets(int *arr, int size, int index, int sum, int *subset, int subset_size, int target)
{
	if (sum == target)
	{
		// print subset
		for (int i = 0; i < subset_size; i++)
			printf("%d ", subset[i]);
		printf("\n");
	}
	else
		for (; index < size; index++)
		{
			subset[subset_size] = arr[index];
			find_subsets(arr, size, index + 1, sum + arr[index], subset, subset_size + 1, target);
		}
}

int main(int argc, char const *argv[])
{
	if (argc < 2)
		return (1);
	int target = atoi(argv[1]), a[100], subset[100], n = argc - 2;
	for (size_t i = 0; i < n; i++)
		a[i] = atoi(argv[i + 2]);
	find_subsets(a, n, 0, 0, subset, 0, target);
	return (0);
}
