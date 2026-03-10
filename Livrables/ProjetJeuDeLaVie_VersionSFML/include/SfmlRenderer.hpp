#pragma once
#include <SFML/Graphics.hpp>
#include "include/Grid.hpp"

/**
 * @brief Handles the graphical rendering of the game using SFML.
 * 
 * Manages the window drawing operations, including the grid of cells, grid lines,
 * and the Heads-Up Display (HUD) for game statistics.
 */
class SfmlRenderer {
public:
    /**
     * @brief Constructor.
     * 
     * @param window Reference to the SFML RenderWindow.
     * @param cellSize Size of each cell in pixels.
     */
    SfmlRenderer(sf::RenderWindow& window, int cellSize);

    /**
     * @brief Initializes the graphical resources.
     * 
     * Pre-calculates vertex arrays for cells and grid lines based on the grid dimensions.
     * 
     * @param grid The game grid to render.
     */
    void initialize(const Grid& grid);

    /**
     * @brief Updates the visual state of the cells.
     * 
     * Updates the color of each cell vertex based on the grid's current state.
     * Optimized to only update colors, not positions.
     * 
     * @param grid The current game grid.
     */
    void update(const Grid& grid);

    /**
     * @brief Draws the game scene.
     * 
     * @param drawGridLines If true, draws the grid lines overlay.
     */
    void draw(bool drawGridLines);

    /**
     * @brief Draws the Heads-Up Display (HUD).
     * 
     * Displays information like generation count, population, speed, and controls.
     * 
     * @param generation Current iteration number.
     * @param population Number of alive cells.
     * @param speedMs Current simulation speed in milliseconds.
     * @param paused Whether the simulation is paused.
     * @param toroidal Whether toroidal mode is active.
     */
    void drawHUD(int generation, int population, int speedMs, bool paused, bool toroidal);

    /**
     * @brief Converts screen pixel coordinates to grid cell coordinates.
     * 
     * Handles camera transformations (zoom/pan) to find which cell is under the mouse.
     * 
     * @param pixelPos Mouse position in window coordinates.
     * @return The grid coordinates (column, row) as a Vector2i.
     */
    sf::Vector2i pixelToCell(sf::Vector2i pixelPos) const;

private:
    sf::RenderWindow& m_window;     ///< Reference to the render window.
    sf::VertexArray m_vertices;     ///< Vertex array for drawing cells (Quads).
    sf::VertexArray m_gridLines;    ///< Vertex array for drawing grid lines (Lines).
    int m_cellSize;                 ///< Size of a cell in pixels.

    sf::Font m_font;                ///< Font for text rendering.
    sf::Text m_textInfo;            ///< Text object for the HUD.

    sf::Color m_colorAlive = sf::Color::White;       ///< Color of alive cells.
    sf::Color m_colorDead = sf::Color(20, 20, 20);   ///< Color of dead cells.
};
