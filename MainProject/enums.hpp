#pragma once


enum Colors		//�� ���� ������������ static_cast � ����
{
	BLUE = 1,
	BRIGHT_BLUE,
	YELLOW,
	BRIGHT_YELLOW,
	MAGENTA,
	CYAN,
	DEFAULT,
};


enum Menu		//�� ���� ������������ static_cast � ����
{
	SORTING = 1,
	SETTINGS,
	EXIT,
};

enum Settings	//�� ���� ������������ static_cast � ����
{
	LANGUAGE = 1,
	COLOR,
	GENERATE,
	RESIZE,
	MAIN_MENU
};


enum Sorting  //�� ���� ������������ static_cast � ����
{
	BUBBLE = 1,
	SHAKER,
	GNOME,
	SELECT,
	INSERT,
	SHELL,
	MENU
};