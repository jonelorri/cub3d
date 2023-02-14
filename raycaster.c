#include "raycaster.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	init_variables(t_m *m)
{
	m->posX = 12;
	m->posY = 12;
	m->dirX = 0;
	m->dirY = -1;
	m->planeX = 0;
	m->planeY = 0.66;
	m->time = 0;
	m->oldTime = 0;
}

int main()
{
	t_data	img;
	t_m		m;
	void	*mlx;
	void	*mlx_win;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		mapX;
	int		mapY;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		x;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, screenWidth, screenHeight, "Raycaster");
	img.img = mlx_new_image(mlx, screenWidth, screenHeight);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	init_variables(&m);
	x = 0;
	m.width = mapWidth;
	m.height = mapHeight;
	while (1)
	{
		while (x < m.width)
		{
			cameraX = 2 * x / (double)m.width - 1;
			rayDirX = m.dirX + m.planeX * cameraX;
			rayDirY = m.dirY + m.planeY * cameraX;
			//which box of the map we're in
			mapX = m.posX;
			mapY = m.posY;

			//length of ray from one x or y-side to next x or y-side
			deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
			deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));

			hit = 0;
			if(rayDirX < 0)
			{
			stepX = -1;
			sideDistX = (m.posX - mapX) * deltaDistX;
			}
			else
			{
			stepX = 1;
			sideDistX = (mapX + 1.0 - m.posX) * deltaDistX;
			}
			if(rayDirY < 0)
			{
			stepY = -1;
			sideDistY = (m.posX - mapY) * deltaDistY;
			}
			else
			{
			stepY = 1;
			sideDistY = (mapY + 1.0 - m.posX) * deltaDistY;
			}
			//perform DDA
			while(hit == 0)
			{
				//jump to next map square, either in x-direction, or in y-direction
				if(sideDistX < sideDistY)
				{
					sideDistX += deltaDistX;
					mapX += stepX;
					side = 0;
				}
				else
				{
					sideDistY += deltaDistY;
					mapY += stepY;
					side = 1;
				}
				//Check if ray has hit a wall
				if(worldMap[mapX][mapY] > 0)
					hit = 1;
			}
			if(side == 0)
				perpWallDist = (sideDistX - deltaDistX);
			else
				perpWallDist = (sideDistY - deltaDistY);
			//Calculate height of line to draw on screen
			lineHeight  = (int)(m.height / perpWallDist);
			//calculate lowest and highest pixel to fill in current stripe
			drawStart = -lineHeight / 2 + m.height / 2;
			if(drawStart < 0)
				drawStart = 0;
			drawEnd = lineHeight / 2 + m.height / 2;
			if(drawEnd >= m.height)
				drawEnd = m.height - 1;
			//choose wall color
			int color = 0x00FF0444;
			// if(side == 1)
			// 	color = color / 2;
			verLine(x, drawStart, drawEnd, color);
			x ++;
		}
		//timing for input and FPS counter
		m.oldTime = m.time;
		m.time = getTicks();
		double frameTime = (m.time - m.oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
		print(1.0 / frameTime); //FPS counter
		redraw();
		cls();
		double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
		double rotSpeed = frameTime * 3.0; //the constant value is in radians/second
		readKeys();
		//move forward if no wall in front of you
		if(keyDown(SDLK_UP))
		{
			if(worldMap[int(m.posX + m.dirX * moveSpeed)][int(m.posY)] == 0)
				m.posX += m.dirX * moveSpeed;
			if(worldMap[int(m.posX)][int(m.posY + m.dirY * moveSpeed)] == 0)
				m.posY += m.dirY * moveSpeed;
		}
		//move backwards if no wall behind you
		if(keyDown(SDLK_DOWN))
		{
			if(worldMap[int(m.posX - m.dirX * moveSpeed)][int(m.posY)] == 0)
				m.posX -= m.dirX * moveSpeed;
			if(worldMap[int(m.posX)][int(m.posY - m.dirY * moveSpeed)] == 0)
				m.posY -= m.dirY * moveSpeed;
		}
		//rotate to the right
		if(keyDown(SDLK_RIGHT))
		{
			//both camera direction and camera plane must be rotated
			double oldDirX = m.dirX;
			m.dirX = m.dirX * cos(-rotSpeed) - m.dirY * sin(-rotSpeed);
			m.dirY = oldDirX * sin(-rotSpeed) + m.dirY * cos(-rotSpeed);
			double oldPlaneX = m.planeX;
			m.planeX = m.planeX * cos(-rotSpeed) - m.planeY * sin(-rotSpeed);
			m.planeY = oldPlaneX * sin(-rotSpeed) + m.planeY * cos(-rotSpeed);
		}
		//rotate to the left
		if(keyDown(SDLK_LEFT))
		{
			//both camera direction and camera plane must be rotated
			double oldDirX = m.dirX;
			m.dirX = m.dirX * cos(rotSpeed) - m.dirY * sin(rotSpeed);
			m.dirY = oldDirX * sin(rotSpeed) + m.dirY * cos(rotSpeed);
			double oldPlaneX = m.planeX;
			m.planeX = m.planeX * cos(rotSpeed) - m.planeY * sin(rotSpeed);
			m.planeY = oldPlaneX * sin(rotSpeed) + m.planeY * cos(rotSpeed);
		}
	}
	//my_mlx_pixel_put(&img, 150, 300, 0x00FF0444);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}