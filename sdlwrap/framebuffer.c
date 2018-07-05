/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   framebuffer.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/04 13:40:09 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/05 12:13:09 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "sdlwrap.h"

t_fb			*fb_create(SDL_Rect r, SDL_Color c)
{
	t_fb		*fb;

	fb = malloc(sizeof(t_fb));
	if (fb == NULL)
		return (NULL);
	fb->r = r;
	fb->tex = NULL;
	fb->data = malloc(sizeof(SDL_Color) * r.w * r.h);
	if (fb->data == NULL)
	{
		free(fb);
		return (NULL);
	}
	fb->cc = c;
	fb_clear(fb);
	return (fb);
}

void			fb_clear(t_fb *fb)
{
	int			i;
	int			l;

	i = 0;
	l = fb->r.w * fb->r.h;
	while (i < l)
		fb->data[i++] = fb->cc;
}

SDL_Color		*fb_access(t_fb *fb, int x, int y)
{
	int			pos;

	if (!fb || x < 0 || y < 0 || x >= fb->r.w || y >= fb->r.h)
		return (NULL);
	pos = x + fb->r.w * y;
	return (&fb->data[pos]);
}

SDL_Texture		*fb_render(t_fb *fb, SDL_Renderer *rend)
{
	SDL_Surface	*sur;

	if (!fb)
		return (NULL);
	if (fb->tex)
		SDL_DestroyTexture(fb->tex);
	fb->tex = NULL;
	sur = SDL_CreateRGBSurfaceFrom((void *)fb->data, fb->r.w, fb->r.h, 32,
			4 * fb->r.w, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);
	if (sur == NULL)
		return (NULL);
	fb->tex = SDL_CreateTextureFromSurface(rend, sur);
	SDL_FreeSurface(sur);
	if (fb->tex == NULL)
		return (NULL);
	return (fb->tex);
}
