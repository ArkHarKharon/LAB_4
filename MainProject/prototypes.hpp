#pragma once
#include <functional>

using sort_ptr = std::function<void(std::vector<int>& main_vector)>;
using vec = std::vector<int>;


int random(int min, int max);
void main_menu(vec &main_vector, Colors& color);
void set_color(Colors& color);
void print_matrix(vec &main_vector, int len);
void print_matrix(vec &main_vector, int len, sort_ptr ptr);
void random_set(vec &main_vector, int min, int max);
void greetings();
void loading(int time);
void bubble_sort(vec &main_vector);
void shaker_sort(vec &main_vector);
void gnome_sort(vec &main_vector);
void select_sort(vec& main_vector);
void insert_sort(vec& main_vector);
void shell_sort(vec& main_vector);
void sorting(vec& main_vector, int len);