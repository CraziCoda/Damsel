#pragma once
#include <iostream>
#include "Core.h"
#include <string>

namespace Damsel {
	class DAMSEL_API  Logger
	{
	public:
		Logger();
		Logger(const std::string& name);
		~Logger();

		void setup(std::string file, std::string encoding, int level);

		const std::string& GetName();

	private:
		std::string m_Name;
	};

}