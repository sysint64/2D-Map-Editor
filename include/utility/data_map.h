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

#ifndef E2DIT_UTILITY_DATA_MAP_H
#define E2DIT_UTILITY_DATA_MAP_H

#include <vector>
#include <string>
#include <map>
#include "stdio.h"
#include "utility/application.h"
#include <boost/filesystem.hpp>
#include "utility/exceptions.h"

namespace fs = boost::filesystem;

class DataMap {
private:

	/* Data Value */

	struct DataVal {

		float		 num;
		std::string	 str;
		std::wstring wstr;
		bool		 isStr;

	} typedef DataVal;

	/* Data Functiosn */

	struct DataParams {

		std::map <std::string, std::vector<DataVal> > params;
		bool def;

	} typedef DataParams;

	/* In File */

	FILE		*inFile;

	/* Parser */

	char		 curToken;
	std::string	 idStr;
	float		 numVal;
	int			 lastChar = ' ';
	int			 posno, lineno; // Line & Pos
	bool		 end = false;

	/* Data */

	std::vector<int> bytecode;
	std::vector<int> offsetStack; // Files offset in bytes

	/**/ 
	Application *app;

	/* Lexer */

	char lexChar();
	char lexToken();
	char lexNextToken();
	char lexStrLen();
	void lexOpenFile   (const char *fileName);
	void lexReopenFile (const char *fileName);

	/* */

	char lexTokString();
	char lexTokNumber();
	char lexTokId();
	char lexComment();

	/* Parser */

	void parse();

	void parseElement ();
	void parseElements();

	void parseFuncs (std::string name);
	void parseFunc  (std::string name);

	void parseVal();
	void parseInclude();

	std::vector<DataVal> parseParams (std::string Name);
	DataVal              parseParam  ();

public:

	/* Tokens */

	enum Token {
		tok_eof = -1,
		//
		tok_id = -2, tok_number = -3, tok_string = -4,
		tok_begin = -5, tok_end = -6, tok_include = -7
	};

	/* Operands */

	enum Operand {
		op_eof  = 0x00, op_elem = 0x01, op_def = 0x02,
		op_str  = 0x03, op_num  = 0x04, op_end = 0x05,
		op_type = 0x06,
	};

	enum ReadType { rtText, rtBin };

	/* Data */

	std::map<std::string, struct DataParams> element;
	bool haltIfErr = false;
	std::string fileName;

	/* Methods */

	DataMap ();
	DataMap (const char *fileName, ReadType rt = rtText);

	virtual void loadFromText (const char *fileName);
	virtual void loadFromBin  (const char *fileName);

	void saveToText (const char *fileName);
	void saveToBin  (const char *fileName);

	void update();

};

#endif
