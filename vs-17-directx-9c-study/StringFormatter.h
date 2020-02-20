/*
 * @Author	: Jungdo Yun
 * @Created	: 19.12.??
 */

#pragma once

#include <sstream>
#include <string>

//����Ÿ���� �޾� ���ڿ��� �������ִ� Ŭ����
class StringFormatter
{
	static std::stringstream ss;
public:
	static std::string Generate() {
		std::string ret = ss.str();
		ss.str(std::string());
		return ret;
	}

	template <typename T, typename ... Types>
	static std::string Generate(T arg, Types ... args) {
		ss << arg;
		return Generate(args...);
	}
};
std::stringstream StringFormatter::ss;
