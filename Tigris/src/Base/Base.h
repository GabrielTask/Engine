#pragma once
#ifdef TG_PLATFORM_WINDOWS

	#ifdef TG_BUILD_DLL
		#define TG_API __declspec(dllexport)
	#else
		#define TG_API __declspec(dllimport)
	#endif // TG_BUILD_DLL

#endif // TG_PLATFORM_WINDOWS

 
#ifdef TG_DEBUG
	#define Assert(expression)if(!expression){std::cout<<"Error: in: "<< __LINE__<<__FILE__;__debugbreak();}
#else 
	#define Assert(expression) expression;
#endif // TG_DEBUG

#define TG_API 

#include <memory>

namespace Tigris
{


	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}