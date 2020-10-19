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
	std::shared_ptr<SDL_Texture> _bee;
	int _bee_x, _bee_y;
	double _bee_phase;

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
