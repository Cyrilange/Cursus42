#include "../includes/so_long.h"


void	exit_map(t_data *data)
{
	mlx_loop_end(data->mlx);
	cleanup(data);
	exit(0);
}

int	exit_hook(void *params)
{
	t_data	*data;

	data = (t_data *)params;
	exit_map(data);
	return (0);
}

t_point	ft_locate(char **map, char c)
{
	t_point	position;
	int		x;
	int		y;

	position.x = -1;
	position.y = -1;
	x = 0;
	y = 0;
	while (map[x] && map[x][y] != '\0')
	{
		if (map[x][y] == c)
		{
			position.x = x;
			position.y = y;
			return (position);
		}
		y++;
		if (map[x][y] == '\0')
		{
			x++;
			y = 0;
		}
	}
	return (position);
}

static char	**ft_move(t_data *data, int x, int y, t_point exit_position)
{
	t_point	player_position;

	player_position = ft_locate(data->map, 'P');
	if (!data->total_star)
		data->total_star = ft_count_char(data->map, 'C');
	if (data->map[player_position.x + x][player_position.y + y] == 'C')
		data->count_star++;
	if (data->map[player_position.x + x][player_position.y + y] == 'E'
		&& data->count_star == data->total_star)
	{
		ft_printf("total_moves : %d\n", data->count_move + 1);
		exit_map(data);
	}
	if (data->map[player_position.x + x][player_position.y + y] != '1')
	{
		data->map[player_position.x + x][player_position.y + y] = 'P';
		if (player_position.x == exit_position.x
			&& player_position.y == exit_position.y)
			data->map[player_position.x][player_position.y] = 'E';
		else
			data->map[player_position.x][player_position.y] = '0';
		data->count_move++;
		ft_printf("total_moves : %d\n", data->count_move);
	}
	return (data->map);
}

int	key_press(int keycode, void *param)
{
	t_data	*data;
	t_point	move;

	data = (t_data *)param;
	move.x = 0;
	move.y = 0;
	if (keycode == 119)
		move.x = -1;
	else if (keycode == 97)
		move.y = -1;
	else if (keycode == 115)
		move.x = 1;
	else if (keycode == 100)
		move.y = 1;
	else if (keycode == 65307)
		exit_map(data);
	if (move.x != 0 || move.y != 0)
		data->map = ft_move(data, move.x, move.y, data->exit_position);
	if (!(data->map))
		return (0);
	mlx_clear_window(data->mlx, data->win);
	render_map(data, data->map);
	return (0);
}