/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:28:42 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 16:08:37 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				init_button(t_rtv1 *rtv1, int error)
{
	error += load_button(rtv1, &rtv1->sprite.setup, "setup");
	error += load_button(rtv1, &rtv1->sprite.close, "close");
	error += load_button(rtv1, &rtv1->sprite.retry, "retry");
	error += load_button(rtv1, &rtv1->sprite.save, "save");
	error += load_button(rtv1, &rtv1->sprite.display, "display");
	error += load_button(rtv1, &rtv1->sprite.render, "render");
	error += load_button(rtv1, &rtv1->sprite.error, "error");
	error += load_button(rtv1, &rtv1->sprite.sample, "sample");
	error += load_button(rtv1, &rtv1->sprite.format, "format");
	error += load_button(rtv1, &rtv1->sprite.close_setting, "close-setting");
	error += load_button(rtv1, &rtv1->sprite.x8, "x8");
	error += load_button(rtv1, &rtv1->sprite.x20, "x20");
	error += load_button(rtv1, &rtv1->sprite.x200, "x200");
	error += load_button(rtv1, &rtv1->sprite.x500, "x500");
	error += load_button(rtv1, &rtv1->sprite.x1000, "x1000");
	error += load_button(rtv1, &rtv1->sprite.x5000, "x5000");
	error += load_button(rtv1, &rtv1->sprite.f320, "320x240");
	error += load_button(rtv1, &rtv1->sprite.f854, "854x480");
	error += load_button(rtv1, &rtv1->sprite.f1024, "1024x768");
	error += load_button(rtv1, &rtv1->sprite.f1280, "1280x720");
	error += load_button(rtv1, &rtv1->sprite.f1400, "1400x1050");
	error += load_button(rtv1, &rtv1->sprite.f1920, "1920x1080");
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

int				load_button(t_rtv1 *rtv1, t_button *button, char *name)
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
	return (EXIT_SUCCESS);
}
