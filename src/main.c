/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:10:17 by anashwan          #+#    #+#             */
/*   Updated: 2026/01/10 17:48:16 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_game	*game;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	game = create_game(get_map(fd));
	if (!game || !validate_map(game))
	{
		close_game(game);
		return (1);
	}
	start_game(game);
	return (0);
}
