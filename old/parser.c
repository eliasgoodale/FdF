/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:50:55 by egoodale          #+#    #+#             */
/*   Updated: 2018/03/19 19:30:28 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
int		do_ops(int ret, t_fdf *fdf, int i)
{
	if (ret == -1)
		return (-1);
	if (fdf->line_len && fdf->line_len != i)
		ret = -1;
	else
	{
		fdf->line_len = i;
		fdf->lines++;
	}
	return (ret);
}

int		check_lines( t_fdf *fdf)
{
	char **line_map;
	int		i;
	int		ret;
	char *line;

	ret = 1;
	while(get_next_line(fdf->fd, &line) > 0)
	{
		line_map = ft_strsplit(line, ' ');
		i = -1;
		while (line_map[++i])
		{
			if (ft_str_is_numeric(line_map[i]))
				free(line_map[i]);
			else
			{
				free(line_map[i]);
				ret = -1;
				break;
			}
		}
		free(line_map);
		free(line);
		ret = do_ops(ret, fdf, i);
		if (ret == -1)
			break;
	}
	line_map = NULL;	
	return (ret);
}
		
int		init_fdf(t_fdf *fdf, int code)
{
	int i;

	i = -1;
	if(!code)
	{
		fdf->line_len = 0;
		fdf->lines = 0;
		fdf->map = 0;
		return (1);
	}
	else if (code)
	{
		if(!(fdf->map = (int **)malloc(sizeof(int *) * fdf->lines)))
			return (-1);
		while(++i < fdf->lines)
			fdf->map[i] = (int*)malloc(sizeof(int) * fdf->line_len);
		close(fdf->fd);
		fdf->fd = open(fdf->filename, O_RDONLY);
		return (1);
	}
	else
		return (-1);
}

void	get_integer_row(t_fdf *fdf, int i, char *line)
{
	int j;

	j = 0;
	while(*line)
	{
		while(*line && W_S(*line))
			line++;
		if(*line != ' ')
			fdf->map[i][j++] = ft_atoi(line);
		while(*line && !W_S(*line))
			line++;
	}
}
	
int parse_input(t_fdf *fdf)
{
	int n_b;
	char *line;
	char **line_map;
	int check;
	int i;
	
	i = 0;
	if(init_fdf(fdf, 0) == -1)
		exit (0);
	if(check_lines(fdf) == -1)
	{
		printf("error in check_line\n");
		exit(0);
	}
	printf("lines: %zu line_len: %lu\n", fdf->lines, fdf->line_len);
	if(init_fdf(fdf, 1) == -1)
		exit(0);
	while (get_next_line(fdf->fd, &line) > 0)
	{
		get_integer_row(fdf, i, line);
		i++;
	}	
	int j;
	int y;
	for(j = 0; j < fdf->lines; j++)
	{
		for(y = 0; y < fdf->line_len; y++)
		{
			printf("%d", fdf->map[j][y]);
		}
		printf("\n");
	}
   	return (0);	
}









































			
