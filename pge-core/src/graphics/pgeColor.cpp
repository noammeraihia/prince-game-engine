#include "PGE/graphics/pgeColor.h"

namespace pge
{
    namespace graphics
    {
        Color::Color() :r(1), g(1), b(1), a(1) {}
        Color::Color(const Color& color)
        {
            *this = color;
        }

        Color::Color(SDL_Color color) :r(color.r), g(color.g), b(color.b), a(color.a) {}
        Color::Color(uint32_t ac) :r(ac), g(ac), b(ac), a(1) {}
        Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) :r(r), g(g), b(b), a(a) {}
    }
}