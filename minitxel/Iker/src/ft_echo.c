/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:30:08 by iportill          #+#    #+#             */
/*   Updated: 2023/10/18 11:32:02 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern t_data	*g_data;

void ft_recorre_el_array()
{
	int i=0;
	while(g_data->array_input[i])
	{
		if(ft_strcmp(g_data->array_input[i],"echo")==0 || ft_strcmp(g_data->array_input[i],"\"echo\"")==0 || ft_strcmp(g_data->array_input[i],"\'echo\'")==0)			
		{
			printf("echo encontrado\n");
		ft_echo(i+1);
		break;
		}
		//printf("%s\n",g_data->array_input[i]);
		i++;
	}
	return ;
}
void ft_putstr_custom(char *str)
{
	int i=0;
	while(str[i])
	{
		write(1,&str[i],1);
		i++;
	}
}
void ft_putstr_custom_simple(char *str)
{
	int i=0;
	while(str[i])
	{
		if(str[i]=='\''&& str[i+1]!= '\0')
			i++;
		if(str[i]!='\'')
			write(1,&str[i],1);
		i++;
	}
}
void ft_putstr_custom_doble(char *str)
{
	int i=0;
	while(str[i])
	{
		if(str[i]=='"'&& str[i+1]!= '\0')
			i++;
		if(str[i]!='"'&& str[i]=='$')
			write(1,&str[i],1);
		if(str[i]=='$')
		{
			
		}
		i++;
	}
}


void ft_echo(int i)
{
	while (g_data->array_input[i])
	{
		if(g_data->array_input[i][0]=='"' || g_data->array_input[i][0]=='\'')
		{
			if(g_data->array_input[i][0]=='\'')
				ft_putstr_custom_simple(g_data->array_input[i]);
			else if(g_data->array_input[i][0]=='"')
				ft_putstr_custom_doble(g_data->array_input[i]);
			else
				ft_putstr_custom(g_data->array_input[i]);
		}		
	//printf("%s ",g_data->array_input[i]);
	i++;
	}
	
}