#pragma once
#include "Base/Window.h"
#include "Graphics/GraphicsContext.h"

struct GLFWwindow;

namespace Tigris
{

    class WindowsWindow :
        public Window
    {
    public:
        WindowsWindow(uint32_t width, uint32_t height, const char* name);
        ~WindowsWindow();
        virtual void OnUpdate() override;

        virtual void SetCallBack(void(*callbackFunc) (Event& e)) override;


        virtual const char* GetName() const override;


        virtual float GetAspectRatio() const override;

        virtual std::pair<uint32_t, uint32_t> GetSize() const override;


        void SetVSync(bool value) override;


        bool IsVSync() const override;


        void* GetNativeWindow() override;

    private:
        void InitBack();

    private:
        GLFWwindow* m_NativeWindow;

            struct WindowData
            {
                uint32_t m_Width;
                uint32_t m_Height;
                const char* m_Name;
                bool m_IsVsync;
                void (*m_CallbackFunc)(Event& e);
            }m_Data;
            Scope<GraphicsContext> m_Context;


    };

}



