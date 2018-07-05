/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sdlwrap.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/11 15:02:59 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/05 12:00:37 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SDLWRAP_H
# define SDLWRAP_H

# include "SDL2/include/SDL.h"
# include "SDL2/include/SDL_image.h"

# include <stdlib.h>

typedef struct		s_fb
{
	SDL_Color		*data;
	SDL_Texture		*tex;
	SDL_Rect		r;
	SDL_Color		cc;
}					t_fb;

typedef struct		s_ev
{
	SDL_Event		e;
	Uint8			*keys;
	int				mx;
	int				my;
	int				exit;
	int				numkeys;
	int				mousemask;
}					t_ev;

typedef struct		s_prg
{
	t_ev			ev;
	SDL_Color		rc;
	SDL_Window		*win;
	SDL_Renderer	*rend;
	t_fb			*fb;
}					t_prg;

/*
**	loop.c
*/

void				input(t_ev *ev);
void				run(t_prg *p);

/*
**	init.c
*/

t_prg				*init(char *title, int x, int y);
void				cleanup(t_prg *p);

/*
**	set.c
*/

SDL_Color			set_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
SDL_Rect			set_rect(int x, int y, int w, int h);
SDL_Point			set_point(int x, int y);

/*
**	framebuffer.c
*/

t_fb				*fb_create(SDL_Rect r, SDL_Color c);
void				fb_clear(t_fb *fb);
SDL_Color			*fb_access(t_fb *fb, int x, int y);
SDL_Texture			*fb_render(t_fb *fb, SDL_Renderer *rend);

#endif
