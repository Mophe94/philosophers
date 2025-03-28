/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:36:12 by dbajeux           #+#    #+#             */
/*   Updated: 2025/03/28 12:40:02 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	thinking_routine(t_philo *philo)
{
	// int		msg_index;
	// char	*messages[] = {"💭 est plongé dans une profonde réflexion...",
	// 		"💭 médite sur le sens de la vie et des spaghettis...",
	// 		"💭 se demande si la fourchette gauche est plus lourde que la droite...",
	// 		"💭 a une idée révolutionnaire... mais il a faim !",
	// 		"💭 est en train de philosopher... Qui suis-je ? Où vais-je ? Où est ma fourchette ?",
	// 		"💭 réfléchit au paradoxe de l'œuf et de la poule...",
	// 		"💭 tente de comprendre pourquoi il n'a toujours pas mangé...",
	// 		"💭 médite sur la gravité des pâtes tombées...",
	// 		"💭 croit avoir résolu un grand mystère... mais il a oublié lequel !",
	// 		"💭 pense qu'il pense, mais en est-il sûr ?",
	// 		"💭 rédige mentalement son livre 'Manger ou être mangé'...",
	// 		"💭 songe à remplacer l'eau par du vin dans son prochain repas...",
	// 		"💭 se demande si tout cela n'est qu'une simulation...",
	// 		"💭 essaye de prédire l'avenir de son assiette...",
	// 		"💭 pense tellement qu'il en a oublié pourquoi il pense..."};

	// msg_index = philo->id % (sizeof(messages) / sizeof(messages[0]));
	print_message(philo, "is thinking");
}

void	sleep_routine(t_philo *philo)
{
	//int	msg_index;

	// char *messages[] = {
	// 	"😴✨ se demande si compter les moutons fonctionne vraiment...",
	// 		"😴✨ médite sur l’instant exact où l’on s’endort… et ne le trouve jamais.",
	// 		"😴✨ essaye de comprendre pourquoi le lit est toujours plus confortable le matin...",
	// 		"😴✨ tente de ne pas penser pour s’endormir… mais pense à ne pas penser.",
	// 		"😴✨ philosophe sur le mystère des chaussettes perdues sous la couette...",
	// 		"😴✨ se demande pourquoi le cerveau devient hyperactif juste avant de dormir...",
	// 		"😴✨ veut dormir… mais une chanson tourne en boucle dans sa tête.",
	// 		"😴✨ réfléchit à la meilleure position pour dormir… et finit en étoile de mer.",
	// 		"😴✨ cherche une signification profonde aux bruits de la nuit…",
	// 		"😴✨ est persuadé d’avoir trouvé la meilleure idée du monde… mais trop fatigué pour la noter.",
	// 		"😴✨ tente de se souvenir d’un rêve génial… mais il s’évapore comme du brouillard.",
	// 		"😴✨ se demande si les oreillers rêvent d’être plus moelleux…",
	// 		"😴✨ hésite entre dormir et scroller encore un peu…",
	// 		"😴✨ se promet de dormir tôt demain… comme tous les soirs."};
	// msg_index = philo->id % (sizeof(messages) / sizeof(messages[0]));
	print_message(philo,  "is sleeping");
	ft_usleep(philo->times.sleep);
}

void	take_forks(t_philo *philo)
{
	if (philo->table->count_philo == 1)
	{
		pthread_mutex_lock(philo->right_fork);
		print_message(philo, "has taken a fork test🍴");
		ft_usleep(philo->times.die);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	if (philo->id % 2 == 0)
	{
	pthread_mutex_lock(philo->right_fork);
	print_message(philo, "has taken a fork 1🍴");
	pthread_mutex_lock(philo->left_fork);
	print_message(philo, "has taken a fork 1🍴");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_message(philo, "has taken a fork 2🍴");
		pthread_mutex_lock(philo->right_fork);
		print_message(philo, "has taken a fork 2🍴");
	}
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	eat_routine(t_philo *philo)
{
	take_forks(philo);
	philo->eating = TRUE;
	pthread_mutex_lock(&philo->table->meal_lock);
	philo->times.last_meal = get_current_time();
	if (philo->must_eat != -1)
		philo->meals_eaten++;
	pthread_mutex_unlock(&philo->table->meal_lock);
	print_message(philo, "is eating 🤤🍽️");
	ft_usleep(philo->times.eat);
	philo->eating = FALSE;
	release_forks(philo);
}