/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:57:18 by dbajeux           #+#    #+#             */
/*   Updated: 2025/03/25 18:53:52 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void init_philo(t_table *table,size_t time_to_eat,size_t time_to_die)
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
        table->philo[i].right_fork = &table->forks[(i + 1) % table->count_philo];
        table->philo[i].times.die = time_to_die;
        table->philo[i].times.eat = time_to_eat;
        table->philo[i].times.last_meal = get_current_time();
        table->philo[i].times.born_time = get_current_time();
        table->philo[i].times.is_dead = false;
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
    {
        printf("Error : Malloc philo init table\n");
        return (FALSE);
    }
    table->forks = malloc(sizeof(pthread_mutex_t) * count_philo);
    if (!table->forks)
    {
        printf("Error : Malloc forks in init table\n");
        return (FALSE);
    }
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

