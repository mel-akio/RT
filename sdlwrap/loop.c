/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   loop.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/16 02:01:13 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/05 12:27:27 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "sdlwrap.h"

void			input(t_ev *ev)
{
	while (SDL_PollEvent(&ev->e))
	{
		if (ev->e.type == SDL_QUIT)
			ev->exit = 1;
		else if (ev->e.type == SDL_KEYDOWN || ev->e.type == SDL_KEYUP)
		{
			if (ev->e.key.keysym.sym == SDLK_ESCAPE)
				ev->exit = 1;
		}
	}
}

void			run(t_prg *p)
{
	SDL_Rect	r;

	fb_render(p->fb, p->rend);
	while (!p->ev.exit)
	{
		input(&p->ev);
		SDL_SetRenderDrawColor(p->rend, 0, 0, 0, 255);
		SDL_RenderClear(p->rend);
		SDL_SetRenderDrawColor(p->rend, 0, 255, 0, 255);
		r = set_rect(200, 200, 150, 150);
		SDL_RenderFillRect(p->rend, &r);
		SDL_SetRenderDrawColor(p->rend, 255, 0, 0, 127);
		r = set_rect(250, 250, 200, 200);
		SDL_RenderFillRect(p->rend, &r);
		SDL_RenderCopy(p->rend, p->fb->tex, NULL, &p->fb->r);
		SDL_RenderPresent(p->rend);
		SDL_Delay(1000 / 60);
	}
}
