/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:28:42 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/22 13:46:44 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_position	button_position(int xmin, int xmax, int ymin, int ymax)
{
	t_position position;

	position.xmin = xmin;
	position.xmax = xmax;
	position.ymin = ymin;
	position.ymax = ymax;
	return (position);
}

static void			init_button_2(t_rtv1 *rtv1, int *error)
{
	*error += load_button(rtv1, &rtv1->sprite.x8, "x8", \
		button_position(0, 276, 79, 122));
	*error += load_button(rtv1, &rtv1->sprite.x20, "x20", \
		button_position(0, 276, 122, 164));
	*error += load_button(rtv1, &rtv1->sprite.x200, "x200", \
		button_position(0, 276, 164, 207));
	*error += load_button(rtv1, &rtv1->sprite.x500, "x500", \
		button_position(0, 276, 207, 251));
	*error += load_button(rtv1, &rtv1->sprite.x1000, "x1000", \
		button_position(0, 276, 251, 294));
	*error += load_button(rtv1, &rtv1->sprite.x5000, "x5000", \
		button_position(0, 276, 294, 340));
	*error += load_button(rtv1, &rtv1->sprite.f320, "320x240", \
		button_position(0, 0, 0, 0));
	*error += load_button(rtv1, &rtv1->sprite.f854, "854x480", \
		button_position(0, 0, 0, 0));
	*error += load_button(rtv1, &rtv1->sprite.f1024, "1024x768", \
		button_position(0, 0, 0, 0));
	*error += load_button(rtv1, &rtv1->sprite.f1280, "1280x720", \
		button_position(0, 0, 0, 0));
	*error += load_button(rtv1, &rtv1->sprite.f1400, "1400x1050", \
		button_position(0, 0, 0, 0));
	*error += load_button(rtv1, &rtv1->sprite.f1920, "1920x1080", \
		button_position(0, 0, 0, 0));
}

int					init_button(t_rtv1 *rtv1, int error)
{
	error += load_button(rtv1, &rtv1->sprite.setup, "setup", \
		button_position(90, 181, 0, 80));
	error += load_button(rtv1, &rtv1->sprite.close, "close", \
		button_position(0, 0, 0, 0));
	error += load_button(rtv1, &rtv1->sprite.retry, "retry", \
		button_position(181, 272, 0, 80));
	error += load_button(rtv1, &rtv1->sprite.save, "save", \
		button_position(272, 362, 0, 80));
	error += load_button(rtv1, &rtv1->sprite.display, "display", \
		button_position(362, 453, 0, 80));
	error += load_button(rtv1, &rtv1->sprite.render, "render", \
		button_position(453, 544, 0, 80));
	error += load_button(rtv1, &rtv1->sprite.error, "error", \
		button_position(0, 0, 0, 0));
	error += load_button(rtv1, &rtv1->sprite.sample, "sample", \
		button_position(92, 183, 0, 80));
	error += load_button(rtv1, &rtv1->sprite.format, "format", \
		button_position(183, 276, 0, 80));
	error += load_button(rtv1, &rtv1->sprite.close_setting, "close-setting", \
		button_position(0, 92, 0, 80));
	init_button_2(rtv1, &error);
	return ((error) ? EXIT_FAILURE : EXIT_SUCCESS);
}

void				*load(t_rtv1 *rtv1, char *pathname, char *attr)
{
	int		width;
	int		height;
	char	*name;
	char	*button;

	name = ft_strjoin(pathname, attr);
	if ((button = mlx_png_file_to_image(rtv1->mlx_ptr, name, &width, &height)) \
	== NULL)
		return (NULL);
	free(name);
	return (button);
}

int					load_button(t_rtv1 *rtv1, t_button *button, \
					char *name, t_position position)
{
	char *pathname;

	button->is_active = FALSE;
	button->is_hover = FALSE;
	button->hover = NULL;
	button->hover_disabled = NULL;
	button->disabled = NULL;
	pathname = ft_strjoin(PATH_SPRITE, name);
	if ((button->active = load(rtv1, pathname, ".png")) == NULL)
		return (EXIT_FAILURE);
	if ((ft_strstr(LIST_HOVER, name)))
		if ((button->hover = load(rtv1, pathname, "-hover.png")) == NULL)
			return (EXIT_FAILURE);
	if ((ft_strstr(rtv1->list_disabled, name)))
		if ((button->disabled = load(rtv1, pathname, "-disabled.png")) == NULL)
			return (EXIT_FAILURE);
	if ((ft_strstr(LIST_HOVER_DISABLED, name)))
		if ((button->hover_disabled = load(rtv1, pathname, \
			"-hover-disabled.png")) == NULL)
			return (EXIT_FAILURE);
	free(pathname);
	button->position = position;
	return (EXIT_SUCCESS);
}
