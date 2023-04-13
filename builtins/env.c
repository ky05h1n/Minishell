/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:51:57 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/19 03:23:52 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	built_env(t_env *envirement, int fd)
{
	t_env	*env;

	env = envirement;
	while (env)
	{
		if (env->path && env->path[0] != '\0')
			print_fd(4, fd, env->name, "=", env->path, "\n");
		env = env->next;
	}
}
