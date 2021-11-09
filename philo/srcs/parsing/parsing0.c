/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:25:03 by lburnet           #+#    #+#             */
/*   Updated: 2021/11/09 13:30:08 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	assign_int(int *to_be_assign, char *str)
{
	*to_be_assign = ft_atoi(str);
	if (*to_be_assign <= 0)
		return (NOT_POS);
	return (NO_ERROR);
}

int	ft_parsing(int ac, char *av[], t_p *p)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (can_atoi(av[i]) == 1)
			return (NOT_AN_INT);
		if (i == 1 && assign_int(&p->nb_philo, av[i]) != NO_ERROR)
			return (NOT_POS);
		else if (i == 2 && assign_int(&p->t_to_die, av[i]) != NO_ERROR)
			return (NOT_POS);
		else if (i == 3 && assign_int(&p->t_to_eat, av[i]) != NO_ERROR)
			return (NOT_POS);
		else if (i == 4 && assign_int(&p->t_to_sleep, av[i]) != NO_ERROR)
			return (NOT_POS);
		else if (i == 5 && assign_int(&p->nb_meal, av[i]) != NO_ERROR)
			return (NOT_POS);
		i++;
	}
	return (NO_ERROR);
}
