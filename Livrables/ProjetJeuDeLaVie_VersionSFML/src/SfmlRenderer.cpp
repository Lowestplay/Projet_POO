#include "SfmlRenderer.hpp"
#include <iostream>
#include <sstream>

/**
 * @brief Constructor implementation.
 * 
 * Initializes vertex arrays and attempts to load a font for the HUD.
 * Tries multiple common font paths (Windows system fonts, local file).
 */
SfmlRenderer::SfmlRenderer(sf::RenderWindow& window, int cellSize)
    : m_window(window), m_cellSize(cellSize) {

    m_vertices.setPrimitiveType(sf::Quads);
    m_gridLines.setPrimitiveType(sf::Lines);

    bool success = false;

    // Try loading Arial from Windows fonts
    if (m_font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")) {
        success = true;
    }
    // Fallback to Segoe UI
    else if (m_font.loadFromFile("C:\\Windows\\Fonts\\segoeui.ttf")) {
        success = true;
    }
    // Fallback to local file
    else if (m_font.loadFromFile("arial.ttf")) {
        success = true;
    }

    if (!success) {
        std::cerr << "!!! ERREUR FATALE : Impossible de charger une police !!!\n";
    }

    m_textInfo.setFont(m_font);
    m_textInfo.setCharacterSize(16);
    m_textInfo.setFillColor(sf::Color::White);
    m_textInfo.setPosition(10.f, 10.f);
}

/**
 * @brief Initializes grid geometry.
 * 
 * Sets up the vertices for all cells and the grid lines.
 */
void SfmlRenderer::initialize(const Grid& grid) {
    int rows = grid.getRows();
    int cols = grid.getCols();

    // Initialize cell vertices
    m_vertices.resize(static_cast<size_t>(rows) * cols * 4);

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            size_t idx = (static_cast<size_t>(r) * cols + c) * 4;
            float x = static_cast<float>(c * m_cellSize);
            float y = static_cast<float>(r * m_cellSize);
            float s = static_cast<float>(m_cellSize);

            m_vertices[idx + 0].position = sf::Vector2f(x, y);
            m_vertices[idx + 1].position = sf::Vector2f(x + s, y);
            m_vertices[idx + 2].position = sf::Vector2f(x + s, y + s);
            m_vertices[idx + 3].position = sf::Vector2f(x, y + s);
        }
    }

    // Initialize grid lines
    m_gridLines.clear();
    sf::Color gridColor(50, 50, 50);

    // Vertical lines
    for (int c = 0; c <= cols; ++c) {
        float x = static_cast<float>(c * m_cellSize);
        float h = static_cast<float>(rows * m_cellSize);
        m_gridLines.append(sf::Vertex(sf::Vector2f(x, 0.f), gridColor));
        m_gridLines.append(sf::Vertex(sf::Vector2f(x, h), gridColor));
    }
    // Horizontal lines
    for (int r = 0; r <= rows; ++r) {
        float y = static_cast<float>(r * m_cellSize);
        float w = static_cast<float>(cols * m_cellSize);
        m_gridLines.append(sf::Vertex(sf::Vector2f(0.f, y), gridColor));
        m_gridLines.append(sf::Vertex(sf::Vector2f(w, y), gridColor));
    }
}

/**
 * @brief Updates cell colors.
 */
void SfmlRenderer::update(const Grid& grid) {
    int rows = grid.getRows();
    int cols = grid.getCols();

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            size_t idx = (static_cast<size_t>(r) * cols + c) * 4;
            sf::Color color = grid.getCell(r, c).isAlive() ? m_colorAlive : m_colorDead;

            m_vertices[idx + 0].color = color;
            m_vertices[idx + 1].color = color;
            m_vertices[idx + 2].color = color;
            m_vertices[idx + 3].color = color;
        }
    }
}

/**
 * @brief Draws the scene.
 */
void SfmlRenderer::draw(bool drawGridLines) {
    m_window.draw(m_vertices);
    if (drawGridLines) {
        m_window.draw(m_gridLines);
    }
}

/**
 * @brief Draws the HUD.
 * 
 * Uses a fixed view to ensure the HUD stays on screen regardless of camera movement.
 */
void SfmlRenderer::drawHUD(int generation, int population, int speedMs, bool paused, bool toroidal) {
    std::stringstream ss;

    ss << "Etat : " << (paused ? "PAUSE (Espace)" : "EN COURS") << "\n"
        << "Gen : " << generation << " | Pop : " << population << "\n"
        << "Vitesse : " << speedMs << "ms (Touche +/-)\n"
        << "Mode Torique : " << (toroidal ? "ON" : "OFF") << " (Touche T)\n"
        << "Grille (G) | Reset (R) | Clear (C) | Save (S)";

    m_textInfo.setString(ss.str());

    sf::View gameView = m_window.getView();
    m_window.setView(m_window.getDefaultView());

    sf::FloatRect bounds = m_textInfo.getGlobalBounds();
    sf::RectangleShape bg(sf::Vector2f(bounds.width + 20.f, bounds.height + 20.f));
    bg.setFillColor(sf::Color(0, 0, 0, 150));
    m_window.draw(bg);

    m_window.draw(m_textInfo);

    m_window.setView(gameView);
}

/**
 * @brief Converts pixel to cell coordinates.
 */
sf::Vector2i SfmlRenderer::pixelToCell(sf::Vector2i pixelPos) const {
    sf::Vector2f worldPos = m_window.mapPixelToCoords(pixelPos);

    int c = static_cast<int>(worldPos.x / m_cellSize);
    int r = static_cast<int>(worldPos.y / m_cellSize);

    return sf::Vector2i(c, r);
}
