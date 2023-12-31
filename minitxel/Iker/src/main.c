/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:31:57 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/18 16:27:00 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_data	*g_data;

void	ft_print_toito(void)
{
	int	i;

	i = 0;
	printf("PATH:\n");
	while (g_data->array_env[i])
		printf("%s\n", g_data->array_env[i++]);
	printf("\n");
	printf("INPUT:%s\n", g_data->input);
	printf("\n");
	printf("INPUT array:\n");
	i = 0;
	while (g_data->array_input[i])
		printf("%s\n", g_data->array_input[i++]);
}


void	ft_set_imput(void)
{
	int		i;
	int		j;
	char	*temp;

	temp = malloc(sizeof(char) * \
	(ft_strlen(g_data->input) + g_data->add_space + 1));
	i = 0;
	j = 0;
	temp[j++] = g_data->input[i++];
	while (g_data->input[i])
	{
		if (g_data->input[i - 1] == '|' && g_data->input[i] != ' ' && \
		g_data->input[i] != '\0')
			temp[j++] = ' ';
		if (g_data->input[i - 1] == '<' && g_data->input[i] != '<' && \
		g_data->input[i] != ' ' && g_data->input[i] != '\0')
			temp[j++] = ' ';
		if (g_data->input[i - 1] == '>' && g_data->input[i] != '>' && \
		g_data->input[i] != ' ' && g_data->input[i] != '\0')
			temp[j++] = ' ';
		if (g_data->input[i - 1] != '<' && g_data->input[i - 1] != '>' && g_data->input[i - 1] != '|' && \
		g_data->input[i - 1] != ' ' && (g_data->input[i] == '<' || g_data->input[i] == '>'  || g_data->input[i] == '|'))
			temp[j++] = ' ';
		temp[j++] = g_data->input[i++];
	}
	temp[j++] = '\0';
	free (g_data->input);
	g_data->input = temp;
	printf("input_ok:\n%s\n", g_data->input);
}

void	input_check(void)
{
	int	i;

	i = 0;
	g_data->add_space = 0;
	while (g_data->input[i])
	{
		if (g_data->input[i] != '<' && g_data->input[i] != '>' && \
		g_data->input[i] != '|'  && g_data->input[i] != ' ' && \
		(g_data->input[i + 1] == '<' || g_data->input[i + 1] == '>' || \
		g_data->input[i + 1] == '|'))
			g_data->add_space++;
		if (g_data->input[i] == '<' && g_data->input[i + 1] != '<' && \
		g_data->input[i + 1] != ' ' && g_data->input[i + 1] != '\0')
			g_data->add_space++;
		if (g_data->input[i] == '>' && g_data->input[i + 1] != '>' \
		&& g_data->input[i + 1] != ' ' && g_data->input[i + 1] != '\0')
			g_data->add_space++;
		if (g_data->input[i] == '|' && (g_data->input[i + 1] != ' ') && \
		g_data->input[i + 1] != '\0')
			g_data->add_space++;
		i++;
	}
	//printf("add_space = %i\n", g_data->add_space);
}

void ft_save_env(char **env)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (env[i])
		i++;
	g_data->array_env = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i])
	{
		g_data->array_env[i] = ft_strdup(env[i]);
		printf("g_data->array_env[%i] = %s\n", i, g_data->array_env[i]);
		i++;
	}
	g_data->array_env[i] = NULL;
}

int		main(int argc, char **argv,char **env)
{
	//printf("argc = %d\n", argc);
	//printf("argv[0] = %s\n", argv[0]);
	(void)argc;
	(void)argv;
	g_data = (t_data *) malloc (sizeof(t_data));
	ft_get_path();
	ft_repair_path();
	
	while (1)
	{
		g_data->input = readline(G"Minitxel > "W);
		if (g_data->input == NULL)
		{
			printf("\nFinishing Minitxel...\n");
			break ;
		}
		add_history(g_data->input);
		//ft_dollar(g_data->input);
		if(ft_error() == 0)
		{
			input_check();
			if(g_data->add_space)
				ft_set_imput();
			//g_data->array_input = ft_split(g_data->input, ' ');
			g_data->array_input = ft_split_quote(g_data->input, ' ');
			ft_recorre_el_array();
			comillas_repair(g_data->array_input,'\'');
			comillas_repair(g_data->array_input,'"');
			//ft_print_toito();
	
			(void)env;
			//try_path_access(g_data->array_env, "ls");//'ls' sera el comando a ejecutar
			//pipe_with_sons(env);
		}
		//free(input);
	}
	return (0);
}
