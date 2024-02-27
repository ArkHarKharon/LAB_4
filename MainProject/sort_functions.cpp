#include <vector>
#include <chrono>
#include <functional>

#include "enums.hpp"
#include "termcolor.hpp"
#include "prototypes.hpp"

using sort_ptr = std::function<void(std::vector<int>& main_vector)>;
using vec = std::vector<int>;
using states = std::vector<bool>;


void bubble_sort(vec& main_vector)
{
	for (std::size_t index = 0; index < main_vector.size() - 1; index++) 
	{
		if (main_vector.at(index) > main_vector.at(index + 1))
		{
			main_vector.at(index) += main_vector.at(index + 1);
			main_vector.at(index + 1) = main_vector.at(index) - main_vector.at(index + 1);
			main_vector.at(index) -= main_vector.at(index + 1);
		}
	}
}

void shaker_sort(vec& main_vector)
{
	std::size_t i, j, k;
	std::size_t n = main_vector.size();

	for (i = 0; i < n;)
	{
		for (j = i + 1; j < n; j++)
		{
			if (main_vector.at(j) < main_vector.at(j -1))
				std::swap(main_vector[j], main_vector[j - 1]);
		}
		n--;

		for (k = n - 1; k > i; k--)
		{
			if (main_vector.at(k) < main_vector.at(k - 1))
				std::swap(main_vector.at(k), main_vector.at(k - 1));
		}
		i++;
	}
}

void gnome_sort(vec& main_vector)
{
	std::size_t index = 0;
	while (index < main_vector.size())
	{
		if (index == 0)
			index++;
		if (main_vector.at(index) >= main_vector.at(index - 1))
			index++;
		else {
			std::swap(main_vector.at(index), main_vector.at(index - 1));
			index--;
		}
	}
}

void select_sort(vec& main_vector)
{
	std::size_t i, j, min_index;

	for (i = 0; i < main_vector.size() - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < main_vector.size(); j++) {
			if (main_vector.at(j) < main_vector.at(min_index))
				min_index = j;
		}

		if (min_index != i)
			std::swap(main_vector.at(min_index), main_vector.at(i));
	}
}

void insert_sort(vec& main_vector)
{
	std::size_t i, key, j;
	for (i = 1; i < main_vector.size(); i++) {
		key = main_vector.at(i);
		j = i - 1;

		while (j >= 0 and main_vector.at(j) > key)
		{
			main_vector.at(j + 1) = main_vector.at(j);
			j = j - 1;
		}
		main_vector.at(j + 1) = key;
	}
}

void shell_sort(vec& main_vector)
{
	for (std::size_t interval = main_vector.size() / 2; interval > 0; interval /= 2) 
	{
		for (std::size_t i = interval; i < main_vector.size(); i += 1) 
		{
			std::size_t j;
			int temp = main_vector.at(i);
			for (j = i; j >= interval and main_vector.at(j - interval) > temp; j -= interval)
				main_vector.at(j) = main_vector.at(j - interval);
			main_vector.at(j) = temp;
		}
	}
}

void sorting(vec& main_vector,states states_vec, sort_ptr ptr, int len)
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
		default: std::cout << termcolor::red << "Неверный индекс!" << termcolor::reset; break; return;
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
