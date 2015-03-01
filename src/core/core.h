/*
 * E2DIT - is a 2D Map Editor to create a levels for 2d games
 * Copyright (C) 2015 Kabylin Andrey <andrey@kabylin.ru>

 * This file is part of E2DIT.

 * E2DIT is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * E2DIT is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with E2DIT.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Kabylin Andrey <andrey@kabylin.ru>
 */

#ifndef E2DIT_CORE_H
#define E2DIT_CORE_H

#include "utility/application.h"

#include "ui/manager.h"
#include "ui/button.h"
#include "ui/theme.h"

#include "renderer/sprite.h"
#include "renderer/shader.h"
#include "renderer/texture.h"

class Application;
class Core {
public:

	Application *app = Application::getInstance();

	/* UI */

	std::shared_ptr<UIManager> uiManager;
	std::shared_ptr<UITheme>   uiTheme;
	std::shared_ptr<Texture>   skin;

	std::shared_ptr<Shader>    atlasShader;
	std::shared_ptr<Shader>    colorShader;

	std::shared_ptr<UIButton>  button;

	/* Constructor */

	 Core();
	~Core();

	/* Events */

	void onKeyPressed  (int key);
	void onKeyReleased (int key);
	void onTextEntered (unsigned int key);
	void onMouseMove   (int x, int y);
	void onMouseDown   (int x, int y, int button);
	void onMouseUp     (int x, int y, int button);
	void onDblClick    (int x, int y, int button);
	void onMouseWheel  (int x, int y, int button);
	void onResize      (int width, int height);

	/* */

	void render();
	void step();

};

#endif
