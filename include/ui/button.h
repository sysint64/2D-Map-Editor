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

#include <string>

#include "ui/widget.h"
#include "ui/manager.h"
#include "ui/tooltip.h"

#include "renderer/base_object.h"


namespace ui {
	class Button : public Widget {
	protected:
		bool drawChilds = true;
		int  iconLeft   = 2;
		int  iconTop    = 0;

		/* Param Names for load from Layout file */

		std::string leaveElement = "leave";
		std::string enterElement = "enter";
		std::string clickElement = "click";
		std::string focusElement = "focus";

		/* Render Objects */

		std::unique_ptr<gapi::BaseObject> leftElement   = std::make_unique<gapi::BaseObject> (manager->uiDataRender, app->screenCamera.get());
		std::unique_ptr<gapi::BaseObject> rightElement  = std::make_unique<gapi::BaseObject> (manager->uiDataRender, app->screenCamera.get());
		std::unique_ptr<gapi::BaseObject> middleElement = std::make_unique<gapi::BaseObject> (manager->uiDataRender, app->screenCamera.get());
		std::unique_ptr<gapi::BaseObject> iconElement   = std::make_unique<gapi::BaseObject> (manager->uiDataRender, app->screenCamera.get());
		std::unique_ptr<gapi::BaseObject> iconElement2  = std::make_unique<gapi::BaseObject> (manager->uiDataRender, app->screenCamera.get());

		int focusOffsets[3]; // Left, Top, Width

		/* Draw Text */

		void renderText (const Align align, const std::wstring &text, const int offset = 0);
		void renderSkin();

	public:
		std::unique_ptr<Tooltip> tooltip = nullptr;

		/* Icon */

		int iconOffset     [2] = {-1, -1}; bool showIcon      = false;
		int icon2Offset    [2] = {-1, -1}; bool showIcon2     = false;
		int clickIconOffset[2] = {-1, -1}; bool showClickIcon = false;

		//

		bool allowCheck;
		std::wstring caption = L"";
		int  icoOffset = 0;
		bool noRenderText = false;
		Align textAlign = Align::Center;

		virtual void precompute() override;
		virtual void render()     override;

		virtual void mouseDown (int x, int y, int button) override;
		virtual void mouseUp   (int x, int y, int button) override;

		inline void setTooltip() {
			tooltip = std::make_unique<Tooltip> (manager);
			tooltip->target = this;
			manager->overlayElements.push_back(tooltip.get());
		}

		//using Widget::Widget;
		Button (Manager *manager, bool allowCheck = false) : Widget (manager) {

			this->manager    = manager;
			this->allowCheck = allowCheck;

			style = allowCheck ? "checkbutton" : "button";
			precompute();

		}

	};
};
