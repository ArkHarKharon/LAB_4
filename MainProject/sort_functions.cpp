#include <vector>
#include <chrono>
#include <functional>

#include "enums.hpp"
#include "termcolor.hpp"
#include "prototypes.hpp"

using sort_ptr = std::function<void(std::vector<int>& main_vector)>;
using vec = std::vector<int>;

void bubble_sort(vec& main_vector)
{

}

void shaker_sort(vec& main_vector)
{

}

void gnome_sort(vec& main_vector)
{

}

void select_sort(vec& main_vector)
{

}

void insert_sort(vec& main_vector)
{

}

void shell_sort(vec& main_vector)
{

}

void sorting(vec& main_vector, int len)
{
	system("cls");

	int sort_answer{};
	sort_ptr ptr{};

	do
	{
		std::cout
			<< "\t\t\t    ----------------СОРТИРОВКА----------------\n"
			<< "1) Я хочу выполнить пузырьковую сортировку\n"
			<< "2) Я хочу выполнить шейкерную сортировку\n"
			<< "3) Я хочу выполнить гномью сортировку\n"
			<< "4) Я хочу выполнить сортировку выбором\n"
			<< "5) Я хочу выполнить сортировку вставкой\n"
			<< "6) Я хочу выполнить сортировку Шелла\n"
			<< "7) Я хочу вернуться в главное меню\n\n"
			<< "Выбор: ";

		
		std::cin >> sort_answer;

		system("cls");

		switch (sort_answer)
		{
		case(BUBBLE): ptr = bubble_sort; break;
		case(SHAKER): ptr = shaker_sort; break;
		case(GNOME):  ptr = gnome_sort;  break;
		case(SELECT): ptr = select_sort; break;
		case(INSERT): ptr = insert_sort; break;
		case(SHELL):  ptr = shell_sort;  break;
		case(MENU):						 break;
		}

		std::cout << "Запускаю сортировку...";
		Sleep(1000);
		loading(2000);

		print_matrix(main_vector, len, ptr);
		Sleep(3000);
		system("cls");

		std::cout << "Сортировка завершена!";
		Sleep(3000);
		system("cls");
	} while (sort_answer != 7);
}
