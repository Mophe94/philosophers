/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:57:18 by dbajeux           #+#    #+#             */
/*   Updated: 2025/03/11 14:54:29 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int init_philo(t_table *table)
{
    int i;

    i = 0;
    while (i < table->count_philo)
    {
        table->philo[i].id = i;
        table->philo[i].must_eat = -1;
        table->philo[i].meals_eaten = 0;
        table->philo[i].table = table;
        table->philo[i].left_fork = &table->forks[i];
        table->philo[i].right_fork = &table->forks[i + 1 % table->count_philo];
        table->philo[i].times.die = -1;
        table->philo[i].times.eat = 0;
        table->philo[i].times.last_meal = 0;
        table->philo[i].times.born_time = 0;
        i++;
    }
}

int	init_table(t_table *table, int count_philo)
{
	int i;

	i = 0;
	ft_memset(table, 0, sizeof(t_table));
	table->is_running = true;
	table->count_philo = count_philo;
	table->philo = malloc(sizeof(t_philo) * count_philo);
    if (!table->philo)
        return (FALSE,printf("Error : Malloc philo init table\n"));
    table->forks = malloc(sizeof(pthread_mutex_t) * count_philo);
    if (!table->forks)
        return (FALSE,printf("Error : Malloc forks in init table\n"));
    pthread_mutex_init(&table->is_running_lock,NULL);
    pthread_mutex_init(&table->write_lock,NULL);
    pthread_mutex_init(&table->meal_lock,NULL);
    while (i < count_philo)
    {
        pthread_mutex_init(&table->forks[i],NULL);
        i++;
    }
    return (TRUE);
}

