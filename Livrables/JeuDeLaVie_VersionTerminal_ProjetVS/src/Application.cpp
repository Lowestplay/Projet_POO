#include "../include/Application.hpp"
#include "../include/FileLoader.hpp"
#include "../include/FileWriter.hpp"
#include "../include/ConsoleRenderer.hpp"
#include "../include/ConwayRuleSet.hpp"
#include <thread>
#include <chrono>
#include <iostream>

Application::Application(int argc, char* argv[]) {
    m_config.parseArgs(argc, argv);
}

void Application::run() {
    if (m_config.filePath.empty()) {
        std::cerr << "Erreur : Fichier d'entrée manquant (--file=PATH)\n";
        return;
    }

    try {
        // 1. Chargement
        std::cout << "Chargement de " << m_config.filePath << "...\n";
        Grid initialGrid = FileLoader::loadFromFile(m_config.filePath);

        // 2. Init Moteur
        GameEngine engine(initialGrid, std::make_unique<ConwayRuleSet>());

        // 3. Boucle de simulation
        std::cout << "Debut simulation | Max Iters: " << m_config.maxIterations
            << " | Toroidal: " << (m_config.toroidal ? "OUI" : "NON") << "\n";

        for (int i = 0; i < m_config.maxIterations; ++i) {
            // Affichage
            ConsoleRenderer::printGrid(engine.getGrid());
            ConsoleRenderer::printStats(engine.getIteration(), engine.getGrid().countAlive());

            // Sauvegarde
            FileWriter::write(engine.getGrid(), m_config.outputFolder, engine.getIteration());

            // Simulation d'une étape
            engine.step(m_config.toroidal);

            // --- CORRECTION MAJEURE ICI ---
            // On vérifie si la grille est stable APRES l'étape
            if (engine.isStable()) {
                std::cout << "=== STABILITE ATTEINTE a l'iteration " << engine.getIteration() << " ===\n";
                std::cout << "La grille ne change plus. Arret premature.\n";
                break; // On sort de la boucle for
            }
            // ------------------------------

            // Petit délai pour l'animation
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Erreur critique : " << e.what() << "\n";
    }
}
