# skeleton_project

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

# Clone du dépôt git :

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

## Compilation pmp

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

    ```
    git submodule update --remote --merge
    ```
