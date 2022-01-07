# Géométrie Numérique - TP 1

## Objectifs théoriques

- Manipuler une bibliothèque externe
- Apprendre à chercher dans une documentation
- Prendre en main la bibliothèque PMP
- Comprendre la structure de maillage "Half-Edge" et manipuler les relations d'adjacence

## Objectifs pratiques

- Charger et afficher un maillage polygonal
- Ajouter des propriétés scalaires sur différents éléments du maillage (sommets et faces)
- Visualiser ces propriétés en couleur
- Détcter et visualiser les différentes composantes connexes d'un maillage

---

## La bibliothèque PMP

[PMP (Polygon Mesh Processing)](https://www.pmp-library.org/) est une bibliothèque c++ pour le traitement et la visualisation de maillages polygonaux.
Elle va nous éviter de réinventer la roue pour notre série de travaux pratiques.

Pour toute la série de TP à venir, vous serez amenés à chercher par vous même "comment faire pour ... avec PMP ?".
La [documentation en ligne](https://www.pmp-library.org/userguide.html) (ou en local dans le dossier `externals/pmp-library/docs/` de ce dépôt) de cette bibliothèque sera donc un allié important de vos travaux et vous êtes **plus qu'insités** à vous y réferrer souvent.

Vous commencerez en particulier par lire le [tutoriel](https://www.pmp-library.org/tutorial.html) proposé par l'équipe de développement.
Lors des prochaines séances vous serez aussi amenés à rentrer plus en détail dans le code de la bibliothèque pour comprendre certains points illustrés en cours.
Vous trouverez le code source de PMP dans le dossier `externals/pmp-library/src/` de ce dépôt.
Finalement, vous trouverez des exemples pratiques écrits par l'équipe de développement de PMP dans le dossier `externals/pmp-library/examples/` dont vous pourrez vous inspirer au besoin.

## Exercice 0

- Charger un maillage
- Sauvegarder ce maillage dans un autre fichier

## Exercice 1 - Informations générales sur un maillage

- A: Charger un maillage, afficher en console : le nombre de sommets, d'aretes et de faces
- B: Afficher ses sommets (index et position)
- C: Afficher ses helf edges
- D: Afficher ses aretes
- E: Afficher ses faces dans une console

### Exercice 2 - Découvrir la topologie du maillage (structure de Half-Edge)

- A: Parcourir les arêtes adjacentes à une arête source
- Parcourir les sommets voisins une arête source
- Parcourir les faces adjacentes à une arête source
- 
- B : Parcourir les arêtes adjacentes à un sommet source
- Parcourir les sommets voisins d'un sommet source
- Parcourir les faces adjacentes à un sommet source

- C: Parcourir les arêtes adjacentes à une face source
- Parcourir les sommets voisins d'une face source
- Parcourir les faces adjacentes à une face source

- ## Exercice 3 - Modifier géométrie

- Charger un maillage
- Appliquer une transformation affine
- Sauvegarder le maillage transformé

## Exercice 3 - Visualisation

- Charger un maillage
- Afficher ses sommets, aretes et faces dans une GUI
- Ajouter un bouton à la GUI permettant de colorer le maillage

- Charger deux maillages
- Avoir une combo box qui selectionne lequel afficher



Topologie:
- Visualiser les faces non triangulaires



## Exercice 5

- Charger un maillage
- Colorer les sommets selon leur valence
- Colorer les faces selon leur aire

## Exercice 5

- Charger un maillage
- Identifier les composantes connexes et les afficher dans une couleur différente

## Exercice 6 (bonus)

- Un sommet source, utiliser Kruskal pour approximer des géodésiques