/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:36:12 by dbajeux           #+#    #+#             */
/*   Updated: 2025/03/17 12:54:15 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philosophers.h"

void thinking_routine(t_philo *philo)
{
    int msg_index;
    const char *messages[] = {
        "💭 Philosophe %d est plongé dans une profonde réflexion...",
        "💭 Philosophe %d médite sur le sens de la vie et des spaghettis...",
        "💭 Philosophe %d se demande si la fourchette gauche est plus lourde que la droite...",
        "💭 Philosophe %d a une idée révolutionnaire... mais il a faim !",
        "💭 Philosophe %d est en train de philosopher... Qui suis-je ? Où vais-je ? Où est ma fourchette ?",
        "💭 Philosophe %d réfléchit au paradoxe de l'œuf et de la poule...",
        "💭 Philosophe %d tente de comprendre pourquoi il n'a toujours pas mangé...",
        "💭 Philosophe %d médite sur la gravité des pâtes tombées...",
        "💭 Philosophe %d croit avoir résolu un grand mystère... mais il a oublié lequel !",
        "💭 Philosophe %d pense qu'il pense, mais en est-il sûr ?",
        "💭 Philosophe %d rédige mentalement son livre 'Manger ou être mangé'...",
        "💭 Philosophe %d songe à remplacer l'eau par du vin dans son prochain repas...",
        "💭 Philosophe %d se demande si tout cela n'est qu'une simulation...",
        "💭 Philosophe %d essaye de prédire l'avenir de son assiette...",
        "💭 Philosophe %d pense tellement qu'il en a oublié pourquoi il pense..."
    };

    msg_index = philo->id % (sizeof(messages) / sizeof(messages[0]));

    pthread_mutex_lock(&philo->table->write_lock);
    printf(messages[msg_index],philo->id);
    printf("\n");
    pthread_mutex_unlock(&philo->table->write_lock);
}