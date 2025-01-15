/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:27:05 by dbajeux           #+#    #+#             */
/*   Updated: 2025/01/15 17:23:59 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int check_args(int argc,char ** argv)
{
    int i;
    
    i = 0;
    if (argc != 6)
    {
        printf("Error to much argument in check arg\n");
        return (0);
    }
    while (argv[i])
    {
        if (ft_isdigit(ft_atoi(argv[i])) == 1) 
            i++;
        else 
            return (0);
        i++;
    }
    return (1);
}