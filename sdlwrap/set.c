/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   set.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/16 02:13:23 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/23 19:40:22 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "sdlwrap.h"

SDL_Color		set_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_Color	c;

	c.r = r;
	c.g = g;
	c.b = b;
	c.a = a;
	return (c);
}

SDL_Rect		set_rect(int x, int y, int w, int h)
{
	SDL_Rect	r;

	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;
	return (r);
}

SDL_Point		set_point(int x, int y)
{
	SDL_Point	p;

	p.x = x;
	p.y = y;
	return (p);
}
