/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amokone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:42:59 by amokone           #+#    #+#             */
/*   Updated: 2017/12/02 14:34:03 by amokone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		print_out_move(t_game *game)
{
	t_point		move;

	move = get_best_move(game);
	ft_putstr(ft_itoa(move.row));
	ft_putchar(' ');
	ft_putendl(ft_itoa(move.col));
}

int				main(void)
{
	t_game		game;
	char		*line;

	game = (t_game){'\0', '\0', NULL, 0, 0, 0, {0, 0, NULL}, NULL};
	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '$')
			get_player(line, &game);
		if (line[1] == 'l')
		{
			if (!get_dimensions(line, &game) || !(play_game(&game)))
				break ;
		}
		if (line[1] == 'i')
		{
			if (!(get_token(&game.token, line)))
				break ;
			get_possible_moves(&game, &game.token);
			print_out_move(&game);
		}
	}
	free(line);
	destroy_game(&game);
	return (0);
}
