#pragma once


namespace TYPE {

	bool find_s(const std::string& type, const char* name)
	{
		return type.find(name) != std::string::npos ? true : false;
	}

	int checkType(const char* type)
	{
		const std::string type_s = type;
		#define is_type(...)  find_s(type_s, __VA_ARGS__)
		bool isNumber = is_type("int") || is_type("float")|| is_type("double") || is_type("short")|| is_type("long");
		bool isBool = is_type("bool");
		bool isString = is_type("char") || is_type("basic_string");

		int t = 1 * isNumber + 2 *isBool + 3 * isString;

		return t;
	}

}
