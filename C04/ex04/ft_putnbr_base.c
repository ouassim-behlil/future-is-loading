#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	has_duplicates(char *base, int base_len)
{
	int	base_ind;
	int	next_base_ind;

	base_ind = 0;
	while (base_ind < (base_len - 1))
	{
		next_base_ind = base_ind + 1;
		while (next_base_ind < base_len)
		{
			if (base[base_ind] == base[next_base_ind])
				return (1);
			next_base_ind ++;
		}
		base_ind ++;
	}
	return (0);
}

void	ft_putnbr_base(int nb, char *base)
{
	int	base_len;
	int	base_ind;

	base_len = 0;
	base_len = 0;
	while (base[base_len])
	{
		if (base[base_len] == '+' || base[base_len] == '-')
			return ;
		base_len++;
	}
	if (base_len < 2)
		return ;
	if (has_duplicates(base, base_len))
		return ;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= base_len)
		ft_putnbr_base((nb / base_len), base);
	ft_putchar(base[nb % base_len]);
}

int	main(void)
{
	char	base[3] = "01";
	int	nb = -244123;
	ft_putnbr_base(nb, base);
}
