/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:19:33 by dbajeux           #+#    #+#             */
/*   Updated: 2025/03/28 17:33:48 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/* ************************************************************************** */
/*                                 INCLUDE                                    */
/* ************************************************************************** */

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

/* ************************************************************************** */
/*                                 MACCRO                                     */
/* ************************************************************************** */

# define PHILO_MAX 200
# define TRUE 0
# define FALSE 1

/* ************************************************************************** */
/*                                 STRUCT                                     */
/* ************************************************************************** */

typedef struct s_times
{
	size_t			die;
	size_t			eat;
	size_t			sleep;
	size_t			last_meal;
	size_t			born_time;
}					t_times;

typedef struct s_table
{
	struct s_philo	*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	is_running_lock;
	pthread_mutex_t	meal_lock;
	int				count_philo;
	int				is_running;
}					t_table;

typedef struct s_philo
{
	int				id;
	int				must_eat;
	int				meals_eaten;
	int				is_dead;
	int				eating;
	pthread_t		thread_id;
	t_times			times;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_table			*table;
}					t_philo;

/* ************************************************************************** */
/*                                 FUNCTION                                   */
/* ************************************************************************** */

// utils

int					ft_putstr(char *str);
int					ft_isdigit(int c);
int					check_args(int argc, char **argv);
long				ft_atol(char *str);
int					ft_atoi(char *str);
size_t				get_current_time(void);
void				*ft_memset(void *b, int c, size_t len);
int					init_table(t_table *table, char **argv, int argc);
void				init_philo(t_table *table, char **argv, int argc);
int					create_threads(t_table *table);
void				*monitoring_life(void *);
void				thinking_routine(t_philo *philo);
void				print_message(t_philo *philo, char *msg);
int					ft_usleep(size_t milliseconds);
void				sleep_routine(t_philo *philo);
void				eat_routine(t_philo *philo);
int					check_table_is_running(t_philo *philo);
int					check_death_philo(t_table *table);
int					check_must_eat_philo(t_table *table);
void				kill_prog(t_table *table, char *msg);
void				print_table(t_table *table);
#endif