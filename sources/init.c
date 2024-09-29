void	init_game(t_game *game, const char *filename)
{
	game->player = 0;
	game->map = read_map(filename);
	game->mlx = 0;
	game->window = 0;
	game->wall_img = 0;
	game->player_img = 0;
	game->floor_img = 0;
	game->collectible_img = 0;
	game->exit_img = 0;
	game->img_width = 0;
	game->img_height = 0;
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		perror("Error: could not initialize MLX\n");
		exit(1);
	} 
	game->window = mlx_new_window(game->mlx, TILE_SIZE * game->map.width, TILE_SIZE * game->map.height, "so_long");
	if (!game->window)
	{
		perror("Error:\ncould not create a window\n");
		exit(1);
	}
}
