/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 09:56:50 by gguillen          #+#    #+#             */
/*   Updated: 2026/06/10 17:23:53 by hcostoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	lambert_modele(t_hit hit, t_light light)
{
	t_light_info	li;
	t_vec3			l;
	int				r;
	int				g;
	int				b;

	l = vec3_sub(light.pos, hit.point);
	l = vec3_normalize(l);
	li.diffuse = vec3_dot(hit.normal, l);
	if (li.diffuse < 0.0)
		li.diffuse = 0.0;
	li.intensity = light.intensity * li.diffuse;
	li.ambient = 0.1;
	r = ((hit.color >> 16) & 0xFF) * (li.intensity + li.ambient);
	g = ((hit.color >> 8) & 0xFF) * (li.intensity + li.ambient);
	b = (hit.color & 0xFF) * (li.intensity + li.ambient);
	r = clamp(r, 0, 255);
	g = clamp(g, 0, 255);
	b = clamp(b, 0, 255);
	return (create_trgb(0, r, g, b));
}
