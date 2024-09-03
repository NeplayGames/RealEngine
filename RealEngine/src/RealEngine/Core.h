#pragma once

#ifdef RE_PLATFORM_WINDOWS
	#ifdef RE_BUILD_DLL
		#define REALENGINE_API __declspec(dllexport)
	#else
		#define REALENGINE_API __declspec(dllimport)
#endif
#endif // DEBUG
