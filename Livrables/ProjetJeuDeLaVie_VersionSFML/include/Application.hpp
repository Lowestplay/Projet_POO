#pragma once
#include "Config.hpp"
#include "GameEngine.hpp"
#include <SFML/Graphics.hpp>

/**
 * @brief Main application class that manages the game loop and user interaction.
 * 
 * This class is responsible for initializing the game, handling user input (keyboard and mouse),
 * managing the rendering window, and executing the main simulation loop.
 */
class Application {
public:
    /**
     * @brief Constructor for the Application class.
     * 
     * Parses command line arguments to configure the application settings.
     * 
     * @param argc Number of command line arguments.
     * @param argv Array of command line arguments.
     */
    Application(int argc, char* argv[]);

    /**
     * @brief Starts the main application loop.
     * 
     * This method initializes the grid, window, and renderer, and enters the game loop
     * where events are polled, logic is updated, and the scene is rendered.
     */
    void run();

private:
    Config m_config;             ///< Configuration settings loaded from arguments.
    Grid m_initialGrid;          ///< Backup of the initial grid state for resetting.
    bool m_showGrid = true;      ///< Flag to toggle grid lines visibility.
    bool m_isPanning = false;    ///< Flag indicating if the camera is currently being panned.
    sf::Vector2i m_lastMousePos; ///< Last recorded mouse position for panning calculations.
    int m_cellSize = 10;         ///< Size of a single cell in pixels.
    int m_stepMs = 100;          ///< Time interval between simulation steps in milliseconds.
};
