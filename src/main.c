/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:35:35 by dbajeux           #+#    #+#             */
/*   Updated: 2025/03/27 15:59:54 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_table	table;

	if (check_args(argc, argv) == FALSE)
	{
		printf("error args\n");
		return (1);
	}
	else
	{
		if (init_table(&table, argv, argc) == FALSE)
			return (printf("Error : can't initilize the table\n"), 1);
		if (create_threads(&table) == FALSE)
			return (printf("Error : End of simulation\n ❌ \n"), 1);
		kill_prog(&table, "Succes : End of Simulation ✅ \n");
	}
	return (0);
}
