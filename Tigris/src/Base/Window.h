#pragma once
#include <stdint.h>
#include "Events/Event.h"
#include <functional>
#include <utility>
namespace Tigris
{

	class Window
	{
	public:


	public:
		virtual ~Window() = default;
		virtual void OnUpdate() = 0;
		virtual void SetCallBack(void(*callbackFunc)(Event& e)) = 0;;
		virtual void SetVSync(bool value) = 0;
		virtual bool IsVSync() const = 0;
		virtual const char* GetName()const = 0;
		virtual float GetAspectRatio()const = 0;
		virtual std::pair<uint32_t, uint32_t>GetSize()const = 0;
		virtual void* GetNativeWindow() = 0;

	public:
		static Ref<Window> Create(uint32_t width, uint32_t height, const char* name);
	};
}