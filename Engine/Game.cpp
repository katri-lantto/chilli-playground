/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	speed = 2;
	r = 255;
	g = 255;
	b = 255;

	if (wnd.kbd.KeyIsPressed(VK_SHIFT)) {
		speed = 4;
	}

	if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
		r = 255;
		g = 0;
		b = 0;
	}
	
	if (!x || x <= 0) {
		x = gfx.ScreenWidth / 2;
	}
	else {
		if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
			x -= speed;
		}
		if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
			x += speed;
		}
	}
	if (!y || y <= 0) {
		y = gfx.ScreenHeight / 2;
	}
	else {
		if (wnd.kbd.KeyIsPressed(VK_UP)) {
			y -= speed;
		}
		if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
			y += speed;
		}
	}
}

void Game::ComposeFrame() {

	if (speed == 2) {
		gfx.PutPixel(x - 5, y, r, g, b);
		gfx.PutPixel(x - 4, y, r, g, b);
		gfx.PutPixel(x - 3, y, r, g, b);
		gfx.PutPixel(x + 3, y, r, g, b);
		gfx.PutPixel(x + 4, y, r, g, b);
		gfx.PutPixel(x + 5, y, r, g, b);
		gfx.PutPixel(x, y - 5, r, g, b);
		gfx.PutPixel(x, y - 4, r, g, b);
		gfx.PutPixel(x, y - 3, r, g, b);
		gfx.PutPixel(x, y + 3, r, g, b);
		gfx.PutPixel(x, y + 4, r, g, b);
		gfx.PutPixel(x, y + 5, r, g, b);
	}
	else if (speed == 4) {
		gfx.PutPixel(x - 7, y, r, g, b);
		gfx.PutPixel(x - 6, y, r, g, b);
		gfx.PutPixel(x - 5, y, r, g, b);
		gfx.PutPixel(x + 5, y, r, g, b);
		gfx.PutPixel(x + 6, y, r, g, b);
		gfx.PutPixel(x + 7, y, r, g, b);
		gfx.PutPixel(x, y - 7, r, g, b);
		gfx.PutPixel(x, y - 6, r, g, b);
		gfx.PutPixel(x, y - 5, r, g, b);
		gfx.PutPixel(x, y + 5, r, g, b);
		gfx.PutPixel(x, y + 6, r, g, b);
		gfx.PutPixel(x, y + 7, r, g, b);
	}
}
