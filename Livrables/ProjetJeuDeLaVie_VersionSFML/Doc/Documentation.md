# Documentation du Projet : Jeu de la Vie (Version SFML)

## Vue d'ensemble
Ce projet est une implémentation du "Jeu de la Vie" de Conway en C++ utilisant la bibliothèque SFML pour le rendu graphique. Il supporte également un mode console et diverses fonctionnalités comme le chargement/sauvegarde de grilles, le mode torique, et l'interaction à la souris.

## Structure du Projet

### Core (Cœur du jeu)
- **Application** (`include/Application.hpp`, `src/Application.cpp`) : Classe principale qui gère la boucle de jeu, les événements (clavier/souris) et l'orchestration des composants.
- **GameEngine** (`include/GameEngine.hpp`, `src/GameEngine.cpp`) : Moteur de jeu qui gère l'état de la simulation (grille courante, itérations) et applique les règles.
- **Grid** (`include/Grid.hpp`, `src/Grid.cpp`) : Représente la grille de jeu composée de cellules. Gère la mémoire et l'accès aux cellules.
- **Cell** (`include/Cell.hpp`, `src/Cell.cpp`) : Représente une cellule individuelle (vivante ou morte).

### Règles
- **RuleSet** (`include/RuleSet.hpp`) : Interface abstraite pour définir des règles de jeu.
- **ConwayRuleSet** (`include/ConwayRuleSet.hpp`, `src/ConwayRuleSet.cpp`) : Implémentation des règles classiques de Conway.
- **Neighborhood** (`include/Neighborhood.hpp`, `src/Neighborhood.cpp`) : Utilitaire pour calculer le voisinage d'une cellule (supporte le mode torique).

### Rendu
- **SfmlRenderer** (`SfmlRenderer.hpp`, `SfmlRenderer.cpp`) : Gère l'affichage graphique avec SFML (cellules, grille, HUD).
- **ConsoleRenderer** (`include/ConsoleRenderer.hpp`, `src/ConsoleRenderer.cpp`) : Gère l'affichage textuel dans la console (pour débogage ou mode sans tête).

### Utilitaires / IO
- **Config** (`include/Config.hpp`, `src/Config.cpp`) : Gère la configuration de l'application via les arguments de ligne de commande.
- **FileLoader** (`include/FileLoader.hpp`, `src/FileLoader.cpp`) : Permet de charger une configuration initiale de grille depuis un fichier texte.
- **FileWriter** (`include/FileWriter.hpp`, `src/FileWriter.cpp`) : Permet de sauvegarder l'état actuel de la grille dans un fichier texte.

## Compilation et Exécution
Le projet utilise CMake (ou un Makefile selon la configuration) et dépend de la bibliothèque SFML.

### Commandes Clavier
- **Espace** : Mettre en pause / Reprendre la simulation.
- **N** : Avancer d'un pas (si en pause).
- **R** : Réinitialiser la grille à son état initial.
- **C** : Effacer la grille (toutes les cellules mortes).
- **S** : Sauvegarder l'état courant dans un fichier.
- **G** : Afficher / Masquer la grille.
- **T** : Activer / Désactiver le mode torique.
- **+ / -** : Augmenter / Diminuer la vitesse de simulation.

### Commandes Souris
- **Clic Gauche** : Dessiner / Effacer une cellule (toggle).
- **Clic Droit + Glisser** : Déplacer la caméra (Pan).
- **Molette** : Zoom avant / arrière.

## Arguments de Ligne de Commande
- `--file=<path>` : Charger une grille depuis un fichier.
- `--max-iters=<int>` : Nombre maximum d'itérations (utile pour le mode console).
- `--toroidal=<1|0>` : Activer le mode torique par défaut.
- `--step-ms=<int>` : Temps en millisecondes entre chaque étape.
- `--cell-size=<int>` : Taille des cellules en pixels.

## Format de Fichier
Les fichiers de grille doivent suivre le format suivant :
```
Lignes Colonnes
etat_cellule_0_0 etat_cellule_0_1 ...
...
```
Où `etat_cellule` est `1` (vivante) ou `0` (morte).
