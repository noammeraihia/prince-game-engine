#include <stdio.h>
#include <PGE/pge.h>

class Sandbox : public pge::Application
{
public:
    Sandbox()
    {
        pge::Logger::Init();
    }

    ~Sandbox()
    {

    }

    void Run()
    {
        pge::Logger::Log(pge::PGELLVL_FATAL, "Test Fatal\n");
        pge::Logger::Log(pge::PGELLVL_ERROR, "Test Error\n");
        pge::Logger::Log(pge::PGELLVL_INFO, "Test Info\n");
        pge::Logger::Log(pge::PGELLVL_WARN, "Test Warn\n");
        pge::Logger::Log(pge::PGELLVL_DEBUG, "Test Debug\n");
    }
};

pge::Application* pge::AppInit()
{
    return new Sandbox();
}