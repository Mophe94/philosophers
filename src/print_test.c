/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:31:37 by dbajeux           #+#    #+#             */
/*   Updated: 2025/03/25 19:47:12 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philosophers.h"  
#include <stdio.h>

// void print_philo(t_philo *philo)
// {
//     printf("Philosophe %d:\n", philo->id);
//     printf("  Must Eat: %d\n", philo->must_eat);
//     printf("  Meals Eaten: %d\n", philo->meals_eaten);
//     printf("  Forks: Left[%p] Right[%p]\n", (void *)philo->left_fork, (void *)philo->right_fork);
//     printf("  Times: Die[%lu] Eat[%lu] Sleep[%lu] LastMeal[%lu] Born[%lu] IsDead[%d]\n\n\n\n\n\n",
//            philo->times.die, philo->times.eat, philo->times.sleep,
//            philo->times.last_meal, philo->times.born_time, philo->times.is_dead);
// }

// void print_table(t_table *table)
// {
//     printf("Table:\n");
//     printf("  Philosophers Count: %d\n", table->count_philo);
//     printf("  Is Running: %d\n", table->is_running);
//     for (int i = 0; i < table->count_philo; i++)
//     {
//         print_philo(&table->philo[i]);
//     }
// }
