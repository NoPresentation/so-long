/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <anashwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:10:17 by anashwan          #+#    #+#             */
/*   Updated: 2026/01/21 19:23:59 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber(char *file_name)
{
	char *dot;

	if (!file_name || ft_strlen(file_name) < 5)
		return (0);
	dot = ft_strrchr(file_name, '.');
	if (!dot)
		return (0);
	if (ft_strncmp(dot, ".ber", 5) == 0)
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	*game;

	if (argc != 2)
		return (1);
	if (!check_ber(argv[1]))
	{
		ft_putstr_fd("Error\nInvalid map file extension.\n", 2);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nInvaid file descriptor\n", 2);
		return (1);
	}
	game = create_game(get_map(fd));
	close(fd);
	if (!game || !validate_map(game))
	{
		close_game(game);
		return (1);
	}
	start_game(game);
	return (0);
}
