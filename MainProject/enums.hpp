#pragma once


enum Colors		//Не хочу использовать static_cast в меню
{
	BLUE = 1,
	BRIGHT_BLUE,
	YELLOW,
	BRIGHT_YELLOW,
	MAGENTA,
	CYAN,
	DEFAULT,
};


enum Menu		//Не хочу использовать static_cast в меню
{
	SORTING = 1,
	SETTINGS,
	EXIT,
};

enum Settings	//Не хочу использовать static_cast в меню
{
	LANGUAGE = 1,
	COLOR,
	GENERATE,
	RESIZE,
	MAIN_MENU
};


enum Sorting  //Не хочу использовать static_cast в меню
{
	BUBBLE = 1,
	SHAKER,
	GNOME,
	SELECT,
	INSERT,
	SHELL,
	MENU
};