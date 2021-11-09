/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburnet <lburnet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:51:25 by lburnet           #+#    #+#             */
/*   Updated: 2021/11/09 10:45:37 by lburnet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "stdio.h"
# include "pthread.h"
# include "string.h"
# include "unistd.h"
# include "stdlib.h"

typedef struct s_philos	t_p;
typedef enum e_error	t_error;

struct s_philos
{
	int	nb_philo;
	int	t_to_die;
	int	t_to_eat;
	int	t_to_sleep;
	int	nb_meal;
};

enum e_error
{
	NO_ERROR,
	WRONG_NB_ARG,
	ERROR_MALLOC,
};

//fct in display
void	error_message(int err);

//fct in parsing
int		ft_parsing(int ac, char *av[], t_p *p);

//fct in tools
int		can_atoi(const char *str);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_strlen(const char *str);
#endif
