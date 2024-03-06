/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:12:46 by alimotta          #+#    #+#             */
/*   Updated: 2024/01/20 15:12:48 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	size_n(int n, int size)
{
	long int	div;

	div = 1;
	size = 0;
	if (n == 0)
		size++;
	else
	{
		while ((n / div) != 0)
		{
			div *= 10;
			size++;
		}
	}
	if (n < 0)
		size++;
	return (size);
}

static char	*fill_s(int n, int size, char *s, int i)
{
	int	digit;

	s[size] = '\0';
	size--;
	if (n < 0)
	{
		s[i] = '-';
		n *= -1;
		i++;
	}
	if (n == 0)
		s[size] = n + '0';
	else
	{
		while (size >= i)
		{
			digit = n % 10;
			if (digit < 0)
				digit *= -1;
			s[size] = digit + '0';
			n /= 10;
			size--;
		}
	}
	return (s);
}

char	*ft_itoa(int n)
{
	int		i;
	int		size;
	char	*s;

	i = 0;
	size = 0;
	size = size_n(n, size);
	s = (char *)malloc((size + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s = fill_s(n, size, s, i);
	return (s);
}
