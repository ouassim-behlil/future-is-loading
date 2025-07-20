#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	*a += *b;
	*b = *a - *b;
	*a -= *b;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = size - 1;
	while (i <= (size / 2))
	{
		ft_swap(&tab[i], &tab[j]);
		i++;
		j--;
	}
}
