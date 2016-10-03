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

#include "ui/button.h"
#include "ui/listmenu.h"

namespace ui {
	class UIDropMenu : public UIButton {
	private:
		UIListMenu *menu = nullptr;
		bool isMenu      = false;
		int  menuOffsets[3];

		std::unique_ptr<gapi::BaseObject> arrowElement = std::make_unique<gapi::BaseObject> (manager->uiDataRender, app->screenCamera.get());

	public:
		bool autoSizeMenu = true;
		void updateMenu();

		UIDropMenu (UIManager *manager, bool isMenu = false) : UIButton(manager) {

			this->manager = manager;
			this->isMenu  = isMenu;

			drawChilds = false;
			style = isMenu ? "flatbutton" : "droplist";
			precompute();

		}

		inline void setMenu (std::unique_ptr<UIListMenu> m) {

			menu = m.get();
			menu->visible = false;
			addElement (std::move(m));

		}

		virtual void addElement (std::unique_ptr<UIElement> el) override {
			menu = dynamic_cast<UIListMenu*>(el.get());

			if (menu) {
				menu->visible = false;
				menu->overlay = true;
				manager->overlayElements.push_back(menu);
				UIElement::addElement (std::move(el));
			} else {
				UIElement::addElement (std::move(el));
			}

		}

		virtual void precompute() override;
		virtual void render()     override;

		virtual void mouseUp (int x, int y, int button) override;

	};
};
