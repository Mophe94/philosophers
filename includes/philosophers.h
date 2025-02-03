/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:19:33 by dbajeux           #+#    #+#             */
/*   Updated: 2025/02/03 16:44:02 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/* ************************************************************************** */
/*                                 INCLUDE                                    */
/* ************************************************************************** */

# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>


/* ************************************************************************** */
/*                                 MACCRO                                     */
/* ************************************************************************** */

# define PHILO_MAX 200
# define TRUE 0
# define FALSE 1


/* ************************************************************************** */
/*                                 STRUCT                                     */
/* ************************************************************************** */

typedef struct s_philo
{
    pthread_t thread;
    int id;
    int meal_eaten;
    size_t last_meal;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    struct t_table *table;
    
} t_philo;

typedef struct s_table
{
    int number_philo;
    size_t time_to_die;
    size_t time_to_eat;
    size_t time_to_sleep;
    size_t num_ot_time_each_must_eat;
    int eating_count;
    int dead_flag;
    pthread_mutex_t eating_lock;
    pthread_mutex_t write_lock;
    pthread_mutex_t *forks;
    t_philo *philos; 
} t_table;


/* ************************************************************************** */
/*                                 FUNCTION                                   */
/* ************************************************************************** */

// utils

int		ft_putstr(char *str);
int		ft_isdigit(int c);
int		check_args(int argc, char **argv);
long	ft_atol(char *str);
int	ft_atoi(char *str);

#endif