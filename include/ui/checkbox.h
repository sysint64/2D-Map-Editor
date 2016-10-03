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
 * Author: Kabylin Andrey <andrey@kabylin.ru
 */

#pragma once

#include "ui/widget.h"
#include "ui/manager.h"

#include "renderer/base_object.h"

namespace ui {
	class Checkbox : public Widget {
	protected:
		std::unique_ptr<gapi::BaseObject> boxElement   = std::make_unique<gapi::BaseObject> (manager->uiDataRender, app->screenCamera.get());
		std::unique_ptr<gapi::BaseObject> focusElement = std::make_unique<gapi::BaseObject> (manager->uiDataRender, app->screenCamera.get());

		int focusOffsets[2]; // Left, Top

	public:

		std::wstring caption = L"Test Checkbox";

		virtual void precompute() override;
		virtual void render()     override;

		/* Events */

		virtual void mouseDown (int x, int y, int button) override;

		Checkbox (Manager *manager) : Widget (manager) {

			autoSize = true;
			style = "checkbox";
			this->manager = manager;
			precompute();

		}

	};
};
