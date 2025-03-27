/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:39:55 by dbajeux           #+#    #+#             */
/*   Updated: 2025/03/27 12:17:18 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/*doit encore etre fini une fois la partie monitoring faite*/

void	*philosopher_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (check_table_is_running(philo) == TRUE)
	{
		thinking_routine(philo);
		eat_routine(philo);
		sleep_routine(philo);
	}
	return (NULL);
}

void *monitoring_life(void *arg)
{
	t_table *table;

	table = (t_table *)arg;
    while (1)
	{
		pthread_mutex_lock(&table->is_running_lock);
		if (table->is_running == FALSE)
        {
            pthread_mutex_unlock(&table->is_running_lock);
            break;
        }
        pthread_mutex_unlock(&table->is_running_lock);
        if (check_death_philo(table) == TRUE /*|| check_must_eat_philo(table) == TRUE*/)	
			break;
	}
    return (NULL);
}

int	create_threads(t_table *table)
{
	int i;
	pthread_t monitoring;
	
	i = 0;
	if (pthread_create(&monitoring,NULL,monitoring_life,(void *)table) != 0)
		return (printf("Error : can't create thread for the Monitoring"),FALSE);
	while (i < table->count_philo)
	{
		if (pthread_create(&table->philo[i].thread_id, NULL, philosopher_life,
			&table->philo[i]) != 0)
			return (printf("Error : can't create thread for the philo number %d\n",table->philo[i].id), FALSE);
		i++;
	}
	i = 0;
	if (pthread_join(monitoring,NULL) != 0)
		return (printf("Error  : exit prog"),FALSE);
	while (i < table->count_philo)
	{
		if (pthread_join(table->philo[i].thread_id, NULL) != 0)
			return (printf("ERROR : EXIT PROG"),FALSE);
		i++;	
	}
	return (TRUE);
}