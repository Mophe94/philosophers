/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:57:18 by dbajeux           #+#    #+#             */
/*   Updated: 2025/03/26 11:51:54 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void init_philo(t_table *table,char **argv)
{
    int i;
    
    i = 0;
    while (i < table->count_philo)
    {
        table->philo[i].id = i + 1;
        table->philo[i].meals_eaten = 0;
        table->philo[i].is_dead = false;
        table->philo[i].table = table;
        table->philo[i].left_fork = &table->forks[i];
        table->philo[i].right_fork = &table->forks[(i + 1) % table->count_philo];
        table->philo[i].times.eat = ft_atoi(argv[2]);
        table->philo[i].times.die = ft_atoi(argv[3]);
        table->philo[i].times.sleep = ft_atoi(argv[4]);
        if (argv[5])
            table->philo[i].must_eat = ft_atoi(argv[5]);
        else
            table->philo[i].must_eat = -1;
        table->philo[i].times.last_meal = get_current_time();
        table->philo[i].times.born_time = get_current_time();
        i++;
    }
}

int	init_table(t_table *table,char  **argv)
{
    int i;
    
	i = 0;
	ft_memset(table, 0, sizeof(t_table));
	table->is_running = true;
	table->count_philo = ft_atoi(argv[1]);
	table->philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
    if (!table->philo)
    {
        printf("Error : Malloc philo init table\n");
        return (FALSE);
    }
    table->forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
    if (!table->forks)
    {
        printf("Error : Malloc forks in init table\n");
        return (FALSE);
    }
    pthread_mutex_init(&table->is_running_lock,NULL);
    pthread_mutex_init(&table->write_lock,NULL);
    while (i < ft_atoi(argv[1]))
    {
        pthread_mutex_init(&table->forks[i],NULL);
        i++;
    }
    init_philo(table,argv);
    return (TRUE);
}

