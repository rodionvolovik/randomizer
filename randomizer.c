#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int 	norepeat(int *arr, int i)
{
	int 	j;

	j = 0;
	if (i) {
		for (j = 0; j < i; j++) {
			if (arr[i] == arr[j])
				return (0);
		}
	}
	return (1);
}

int		main(int ac, char **av)
{
	int 	min;
	int 	max;
	int 	len;
	int 	*arr = NULL;

    srand(time(NULL));
	if (ac == 4)
	{
		int 	i = 0;
		min = atoi(av[1]);
		max = atoi(av[2]);
		len = atoi(av[3]);
		if (max - min < len) {
			printf("%s\n", "\033[1m\033[31mPlease, provide right input \033[0m\n");
			return (0);
		}
		arr = (int*)malloc(sizeof(int) * len);
		arr[i] = min + rand() % (max - min);
		for (i = 1; i < len; i++) {
			do {
				arr[i] = min + rand() % (max - min);
			} while (!norepeat(arr, i));
		}
		for (i = 0; i < len; i++) {
			printf("%d ", arr[i]);
		}
	}
	else
		printf("\033[1m\033[31mWrong input. Usage ./rand [min] [max] [number] \033[0m\n");
	arr ? free(arr)  : 0;
	return (0);
}