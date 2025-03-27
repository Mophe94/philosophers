/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:27:05 by dbajeux           #+#    #+#             */
/*   Updated: 2025/03/27 14:22:23 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

// rajouter a la fin du projet de mettre une condition pour faire en sorete que pas plus de 200 philo soit cree 
// mais seulement a ala fin pour pouvoir tester comme une brute 
/*check si la validiter des argv est correct  si il ne sont pas a NULL car sinon fait planter le projet 
a partir des inits*/

int	check_args(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	if (!argv[1])
		return (FALSE);
	if (argc != 6 && argc != 5)
	{
		printf("Error : put 4 or 5 arguments\n");
		return (FALSE);
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
					return(FALSE);
			}
		}
		else
			return (FALSE);
		i++;
	}
	return (TRUE);
}