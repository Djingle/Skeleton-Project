# Travaux pratiques Géométrie Numérique 2021 : starter kit

Travaux pratiques pour le cours de géométrie numérique de Master 1 de l'Université de Strasbourg (2021)

# IMPORTANT : 

Peut être utile:
```
git submodule update --remote --merge
```

# Comment utiliser ce starter kit :

## Prérequis :
1. Avoir installé git
1. Avoir installé cmake
1. Avoir un compilateur c++
1. Avoir installé OpenGL

> Note : Pour les utilisateurs de Windows, la commande `cmake` sera remplacée par la commande `cmake.exe`

## Etapes :

L'utilisation de ce starter kit passe par trois étapes principales qui sont décrites plus en détails dans les sections suivantes :

1. Récupérer le code source
1. Compiler la bibliothèque externe PMP
1. Compiler le code source du starter kit

A ces étapes s'ajoutent des étapes nécessaires avant chaque nouveau tp :

1. Mettre à jour le projet
1. Compiler le(s) code(s) source(s) des tps additionnels

# Récupérer le code souce

1. Cloner le dépôt git de ce starter kit dans un dossier nommé `geometrie_numerique_tps` :
   ``` bash
   git clone https://git.unistra.fr/ravaglia/tp_geometrie_numerique_m1_students_starter_kit.git ./geometrie_numerique_tps
   ```
2. Se déplacer dans le répertoire créé:
    ``` bash
    cd ./geometrie_numerique_tps
    ```  
3. Ce projet inclut la librairie pmp en tant que sous-module, il faut donc également récupérer ce sous-module (et ses sous modules également) via :
    ``` bash
    git submodule update --init --recursive
    ```

# Compiler la bibliothèque externe PMP :

## A savoir

---
**Important**

Pour les utilisateurs de MinGW, il est nécessaire d'ajouter la ligne `target_link_libraries(pmp OpenMP::OpenMP_CXX)` a la ligne 24 du fichier `extertnals/pmp-library/src/pmp/CMakeLists.txt`.
Le fichier doit alors ressembler à :
```
[...]
if (WIN32 OR EMSCRIPTEN)
  add_library(pmp STATIC ${SOURCES} ${HEADERS} $<TARGET_OBJECTS:rply>)
elseif(UNIX)
  add_library(pmp SHARED ${SOURCES} ${HEADERS} $<TARGET_OBJECTS:rply>)
endif()

target_link_libraries(pmp OpenMP::OpenMP_CXX)

set_target_properties(pmp PROPERTIES VERSION ${PMP_VERSION})
[...]
```
---

## Compilation étape par étape

1. A la racine de la librairie pmp (`geometrie_numerique_tps/externals/pmp-library/`), créer un dossier `build` et s'y déplacer :
   ``` bash
   cd ./externals/pmp-library/
   mkdir build
   cd build
   ```

2. Exécuter cmake pour configurer le projet
   ``` bash
   cmake -S ../ -B ./
   ```

3. Compiler la bibliothèque pmp:
    ``` bash
    cmake --build ./
    ```

# Compiler le code source du starter kit :

1. A la racine du projet (dans `geometrie_numerique_tps`), créer un dossier `build` et s'y déplacer
   ``` bash
   cd ../../../
   mkdir build
   cd build
   ```

2. Appeler cmake
   ``` bash
   cmake -S ../ -B ./
   ```
 
3. Compiler le starter kit
   ``` bash
   cmake --build ./
   ```

# Etendre ce starter kit :

Il vous est possible d'ajouter du code de votre côté, en particulier du code "outil" dans les dossiers `geometrie_numerique_tps/tps/include/` et `geometrie_numerique_tps/tps/src/` pour les en-têtes (headers) et les sources respectivement.
Tous les fichiers dans ces dossiers seront automatiquement compilés et liés aux programmes principaux placés dans le dossier `geometrie_numerique_tps/tps/apps/`.

Il vous est aussi possible d'ajouter autant de programmes principaux que vous le souhaitez dans le dossier `geometrie_numerique_tps/tps/apps/`. Ceux-ci seront automatiquement compilés par la suite.

> Note : ne pas oublier de reconfigurer le projet avec `cmake -S ../ -B ./`, puis de le recompiler avec `cmake --build ./` à chaque ajout de nouveau fichier.