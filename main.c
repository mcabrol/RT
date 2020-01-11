#include "libui.h"

int 	main(void)
{
	SDL_Event	event;
	int			ret;
	t_window 	window;

	ret = 1;
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		ft_dprintf(2 ,"Échec de l'initialisation de la SDL %s\n", SDL_GetError());
		return (EXIT_FAILURE);
	}
	if (init_window(&window) && create_window("SDL", &window))
	{
		while (ret)
		while (SDL_PollEvent(&event))
		{
			SDL_RenderDrawPoint(window.render, 400, 300); //Renders on middle
			if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			ret = 0;
		}
		SDL_DestroyWindow(window.ptr);
	}
	else
		ft_dprintf(2, "Erreur de création de la fenêtre: %s\n", SDL_GetError());
	SDL_Quit();
	return (0);
}
