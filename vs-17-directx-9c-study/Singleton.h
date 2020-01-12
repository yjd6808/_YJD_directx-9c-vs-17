#pragma once


#define SINGLETONE(className, ...) \
public: \
	static className* GetInstance() { \
		static className* s_instance = nullptr; \
		if (s_instance == nullptr) \
			s_instance = new className(__VA_ARGS__); \
		return s_instance; \
	}


#define SINGLETON_MAINCLASS_PUBLIC_CREATE(className, mainMethodName) \
public: \
	static int main() { \
		return className::GetInstance()->mainMethodName(); \
	} \
	static className* GetInstance() { \
		static className* s_instance = nullptr; \
		if (s_instance == nullptr) \
			s_instance = new className; \
		return s_instance; \
	}

#define SINGLETON_MAINCLASS_PRIATE_CREATE(className, mainMethodName) \
public: \
	static int main() { \
		return className::GetInstance()->mainMethodName(); \
	} \
private: \
	static className* GetInstance() { \
		static className* s_instance = nullptr; \
		if (s_instance == nullptr) \
			s_instance = new className; \
		return s_instance; \
	}
