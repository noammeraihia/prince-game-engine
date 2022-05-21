#include <stdio.h>
#include <PGE/pge.h>

class Sandbox : public pge::Application
{
public:
    Sandbox()
    {

    }

    ~Sandbox()
    {

    }

    void Run()
    {
        PGE_LOG_TRACE("Heyy lads %d", 9)
    }
};

pge::Application* pge::AppInit()
{
    return new Sandbox();
}