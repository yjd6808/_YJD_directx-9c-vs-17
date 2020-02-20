/*
 * @Author	: Jungdo Yun
 * @Created	: 19.12.??
 */

#pragma once

#include <sstream>
#include <string>

//여러타입을 받아 문자열을 생성해주는 클래스
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
