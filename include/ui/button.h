/*
 * E2DIT - is a 2D Map Editor to create a levels for 2d games
 * Copyright (C) 2015 Kabylin Andrey <andrey@kabylin.ru>

 * This file is part of E2DIT-UI.

 * E2DIT-UI is free library: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.

 * E2DIT-UI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.   See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License
 * along with E2DIT-UI. If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Kabylin Andrey <andrey@kabylin.ru>
 */

#ifndef E2DIT_UI_BUTTON_H
#define E2DIT_UI_BUTTON_H

#include <string>
#include <vector>
#include <glm/glm.hpp>

#include "utility/config.h"
#include "utility/renderer.h"

#include "ui/element.h"
#include "ui/manager.h"

#include "renderer/shader.h"
#include "renderer/data_render.h"
#include "renderer/base_object.h"

class UIButton : public UIElement {
protected:

	/* Precomputed tables */

	int   iWidths [12];    int   iHeights[12];
	float fWidths [12];    float fHeights[12];
	float offsetsX[12];    float offsetsY[12];

	float textColors [12];
	float textOffsets[16];

	/* Param Names for load from Layout file */

	std::string leaveElement = "buttonleav";
	std::string enterElement = "buttonenter";
	std::string clickElement = "buttonclick";

	/* Render Objects */

	std::unique_ptr<BaseObject> leftElement   = std::make_unique<BaseObject> (manager->uiDataRender, app->screenCamera);
	std::unique_ptr<BaseObject> rightElement  = std::make_unique<BaseObject> (manager->uiDataRender, app->screenCamera);
	std::unique_ptr<BaseObject> middleElement = std::make_unique<BaseObject> (manager->uiDataRender, app->screenCamera);
	std::unique_ptr<BaseObject> iconElement   = std::make_unique<BaseObject> (manager->uiDataRender, app->screenCamera);
	std::unique_ptr<BaseObject> iconElement2  = std::make_unique<BaseObject> (manager->uiDataRender, app->screenCamera);

	/* Draw Text */

	void renderText (Align align, std::string text, int size, int offset = 0);
	void renderSkin();

	/* Precompute */

	void precomputeElement (const int n, std::string element, std::string params);
	void precomputeText    (const int n, std::string element);

public:

	std::wstring caption;
	int  icoOffset;
	bool noRenderText = false;
	Align textAlign = Align::Left;

	virtual void precompute()          override;
	virtual void render (int x, int y) override;

	using UIElement::UIElement;

};

#endif
