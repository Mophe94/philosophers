/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:35:35 by dbajeux           #+#    #+#             */
/*   Updated: 2025/02/03 16:07:14 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int main(int argc,char **argv)
{
    t_table table;
    t_philo philos[PHILO_MAX];
    pthread_mutex_t forks[PHILO_MAX];
    
    if (check_args(argc,argv) == FALSE)
    {
        printf("error args");
        return (FALSE);
    }
    else
    {
        
       printf("prog run\n"); 
    }
    
    return (1);
}