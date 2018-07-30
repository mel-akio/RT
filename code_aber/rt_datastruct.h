/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rt_datastruct.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/30 15:54:23 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/30 16:15:20 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef RT_DATASTRUCT
# define RT_DATASTRUCT

typedef unsigned char	t_uint8;

typedef struct			s_vec
{
	float				x;
	float				y;
	float				z;
}						t_vec;

typedef struct			s_col
{
	t_uint8				r;
	t_uint8				g;
	t_uint8				b;
	t_uint8				a;
}						t_col;

typedef struct			s_mtl
{
	char				*name;
	t_col				spec;
	t_col				diff;
	t_col				ambiant;
	float				shine;
	float				shinestr;
	float				trans;
	float				reflect;
	struct s_mtl		*next;
}						t_mtl;

typedef struct			s_tex
{
	t_col				*data;
	char				*name;
	int					w;
	int					h;
	struct s_tex		*next;
}						t_tex;

typedef struct			s_obj
{
	t_mtl				*mtl;
	t_tex				*tex;
	t_vec				pos;
	t_vec				vdata1;
	t_vec				vdata2;
	float				fdata1;
	float				fdata2;
	int					type;
}						t_obj;

typedef struct			s_light
{
	t_vec				pos;
	t_vec				dir;
	float				radius;
	int					type;
}						t_light;

#endif
