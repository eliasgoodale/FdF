#include "fdf.h"

void	get_center(t_fdf *fdf)
{
	int		y_len;
	int		x_len;
	y_len = fdf->map->len;
	x_len = fdf->map->lines[y_len - 1]->len;
	fdf->center.x = (fdf->map->lines[y_len - 1]->points[x_len - 1]->x + fdf->map->lines[0]->points[0]->x) / 2;
	fdf->center.y  = (fdf->map->lines[y_len - 1]->points[x_len - 1]->y + fdf->map->lines[0]->points[0]->y) / 2;
}

static	void ft_cal_matrice(t_point *p, t_matrice *m, t_fdf *fdf)
{
	double tmp_x;
	double tmp_y;
	double tmp_z;

	p->x -= e->center.x;
	p->y -= e->center.y;
	tmp_x = p->x * m->a1 + p->y * m->a2


void	cal_translate(t_fdf *fdf, double x, double y, double z)
{
	t_matrice *m_tran;

	m_tran = ft_matrice_translation(x, y, z);
	ft_cal_matrice_all_points(m_tran, e);
	get_center(fdf);
	free(m_tran);
}

void	adapt_map(t_fdf *fdf)
{
	int	w;
	int h;
	double s;

	w = (W_WIDTH + 100) / 2;
	h = (W_HEIGHT + 100) / 2;
	fdf->center.x == 0 ? fdf->center.x = 10 : fdf->center.x;
	s = (w - 600) / e->center.x;
	cal_translate(fdf, -fdf->center.x + w, -fdf->center.y + h, 0);

