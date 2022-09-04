#pragma once

#include <cstdio>
#include <SDL2/SDL.h>

#include "PGE/utils/pgeLogger.h"
#include "PGE/utils/pgeTypes.h"

namespace pge
{
    namespace graphics
    {
        struct Color
        {
            Color();
            Color(const Color& color);
            Color(SDL_Color color);
            Color(ui32 ac);
            Color(ui8 r, ui8 g, ui8 b, ui8 a);

            ~Color();

            inline void InitCStrName()
            {
                sprintf(cstrName, "RGBA(%d, %d, %d, %d)", r, g, b, a);
            }

            inline SDL_Color AsSDLColor()
            {
                return (SDL_Color) { r, g, b, a };
            };

            inline const char* AsCStr()
            {
                return cstrName;
            };

            ui8 r, g, b, a;
            char cstrName[25];

        };
    }
}