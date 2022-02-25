# Géométrie Numérique - TP 2 : qualités d'un maillage et PMP *algorithms*

## Objectifs théoriques

- Manipuler une bibliothèque externe
- Apprendre à chercher dans une documentation
- Se familiariser avec les termes associés aux maillages

## Objectifs pratiques

- Faire ses premiers pas avec le module *algorithms* de PMP
- Identifier des propriétés géométriques/topologiques des composants d'un maillage
- Etre capable de "réparer" ou "préparer" un maillage pour faciliter son traitement

## Exercice 1 - Triangulation

Quels sont les avantages et désavantages des faces non triangulaires ?
A votre avis, comment peut-on trianguler une face ?

- Charger un maillage
- Visualiser les faces non triangulaires
- Les trianguler de manière simple (Voir [la documentation de la classe SurfaceTriangulation du module *algorithms*](https://www.pmp-library.org/classpmp_1_1_surface_triangulation.html))

## Exercice 2 - Watertight

> Utiliser le maillage de Suzan

- Charger un maillage
- Identifier ses composantes connexes **(optionnel)**
- Supprimer les petites composantes connexes **(optionnel)**
- Identifier les bords (e.g. colorier les sommets des bords en rouge)
- Remplir les trous (Voir [la documentation de la classe SurfaceHoleFilling du module *algorithms*](https://www.pmp-library.org/classpmp_1_1_surface_hole_filling.html))

## Exercice 3 - Manifold

Dans quel cas un maillage n'est pas manifold ?
Quels problème cela peut engendrer sur les traitements ?

- Charger un maillage
- Verifier qu'il est triangulaire et afficher en console. (Voir [la documentation de la classe SurfaceMesh du module *core*, méthode is_triangular_mesh](https://www.pmp-library.org/classpmp_1_1_surface_mesh.html#a9cede937c41f63448522e8522f7d65a5))
- Verifier qu'il est watertight et afficher en console (vérifier l'abscence de bords sur les demis-arêtes)
- Verifier qu'il est manifold **optionnel** et mettre en valeur les sommets/demi-arêtes/faces non-manifold. Que faut tester ? (ex: isolated vertex, etc)

## Exercice 4 - Propriétés géométriques générales **(optionnel)**

- Charger un maillage
- Calculer ses propriétés géométriques
  - Bounding coords
  - Bounding box size
  - Bounding diag
  - Aire totale
  - Barycentre des sommets
  - Barycentre des faces
  - Volume
  - Nombre d'Euler et genre de la surface

## Exercice 5 - Graphe dual **(optionnel)**

Qu'est ce qu'un graphe dual et à quoi peut il servir ?

- Charger un maillage
- Calculer le Voronoï du maillage (dual)

## Exercice 6 - Géodésiques et picking avec la GUI **(optionnel)**

- Charger un maillage
- Sélectionner un sommet source par un click souris
- Calculer la distance géodésique de chque sommet au sommet source
- Afficher cette distance sous forme de carte de couleurs
