#pragma once

#ifdef OC_PLATFORM_WINDOWS
	#ifdef OC_BUILD_DLL
		#define OC_API __declspec(dllexport)
	#else
		#define OC_API __declspec(dllimport)
	#endif
#endif

#ifndef OC_DIST
	#define OC_ASSERT(x, ...) { if(!(x)) { OC_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define OC_CORE_ASSERT(x, ...) { if(!(x)) { OC_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else	OC
	#define OC_ASSERT(x, ...)
	#define OC_CORE_ASSERT(x, ...)
#endif
