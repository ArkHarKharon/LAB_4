#include "all_pack.hpp"

int main()
{
	setlocale(0, "");
	srand(time(0));

	vec main_vector{};
	states states_vec{};			//������ ��������� ���������(������������ ��� ���)
	Colors menu_color{ DEFAULT };

	main_menu(main_vector, menu_color);
}