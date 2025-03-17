/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:39:55 by dbajeux           #+#    #+#             */
/*   Updated: 2025/03/17 12:55:35 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void print_death_message(t_philo *philo)
{
    const char *death_messages[] = {
        "💀 Philosophe %d a médité trop longtemps... et a oublié de manger.",
        "💀 Philosophe %d a cherché le sens de la vie... il a trouvé la fin.",
        "💀 Philosophe %d a eu une révélation... mais trop tard.",
        "💀 Philosophe %d a tellement réfléchi qu'il en est resté figé pour l'éternité.",
        "💀 Philosophe %d est parti rejoindre Platon au royaume des idées.",
        "💀 Philosophe %d s'est éteint, tel une chandelle dans la nuit...",
        "💀 Philosophe %d a eu une dernière pensée brillante... puis plus rien.",
        "💀 Philosophe %d a contemplé le temps qui passe... il s'est arrêté.",
        "💀 Philosophe %d a joué son dernier acte sur la scène de la vie.",
        "💀 Philosophe %d est devenu un avec l'univers... et avec la faim."
    };

    int msg_index = philo->id % (sizeof(death_messages) / sizeof(death_messages[0]));

    pthread_mutex_lock(&philo->table->write_lock);
    printf(death_messages[msg_index], philo->id);
    printf("\n");
    pthread_mutex_unlock(&philo->table->write_lock);
}


void	*monitoring_life(void *arg)
{
	t_table	*table;
	size_t	current_time;
	int		i;
	int running;

	table = (t_table *)arg;
	while (1)
	{
		pthread_mutex_lock(&table->is_running_lock);
		running = table->is_running;
		pthread_mutex_unlock(&table->is_running_lock);
		if (running == false)
			break ;
		current_time = get_current_time();
		i = 0;
		while (i < table->count_philo)
		{
			pthread_mutex_lock(&table->meal_lock);
			if (current_time
				- table->philo[i].times.last_meal >= table->philo[i].times.die)
			{
				pthread_mutex_lock(&table->is_running_lock);
				table->is_running = false;
				pthread_mutex_unlock(&table->is_running_lock);
				pthread_mutex_lock(&table->write_lock);
				print_death_message(&table->philo[i]);
				pthread_mutex_unlock(&table->write_lock);
				pthread_mutex_unlock(&table->meal_lock);
				return (NULL);
			}
			pthread_mutex_unlock(&table->meal_lock);
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}



void	*philosopher_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("Philosophe %d a démarré\n", philo->id);
	while (1)
	{
		pthread_mutex_lock(&philo->table->is_running_lock);
		if (philo->table->is_running == false)
		{
			pthread_mutex_unlock(&philo->table->is_running_lock);
			printf("Philosophe %d s'arrête\n", philo->id);
			break;
		}
		pthread_mutex_unlock(&philo->table->is_running_lock);
		printf("Philosophe %d va penser\n", philo->id);
		thinking_routine(philo);
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
			return (printf("Error : can't create thread for the philo number%d\n",
					table->philo[i].id), FALSE);
		i++;
	}
	return (TRUE);
}