/*
 * ExampleWindow.h
 *
 *  Created on: 19 окт. 2020 г.
 *      Author: unyuu
 */

#ifndef EXAMPLEWINDOW_H_
#define EXAMPLEWINDOW_H_

#include "Window.h"

class ExampleWindow: public Window
{
protected:
	std::shared_ptr<SDL_Texture> _sky, _sun, _cloud1, _cloud2, _mountains, _ground, _tree1, _eater, _fog, _myeye, _eye1;
	int _sky_x, _sky_y, _sky_w, _sky_h, _sky_flip_x,
		_sun_x, _sun_y, _sun_w, _sun_h,
		_cloud1_x, _cloud1_y, _cloud1_w, _cloud1_h,
		_cloud2_x, _cloud2_y, _cloud2_w, _cloud2_h, _cloud21_x, _cloud21_y, _cloud22_x, _cloud22_y, _cloud23_x, _cloud23_y,
		_mountains_x, _mountains_y, _mountains_w, _mountains_h, _mountains_flip_x,
		_ground_x, _ground_y, _ground_w, _ground_h, _ground_flip_x,
		_tree1_x, _tree1_y, _tree1_w, _tree1_h,
		_tree2_x, _tree2_y, _tree2_w, _tree2_h,
		_tree3_x, _tree3_y, _tree3_w, _tree3_h,
		_eater_x, _eater_y, _eater_w, _eater_h, _eater_mod,
		_fog_w, _fog_h,
		_myeye_x, _myeye_y, _myeye_w, _myeye_h,
		_eye1_x, _eye1_y, _eye1_w, _eye1_h, _eye11_x, _eye11_y, _eye12_x, _eye12_y
		;

public:
	ExampleWindow(
			int width = DEFAULT_WIDTH,
			int height = DEFAULT_HEIGHT);
	virtual ~ExampleWindow() = default;

	virtual void render() override;
	virtual void do_logic() override;
	virtual void handle_keys(const Uint8 *keys) override;
};


#endif /* EXAMPLEWINDOW_H_ */
