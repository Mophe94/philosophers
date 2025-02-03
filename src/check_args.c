/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:27:05 by dbajeux           #+#    #+#             */
/*   Updated: 2025/01/18 17:51:09 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

// rajouter a la fin du projet de mettre une condition pour faire en sorete que pas plus de 200 philo soit cree 
// mais seulement a ala fin pour pouvoir tester comme une brute 

int	check_args(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	if (argc != 6 && argc != 5)
	{
		printf("Error : put 5 or 6 arguments\n");
		return (0);
	}
	while (argv[i])
	{
		if (ft_atol(argv[i]) <= INT_MAX && ft_atol(argv[i]) > 0)
		{
			j = 0;
			while(argv[i][j])
			{
				if ((ft_isdigit(argv[i][j]) == 1))
					j++;
				else
					return(0);
			}
		}
		else
			return (0);
		i++;
	}
	return (1);
}