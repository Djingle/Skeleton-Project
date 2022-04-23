# skeleton_project

## Présentation du projet

Dans le cardre de l'UE de géométrie numérique, M. Franck HETROY-WHEELER joue le 
rôle d'un client ayant contacté notre groupe, afin de créer et de fournir un
programme estimant s'il est prudent d'imprimer un certain modèle 3D. Pour ce
faire, nous devrons développer un programme déterminant le squelette du modèle
3D afin de voir où il y a des fragilités. Nous utiliserons pour ça la librairie
PMP.

### Membres du groupe

**Chef de projet :** Bryan EMERY

* Bryan EMERY
* Grégory HORNY
* Paul LABAYE
* Titouan LAURENT
* Vinojan RAJENDIRAN

## Installation

### Prérequis

1. Git
2. CMake
3. Compilateur C++
4. OpenGL

### Etapes

L'installation se fait en 3 étapes :

1. [Récupérer le code source (et le modifier légèrement)](#recuperer-le-code-souce-et-le-modifier)
2. [Compiler la bibliothèque externe PMP](#compiler-la-bibliotheque-externe-pmp)
3. [Compiler le code source du starter-kit](#compiler-le-code-source-du-starter-kit)

> **Note :** Pour les utilisateurs de Windows, la commande `cmake` sera remplacée par la commande `cmake.exe`

### Clone du dépôt git

```bash
git clone https://git.unistra.fr/bemery/skeleton_project.git

cd ./skeleton_project

git submodule update --init --recursive
```

1. Remplacer le fichier `externals/pmp-library/src/pmp/visualization/SurfaceMeshGL.cpp` par le fichier `override_pmp_files/SurfaceMeshGL.cpp` :

   ```bash
   cp override_pmp_files/SurfaceMeshGL.cpp externals/pmp-library/src/pmp/visualization/SurfaceMeshGL.cpp
   ```

2. Remplacer le fichier `externals/pmp-library/src/pmp/visualization/SurfaceMeshGL.h` par le fichier `override_pmp_files/SurfaceMeshGL.h` :

   ```bash
   cp override_pmp_files/SurfaceMeshGL.h externals/pmp-library/src/pmp/visualization/SurfaceMeshGL.h
   ```

3. Remplacer le fichier `externals/pmp-library/src/pmp/algorithms/SurfaceSmoothing.h` par le fichier `override_pmp_files/SurfaceSmoothing.h` :
   ```bash
   cp override_pmp_files/SurfaceSmoothing.h externals/pmp-library/src/pmp/algorithms/SurfaceSmoothing.h
   ```

4. Remplacer le fichier `externals/pmp-library/src/pmp/SurfaceMeshIO.cpp` par le fichier `override_pmp_files/SurfaceMeshIO.cpp` :
   ```bash
   cp override_pmp_files/SurfaceMeshIO.cpp externals/pmp-library/src/pmp/SurfaceMeshIO.cpp
   ```

### Compiler la bibliotheque externe PMP

#### A savoir avant de continuer

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

#### Compilation pmp

```bash
cd ./externals/pmp-library/
mkdir build
cd build
cmake -S ../ -B ./
cmake --build ./
```

### Compiler le code source du starter-kit

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

## Fonctionnement en mode projet

### Utilisation du git

Nous avons décidé de consacrer une branche git par nouveau module qui sera
ajouté. Ainsi, seule la branche master contiendra la version la plus aboutie du
projet. Cela permettra également un retour en arrière facilité en cas de
problème avec une nouvelle fonctionnalité.

### Tag

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
V0.2.x : Projet vide avec de la documentation

## Spécifications de l'ihm

### Fonctionnalités

Ici sont listées les fonctionnalités que l’interface doit pouvoir fournir à l’utilisateur:

 - Charger un maillage à partir d’un fichier
- Afficher un maillage
- Afficher le squelette d’un maillage
- Saisir la taille de l’objet final à imprimer
- Afficher les zones de l’objet qui seront trop fragiles pour l’impression
- Saisir le seuil de fragilité (épaisseur min)


### Mise en oeuvre

Ceci est une courte description du fonctionnement de l’interface du produit final.
Après avoir affiché un maillage, l’utilisateur pourra saisir la taille cible de l’objet à imprimer. Cela sera utile pour déterminer quelles seront les zones fragiles de l’objet. La méthode pour donner la taille de l’objet reste à déterminer, mais l’utilisateur indiquera certainement la taille sur un axe de l’objet (eg. de bas en haut).
    
L’objet, par défaut, sera transparent, de manière à ce que le squelette puisse apparaître au travers par la suite. Ensuite, l’utilisateur pourra afficher son squelette. Le squelette sera affiché à sa position relative au maillage de base (en son sein). En chaque point, il prendra une couleur propre à “l’épaisseur” du maillage. Nous utiliserons une palette de couleur allant du bleu au rose en passant par le violet. En un point, plus le maillage est épais, plus le squelette sera bleu. Plus il est fin, plus son squelette prendra une teinte rose. À noter que la couleur associée au squelette ne dépendra pas de la taille saisie par l’utilisateur associée au maillage, mais sera définie à partir du maillage seul. Le point où l’objet est le plus fin donnera une couleur “totalement rose” au squelette, et le point où il est le plus large lui donnera une teinte “totalement bleue”.
    
Par la suite, si l’utilisateur saisit une taille cible, il lui sera possible de changer l’affichage de l’objet pour le colorer en fonction des zones plus ou moins fragiles. La palette utilisée changera de celle utilisée pour le squelette, pour différencier les deux fonctionnalités aux yeux de l’utilisateur. Cette palette-ci ira du rouge au vert, en passant par le jaune-orange. Cette fois-ci, elle prendra en compte la taille de l’objet. En effet, avec cette échelle-ci, il est possible par exemple qu’un objet soit affiché totalement en rouge ou totalement en vert (eg. que tout l’objet soit une zone fragile, ou au contraire qu’il n’en contienne aucune). Cette fonctionnalité sera disponible uniquement si la taille cible réelle de l’objet a été saisie par l’utilisateur. Lorsque le maillage est affiché coloré, on ne peut plus voir le squelette à travers.

Enfin, l’utilisateur pourra également choisir d’afficher uniquement le squelette ou uniquement le maillage.

### Éléments d’interface 

- Bouton charger -> ouvre un sélecteur de fichier pour sélectionner le fichier à charger
- Champ taille (+ sélecteur d’axe?) -> calcule les zones fragiles de l’objet par rapport à la taille entrée dans le champ. La taille entrée sera la distance entre les deux points les plus éloignés sur l’axe sélectionné (X, Y, ou Z).
- Checkbox maillage -> Active / Désactive l’affichage du maillage
- Checkbox squelette -> Active / Désactive l’affichage du squelette
- Checkbox coloration -> Active / Désactive la coloration du maillage en fonction des zones fragiles. Ne doit être activable uniquement si la taille de l’objet a été saisie.
- Champs seuil (sélecteur d’unité) -> Fixe le seuil de fragilité


<hr>