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
        
    }
};

pge::Application* pge::AppInit()
{
    return new Sandbox();
}