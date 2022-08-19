#pragma once

extern pge::Application* pge::AppInit();

int main(int argc, char** argv)
{
    auto app = pge::AppInit();
    app->_MainLoop();

    delete app;
    return 0;
}