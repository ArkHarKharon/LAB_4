#include "all_pack.hpp"

int main()
{
	setlocale(0, "");
	srand(time(0));

	vec main_vector{};
	states states_vec{};			//вектор состояний элементов(остортирован или нет)
	Colors menu_color{ DEFAULT };

	main_menu(main_vector, menu_color);
}