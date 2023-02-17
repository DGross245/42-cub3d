#include <math.h>

static void	set_ray(t_cub3d *cube, t_ray	*ray, t_cords *player, int x)
{
	ray->raydir = θ; //theta is the direction
	player->pos_x = ; //player pos x
	player->pos_y = ; //player pos y
	ray->delta_x = -tan(θ); // offset within tile x
	ray->delta_y = 1/tan(θ); // offset within tile y
	ray->tilestep_x = 1; //+-1 depending theta (θ)
	ray->tilestep_y = ; //+-1 depending theta (θ)
	ray->step_x = tan(θ);
	ray->step_y = 1/tan(θ);
	ray->intercept_x = player->pos_x + ray->delta_x + -ray->delta_y/tan(θ);
	ray->intercept_y = player->pos_y + ray->delta_y + ray->delta_x/tan(θ);
	ray->deltadisy = -dy / tan(θ) , -dy;
	ray->deltadisx = dx, -dx tan(θ);
}

void	dda(t_cub3d *cube)
{
	while (cube->ray.wall_hit == 0)
	{
		if (cube->ray.intercept_y < cube->player.pos_y)
		{
			cube->ray.wall_side = 0;
			cube->ray.sidedis_x += cube->ray.deltadisx;
			cube->ray.map_x += cube->ray.stepx;
		}
		else
		{
			cube->ray.wall_side = 1;
			cube->ray.sidedis_y += cube->ray.deltadisy;
			cube->ray.map_y += cube->ray.stepy;
		}
		if (cube->data.map[cube->ray.map_x][cube->ray.map_y] == '1')
			cube->ray.wall_hit = 1;
	}
}