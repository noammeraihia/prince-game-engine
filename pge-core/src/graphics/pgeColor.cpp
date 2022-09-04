#include "PGE/graphics/pgeColor.h"

namespace pge
{
    namespace graphics
    {
        Color::Color() :r(1), g(1), b(1), a(1) { InitCStrName(); }
        Color::Color(const Color& color)
        {
            *this = color;
            InitCStrName();
        }

        Color::Color(SDL_Color color) :r(color.r), g(color.g), b(color.b), a(color.a) { InitCStrName(); }
        Color::Color(ui32 ac) :r(ac), g(ac), b(ac), a(1) { InitCStrName(); }
        Color::Color(ui8 r, ui8 g, ui8 b, ui8 a) :r(r), g(g), b(b), a(a) { InitCStrName(); }

        Color::~Color()
        {
            // if (cstrName != NULL)
            //     free(cstrName);
        }
    }
}