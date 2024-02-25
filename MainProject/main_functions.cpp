#include <iostream>
#include <vector>
#include <Windows.h>
#include <ctime>
#include <random>
#include <math.h>
#include <algorithm>
#include <chrono>

#include "enums.hpp"
#include "termcolor.hpp"
#include "prototypes.hpp"



int random(int min, int max)
{
	int number = min + rand() % (max - min + 1);
	return number;
}

void print_matrix(vec &main_vector, int len)
{

	std::cout
		<< termcolor::reset
		<< "\t\t\t    ---------------МАТРИЦА---------------\n\n\t";

	int counter{ 0 };
	for (auto element : main_vector)
	{
		if (counter == len)
		{
			std::cout << "\n\n\t";
			counter = 0;
		}

		if (element > 99)
			std::cout << element << "\t";
		else if (element > 9 and element < 100)
			std::cout << element << " \t";
		else if (element < 10)
			std::cout << " " << element << " \t";
		counter++;
	}
	std::cout << "\n\n\t\t\t    ---------------МАТРИЦА---------------\n\n\n\n";
}

void set_color(Colors& color)
{
	switch (color)
	{
	case(Colors::BLUE):			 std::cout << termcolor::blue; break;
	case(Colors::BRIGHT_BLUE):   std::cout << termcolor::bright_blue; break;
	case(Colors::YELLOW):		 std::cout << termcolor::yellow; break;
	case(Colors::BRIGHT_YELLOW): std::cout << termcolor::bright_yellow; break;
	case(Colors::MAGENTA):		 std::cout << termcolor::magenta; break;
	case(Colors::CYAN):			 std::cout << termcolor::cyan; break;
	case(Colors::DEFAULT):		 std::cout << termcolor::reset; break;

	}
}

void print_matrix(vec &main_vector, int len, sort_ptr ptr)
{


	std::cout << termcolor::reset << "\t\t\t    ---------------МАТРИЦА---------------\n\n\t";
	int counter{ 0 };
	for (auto element : main_vector)
	{
		if (main_vector.at(index) == element)
			std::cout << termcolor::green;

		if (counter == len)
		{
			std::cout << "\n\n\t";
			counter = 0;
		}

		if (element > 99)
			std::cout << element << "\t";
		else if (element > 9 and element < 100)
			std::cout << element << " \t";
		else if (element < 10)
			std::cout << " " << element << " \t";
		std::cout << termcolor::reset;
		counter++;
	}
	std::cout << "\n\n\t\t\t    ---------------МАТРИЦА---------------\n\n\n\n";
}


void random_set(vec &main_vector, int min, int max)
{
	for (int index{ 0 }; index < main_vector.size(); index++)
		main_vector.at(index) = random(min, max);
}

void greetings()
{
	std::cout
		<< "\tВ этой лабе ты не увидишь ни векторов, ни, чтоб их, обычных динамических массивов.\n"
		<< "Ты можешь спросить,мол, какого хера ты не накатил такой функционал\n"
		<< "Более того, ты будешь прав(-a): вектора это тема\n"
		<< "Но есть одно НО: да поебать мне(-___-), я делаю по-красоте, скоро ты увидишь)))";
	Sleep(7000);
	system("cls");

	std::cout << "\tА хотя не, я передумал: будут тебе вектора)))";
	Sleep(3000);
	system("cls");

	std::cout
		<< "Для начала давай разберемся с некоторыми мелочами\n"
		<< "Во первых, рекомендую развернуть консоль на половину экрана, так красивее всего";
	Sleep(4000);
	system("cls");

	std::cout
		<< "Ты можешь играться с этой программой как хочешь -- я не хочу ограничивать тебя\n"
		<< "Но ты должен(-на) понимать -- хоть функционал и будет работать (наверное) при любых\n"
		<< "твоих шалостях, интерфейс подогнан под рекомендуемые значения";
	Sleep(6000);
	system("cls");

}

void loading(int time) //через std::cout?
{
	std::cout << "В процессе, ожидайте";
	Sleep(time / 4);
	system("cls");

	std::cout << "В процессе, ожидайте.";
	Sleep(time / 4);
	system("cls");

	std::cout << "В процессе, ожидайте..";
	Sleep(time / 4);
	system("cls");

	std::cout << "В процессе, ожидайте...";
	Sleep(time / 4);
	system("cls");
}

void main_menu(vec &main_vector, Colors& color)
{
	//greetings();

	std::cout
		<< "Но ладно,даавай разберемся в матрицей\n"
		<< "Введи длину и шириину матрицы через пробел (рекомендую 10х10): ";

	int len, width;
	std::cin >> len >> width;
	system("cls");

	int volume{ len * width };
	main_vector.resize(volume);

	std::cout
		<< "Матрица " << len << "x" << width << " была создана!\n"
		<< "Ты сможешь изменить ее позже, но лучше не переусердствуй с этим!";
	Sleep(5000);
	system("cls");

	std::cout << "Чтож, прелюдия соблюдена, можем начинать))";
	Sleep(2000);
	system("cls");


	random_set(main_vector, 1, 999);

	int answer_menu{ 0 };
	int answer_settings{ 0 };
	int answer_color{ 0 };
	int answer_searching{ 0 };

	int new_len{}; int new_width{};
	int& temp_len{ len };
	int& temp_width{ width };
	int& new_volume{ volume };

	int index_increm{};
	int index_jump{};
	int index_binary{};

	int element_increm{};
	int element_jump{};
	int element_binary{};

	int temp_increment{ 0 };

	std::chrono::steady_clock::time_point start_increm{};
	std::chrono::steady_clock::time_point start_jump{};
	std::chrono::steady_clock::time_point start_binary{};

	std::chrono::steady_clock::time_point finish_increm{};
	std::chrono::steady_clock::time_point finish_jump{};
	std::chrono::steady_clock::time_point finish_binary{};

	std::chrono::duration<double, std::micro> duration_increm{};
	std::chrono::duration<double, std::micro> duration_jump{};
	std::chrono::duration<double, std::micro> duration_binary{};

	do
	{
		system("cls");

		print_matrix(main_vector, len);
		set_color(color);

		std::cout
			<< "1) Меню поиска элемента\n"
			<< "2) Настройки\n"
			<< "3) Выход\n\n"
			<< "Выбор: ";
		std::cin >> answer_menu;
		system("cls");

		switch (answer_menu)
		{
		case(SORTING):sorting(main_vector, len);
			
		case(SETTINGS):
			do
			{
				std::cout
					<< "\t\t\t    ----------------НАСТРОЙКИ----------------\n"
					<< "1) Я хочу поменять язык\n"
					<< "2) Я хочу поменять цвет меню\n"
					<< "3) Я хочу сгенерировать новые значения элементов матрицы\n"
					<< "4) Я хочу изменить размер матрицы (на свой страх и риск)\n"
					<< "5) Я хочу вернуться в основное меню\n\n"
					<< "Выбор: ";

				std::cin >> answer_settings;

				switch (answer_settings)
				{
				case(LANGUAGE):
					system("cls");
					loading(4000);
					std::cout << "АХАХАХА, хрен тебе, а не смена языка)))))";
					Sleep(3000);
					system("cls");
					break;

				case(COLOR):
					system("cls");

					std::cout
						<< "\t\t\t    ----------------СМЕНА ЦВЕТА----------------\n"
						<< "Выбери новый цвет:\n"
						<< "1) Синий\n"
						<< "2) Голубой(хе)\n"
						<< "3) Желтый\n"
						<< "4) Светло-желтый\n"
						<< "5) Пурпурный\n"
						<< "6) Циановый\n"
						<< "7) Базовый цвет\n"
						<< "Выбор: ";

					std::cin >> answer_color;

					switch (answer_color)
					{
					case(BLUE):				 color = BLUE; break;
					case(BRIGHT_BLUE):		 color = BRIGHT_BLUE; break;
					case(YELLOW):			 color = YELLOW; break;
					case(BRIGHT_YELLOW):	 color = BRIGHT_YELLOW; break;
					case(MAGENTA):			 color = MAGENTA; break;
					case(CYAN):				 color = CYAN; break;
					case(DEFAULT):			 color = DEFAULT; break;
					}

					system("cls");
					loading(4000);
					set_color(color);
					std::cout << "Готово!";
					Sleep(3000);
					system("cls");
					break;

				case(GENERATE):
					system("cls");
					loading(4000);
					random_set(main_vector, 1, 999);
					std::cout << "Готово!";
					Sleep(3000);
					system("cls");
					break;

				case(RESIZE):
					system("cls");
					std::cout
						<< "\t\t\t    ----------------ИЗМЕНЕНИЕ МАТРИЦЫ----------------\n"
						<< "Значения матрицы будут перезаписаны!\n"
						<< "Введи новые длину и ширину матрицы через пробел: ";
					std::cin >> new_len >> new_width;

					temp_len = new_len;
					temp_width = new_width;
					new_volume = new_len * new_width;

					main_vector.resize(new_volume);
					random_set(main_vector, 1, 999);

					system("cls");
					loading(4000);
					std::cout << "Готово!";
					system("cls");
					break;

				case(MAIN_MENU): break;
				}
			} while (answer_settings != MAIN_MENU);
		case(EXIT):
			std::cout << termcolor::green << "Хорошего дня!" << termcolor::reset;
			break;
		}
	} while (answer_menu != EXIT);
}