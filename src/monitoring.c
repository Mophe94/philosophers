/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:35:28 by dbajeux           #+#    #+#             */
/*   Updated: 2025/03/28 17:34:06 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	check_table_is_running(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->is_running_lock);
	if (philo->table->is_running == FALSE)
	{
		pthread_mutex_unlock(&philo->table->is_running_lock);
		return (FALSE);
	}
	pthread_mutex_unlock(&philo->table->is_running_lock);
	return (TRUE);
}

void	print_message(t_philo *philo, char *msg)
{
	size_t	time;

	pthread_mutex_lock(&philo->table->write_lock);
	time = get_current_time() - philo->times.born_time;
	if (check_table_is_running(philo) == TRUE)
		printf("%zu Philosophe %d %s\n", time, philo->id, msg);
	pthread_mutex_unlock(&philo->table->write_lock);
}

int	check_must_eat_philo(t_table *table)
{
	int	i;
	int	finish_eating;

	i = 0;
	finish_eating = 0;
	if (table->philo[0].must_eat == -1)
		return (TRUE);
	pthread_mutex_lock(&table->is_running_lock);
	if (table->is_running == FALSE)
	{
		pthread_mutex_unlock(&table->is_running_lock);
		return (FALSE);
	}
	pthread_mutex_unlock(&table->is_running_lock);
	while (i < table->count_philo)
	{
		pthread_mutex_lock(&table->meal_lock);
		if (table->philo[i].meals_eaten >= table->philo->must_eat)
			finish_eating++;
		pthread_mutex_unlock(&table->meal_lock);
		i++;
	}
	if (finish_eating == table->count_philo)
	{
		pthread_mutex_lock(&table->is_running_lock);
		table->is_running = FALSE;
		pthread_mutex_unlock(&table->is_running_lock);
		printf("End simulation because all eat ✅\n");
		return (FALSE);
	}
	return (TRUE);
}

int	check_death_philo(t_table *table)
{
	int	i;
	int	last_meal;

	i = 0;
	last_meal = 0;
	pthread_mutex_lock(&table->is_running_lock);
	if (table->is_running == FALSE)
	{
		pthread_mutex_unlock(&table->is_running_lock);
		return (FALSE);
	}
	pthread_mutex_unlock(&table->is_running_lock);
	while (i < table->count_philo)
	{
		pthread_mutex_lock(&table->meal_lock);
		if ((get_current_time()
				- table->philo[i].times.last_meal >= table->philo[i].times.die))
		{
			pthread_mutex_unlock(&table->meal_lock);
			print_message(&table->philo[i], "is dead 💀");
			pthread_mutex_lock(&table->is_running_lock);
			table->is_running = FALSE;
			pthread_mutex_unlock(&table->is_running_lock);
			return (FALSE);
		}
		pthread_mutex_unlock(&table->meal_lock);
		i++;
	}
	return (TRUE);
}
