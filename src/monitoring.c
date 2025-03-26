/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:35:28 by dbajeux           #+#    #+#             */
/*   Updated: 2025/03/26 15:15:15 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int check_table_is_running(t_philo *philo)
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

void print_message(t_philo *philo,char *msg)
{
    size_t time;

    pthread_mutex_lock(&philo->table->write_lock);
    time = get_current_time() - philo->times.born_time;
    if (check_table_is_running(philo) == TRUE)
       printf("%zu Philosophe %d %s\n",time,philo->id,msg);
    pthread_mutex_unlock(&philo->table->write_lock);
}
