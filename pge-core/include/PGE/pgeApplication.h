#pragma once

#include <iostream>

#include "PGE/core/pgeCore.h"

#include "PGE/utils/pgeTypes.h"
#include "PGE/utils/pgeTime.h"

#include "PGE/graphics/pgeWindow.h"
#include "PGE/graphics/pgeTexture.h"
#include "PGE/graphics/pgeRendererWrapper.h"

#include "PGE/events/pgeEvent.h"

#include "PGE/ecs/pgeEcs.h"
#include "PGE/components/components.h"
#include "PGE/systems/pgeSystems.h"

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

        inline b8 _GetKeyDown(SDL_Scancode sc)
        {
            return kinput::__GetKeyDown(&mEHD.KID, sc);
        }

        inline glm::vec2 _GetMousePos()
        {
            return glm::vec2(mEHD.KID.mousePosX, mEHD.KID.mousePosY);
        }

        inline f32 _GetDT()
        {
            return mTimeStep.deltaTime;
        }
        
        virtual void Setup();
        virtual void Run();

        void _MainLoop();

    protected:
        b8 mIsRunning;
        TSData mTimeStep;

        graphics::Window* mWindow;
        graphics::RendererWrapper* mRenderer;
        graphics::TextureManager* mTexMan;
        ecs::ECSCoordinator* mECS;

        ehandler::EHData mEHD;

        std::shared_ptr<pge::ecs::RenderSystem> mRenderSystem;
        std::shared_ptr<pge::ecs::AnimationSystem> mAnimationSystem;
    };

    Application* AppInit();
}