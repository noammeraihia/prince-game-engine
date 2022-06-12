#pragma once

#include <cstdio>
#include <SDL2/SDL.h>

#include "PGE/utils/pgeLogger.h"

namespace pge
{
    namespace graphics
    {
        struct Color
        {
            Color();
            Color(const Color& color);
            Color(SDL_Color color);
            Color(uint32_t ac);
            Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

            ~Color();

            inline void InitCStrName()
            {
                cstrName = NULL;
                cstrName = (char*)malloc(sizeof(char) * 1024);
                if (!cstrName)
                {
                    PGE_LOG(PGELLVL_ERROR, "\"cstrName\" mem alloc has failed");
                    return;
                }
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

            uint8_t r, g, b, a;
            char* cstrName;

        };
    }
}