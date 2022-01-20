# Travaux pratiques Géométrie Numérique 2022 : starter-kit

Nous vous proposons ce starter-kit pour les TPs de Géométrie Numérique pour que vous puissiez focaliser votre travail sur les parties essentielles du cours et éviter facilement les embûches liées à la compilation et autres détails qui mettent souvent des batons dans les roues lors du démarage d'un projet.

Dans cette série de TP, nous nous concentrons sur la manipulation des maillages et des principaux algorithmes de traitement.
Le travail demandé sera réalisé en C++, sans toutefois nécessiter de notions avancées du language.
Vous serez amenés à utiliser la bibliothèque C++ PMP (Polygon Mesh Processing).

Notre série de 4 TP sera suivie d'un projet étudiant à réaliser et dont le sujet vous sera donné lors d'une séance de cours ultérieure.
Vous mettrez ainsi en application vos compétences acquises lors des TPs encadrés pour réaliser une application complète autour d'un thème encore non exploré en cours.

> **Note :** certains accents ont disparus des titres de sections de ce document... Ces fautes d'orthographes **sont intentionelles** et permettent d'utiliser des liens vers des ancres en markdown.

## Vue d'ensemble

Cette série de TP se veut progressive et essaie de suivre une logique dans la création d'outils de base pour vos futurs projets.
- **[Séance 1 :](tps/enonces/tp1.md)** Prise en main du starter-kit, recherche de documentation, parcours de la structure en demi-arêtes du module *core* de PMP, et aperçu du module *visualization* de PMP
- **[Séance 2 :](tps/enonces/tp2.md)** Recherche de documentation, exploration du module *algorithms* de PMP (1/3)
- **Séance 3:** Algorithmes de remaillage et module *algorithms* de PMP (2/3)
- **Séance 4:** Algorithmes de simplification et module *algorithms* de PMP (3/3)

## A faire dans l'ordre

Pour réaliser ces TPs nous vous conseillons, dans l'ordre, de:
1. Lire ce README (on ne le dira jamais assez, les README sont faits pour être lus :) ). Il vous donne la marche à suivre pour mettre en place votre environnement de développement (compiler PMP, configurer votre projet de TPs avec CMake, et compiler les sources de vos TPs).
1. Lire la fiche du TP correspondant à la séance courante dans le dossier `tps/enonces/` et faire les exercices demandés. Un squelette de code vous est fourni pour chaque TP dans les dossiers `tps/src`, `tps/include`, et `tps/apps` dans lesquels les parties à remplir sont identifiées par le commentaire suivant :
    ```
    /* ! STUDENTS TODO ! */
    ```
    > **Note :** Au besoin vous pouvez utiliser **(Unix/Linux/macOs uniquement)** la commande suivante à partir de la racine du pojet pour repérer ces commentaires :
    >```
    >grep --line-number -r "/\* \! STUDENTS TODO \! \*/" ./tps/
    >```
    > Vous pouvez par exemple utiliser un pipe pour n'afficher que les résultats inclus dans le tp de votre choix. Par exemple, pour l'exercice 1 du tp 1 :
    >```
    >grep --line-number -r "/\* \! STUDENTS TODO \! \*/" ./tps/ | grep tp1_ex1
    >```
    >Renvera :
    >```
    >./tps/src/tp1_ex1_tools.cpp:6:    /* ! STUDENTS TODO ! */
    >./tps/src/tp1_ex1_tools.cpp:13:    /* ! STUDENTS TODO ! */
    >./tps/src/tp1_ex1_tools.cpp:20:    /* ! STUDENTS TODO ! */
    >./tps/src/tp1_ex1_tools.cpp:27:    /* ! STUDENTS TODO ! */
    >./tps/src/tp1_ex1_tools.cpp:34:    /* ! STUDENTS TODO ! */
    >```
    > Où vous lirez les numéros de lignes après les ":" suivant le nom de fichier

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

2. Exécuter cmake pour configurer le projet
   ``` bash
   cmake -S ../ -B ./ -D BUILD_STUDENTS=TRUE
   ```
   Détails :
   - on appelle cmake (outil qui nous simplifie les compilations)
   - en spécifiant avec `-S` ou se trouve le fichier `CMakeLists.txt` qui contient la configuration du projet
   - en spécifiant avec `-B` dans quel dossier compiler le projet
   - en spécifiant avec `-D` la valeur de l'option de compilation nommée `BUILD_STUDENTS`.
   Pour info :
   - vous pouvez également compiler les corrections en ajoutant aussi l'option `-D BUILD_CORRECTIONS=TRUE`.
   - si votre CPU dispose de plusieurs coeurs, vous pouvez les utiliser pour paralléliser la compilation en ajoutant l'option `-j8` (remplacer 8 par le nombre de coeurs que vous souhaitez utiliser).
 
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

Plusieurs informations concernant la structure de ce starter-kit vous ont été dévoilées dans ce README.
Cette section reprends les points essentiels pour que vous puissiez chercher et trouver les fichiers qui vous sont d'intérêt.

A la racine de ce dépôt vous trouverez 5 fichiers :
- ***CMakeLists.txt*** : contient les éléments nécessaires à la configuration du projet de TP de Géométrie Numérique. Vous ne devriez pas avoir à y toucher, mais vous pouvez toujours expérimenter dessus.
- ***.gitignore*** : fichier utilisé par git pour ignorer certains fichiers/dossiers. Permet d'éviter des ajouts de dossiers de build au dépôt par exemple. Vous n'avez pas à vous en occuper.
- ***.gitlab-ci.yml*** : fichier utilisé par gitlab pour l'intégration continue. Vous n'avez pas à vous en occuper.
- ***.gitmodules*** : fichier utilisé par git pour la gestion des sous-modules (pmp a été ajouté comme sous-module de ce dépôt). Vous n'avez pas à vous en occuper.
- ***README.md*** : le README que vous êtes en train de parcourir.

Vous trouverez également 5 dossiers :
- ***data/*** : contient quelques maillages exemples sur lesquels tester vos programmes.
- ***externals/*** : contient les bibliothèques externes; en l'occurrence : PMP et ses dépendances.
- ***.git/*** : dossier réservé à git pour la gestion de versions.
- ***override_pmp_files/*** : contient des fichiers de remplacement pour la bibliothèque PMP.
- ***tps/*** : le coeur de ce starter-kit ! C'est ici que vous allez travailler principalement ! Vous y trouverez les énnoncés et des propositions de corrections dans les dossiers correspondants, et vous aurez à terminer le code des fichiers situés dans les sous-répertoires `include`, `src` et `apps`.

## Ajout de code source

Il vous est possible d'ajouter du code de votre côté, en particulier du code "outil" dans les dossiers `geometrie_numerique_tps/tps/include/` et `geometrie_numerique_tps/tps/src/` pour les en-têtes (headers) et les sources respectivement.
Pour que vos fichiers additionnels soient compilés et liés à votre programme vous devrez cependant respecter une règle (simple !) :
le nom de vos fichiers additionnels (dans `src` et `include`) doit commencer comme le nom du fichier contenant votre main (dans `apps`).

> **Note :** ne pas oublier de reconfigurer le projet avec `cmake -S ../ -B ./`, puis de le recompiler avec `cmake --build ./` à chaque ajout de nouveau fichier.