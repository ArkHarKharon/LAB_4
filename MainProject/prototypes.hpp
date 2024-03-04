#pragma once
#include <functional>

using sort_ptr = std::function<void(std::vector<int>& main_vector, int& swap, int& compare)>;
using vec = std::vector<int>;


int random(int min, int max);
void main_menu(vec &main_vector);
void set_color(Colors& color);
void print_matrix(vec &main_vector, int len);
void random_set(vec &main_vector, int min, int max);
void loading(int time,std::string str);
void settings(vec& main_vector, Colors& menu_color, int len, int width);

void bubble_sort(vec &main_vector, int& swap, int& compare);
void shaker_sort(vec &main_vector, int& swap, int& compare);
void gnome_sort(vec &main_vector, int& swap, int& compare);
void select_sort(vec& main_vector, int& swap, int& compare);
void insert_sort(vec& main_vector, int& swap, int& compare);
void shell_sort(vec& main_vector, int& swap, int& compare);
void sorting(vec& main_vector, int len);