/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:27:05 by dbajeux           #+#    #+#             */
/*   Updated: 2025/01/15 15:56:00 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int check_args(int argc,char ** argv)
{
    int i;

    i = 0;
    if (argc != 5)
        return (0);
    while (argv[i])
    {
        if (ft_isdigit(ft_atoi(argv[i])) == 1) 
            i++;
        else 
            return (0);
    }
    return (1);
}