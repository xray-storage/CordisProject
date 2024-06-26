#pragma once

#include "xrEngine/SDK_Camera.h"
namespace Cordis
{
    namespace SDK
    {
    class SDKUI_Render
    {
    private:
        SDKUI_Render(void) noexcept = default;

    public:
        inline static SDKUI_Render& GetInstance(void)
        {
            static SDKUI_Render instance;
            return instance;
        }

        SDKUI_Render(const SDKUI_Render&) = delete;
        SDKUI_Render& operator=(const SDKUI_Render&) = delete;
        SDKUI_Render(SDKUI_Render&&) = delete;
        SDKUI_Render& operator=(SDKUI_Render&&) = delete;

        void Initialize(void);
        void MainRender(void);

        ~SDKUI_Render(void);
    };
    }
}

