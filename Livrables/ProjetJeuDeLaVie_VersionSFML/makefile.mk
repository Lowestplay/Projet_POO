# Nom de l'exécutable final
TARGET = jeu_de_la_vie_sfml

# Compilateur et version C++ (C++20 obligatoire)
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Wpedantic -O3 -Iinclude

# Bibliothèques SFML à lier (Ordre important !)
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Dossiers
SRC_DIR = src
OBJ_DIR = obj

# Récupère tous les fichiers .cpp dans src/
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
# Transforme les chemins .cpp en .o dans le dossier obj/
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Règle par défaut
all: $(TARGET)

# Édition de liens (Création de l'exécutable)
$(TARGET): $(OBJS)
	@echo "Liaison de l'executable..."
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Compilation des fichiers objets (.cpp -> .o)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "Compilation de $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage
clean:
	@echo "Nettoyage..."
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean