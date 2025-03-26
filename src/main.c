/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:35:35 by dbajeux           #+#    #+#             */
/*   Updated: 2025/03/26 11:54:49 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_table table;
	if (check_args(argc, argv) == FALSE)
	{
		printf("error args");
		return (1);
	}
	else
	{
		if (init_table(&table, argv) == FALSE)
			return (printf("Error : can't initilize the table"),1);
		//print_table(&table);
        create_threads(&table);	
    	for (int i = 0; i < table.count_philo; i++)
			pthread_join(table.philo[i].thread_id, NULL);
	}
	return (0);
}