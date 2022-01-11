# Travaux pratiques Géométrie Numérique 2021 : starter-kit

Nous vous proposons ce starter-kit pour les TPs de Géométrie Numérique pour que vous puissiez focaliser votre travail sur les parties essentielles du cours et éviter facilement les embûches liées à la compilation et autres détails qui mettent souvent des batons dans les roues lors du démarage d'un projet.

Dans cette série de TP, nous nous concentrons sur la manipulation des maillages et des principaux algorithmes de traitement.
Le travail demandé sera réalisé en C++, sans toutefois nécessiter de notions avancées du language.
Vous serez amenés à utiliser la bibliothèque C++ PMP (Polygon Mesh Processing).

Notre série de 4 TP sera suivie d'un projet étudiant à réaliser et dont le sujet vous sera donné lors d'une séance de cours ultérieure.
Vous mettrez ainsi en application vos compétences acquises lors des TPs encadrés pour réaliser une application complète autour d'un thème encore non exploré en cours.

> **Note :** certains accents ont disparus des titres de sections de ce document... Ces fautes d'orthographes **sont intentionelles** et permettent d'utiliser des liens vers des ancres en markdown.

## Vue d'ensemble

Cette série de TP se veut progressive et essaie de suivre une logique dans la création d'outils de base pour vos futurs projets.
- **[Séance 1 :](tps/ennonces/tp1.md)** Prise en main du starter-kit, recherche de documentation, parcours de la structure en demi-arêtes du module *core* de PMP, et aperçu du module *visualization* de PMP
- **[Séance 2 :](tps/ennonces/tp2.md)** Recherche de documentation, exploration du module *algorithms* de PMP
- **Séance 3:** Algorithmes de remaillage
- **Séance 4:** Algorithmes de simplification

## A faire dans l'ordre

Pour réaliser ces TPs nous vous conseillons, dans l'ordre, de:
1. Lire ce README (on ne le dira jamais assez, les README sont faits pour être lus :) ). Il vous donne la marche à suivre pour mettre en place votre environnement de développement (compiler PMP, configurer votre projet de TPs avec CMake, et compiler les sources de vos TPs).
1. Lire la fiche du TP correspondant à la séance courante dans le dossier `tps/ennonces/` et faire les exercices demandés. Un squelette de code vous est fourni pour chaque TP dans les dossiers `tps/src`, `tps/include`, et `tps/apps` dans lesquels les parties à remplir sont identifiées par le commentaire suivant :
    ```
    /* ! STUDENTS TODO ! */
    ```
    > **Note :** Au besoin vous pouvez utiliser **(Unix/Linux/macOs uniquement)** la commande suivante à partir de la racine du pojet pour repérer ces commentaires :
    ```
    grep -r "/\* \! STUDENTS TODO \! \*/" ./tps/
    ```

3. **Linux uniquement (pour le moment) :** Vous pouvez avoir un aperçu de ce qu'on attend de vous en exécutant les programmes précompilés situés dans `tps/corrections/bin/`
4. Des propositions de corrections sont disponibles dans les dossiers `tps/corrections/src/`, `tps/corrections/include/` et `tps/corrections/apps/`

# Comment utiliser ce starter-kit :

## Prérequis :
1. Avoir installé git
1. Avoir installé cmake
1. Avoir un compilateur c++
1. Avoir installé OpenGL

## Etapes :

L'utilisation de ce starter-kit passe par trois étapes principales qui sont décrites plus en détails dans les sections suivantes :

1. [Récupérer le code source (et le modifier légèrement)](#recuperer-le-code-souce-et-le-modifier)
1. [Compiler la bibliothèque externe PMP](#compiler-la-bibliotheque-externe-pmp)
1. [Compiler le code source du starter-kit](#compiler-le-code-source-du-starter-kit)

A ces étapes s'ajoutent des [étapes nécessaires](#etendre-ce-starter-kit) avant chaque nouveau tp :

1. Mettre à jour le projet
1. Compiler le(s) code(s) source(s) des tps additionnels

> **Note :** Pour les utilisateurs de Windows, la commande `cmake` sera remplacée par la commande `cmake.exe`

# Recuperer le code souce et le modifier

1. Cloner le dépôt git de ce starter-kit dans un dossier nommé `geometrie_numerique_tps` :
   ``` bash
   git clone https://git.unistra.fr/ravaglia/tp_geometrie_numerique_m1_students_starter_kit.git ./geometrie_numerique_tps
   ```
1. Se déplacer dans le répertoire créé:
    ``` bash
    cd ./geometrie_numerique_tps
    ```  
1. Ce projet inclut la librairie pmp en tant que sous-module, il faut donc également récupérer ce sous-module (et ses sous modules également) via :
    ``` bash
    git submodule update --init --recursive
    ```

1. Remplacer le fichier `externals/pmp-library/src/pmp/visualiszation/SurfaceMeshGL.cpp` par le fichier `override_pmp_files/SurfaceMeshGL.cpp` :
    ```bash
    cp override_pmp_files/SurfaceMeshGL.cpp externals/pmp-library/src/pmp/visualization/SurfaceMeshGL.cpp
    ```
# Compiler la bibliotheque externe PMP

## A savoir avant de continuer

Pour les utilisateurs de MinGW, il sera peut être nécessaire d'ajouter la ligne `target_link_libraries(pmp OpenMP::OpenMP_CXX)` au fichier `extertnals/pmp-library/src/pmp/CMakeLists.txt`.
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

# Compiler le code source du starter-kit

1. A la racine du projet (dans `geometrie_numerique_tps`), créer un dossier `build` et s'y déplacer :
   ``` bash
   cd ../../../
   mkdir build
   cd build
   ```

2. Appeler cmake :
   ``` bash
   cmake -S ../ -B ./
   ```
 
3. Compiler le starter-kit :
   ``` bash
   cmake --build ./
   ```

> Note: Si vous rencontrez des problèmes de compilation par la suite, c'est peut être du à une ancienne version de PMP. Dans ce cas, déplacez vous à la racone du projet et utilisez :
    ```
    git submodule update --remote --merge
    ```
avant de reprendre toutes les étapes de compilation (PMP + TP de Géométrie Numérique).

# Etendre ce starter-kit

## Structure du projet

## Ajout de code source

Il vous est possible d'ajouter du code de votre côté, en particulier du code "outil" dans les dossiers `geometrie_numerique_tps/tps/include/` et `geometrie_numerique_tps/tps/src/` pour les en-têtes (headers) et les sources respectivement.
Tous les fichiers dans ces dossiers seront automatiquement compilés et liés aux programmes principaux placés dans le dossier `geometrie_numerique_tps/tps/apps/`.

Il vous est aussi possible d'ajouter autant de programmes principaux que vous le souhaitez dans le dossier `geometrie_numerique_tps/tps/apps/`. Ceux-ci seront automatiquement compilés par la suite.

> **Note :** ne pas oublier de reconfigurer le projet avec `cmake -S ../ -B ./`, puis de le recompiler avec `cmake --build ./` à chaque ajout de nouveau fichier.