/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:48:50 by mmoulati          #+#    #+#             */
/*   Updated: 2025/01/14 11:42:38 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"
#include "stack.h"
#include <stdio.h>
#include <string.h>

#define SEPERATOR "    |    "

typedef struct s_cmd
{
	void	(*func)(t_game *);
	char	name[10];
}			t_cmd;

void	t_game_print(t_game *game)
{
	t_stack	*pa;
	t_stack	*pb;

	pa = game->a;
	pb = game->b;
	printf("%10s" SEPERATOR "%10s\n--------------------------------\n", "A",
		"B");
	while (pa != NULL || pb != NULL)
	{
		if (pa != NULL)
		{
			printf("%10d", pa->num);
			pa = pa->next;
		}
		else
			printf("%10s", "");
		printf(SEPERATOR);
		if (pb != NULL)
		{
			printf("%10d", pb->num);
			pb = pb->next;
		}
		printf("\n");
	}
	printf("--------------------------------\n");
}

int	main(int argc, char **argv)
{
	t_game	*game;
	char	str[100];
	int		found;

	setvbuf(stdout, NULL, _IONBF, 0);
	t_cmd cmds[10] = {
		{
			.func = sa,
			.name = "sa",
		},
		{
			.func = sb,
			.name = "sb",
		},
		{
			.func = pa,
			.name = "pa",
		},
		{
			.func = pb,
			.name = "pb",
		},
		{
			.func = ra,
			.name = "ra",
		},
		{
			.func = rb,
			.name = "rb",
		},
		{
			.func = rra,
			.name = "rra",
		},
		{
			.func = rrb,
			.name = "rrb",
		},
		{
			.func = rrr,
			.name = "rrr",
		},
		{
			.func = rr,
			.name = "rr",
		},
	};
	if (argc < 2)
		return (0);
	game = t_game_new(argc, argv);
	t_game_print(game);
	do
	{
		found = 0;
		printf("command : ");
		scanf("%s", str);
		printf("\n");
		for (int i = 0; i < 10; i++)
		{
			if (!strcmp(str, cmds[i].name))
			{
				found = 1;
				cmds[i].func(game);
				break ;
			}
		}
		if (!found && (!strcmp(str, "restart") || !strcmp(str, "re")))
		{
			found = 1;
			t_game_clear(&game);
			game = t_game_new(argc, argv);
		}
		if (!found && (!strcmp(str, "exit") || !strcmp(str, "q")))
		{
			found = 1;
			t_game_clear(&game);
			game = t_game_new(argc, argv);
		}
		if (!found)
			printf("%s : command not found\n", str);
		t_game_print(game);
	} while (1);
	t_game_clear(&game);
}
