#include "../include/Application.hpp"
#include "../SfmlRenderer.hpp"
#include "../include/FileLoader.hpp"
#include "../include/FileWriter.hpp"
#include "../include/ConwayRuleSet.hpp"
#include <iostream>

/**
 * @brief Constructor implementation.
 * 
 * Initializes the application configuration based on command line arguments.
 * Sets the simulation step duration and cell size if provided in the configuration.
 */
Application::Application(int argc, char* argv[]) {
    m_config.parseArgs(argc, argv);
    if (m_config.stepMs > 0) m_stepMs = m_config.stepMs;
    if (m_config.cellSize > 0) m_cellSize = m_config.cellSize;
}

/**
 * @brief Main execution method.
 * 
 * Handles the following tasks:
 * 1. Initializes the grid (empty or loaded from file).
 * 2. Sets up the SFML window, game engine, and renderer.
 * 3. Configures the camera view.
 * 4. Runs the main game loop which includes:
 *    - Event handling (keyboard shortcuts, mouse interaction).
 *    - Logic updates (simulation steps).
 *    - Rendering (drawing the grid and HUD).
 */
void Application::run() {
    // Initialize Grid
    Grid currentGrid;
    if (!m_config.filePath.empty()) {
        try {
            currentGrid = FileLoader::loadFromFile(m_config.filePath);
        }
        catch (const std::exception& e) {
            std::cerr << "Erreur chargement: " << e.what() << "\nGrille vide par defaut.\n";
            currentGrid = Grid(100, 100);
        }
    }
    else {
        currentGrid = Grid(100, 100);
    }

    // Backup for Reset
    m_initialGrid = currentGrid.clone();

    // Window & Engine Setup
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Jeu de la Vie - Groupe 01");
    window.setFramerateLimit(60);

    GameEngine engine(currentGrid, std::make_unique<ConwayRuleSet>());
    SfmlRenderer renderer(window, m_cellSize);
    renderer.initialize(engine.getGrid());

    // Camera (View) Setup
    sf::View view = window.getDefaultView();
    float w = static_cast<float>(engine.getGrid().getCols() * m_cellSize);
    float h = static_cast<float>(engine.getGrid().getRows() * m_cellSize);
    view.setCenter(w / 2.0f, h / 2.0f);
    window.setView(view);

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    bool isPaused = true;

    // Main Loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();

            // Keyboard Handling
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                case sf::Keyboard::Space: isPaused = !isPaused; break;
                case sf::Keyboard::N:     engine.step(m_config.toroidal); break;
                case sf::Keyboard::G:     m_showGrid = !m_showGrid; break;
                case sf::Keyboard::T:     m_config.toroidal = !m_config.toroidal; break;
                case sf::Keyboard::C:
                    {
                        Grid empty(engine.getGrid().getRows(), engine.getGrid().getCols());
                        engine = GameEngine(empty, std::make_unique<ConwayRuleSet>());
                    }
                    break;
                case sf::Keyboard::R:
                    engine = GameEngine(m_initialGrid.clone(), std::make_unique<ConwayRuleSet>());
                    break;
                case sf::Keyboard::S:
                    FileWriter::write(engine.getGrid(), "Sauvegardes", engine.getIteration());
                    std::cout << "Etat sauvegarde dans le dossier Sauvegardes/\n";
                    break;
                case sf::Keyboard::Add:
                    if (m_stepMs > 10) m_stepMs -= 10;
                    break;
                case sf::Keyboard::Subtract:
                    m_stepMs += 10;
                    break;
                default: break;
                }
            }

            // Mouse Handling (Zoom & Pan)
            if (event.type == sf::Event::MouseWheelScrolled) {
                if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
                    float zoomFactor = (event.mouseWheelScroll.delta > 0) ? 0.9f : 1.1f;
                    view.zoom(zoomFactor);
                    window.setView(view);
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Right) {
                    m_isPanning = true;
                    m_lastMousePos = sf::Mouse::getPosition(window);
                }
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i cellPos = renderer.pixelToCell(sf::Mouse::getPosition(window));
                    engine.toggleCell(cellPos.y, cellPos.x);
                }
            }
            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Right) {
                    m_isPanning = false;
                }
            }
            if (event.type == sf::Event::MouseMoved) {
                if (m_isPanning) {
                    sf::Vector2i newMousePos = sf::Mouse::getPosition(window);
                    sf::Vector2f delta = window.mapPixelToCoords(m_lastMousePos) - window.mapPixelToCoords(newMousePos);
                    view.move(delta);
                    window.setView(view);
                    m_lastMousePos = newMousePos;
                }
            }
        }

        // Logic Update
        if (!isPaused) {
            timeSinceLastUpdate += clock.restart();
            sf::Time timePerFrame = sf::milliseconds(m_stepMs);

            while (timeSinceLastUpdate > timePerFrame) {
                timeSinceLastUpdate -= timePerFrame;
                engine.step(m_config.toroidal);
            }
        }
        else {
            clock.restart();
        }

        // Rendering
        window.clear(sf::Color(30, 30, 30));

        renderer.update(engine.getGrid());
        renderer.draw(m_showGrid);

        renderer.drawHUD(
            engine.getIteration(),
            engine.getGrid().countAlive(),
            m_stepMs,
            isPaused,
            m_config.toroidal
        );

        window.display();
    }
}