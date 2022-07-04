/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 11:25:16 by juhur             #+#    #+#             */
/*   Updated: 2022/07/04 13:45:00 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>
# include "util.h"

# define WIDTH	960
# define HEIGHT	640

enum e_error
{
	STATUS_OK,
	STATUS_ERROR_ARG,
	STATUS_ERROR_FILE_OPEN,
	STATUS_ERROR_ALLOC,
	STATUS_ERROR_INVALID_MAP,
	STATUS_MAX
};

enum e_image
{
	NO = 0,
	SO,
	WE,
	EA,
	MAX_IMAGE
};

enum e_background_color
{
	CEILING = 0,
	FLOOR,
	MAX_BACKGROUND_COLOR
};

enum e_color
{
	RED = 0,
	GREEN,
	BLUE,
	MAX_COLOR
};

struct s_image
{
	void	*img;
	char	*path;
	int		h;
	int		w;
};

struct s_background
{
	int	rgb;
};

struct s_map
{
	char	**map;
	int		width;
	int		height;
};

typedef struct s_game
{
	void				*mlx;
	void				*win;
	struct s_image		wall[MAX_IMAGE];
	struct s_background	background[MAX_BACKGROUND_COLOR];
	struct s_map		map;
}	t_game;

/*
** draw
*/
void	destroy_window(t_game *g);
int		draw_window(t_game *g);

/*
** event
*/
int		key_press(int key, t_game *g);
int		mouse_hook(t_game *g);

/*
** init
*/
void	init(t_game *g);
void	init_mlx(t_game *g);

/*
** parse
*/
bool	set_background(t_game *g, char *data);
bool	check_map(struct s_map map);
bool	set_image(t_game *g, char *data);
void	set_map(struct s_map *map, t_list *list);
void	parse(t_game *g, const char *file_name);
bool	read_raw_data(t_list **map_raw_data, const char *file_name);

/*
** quit
*/
int		quit_program(enum e_error err_no);

#endif
