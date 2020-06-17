#pragma once

#ifdef BORON_BUILD_DLL
	#define BORON_API __declspec(dllexport)
#else
	#define BORON_API __declspec(dllimport)
#endif