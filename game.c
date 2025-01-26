/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:52:40 by mmoulati          #+#    #+#             */
/*   Updated: 2025/01/16 15:30:15 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

int	ft_atoi(char **str, t_state *state)
{
	long	res;
	int		sign;

	sign = 1;
	res = 0;
	while (**str == 32)
		(*str)++;
	if (**str == '-' || **str == '+')
		if (*(*str)++ == '-')
			sign = -1;
	if (**str < '0' || **str > '9')
		return (*state = ERR_NUMBER_FORMAT);
	while (**str >= '0' && **str <= '9')
	{
		res = 10 * res + **str - '0';
		if (res > 2147483647L + (sign == -1))
			return (*state = ERR_NUMBER_TOO_LARGE);
		(*str)++;
	}
	while (**str == 32)
		(*str)++;
	return (res * sign);
}

void	t_game_clear(t_game **game)
{
	if (game == NULL)
		return ;
	if (*game != NULL)
	{
		t_stack_clear(&(*game)->a);
		t_stack_clear(&(*game)->b);
		t_stack_clear(&(*game)->move);
	}
	free(*game);
	*game = NULL;
}

void	t_game_parse(t_game **game, char *str)
{
	t_state	state;
	int		num;

	state = OK;
	if (*str == '\0')
		state = ERR_NUMBER_FORMAT;
	while (*str)
	{
		num = ft_atoi(&str, &state);
		if (state == OK && t_stack_idx((*game)->a, num) >= 0)
			state = ERR_NUMBER_EXIST;
		if (state == OK && t_stack_push(&(*game)->a, num) == NULL)
			state = ERR_MALLOC_FAILED;
		if (state != OK)
			break ;
		(*game)->size++;
	}
	if (state == OK)
		return ;
	t_game_clear(game);
	write(2, "Error\n", 6);
	exit(1);
}

t_game	*t_game_new(long argc, char **argv)
{
	t_game	*game;
	long	i;

	if (argc < 2)
		return (NULL);
	game = malloc(sizeof(t_game));
	if (game == NULL)
		return (NULL);
	i = 1;
	game->a = NULL;
	game->b = NULL;
	game->move = NULL;
	game->size = 0;
	while (i < argc)
	{
		t_game_parse(&game, argv[i]);
		i++;
	}
	return (game);
}

void	t_game_solve(t_game *game)
{
	t_move_optimize(game->move);
}
