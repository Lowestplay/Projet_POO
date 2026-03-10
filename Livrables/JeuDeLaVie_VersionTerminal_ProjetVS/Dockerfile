# Image de base légère avec GCC
FROM alpine:latest

# Installation des outils de compilation
RUN apk add --no-cache g++ make

# Création du dossier de travail
WORKDIR /app

# Copie des fichiers du projet
COPY . .

# Compilation via le Makefile
RUN make

# Point d'entrée : lance le mode console par défaut avec un fichier test inclus
# (Assurez-vous d'avoir un fichier input.txt dans le dossier pour l'exemple)
ENTRYPOINT ["./jeu_de_la_vie_console"]
CMD ["--file=input.txt", "--mode=console", "--max-iters=100", "--toroidal=1"]