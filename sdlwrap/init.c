/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/16 02:15:45 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/05 12:02:13 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "sdlwrap.h"

static void		init_ev(t_ev *ev)
{
	ev->exit = 0;
	ev->keys = (Uint8 *)SDL_GetKeyboardState(&ev->numkeys);
	ev->mousemask = SDL_GetMouseState(&ev->mx, &ev->my);
}

t_prg			*init(char *title, int x, int y)
{
	t_prg		*p;

	SDL_Init(SDL_INIT_VIDEO);
	p = malloc(sizeof(t_prg));
	p->win = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, x, y, 0);
	p->rend = SDL_CreateRenderer(p->win, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(p->rend, 0, 0, 0, 255);
	SDL_SetRenderDrawBlendMode(p->rend, SDL_BLENDMODE_BLEND);
	init_ev(&p->ev);
	p->fb = fb_create(set_rect(500, 400, 200, 200), set_color(0, 255, 0, 255));
	return (p);
}

void			cleanup(t_prg *p)
{
	SDL_DestroyRenderer(p->rend);
	SDL_DestroyWindow(p->win);
	SDL_Quit();
}
