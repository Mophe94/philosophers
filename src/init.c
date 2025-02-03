/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:57:18 by dbajeux           #+#    #+#             */
/*   Updated: 2025/02/03 16:49:30 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int init_table(t_table *table,t_philo *philos,char **argv,pthread_mutex_t *forks)
{
    table->number_philo = ft_atol(argv[1]);
    table->time_to_die = ft_atol(argv[2]);
    table->time_to_eat = ft_atol(argv[3]);
    table->time_to_sleep = ft_atol(argv[4]);
    if (argv[5])
        table->num_ot_time_each_must_eat = ft_atol(argv[5]);
    else   
        table->num_ot_time_each_must_eat = -1;
    table->eating_count = 0;
    table->dead_flag = FALSE;
    table->forks = forks;
    table->philos = philos;
    if (pthread_mutex_init(&table->eating_lock,NULL) != TRUE)
        return (FALSE);
    if (pthread_mutex_init(&table->write_lock,NULL) != TRUE)
        return (FALSE);
    
}
int init_philo()
{

}

int init_forks()
{
    
}