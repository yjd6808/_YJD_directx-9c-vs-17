#pragma once

#include <Windows.h>
#include <sstream>
#include <string>
#include <thread>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <stdarg.h>

using namespace std;

#define MSGBOX(...)					MessageBox(nullptr, StringFormatter::Generate(__VA_ARGS__).c_str(), nullptr, MB_OK)
#define TIDS						string((stringstream() << std::this_thread::get_id()).str())
#define TIDCS						string((stringstream() << std::this_thread::get_id()).str()).c_str()
#define TID							atoi(string((stringstream() << std::this_thread::get_id()).str()).c_str())