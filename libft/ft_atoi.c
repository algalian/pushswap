/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algalian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:28:25 by algalian          #+#    #+#             */
/*   Updated: 2023/01/19 13:28:29 by algalian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_blanks(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
	{
		return (1);
	}
	return (0);
}

static int	clean_string(const char *str, unsigned int i)
{
	if (ft_isdigit(str[i]) == 1)
		return (i);
	if (ft_blanks(str[i]) != 1 && (str[i] != '+' && str[i] != '-'))
	{
		if (ft_isdigit(str[i]) != 1)
			return (-1);
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (ft_isdigit(str[i + 1]) != 1)
		{
			return (-1);
		}
		return (i + 1);
	}
	if (ft_blanks(str[i]) == 1)
	{
		while (ft_blanks(str[i]) == 1)
			i++;
		return (clean_string(str, i));
	}
	return (-1);
}

static int	sign(const char *str, unsigned int i)
{
	if (i == 0)
		return (1);
	if (str[i - 1] == '-')
	{
		return (-1);
	}
	return (1);
}

long	ft_atoi(const char *str)
{
	int		i;
	long	num;
	long	next;

	i = clean_string(str, 0);
	if (i == -1)
	{
		ft_printf("Error 0\n");
		exit(2);
	}
	num = str[i] - '0';
	i++;
	while (ft_isdigit(str[i]) == 1)
	{
		next = str[i] - '0';
		num = num * 10 + next;
		i++;
	}
	if (num < -2147483648 || num >= 4294967296)
	{
		ft_printf("Error -1 \n");
		exit(2);
	}
	return (num * sign(str, clean_string(str, 0)));
}

/*int main(int argc, char **argv)
{
	int i;

	i = 0;
	while(argv[i+1])
	{
		printf("%i\n",ft_atoi(argv[i + 1]));
		i ++;
	}
	return(0);
}*/