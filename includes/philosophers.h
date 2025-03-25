/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:19:33 by dbajeux           #+#    #+#             */
/*   Updated: 2025/03/25 19:41:40 by dbajeux          ###   ########.fr       */
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

# define PHILO_MA 200
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
	bool			is_dead;
}					t_times;

typedef struct s_table
{
	struct s_philo	*philo;
	pthread_t		monitoring;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	is_running_lock;
	int				count_philo;
	bool			is_running;

}					t_table;

typedef struct s_philo
{
	int				id;
	t_times			times;
	int				must_eat;
	int				meals_eaten;
	pthread_t		thread_id;
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
int					init_table(t_table *table, int count_philo);
void				init_philo(t_table *table,size_t time_to_eat,size_t time_to_die);
void				print_philo(t_philo *philo);
void				print_table(t_table *table);
int					create_threads(t_table *table);
void				*monitoring_life(void *);
void				thinking_routine(t_philo *philo);
int print_message(t_philo *philo,char *msg);
int	ft_usleep(size_t milliseconds);
void sleep_routine(t_philo *philo);
#endif