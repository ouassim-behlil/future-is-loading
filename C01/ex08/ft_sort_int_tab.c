#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	*a += *b;
	*b = *a - *b;
	*a -= *b;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (i < (size - 1))
	{
		j = i;
		min = j;
		while (j < (size -1))
		{
			if (tab[j] < min)
				min = tab[j];
			j++;
		}
		ft_swap(tab[i], min);
	}
}
