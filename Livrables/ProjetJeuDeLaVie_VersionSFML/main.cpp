#include "include/Application.hpp"

/**
 * @brief Entry point of the application.
 * 
 * Creates an Application instance and starts the run loop.
 * 
 * @param argc Argument count.
 * @param argv Argument values.
 * @return Exit code (0 for success).
 */
int main(int argc, char* argv[]) {
    Application app(argc, argv);
    app.run();
    return 0;
}
