#pragma once

#include <iostream>

#include "PGE/core/pgeCore.h"

#include "PGE/graphics/pgeWindow.h"
#include "PGE/graphics/pgeTexture.h"
#include "PGE/graphics/pgeRendererWrapper.h"

#include "PGE/events/pgeEvent.h"

namespace pge
{
    class Application
    {
    public:
        Application();
        virtual ~Application();

        void _Init();
        void _HandleEvents();

        inline bool _GetKeyDown(SDL_Scancode sc)
        {
            return kinput::__GetKeyDown(&mEHD.KID, sc);
        }
        
        void _Setup();
        virtual void Setup();
        virtual void Run();

        void _MainLoop();

    protected:
        bool mIsRunning;

        graphics::Window* mWindow;
        graphics::RendererWrapper* mRenderer;
        graphics::TextureManager* mTexMan;

        ehandler::EHData mEHD;
    };

    Application* AppInit();
}