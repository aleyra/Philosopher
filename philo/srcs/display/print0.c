/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:11:08 by lburnet           #+#    #+#             */
/*   Updated: 2021/11/09 11:03:57 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philos(t_p *p)
{
	printf("nb_philo = %d\n", p->nb_philo);
	printf("t_to_die = %d\n", p->t_to_die);
	printf("t_to_eat = %d\n", p->t_to_eat);
	printf("t_to_sleep = %d\n", p->t_to_sleep);
	printf("nb_meal = %d\n", p->nb_meal);
}
