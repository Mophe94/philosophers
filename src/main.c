/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:35:35 by dbajeux           #+#    #+#             */
/*   Updated: 2025/01/14 14:25:32 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int main(int argc,char **argv)
{
    if (!check_args(argc,argv))
    {
        ft_putstr("Error args");
    }
    
    return (1);
}