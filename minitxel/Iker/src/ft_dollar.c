/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:31:28 by iportill          #+#    #+#             */
/*   Updated: 2023/10/18 11:34:08 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern t_data	*g_data;

void ft_env_dollar(char *str)
{
	g_data->env_dollar = str;
	
	 // Reemplaza con el nombre de la variable de entorno que deseas consultar
    g_data->string_env_dollar = getenv(g_data->env_dollar);
    if (g_data->string_env_dollar != NULL)
        printf(G" >>FT_ENV_DOLLAR<< El valor de string_env_dollar es: %s\n", g_data->string_env_dollar);
	else
		ft_error_iker(7);
	printf(R"FT_ENV_DOLLAR OK\n");
    return;
}

void ft_dollar(char *str)
{
	int i=0;
	int len=ft_strlen(str-1);
	g_data->contenido_dollar=malloc(sizeof(char)*len);
	if(!g_data->contenido_dollar)
		ft_error_iker(8); 
	int e=0;
	while(str[i+e])
	{
		if(str[i+e]=='$')
		{
			i++;
		}
		else
		{
			g_data->contenido_dollar[e]=str[i+e];
			e++;
		}
	}
	ft_env_dollar(g_data->contenido_dollar);
}