/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:28:42 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 15:58:16 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int 		*position(int xmin, int xmax, int ymin, int ymax)
{
	int *position;

	if (position = (int *)malloc())
	position[0] = xmin;
	position[1] = xmax;
	position[2] = ymin;
	position[3] = ymax;
	return (position);
}

int				init_button(t_rtv1 *rtv1, int e)
{
	e += load_button(rtv1, &rtv1->sprite.setup, "setup", position(P_SETUP));
	e += load_button(rtv1, &rtv1->sprite.close, "close", position(P_CLOSE));
	e += load_button(rtv1, &rtv1->sprite.retry, "retry", position(P_RETRY));
	e += load_button(rtv1, &rtv1->sprite.save, "save", position(P_SAVE));
	e += load_button(rtv1, &rtv1->sprite.display, "display", position(P_DISPLAY));
	e += load_button(rtv1, &rtv1->sprite.render, "render", position(P_RENDER));
	e += load_button(rtv1, &rtv1->sprite.error, "error", position(P_ERROR));
	e += load_button(rtv1, &rtv1->sprite.sample, "sample", position(P_SAMPLE));
	e += load_button(rtv1, &rtv1->sprite.format, "format", position(P_FORMAT));
	e += load_button(rtv1, &rtv1->sprite.close_setting, "close-setting", position(P_CLOSE_SETTING));
	e += load_button(rtv1, &rtv1->sprite.x8, "x8", position(P_X8));
	e += load_button(rtv1, &rtv1->sprite.x20, "x20", position(P_X20));
	e += load_button(rtv1, &rtv1->sprite.x200, "x200", position(P_X200));
	e += load_button(rtv1, &rtv1->sprite.x500, "x500", position(P_X500));
	e += load_button(rtv1, &rtv1->sprite.x1000, "x1000", position(P_X1000));
	e += load_button(rtv1, &rtv1->sprite.x5000, "x5000", position(P_X5000));
	e += load_button(rtv1, &rtv1->sprite.f320, "320x240", position(P_X8));
	e += load_button(rtv1, &rtv1->sprite.f854, "854x480", position(P_X20));
	e += load_button(rtv1, &rtv1->sprite.f1024, "1024x768", position(P_X200));
	e += load_button(rtv1, &rtv1->sprite.f1280, "1280x720", position(P_X500));
	e += load_button(rtv1, &rtv1->sprite.f1400, "1400x1050", position(P_X1000));
	e += load_button(rtv1, &rtv1->sprite.f1920, "1920x1080", position(P_X5000));
	return ((error) ? EXIT_FAILURE : EXIT_SUCCESS);
}

void			*load(t_rtv1 *rtv1, char *pathname, char *attr)
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

int				load_button(t_rtv1 *rtv1, t_button *button, char *name, int position[4])
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
	if ((ft_strstr(LIST_DISABLED, name)))
		if ((button->disabled = load(rtv1, pathname, "-disabled.png")) == NULL)
			return (EXIT_FAILURE);
	if ((ft_strstr(LIST_HOVER_DISABLED, name)))
		if ((button->hover_disabled = load(rtv1, pathname, \
			"-hover-disabled.png")) == NULL)
			return (EXIT_FAILURE);
	free(pathname);
	button->xmin = position[0];
	button->xmax = position[1];
	button->ymin = position[2];
	button->ymax = position[3];
	return (EXIT_SUCCESS);
}
