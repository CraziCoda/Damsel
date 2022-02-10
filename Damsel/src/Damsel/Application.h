#pragma once
#include <iostream>

namespace Damsel {
	class _declspec(dllexport)  Application
	{
	public:
		Application();
		virtual ~Application();
		void setup();
	};
}