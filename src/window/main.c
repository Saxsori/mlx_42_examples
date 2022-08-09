/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-tena <oal-tena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 09:49:20 by oal-tena          #+#    #+#             */
/*   Updated: 2022/08/09 13:27:46 by oal-tena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mlx_example.h"

#define WIDTH 800
#define HEIGHT 600


typedef struct s_line
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
}			t_line;

typedef struct s_windows
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*data;
	int		bpp;
	int		size_line;
	int		endian;
}			t_windows;

void	init_window(t_windows *window)
{
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, WIDTH, HEIGHT, "mlx_ex01");
	window->img = mlx_new_image(window->mlx, WIDTH, HEIGHT);
	window->data = (int *)mlx_get_data_addr(window->img, &window->bpp,
			&window->size_line, &window->endian);
}

void	init_line(t_line *line)
{
	line->x1 = 0;
	line->y1 = 0;
	line->x2 = 300;
	line->y2 = 300;
}

void	draw_line(t_windows *window, t_line *line)
{
	while (line->y1 < line->y2)
	{
		window->data[(line->y1 * WIDTH) + line->x1] = 0xDD9933;
		line->y1++;
		line->x1++;
	}
}

int	main(void)
{
	t_windows	*window;
	t_line		*line;

	window = (t_windows *)malloc(sizeof(t_windows));
	line = (t_line *)malloc(sizeof(t_line));
	init_window(window);
	init_line(line);
	draw_line(window, line);
	mlx_put_image_to_window(window->mlx, window->win, window->img, 0, 0);
	mlx_loop(window->mlx);
}
