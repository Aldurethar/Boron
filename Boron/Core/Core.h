#pragma once
#pragma warning( disable : 4251 )


#ifdef BORON_BUILD_DLL
	#define BORON_API __declspec(dllexport)
#else
	#define BORON_API __declspec(dllimport)
#endif

#define BR_ASSERT(b, t) {if (!b) {BORON_ERROR(std::string("Assertion Failed!:") + std::string(t)); __debugbreak(); } }

#define BIT(i) (1 << i)