/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:39:55 by dbajeux           #+#    #+#             */
/*   Updated: 2025/03/26 10:58:33 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*philosopher_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		thinking_routine(philo);
		eat_routine(philo);
		sleep_routine(philo);
	}
	return (NULL);
}


int	create_threads(t_table *table)
{
	int i;

	i = 0;
	while (i < table->count_philo)
	{
		if (pthread_create(&table->philo[i].thread_id, NULL, philosopher_life,
				&table->philo[i]) != 0)
			return (printf("Error : can't create thread for the philo number %d\n",
					table->philo[i].id), FALSE);
		i++;
	}
	return (TRUE);
}