/*
 * E2DIT - is a 2D Map Editor to create a levels for 2d games
 * Copyright (C) 2015 Kabylin Andrey <andrey@kabylin.ru>

 * This file is part of E2DIT-UTILITY.

 * E2DIT-UTILITY is free library: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * E2DIT-UTILITY is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License
 * along with E2DIT-UTILITY.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Kabylin Andrey <andrey@kabylin.ru>
 */
 
#ifndef E2DIT_UTILITY_INPUT_H
#define E2DIT_UTILITY_INPUT_H

/* Mouse */

#define mouseLeft			sf::Mouse::Left
#define mouseRight			sf::Mouse::Right
#define mouseMiddle			sf::Mouse::Middle
#define mouseWheellUp		0
#define mouseWheellDown		0
#define mouseNone		   -1

/* Keyboard */

#define keyUnknown			sf::Keyboard::Unknown
#define keyBackspace		sf::Keyboard::BackSpace
#define keyEnd				sf::Keyboard::End
#define keyHome				sf::Keyboard::Home
#define keyLeftArrow		sf::Keyboard::Left
#define keyUpArrow			sf::Keyboard::Up
#define keyRightArrow		sf::Keyboard::Right
#define keyDownArrow		sf::Keyboard::Down
#define keyDelete			sf::Keyboard::Delete
#define keyPageUp			sf::Keyboard::PageUp
#define keyPageDown			sf::Keyboard::PageDown
#define keyLAlt				sf::Keyboard::LAlt
#define keyRAlt				sf::Keyboard::RAlt
#define keyAlt				256
#define keyLShift			sf::Keyboard::LShift
#define keyRShift			sf::Keyboard::RShift
#define keyShift			257
#define keyLCtrl			sf::Keyboard::LControl
#define keyRCtrl			sf::Keyboard::RControl
#define keyCtrl				258
#define keyEnter			sf::Keyboard::Return
#define keyEscape			sf::Keyboard::Escape
#define keyF2				sf::Keyboard::F2
#define keyRSuper			sf::Keyboard::RSystem
#define keyLSuper			sf::Keyboard::LSystem
#define keyTab				sf::Keyboard::Tab

/* Letters */

#define keyA				sf::Keyboard::A
#define keyB				sf::Keyboard::B
#define keyC				sf::Keyboard::C
#define keyD				sf::Keyboard::D
#define keyE				sf::Keyboard::E
#define keyF				sf::Keyboard::F
#define keyG				sf::Keyboard::G
#define keyH				sf::Keyboard::H
#define keyI				sf::Keyboard::I
#define keyJ				sf::Keyboard::J
#define keyK				sf::Keyboard::K
#define keyL				sf::Keyboard::L
#define keyM				sf::Keyboard::M
#define keyN				sf::Keyboard::N
#define keyO				sf::Keyboard::O
#define keyP				sf::Keyboard::P
#define keyQ				sf::Keyboard::Q
#define keyR				sf::Keyboard::R
#define keyS				sf::Keyboard::S
#define keyT				sf::Keyboard::T
#define keyU				sf::Keyboard::U
#define keyV				sf::Keyboard::V
#define keyW				sf::Keyboard::W
#define keyX				sf::Keyboard::X
#define keyY				sf::Keyboard::Y
#define keyZ				sf::Keyboard::Z

/* Numbers */

#define keyAdd				sf::Keyboard::Add
#define keySub				sf::Keyboard::Subtract
//
inline bool pressed (int key) {

	if (key == keyShift) return sf::Keyboard::isKeyPressed (keyLShift) || sf::Keyboard::isKeyPressed (keyRShift);
	if (key == keyCtrl)  return sf::Keyboard::isKeyPressed (keyLCtrl)  || sf::Keyboard::isKeyPressed (keyRCtrl);
	if (key == keyAlt)   return sf::Keyboard::isKeyPressed (keyLAlt)   || sf::Keyboard::isKeyPressed (keyRAlt);

	sf::Keyboard::Key skey = static_cast<sf::Keyboard::Key>(key);
	return sf::Keyboard::isKeyPressed (skey);

}

#endif
