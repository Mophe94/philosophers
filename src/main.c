/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:35:35 by dbajeux           #+#    #+#             */
/*   Updated: 2025/02/08 20:48:37 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int main(int argc,char **argv)
{

    
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