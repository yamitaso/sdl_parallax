/*
 * ExampleWindow.cc
 *
 *  Created on: 19 окт. 2020 г.
 *      Author: unyuu
 */
#include "ExampleWindow.h"

#include <stdexcept>
#include <SDL2/SDL_image.h>

ExampleWindow::ExampleWindow(int width, int height)
: Window(width, height),
  _sky_x(0), _sky_y(0), _sky_w(width), _sky_h(height/2),
  _sky_flip_x(width),
  _sun_x(width), _sun_y(height/48), _sun_w(width/8), _sun_h(width/8),
  _cloud1_x(width), _cloud1_y(height/6), _cloud1_w(width/6), _cloud1_h(height/6),
  _cloud2_x(width), _cloud2_y(height/12), _cloud2_w(width/6), _cloud2_h(height/6), _cloud21_x(width+width/4), _cloud21_y(height/8),
  _cloud22_x(width+width/2), _cloud22_y(height/5), _cloud23_x(width*2), _cloud23_y(height/8),
  _mountains_x(0), _mountains_y(0), _mountains_w(width), _mountains_h(height/2),
  _mountains_flip_x(width),
  _ground_x(0), _ground_y(height/2), _ground_w(width), _ground_h(height/2),
  _ground_flip_x(width),
  _tree1_x(width), _tree1_y(height/6+height/48), _tree1_w(width/8), _tree1_h(height/3),
  _tree2_x(width*3+width/2), _tree2_y(height/48), _tree2_w(width/6), _tree2_h(height/2),
  _tree3_x(width*4+width/3), _tree3_y(-height/2+height/36), _tree3_w(width/2), _tree3_h(height/1),
  _eater_x(-width/2), _eater_y(height-height/3), _eater_w(width/2), _eater_h(height/6), _eater_mod(3),
  _fog_w(width), _fog_h(height+height/8),
  _myeye_x(width/4), _myeye_y(height/2-height/4), _myeye_w(width/16), _myeye_h(height/10),
  _eye1_x(0-width/6), _eye1_y(height/3), _eye1_w(width/18), _eye1_h(height/12), _eye11_x(0-width/3), _eye11_y(height/4), _eye12_x(0-width/8), _eye12_y(height/6)

{
	_sky = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "sky.jpg"),
			SDL_DestroyTexture);
	if (_sky == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить небо: ") +
				std::string(SDL_GetError()));

	_sun = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "sun.png"),
				SDL_DestroyTexture);
		if (_sun == nullptr)
			throw std::runtime_error(
					std::string("Не удалось загрузить солнце: ") +
					std::string(SDL_GetError()));

	_cloud1 = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "cloud1.png"),
				SDL_DestroyTexture);
	_cloud2 = std::shared_ptr<SDL_Texture>(
					IMG_LoadTexture(_renderer.get(), "cloud2.png"),
					SDL_DestroyTexture);
		if (_cloud1 == nullptr || _cloud2 == nullptr)
			throw std::runtime_error(
					std::string("Не удалось загрузить облака: ") +
					std::string(SDL_GetError()));

	_mountains = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "mountains.png"),
				SDL_DestroyTexture);
		if (_mountains == nullptr)
			throw std::runtime_error(
					std::string("Не удалось загрузить горы: ") +
					std::string(SDL_GetError()));

	_ground = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "ground.png"),
				SDL_DestroyTexture);
		if (_ground == nullptr)
			throw std::runtime_error(
					std::string("Не удалось загрузить землю: ") +
					std::string(SDL_GetError()));

	_tree1 = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "tree1.png"),
				SDL_DestroyTexture);
		if (_cloud1 == nullptr)
			throw std::runtime_error(
					std::string("Не удалось загрузить деревья: ") +
					std::string(SDL_GetError()));

	_eater = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "eater.png"),
				SDL_DestroyTexture);
		if (_eater == nullptr)
			throw std::runtime_error(
					std::string("Не удалось загрузить чудище: ") +
					std::string(SDL_GetError()));

	_fog = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "fog.png"),
				SDL_DestroyTexture);
		if (_fog == nullptr)
				throw std::runtime_error(
					std::string("Не удалось загрузить туман: ") +
					std::string(SDL_GetError()));
	_myeye = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "myeye.png"),
				SDL_DestroyTexture);
	_eye1 = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "eye.png"),
				SDL_DestroyTexture);
		if (_myeye == nullptr || _eye1 == nullptr)
				throw std::runtime_error(
					std::string("Не удалось загрузить глаза: ") +
					std::string(SDL_GetError()));
}

void ExampleWindow::render()
{
	SDL_SetRenderDrawColor(_renderer.get(), 32, 32, 96, 255);
	SDL_RenderClear(_renderer.get());

	SDL_Rect sky_rect { _sky_x, _sky_y, _sky_w, _sky_h };
	SDL_RenderCopy(_renderer.get(), _sky.get(), nullptr, &sky_rect);
	SDL_Rect sky_rect_flip { _sky_flip_x, _sky_y, _sky_w, _sky_h };
	SDL_RenderCopyEx(_renderer.get(), _sky.get(), nullptr, &sky_rect_flip, 0, nullptr, SDL_FLIP_HORIZONTAL);

	SDL_Rect sun_rect { _sun_x, _sun_y, _sun_w, _sun_h };
	SDL_RenderCopy(_renderer.get(), _sun.get(), nullptr, &sun_rect);

	SDL_Rect mountains_rect { _mountains_x, _mountains_y, _mountains_w, _mountains_h };
	SDL_RenderCopy(_renderer.get(), _mountains.get(), nullptr, &mountains_rect);
	SDL_Rect mountains_rect_flip { _mountains_flip_x, _mountains_y, _mountains_w, _mountains_h };
	SDL_RenderCopyEx(_renderer.get(), _mountains.get(), nullptr, &mountains_rect_flip, 0, nullptr, SDL_FLIP_HORIZONTAL);
	SDL_Rect cloud23_rect { _cloud23_x, _cloud23_y, _cloud2_w, _cloud2_h };
	SDL_RenderCopy(_renderer.get(), _cloud2.get(), nullptr, &cloud23_rect);
	SDL_Rect cloud2_rect { _cloud2_x, _cloud2_y, _cloud2_w, _cloud2_h };
	SDL_RenderCopy(_renderer.get(), _cloud2.get(), nullptr, &cloud2_rect);
	SDL_Rect cloud21_rect { _cloud21_x, _cloud21_y, _cloud2_w, _cloud2_h };
	SDL_RenderCopy(_renderer.get(), _cloud2.get(), nullptr, &cloud21_rect);
	SDL_Rect cloud22_rect { _cloud22_x, _cloud22_y, _cloud2_w, _cloud2_h };
	SDL_RenderCopy(_renderer.get(), _cloud2.get(), nullptr, &cloud22_rect);


	SDL_Rect cloud1_rect { _cloud1_x, _cloud1_y, _cloud1_w, _cloud1_h };
	SDL_RenderCopy(_renderer.get(), _cloud1.get(), nullptr, &cloud1_rect);

	SDL_Rect eye1_rect { _eye1_x, _eye1_y, _eye1_w, _eye1_h };
	SDL_RenderCopy(_renderer.get(), _eye1.get(), nullptr, &eye1_rect);

	SDL_Rect tree1_rect { _tree1_x, _tree1_y, _tree1_w, _tree1_h };
	SDL_RenderCopy(_renderer.get(), _tree1.get(), nullptr, &tree1_rect);

	SDL_Rect ground_rect { _ground_x, _ground_y, _ground_w, _ground_h };
	SDL_RenderCopy(_renderer.get(), _ground.get(), nullptr, &ground_rect);
	SDL_Rect ground_rect_flip { _ground_flip_x, _ground_y, _ground_w, _ground_h };
	SDL_RenderCopyEx(_renderer.get(), _ground.get(), nullptr, &ground_rect_flip, 0, nullptr, SDL_FLIP_HORIZONTAL);

	SDL_Rect eye12_rect { _eye12_x, _eye12_y, _eye1_w, _eye1_h };
	SDL_RenderCopy(_renderer.get(), _eye1.get(), nullptr, &eye12_rect);

	SDL_Rect myeye_rect { _myeye_x, _myeye_y, _myeye_w, _myeye_h };
	SDL_RenderCopy(_renderer.get(), _myeye.get(), nullptr, &myeye_rect);

	SDL_Rect tree2_rect { _tree2_x, _tree2_y, _tree2_w, _tree2_h };
	SDL_RenderCopy(_renderer.get(), _tree1.get(), nullptr, &tree2_rect);

	SDL_Rect eye11_rect { _eye11_x, _eye11_y, _eye1_w, _eye1_h };
	SDL_RenderCopy(_renderer.get(), _eye1.get(), nullptr, &eye11_rect);

	SDL_Rect tree3_rect { _tree3_x, _tree3_y, _tree3_w, _tree3_h };
	SDL_RenderCopy(_renderer.get(), _tree1.get(), nullptr, &tree3_rect);

	SDL_Rect eater_rect { _eater_x, _eater_y, _eater_w, _eater_h };
	SDL_RenderCopy(_renderer.get(), _eater.get(), nullptr, &eater_rect);

	SDL_Rect fog_rect { _sky_x, _sky_y, _fog_w, _fog_h };
	SDL_RenderCopy(_renderer.get(), _fog.get(), nullptr, &fog_rect);
	SDL_Rect fog_rect_flip { _sky_flip_x, _sky_y, _fog_w, _fog_h };
	SDL_RenderCopyEx(_renderer.get(), _fog.get(), nullptr, &fog_rect_flip, 0, nullptr, SDL_FLIP_HORIZONTAL);


}

void ExampleWindow::do_logic()
{
	_sky_x -= 2;
	if (_sky_x <= -width())
		_sky_x = width();
	_sky_flip_x -= 2;
	if (_sky_flip_x <= -width())
		_sky_flip_x = width();

	_sun_x -= 1;
	if (_sun_x <= -width())
		_sun_x = width();

	_cloud1_x -= 4;
	if (_cloud1_x <= -width()-width()/4)
		_cloud1_x = width();

	_cloud2_x -= 5;
	if (_cloud2_x <= -width()/6)
		_cloud2_x = width();
	_cloud21_x -= 4;
	if (_cloud21_x <= -width()/5)
		_cloud21_x = width();
	_cloud22_x -= 3;
	if (_cloud22_x <= -width()/4)
		_cloud22_x = width();
	_cloud23_x -= 6;
	if (_cloud23_x <= -width()/5)
		_cloud23_x = width();

	_mountains_x -= 3;
	if (_mountains_x <= -width())
		_mountains_x = width();
	_mountains_flip_x -= 3;
	if (_mountains_flip_x <= -width())
		_mountains_flip_x = width();

	_ground_x -= 5;
	if (_ground_x <= -width())
		_ground_x = width();
	_ground_flip_x -= 5;
	if (_ground_flip_x <= -width())
		_ground_flip_x = width();

	_tree1_x -= 5;
	if (_tree1_x <= -width())
		_tree1_x = width();
	_tree2_x -= 5;
	if (_tree2_x <= -width())
		_tree2_x = width()+width()/4;
	_tree3_x -= 5;
	if (_tree3_x <= -width())
		_tree3_x = width()+width()/2;
	_eye1_x += 5; ;
	if (_eye1_x >= width())
		_eye1_x = -width()+width()/2;
	_eye11_x += 6;
	if (_eye11_x >= width())
		_eye11_x = -width()+width()/3;
	_eye12_x += 5;
	if (_eye12_x >= width())
		_eye12_x = -width()+width()/4;

	_eater_x += _eater_mod;
	_eater_y = height()-height()/3+sin(_eater_x*2)*5;
 	if (_eater_x >= 0)
		_eater_mod = -5;
	if (_eater_x <= -width()+width()/4)
		_eater_mod = 3;
}

void ExampleWindow::handle_keys(const Uint8 *keys)
{
	if (keys[SDL_SCANCODE_DOWN] &&_myeye_y < height()/2-_myeye_h)
		_myeye_y += 6;
	if (keys[SDL_SCANCODE_UP] && _myeye_y > 0)
		_myeye_y -= 6;
	if (keys[SDL_SCANCODE_RIGHT] && _myeye_x < width()-_myeye_w)
		_myeye_x += 6;
	if (keys[SDL_SCANCODE_LEFT] && _myeye_x > 0)
		_myeye_x -= 6;
}


