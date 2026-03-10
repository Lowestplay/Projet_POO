#pragma once
#include "../include/Grid.hpp"
#include <string>

class FileLoader {
public:
    // Charge une grille depuis un fichier texte formaté.
    static Grid loadFromFile(const std::string& path);
};
