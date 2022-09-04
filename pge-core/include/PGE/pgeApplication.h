#pragma once

#include <iostream>

#include "PGE/core/pgeCore.h"

#include "PGE/utils/pgeTime.h"

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

        void _InitECS();

        inline bool _GetKeyDown(SDL_Scancode sc)
        {
            return kinput::__GetKeyDown(&mEHD.KID, sc);
        }

        inline float _GetDT()
        {
            return mTimeStep.deltaTime;
        }
        
        virtual void Setup();
        virtual void Run();

        void _MainLoop();

    protected:
        bool mIsRunning;
        TSData mTimeStep;

        graphics::Window* mWindow;
        graphics::RendererWrapper* mRenderer;
        graphics::TextureManager* mTexMan;
        ecs::ECSCoordinator* mECS;

        ehandler::EHData mEHD;
    };

    Application* AppInit();
}