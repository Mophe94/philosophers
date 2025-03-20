/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:35:35 by dbajeux           #+#    #+#             */
/*   Updated: 2025/03/20 12:46:01 by dbajeux          ###   ########.fr       */
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
		init_table(&table, ft_atoi(argv[1]));
		init_philo(&table,ft_atoi(argv[2]),ft_atoi(argv[3]));
		print_table(&table);
        create_threads(&table);	
    	for (int i = 0; i < table.count_philo; i++)
			pthread_join(table.philo[i].thread_id, NULL);
	}
	return (0);
}