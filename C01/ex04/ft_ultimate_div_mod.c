#include <unistd.h>

void ft_ultimate_div_mod(int *a, int *b)
{
	div = *a / *b;
	b = *a % *b;
	a = div;
}
