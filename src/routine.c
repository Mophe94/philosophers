/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:36:12 by dbajeux           #+#    #+#             */
/*   Updated: 2025/03/28 17:34:12 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	thinking_routine(t_philo *philo)
{
	print_message(philo, "is thinking 💭");
}

void	sleep_routine(t_philo *philo)
{
	print_message(philo, "is sleeping 😴✨");
	ft_usleep(philo->times.sleep);
}

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_message(philo, "has taken a fork 🍴");
		pthread_mutex_lock(philo->left_fork);
		print_message(philo, "has taken a fork 🍴");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_message(philo, "has taken a fork 🍴");
		pthread_mutex_lock(philo->right_fork);
		print_message(philo, "has taken a fork 🍴");
	}
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	eat_routine(t_philo *philo)
{
	if (philo->table->count_philo == 1)
	{
		pthread_mutex_lock(philo->right_fork);
		print_message(philo, "has taken a fork 🍴");
		ft_usleep(philo->times.die);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	take_forks(philo);
	pthread_mutex_lock(&philo->table->meal_lock);
	philo->times.last_meal = get_current_time();
	if (philo->must_eat != -1)
		philo->meals_eaten++;
	pthread_mutex_unlock(&philo->table->meal_lock);
	print_message(philo, "is eating 🤤🍽️ ");
	ft_usleep(philo->times.eat);
	release_forks(philo);
}