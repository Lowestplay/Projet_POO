# Nom de l'exécutable
TARGET = jeu_de_la_vie_console

# Compilateur et options (C++20 obligatoire)
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Wpedantic -O3

# Dossiers (Ajustez si vos fichiers sont ailleurs)
SRC_DIR = src
OBJ_DIR = obj

# Trouve tous les fichiers .cpp
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Règle par défaut
all: $(TARGET)

# Édition de lien
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilation des objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean
