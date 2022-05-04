# skeleton_project

## Présentation du projet

Dans le cardre de l'UE de Géométrie Numérique, M. Franck HETROY-WHEELER joue le 
rôle d'un client ayant contacté notre groupe, afin de créer et de fournir un
programme estimant s'il est prudent d'imprimer un certain modèle 3D. Pour ce
faire, nous devrons développer un programme déterminant le squelette du modèle
3D et de détecter les zones fragiles.

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
5. CGAL

### Installation et exécution

Récuperer le projet :

```bash
git clone https://git.unistra.fr/bemery/skeleton_project.git
cd skeleton_project
```

Compiler le projet pour la première fois (ainsi que la librarie PMP) :

```bash
./firstBuild.sh
```

Recompiler le projet :

```bash
./build.sh
```

Lancer le programme :

```bash
./start.sh
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
a -> Mise à jour majeure
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
- Afficher le squelette du maillage
- Saisir la taille de l’objet final à imprimer
- Afficher les zones de l’objet qui seront trop fragiles pour l’impression
- Saisir le seuil de fragilité (épaisseur minimum)


### Mise en oeuvre

Ceci est une courte description du fonctionnement de l’interface du produit final.

Après avoir affiché un maillage, l’utilisateur pourra saisir la taille cible de l’objet à imprimer. 
Cela sera utile pour déterminer quelles seront les zones fragiles de l’objet. 
La méthode pour donner la taille de l’objet reste à déterminer, mais l’utilisateur indiquera certainement la taille sur un axe de l’objet (par exemple de bas en haut).
    
L’objet, par défaut, sera transparent, de manière à ce que le squelette puisse apparaître au travers par la suite.
Ensuite, l’utilisateur pourra afficher son squelette.
Le squelette sera affiché à sa position relative au maillage de base (en son sein).
En chaque point, il prendra une couleur propre à “l’épaisseur” du maillage.
Nous utiliserons une palette de couleur allant du bleu au rose en passant par le violet.
En un point, plus le maillage est épais, plus le squelette sera bleu.
Plus il est fin, plus son squelette prendra une teinte rose.
À noter que la couleur associée au squelette ne dépendra pas de la taille saisie par l’utilisateur associée au maillage,
mais sera définie à partir du maillage seul.
Le point où l’objet est le plus fin donnera une couleur “totalement rose” au squelette, et le point où il est le plus large lui donnera une teinte “totalement bleue”.
    
Par la suite, si l’utilisateur saisit une taille cible, il lui sera possible de changer l’affichage de l’objet pour le colorer en fonction des zones plus ou moins fragiles.
La palette utilisée changera de celle utilisée pour le squelette, pour différencier les deux fonctionnalités aux yeux de l’utilisateur.
Cette palette-ci ira du rouge au vert, en passant par le jaune-orange.
Cette fois-ci, elle prendra en compte la taille de l’objet.
En effet, avec cette échelle-ci, il est possible par exemple qu’un objet soit affiché totalement en rouge ou totalement en vert (eg. que tout l’objet soit une zone fragile, ou au contraire qu’il n’en contienne aucune).
Cette fonctionnalité sera disponible uniquement si la taille cible réelle de l’objet a été saisie par l’utilisateur.
Lorsque le maillage est affiché coloré, on ne peut plus voir le squelette à travers.

Enfin, l’utilisateur pourra également choisir d’afficher uniquement le squelette ou uniquement le maillage.

### Éléments d’interface 

- **Bouton charger** : ouvre un sélecteur de fichier pour sélectionner le fichier à charger
- **Champ taille (+ sélecteur d’axe)** : calcule les zones fragiles de l’objet par rapport à la taille entrée dans le champ. La taille entrée sera la distance entre les deux points les plus éloignés sur l’axe sélectionné (X, Y, ou Z).
- **Checkbox maillage** : Active / Désactive l’affichage du maillage
- **Checkbox squelette** : Active / Désactive l’affichage du squelette
- **Checkbox coloration** : Active / Désactive la coloration du maillage en fonction des zones fragiles. Ne doit être activable uniquement si la taille de l’objet a été saisie.
- **Champs seuil (sélecteur d’unité)** : Fixe le seuil de fragilité


<hr>