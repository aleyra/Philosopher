/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucille <lucille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:51:25 by lburnet           #+#    #+#             */
/*   Updated: 2021/11/16 15:10:45 by lucille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "stdio.h"
# include "pthread.h"
# include "string.h"
# include "unistd.h"
# include "stdlib.h"

typedef struct s_suitcase	t_suitcase;
typedef struct s_philo	t_philo;
typedef enum e_error	t_error;

struct s_philo
{
	int					who;
	int					iseating;
	unsigned long long	limit;//?
	unsigned long long	last_eat;
	int					lfork;
	int					rfork;
	int					meal;
	t_suitcase			*sc;//pour pouvoir revenir en arrière ?
	pthread_mutex_t		mutex;
	pthread_mutex_t		eat_m;
};

struct s_suitcase
{
	int					nb_philo;
	int					t_to_die;
	int					t_to_eat;
	int					t_to_sleep;
	int					nb_meal;
	unsigned long long	start;//?
	t_philo				*philos;
	pthread_mutex_t		*forks_m;
	pthread_mutex_t		write_m;//think ?
	pthread_mutex_t		isdead;
};

enum e_error
{
	NO_ERROR,
	WRONG_NB_ARG,
	ERROR_MALLOC,
	NOT_AN_INT,
	NOT_POS,
};

//fct in display
void	error_message(int err);
void	print_philos(t_suitcase *p);

//fct in parsing
int		ft_parsing(int ac, char *av[], t_suitcase *p);

//fct in tools
int		can_atoi(const char *str);
int		ft_atoi(const char *str);
int		ft_exit(t_suitcase *sc, int err);
int		ft_isdigit(int c);
int		ft_strlen(const char *str);
#endif
