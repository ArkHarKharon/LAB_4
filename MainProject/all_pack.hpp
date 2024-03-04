#pragma once


#include <iostream>
#include <vector>
#include <Windows.h>
#include <ctime>
#include <random>
#include <math.h>
#include <algorithm>
#include <chrono>
#include <functional>

#include "enums.hpp"
#include "prototypes.hpp"
#include "termcolor.hpp"

using vec = std::vector<int>;
using states = std::vector<bool>;

using sort_ptr = std::function<void(std::vector<int>& main_vector, int& swap, int& compare)>;
