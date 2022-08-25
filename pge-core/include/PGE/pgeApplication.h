#pragma once

#include <iostream>

#include "PGE/core/pgeCore.h"

#include "PGE/graphics/pgeWindow.h"
#include "PGE/graphics/pgeTexture.h"
#include "PGE/graphics/pgeRendererWrapper.h"

#include "PGE/events/pgeEvent.h"

#include "PGE/ecs/pgeEcs.h"

namespace pge
{
    class Application
    {
    public:
        Application();
        virtual ~Application();

        void _Setup();
        void _Destroy();
        void _HandleEvents();

        inline bool _GetKeyDown(SDL_Scancode sc)
        {
            return kinput::__GetKeyDown(&mEHD.KID, sc);
        }
        
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