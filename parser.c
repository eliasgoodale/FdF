#include "fdf.h"

int     init_fdf(t_fdf *fdf, int code)
{
	char *line;

    if(!code)
    {
	
		fdf->mlx = mlx_init();
		fdf->win = mlx_new_window(fdf->mlx, W_WIDTH, W_HEIGHT, fdf->filename);
        fdf->line_len = 0;
        fdf->lines = 0;
		while(get_next_line(fdf->fd, &line) > 0)
		{
			fdf->lines++;
			free(line);
		}
        if(!(fdf->map = (t_map *)malloc(sizeof(t_map))))
			return (-1);
		if(!(fdf->map->lines = (t_line**)malloc(sizeof(t_line) * fdf->lines)))
			return (-1);
		close(fdf->fd);
		fdf->fd = open(fdf->filename, O_RDONLY);	
		fdf->map->len = 0;
        return (1);
    } 
	return (1);	
}

int		point_get(char *line, int nb_line, t_point ***array_points)
{
	char **array_str;
	t_point *a_point;
	int i;

	i = 0;
	array_str = ft_strsplit(line, ' ');
	while(array_str[i])
		i++;
	if (!((*array_points) = (t_point **)malloc(sizeof(t_point) * i)))
		exit(0);
	i = 0;
	while(array_str[i])
	{
		a_point = (t_point *)malloc(sizeof(t_point));
		a_point->x = i * 20;
		a_point->y = nb_line * 30;
		a_point->z = ft_atoi(array_str[i]);
		a_point->s = 1;
		a_point->z_color = a_point->z;
		(*array_points)[i++] = a_point;
	}
	return (i);
}
	
void	parse_input(t_fdf *fdf)
{
	char 	*line;
	int		n_b;
	t_line	*line_map;
	t_point	**array_points;
	
	if(init_fdf(fdf, 0) < 0)
		exit(0);
	n_b = 0;
	while ((get_next_line(fdf->fd, &line)) > 0)
	{
		if (!(line_map = (t_line*)malloc(sizeof(t_line))))
			exit(0);
		line_map->len = point_get(line, n_b, &array_points);
		line_map->points = array_points;
		fdf->map->lines[n_b++] = line_map;
	}
	fdf->map->len = n_b;
for(int y = 0; y < fdf->map->len; y++)
{
	printf("line: %d has len %d with points:\n\n", y, fdf->map->lines[y]->len);
	for(int j = 0; j < fdf->map->lines[y]->len; j++)
	{	
		printf("point %d: x: %f y: %f z: %f\n", j, fdf->map->lines[y]->points[j]->x, fdf->map->lines[y]->points[j]->y, fdf->map->lines[y]->points[j]->z);
		if(j < 10)
			printf("\t\tand\n");
		else
			printf("\n");
	}
	draw_lines(fdf);
}
}

