

#define ABS_V(x) (x < 0 ? -x : x)

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}


void	swap_params(t_fdf *fdf)
{
	if(fdf->dy > fdf->dx)
    {   
        ft_swap(fdf->p1[0],fdf->p1[1]);
        ft_swap(fdf->p2[0],fdf->p2[1]);
        ft_swap(&fdf->dx, &fdf->dy);
        fdf->slopegt1=1;
    }   
    if(fdf->p1[0] > fdf->p2[0])
    {   
        ft_swap(fdf->p1[0], fdf->p2[0]);
        ft_swap(fdf->p1[1], fdf->p2[1]);
    }   
    if(fdf->p1[1] > fdf->p2[1])
        incry = -1;
    else
        incry = 1;
    fdf->d = 2 * fdf->dy - fdf->dx;
    fdf->incre = 2 * dy;
    fdf->incrne = 2 * (dy-dx);
}




void draw_line(t_fdf *fdf)
{
	fdf->dx = ABS_V(fdf->p2[0] - fdf->p1[0]);
	fdf->dy = ABS_V(fdf->p2[1] - fdf->p2[1]);
	ft_swap_params(fdf);
	while (fdf->p1[0] < fdf->p2[0])
	{
		if(fdf->d <= 0)
			fdf->d += fdf->incre;
		else
		{
			fdf->d += fdf->incrne;
			fdf->p1[1] += incry;
		}
		fdf->p1[0]++;
		if (fdf->slopegt1)
			mlx_pixel_put(fdf->mlx, fdf->win, fdf->p1[1], fdf->p1[0], 0xFFFFFF);
		else
			mlx_pixel_put(fdf->mlx, fdf->win, fdf->p1[0], fdf->p1[1], 0xFFFFFF);
	}
}

int		fdf_init(t_fdf *fdf)
{
	int i;
	i = 0;
	if (draw->check == 0)
	{
		fdf->map = (int **)malloc(sizeof(int *) * (2));
		while(i < 2)
			fdf->map[i++] = (int*)malloc(sizeof(int) * 2);
		fdf->line_len = 2;
		fdf->lines = 2;
		fdf->mlx = mlx_init();
		fdf->win = mlx_new_window(fdf->mlx, 500, 500, "drawing");
		fdf->p1[0] = 250;
		fdf->p1[1] = 250;
		fdf->p2[0] = 500;
		fdf->p2[1] = 500;
		fdf->sx = (WIDTH * 0.7) / (fdf->line_len - 1);
		fdf->sy = (HEIGHT * 0.5) / (fdf->lines - 1);
	}
		draw->check++;
	return (1);
}

int main(int ac, char **av)
{
	if(ac == 2)
	{	
		t_fdf *fdf;

		fdf.filename = av[1];
		fdf.fd = open(fdf.filename, O_RDONLY);
  			   












































