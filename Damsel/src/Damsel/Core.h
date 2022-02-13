#pragma once

#ifdef DM_PLATFORM_WINDOWS
	#ifdef DM_BUILD_DLL
		#define DAMSEL_API _declspec(dllexport)
	#else
		#define DAMSEL_API _declspec(dllimport)
	#endif //DM_BUILD_DLL

#else
	#error Damsel is only built for windows

#endif // DM_PLATFORM_WINDOWS
