# skeleton_project

## Présentation du projet :

Dans le cardre de l'UE de géométrie numérique, M. Franck Hétroy-Wheeler joue le 
rôle d'un client ayant contacté notre groupe, afin de créer et de fournir un
programme estimant s'il est prudent d'imprimer un certain modèle 3D. Pour ce
faire, nous devrons développer un programme déterminant le squelette du modèle
3D afin de voir où il y a des fragilités. Nous utiliserons pour ça la librairie
PMP.

## Membres du groupe :

**Chef de projet :** Bryan Emery

* Bryan Emery
* Grégory Horny
* Paul Labaye
* Titouan Laurent
* Vinojan Rajendiran

## Prérequis :

1. Avoir installé git
1. Avoir installé cmake
1. Avoir un compilateur c++
1. Avoir installé OpenGL

## Etapes :

L'installation se fait en 3 étapes :

1. [Récupérer le code source (et le modifier légèrement)](#recuperer-le-code-souce-et-le-modifier)
1. [Compiler la bibliothèque externe PMP](#compiler-la-bibliotheque-externe-pmp)
1. [Compiler le code source du starter-kit](#compiler-le-code-source-du-starter-kit)

> **Note :** Pour les utilisateurs de Windows, la commande `cmake` sera remplacée par la commande `cmake.exe`

# Clone du dépôt git

```bash
git clone https://git.unistra.fr/bemery/skeleton_project.git

cd ./skeleton_project

git submodule update --init --recursive
```

1. Remplacer le fichier `externals/pmp-library/src/pmp/visualiszation/SurfaceMeshGL.cpp` par le fichier `override_pmp_files/SurfaceMeshGL.cpp` :

   ```bash
   cp override_pmp_files/SurfaceMeshGL.cpp externals/pmp-library/src/pmp/visualization/SurfaceMeshGL.cpp
   ```

1. Remplacer le fichier `externals/pmp-library/src/pmp/algorithms/SurfaceSmoothing.h` par le fichier `override_pmp_files/SurfaceSmoothing.h` :
   ```
   cp override_pmp_files/SurfaceSmoothing.h externals/pmp-library/src/pmp/algorithms/SurfaceSmoothing.h
   ```

# Compiler la bibliotheque externe PMP

## A savoir avant de continuer :

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

## Compilation pmp :

```bash
cd ./externals/pmp-library/
mkdir build
cd build
cmake -S ../ -B ./
cmake --build ./
```

# Compiler le code source du starter-kit

1. A la racine du projet (dans `geometrie_numerique_tps`), créer un dossier `build` et s'y déplacer :

   ```bash
   cd ../../../
   mkdir build
   cd build
   cmake -S ../ -B ./
   cmake --build ./
   ```

   Pour info :

   - si votre CPU dispose de plusieurs coeurs, vous pouvez les utiliser pour paralléliser la compilation en ajoutant l'option `-j8` (remplacer 8 par le nombre de coeurs que vous souhaitez utiliser).

> Note: Si vous rencontrez des problèmes de compilation par la suite, c'est peut être du à une ancienne version de PMP. Dans ce cas, déplacez vous à la racone du projet et utilisez :

   ```bash
   git submodule update --remote --merge
   ```

# Fonctionnement en mode projet

## Utilisation du git :

Nous avons décidé de consacrer une branche git par nouveau module qui sera
ajouté. Ainsi, seule la branche master contiendra la version la plus aboutie du
projet. Cela permettra également un retour en arrière facilité en cas de
problème avec une nouvelle fonctionnalité.

## Tag :

Nous utiliserons un système de tag pour différencier les différentes étapes de
notre projet. Un tag se présentera comme ceci :

```bash
Va.b.c

avec
a -> Mise à jour majeure (Fin d\'un sprint par exemple)
b -> Mise à jour mineure
c -> Correctifs
```

V0.0.0 : Projet vide qui affiche uniquement un mesh