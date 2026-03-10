#pragma once
#include "../include/Config.hpp"
#include "../include/GameEngine.hpp"

class Application {
public:
    Application(int argc, char* argv[]);
    void run();

private:
    Config m_config;
};
