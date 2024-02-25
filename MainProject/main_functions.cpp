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
		<< "\t\t\t    ---------------�������---------------\n\n\t";

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
	std::cout << "\n\n\t\t\t    ---------------�������---------------\n\n\n\n";
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


	std::cout << termcolor::reset << "\t\t\t    ---------------�������---------------\n\n\t";
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
	std::cout << "\n\n\t\t\t    ---------------�������---------------\n\n\n\n";
}


void random_set(vec &main_vector, int min, int max)
{
	for (int index{ 0 }; index < main_vector.size(); index++)
		main_vector.at(index) = random(min, max);
}

void greetings()
{
	std::cout
		<< "\t� ���� ���� �� �� ������� �� ��������, ��, ���� ��, ������� ������������ ��������.\n"
		<< "�� ������ ��������,���, ������ ���� �� �� ������� ����� ����������\n"
		<< "����� ����, �� ������ ����(-a): ������� ��� ����\n"
		<< "�� ���� ���� ��: �� ������� ���(-___-), � ����� ��-�������, ����� �� �������)))";
	Sleep(7000);
	system("cls");

	std::cout << "\t� ���� ��, � ���������: ����� ���� �������)))";
	Sleep(3000);
	system("cls");

	std::cout
		<< "��� ������ ����� ���������� � ���������� ��������\n"
		<< "�� ������, ���������� ���������� ������� �� �������� ������, ��� �������� �����";
	Sleep(4000);
	system("cls");

	std::cout
		<< "�� ������ �������� � ���� ���������� ��� ������ -- � �� ���� ������������ ����\n"
		<< "�� �� ������(-��) �������� -- ���� ���������� � ����� �������� (��������) ��� �����\n"
		<< "����� ��������, ��������� �������� ��� ������������� ��������";
	Sleep(6000);
	system("cls");

}

void loading(int time) //����� std::cout?
{
	std::cout << "� ��������, ��������";
	Sleep(time / 4);
	system("cls");

	std::cout << "� ��������, ��������.";
	Sleep(time / 4);
	system("cls");

	std::cout << "� ��������, ��������..";
	Sleep(time / 4);
	system("cls");

	std::cout << "� ��������, ��������...";
	Sleep(time / 4);
	system("cls");
}

void main_menu(vec &main_vector, Colors& color)
{
	//greetings();

	std::cout
		<< "�� �����,������ ���������� � ��������\n"
		<< "����� ����� � ������� ������� ����� ������ (���������� 10�10): ";

	int len, width;
	std::cin >> len >> width;
	system("cls");

	int volume{ len * width };
	main_vector.resize(volume);

	std::cout
		<< "������� " << len << "x" << width << " ���� �������!\n"
		<< "�� ������� �������� �� �����, �� ����� �� �������������� � ����!";
	Sleep(5000);
	system("cls");

	std::cout << "����, �������� ���������, ����� ��������))";
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
			<< "1) ���� ������ ��������\n"
			<< "2) ���������\n"
			<< "3) �����\n\n"
			<< "�����: ";
		std::cin >> answer_menu;
		system("cls");

		switch (answer_menu)
		{
		case(SORTING):sorting(main_vector, len);
			
		case(SETTINGS):
			do
			{
				std::cout
					<< "\t\t\t    ----------------���������----------------\n"
					<< "1) � ���� �������� ����\n"
					<< "2) � ���� �������� ���� ����\n"
					<< "3) � ���� ������������� ����� �������� ��������� �������\n"
					<< "4) � ���� �������� ������ ������� (�� ���� ����� � ����)\n"
					<< "5) � ���� ��������� � �������� ����\n\n"
					<< "�����: ";

				std::cin >> answer_settings;

				switch (answer_settings)
				{
				case(LANGUAGE):
					system("cls");
					loading(4000);
					std::cout << "�������, ���� ����, � �� ����� �����)))))";
					Sleep(3000);
					system("cls");
					break;

				case(COLOR):
					system("cls");

					std::cout
						<< "\t\t\t    ----------------����� �����----------------\n"
						<< "������ ����� ����:\n"
						<< "1) �����\n"
						<< "2) �������(��)\n"
						<< "3) ������\n"
						<< "4) ������-������\n"
						<< "5) ���������\n"
						<< "6) ��������\n"
						<< "7) ������� ����\n"
						<< "�����: ";

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
					std::cout << "������!";
					Sleep(3000);
					system("cls");
					break;

				case(GENERATE):
					system("cls");
					loading(4000);
					random_set(main_vector, 1, 999);
					std::cout << "������!";
					Sleep(3000);
					system("cls");
					break;

				case(RESIZE):
					system("cls");
					std::cout
						<< "\t\t\t    ----------------��������� �������----------------\n"
						<< "�������� ������� ����� ������������!\n"
						<< "����� ����� ����� � ������ ������� ����� ������: ";
					std::cin >> new_len >> new_width;

					temp_len = new_len;
					temp_width = new_width;
					new_volume = new_len * new_width;

					main_vector.resize(new_volume);
					random_set(main_vector, 1, 999);

					system("cls");
					loading(4000);
					std::cout << "������!";
					system("cls");
					break;

				case(MAIN_MENU): break;
				}
			} while (answer_settings != MAIN_MENU);
		case(EXIT):
			std::cout << termcolor::green << "�������� ���!" << termcolor::reset;
			break;
		}
	} while (answer_menu != EXIT);
}