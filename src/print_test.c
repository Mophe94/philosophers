/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:31:37 by dbajeux           #+#    #+#             */
/*   Updated: 2025/03/26 15:14:50 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philosophers.h"  

void print_philo(t_philo *philo)
{
    printf("Philosopher %d:\n", philo->id);
    printf("  Meals eaten: %d\n", philo->meals_eaten);
    printf("  Is dead: %s\n", philo->is_dead == TRUE ? "Yes" : "No");
    printf("  Must eat: %d\n", philo->must_eat);
    printf("  Time to die: %ld\n", philo->times.die);
    printf("  Time to eat: %ld\n", philo->times.eat);
    printf("  Time to sleep: %ld\n", philo->times.sleep);
    printf("  Last meal time: %ld\n", philo->times.last_meal);
    printf("  Born time: %ld\n", philo->times.born_time);
    printf("  Left fork: %p\n", (void*)philo->left_fork);
    printf("  Right fork: %p\n", (void*)philo->right_fork);
}

void print_table(t_table *table)
{
    printf("Table Info:\n");
    printf("  Philosopher count: %d\n", table->count_philo);
    printf("  Is running: %s\n", table->is_running == TRUE ? "Yes" : "No");
    printf("  Mutex Addresses:\n");
    printf("    is_running_lock: %p\n", (void*)&table->is_running_lock);
    printf("    write_lock: %p\n", (void*)&table->write_lock);
    printf("  Forks:\n");
    for (int i = 0; i < table->count_philo; i++)
    {
        printf("    Fork %d: %p\n", i, (void*)&table->forks[i]);
    }
    printf("Philosophers:\n");
    for (int i = 0; i < table->count_philo; i++)
    {
        print_philo(&table->philo[i]);
    }
}