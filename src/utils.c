/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:18:01 by dbajeux           #+#    #+#             */
/*   Updated: 2025/03/27 11:46:57 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (0);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (1);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

long	ft_atol(char *str)
{
	int					i;
	int					sign;
	unsigned long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

static int	ft_check(int sign)
{
	if (sign == 1)
		return (-1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int					i;
	int					sign;
	unsigned long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
		if (result > 9223372036854775807)
			return (ft_check(sign));
	}
	return (result * sign);
}

size_t	get_current_time(void)
{
	struct timeval	time_now;

	if (gettimeofday(&time_now, NULL) == -1)
	{
		write(2, "Error in function getimeofday()\n", 32);
		return (FALSE);
	}
	return (time_now.tv_sec * 1000 + time_now.tv_usec / 1000);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*cast;

	i = 0;
	cast = b;
	while (i < len)
	{
		cast[i] = c;
		i++;
	}
	return (b);
}

/*le fait d utiliser cette fonction a la place d un usleep "normal"  améliore la précision,
	la réactivité et l’adaptabilité du programme.
usleep(500) dans la boucle permet de réduire le temps de sommeil par petites tranches au lieu d’attendre une longue période d’un seul coup.
Cela permet de réagir plus vite aux changements d’état du programme (comme une fin de simulation ou la détection d’un philosophe mort).
Dans le contexte de Philosophers,
	où la gestion du temps est critique pour éviter les conditions de famine et la synchronisation des threads,
	cette approche améliore la fluidité du programme. */

int	ft_usleep(size_t milliseconds)
{
	size_t start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}