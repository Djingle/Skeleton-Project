# Géométrie Numérique - TP 1 : demi-arêtes et PMP *core*

## Objectifs théoriques

- Manipuler une bibliothèque externe
- Apprendre à chercher dans une documentation
- Comprendre la structure de maillage en ***demi-arêtes*** et manipuler les relations d'adjacence

## Objectifs pratiques

- Prendre en main la bibliothèque PMP
- Charger et afficher un maillage polygonal
- Ajouter des propriétés sur différents éléments du maillage (sommets et faces)
- Visualiser ces propriétés en couleur
- Détcter et visualiser les différentes composantes connexes d'un maillage

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

> Voir la [documentation de la classe SurfaceMesh](https://www.pmp-library.org/classpmp_1_1_surface_mesh.html).

- Charger un maillage
- Afficher son nombre de sommets, d'aretes et de faces
- Afficher ses sommets (index et position)
- Afficher ses demi-arêtes
- Afficher ses arêtes
- Afficher ses faces

### Exercice 2 - Découvrir la topologie du maillage (structure de Half-Edge)

> Voir le tutorial PMP pour les circulateurs et la documentation liée.

Les questions marquées d'un *(!)* comportent un risque potentiel. Quel est ce risque ?

- Charger un maillage
- Parcourir et afficher des éléments de topologie
    - Demi-arêtes et adjacence
        - Afficher les sommets d'une demi-arête source
        - Afficher la demi-arête opposée à une demi-arête source
        - Afficher la demi-arête suivante d'une demi-arête source (!)
        - Afficher la demi-arête précédente d'une demi-arête source (!)
        - Afficher la face attachée à une demi-arête source (!)
    - Sommets et adjacence
        - Afficher les sommets voisins d'un sommet source
        - Afficher les demi-arêtes partant d'un sommet source
        - Afficher les faces auxquelles appartient un sommet source
    - Faces et adjacence
        - Afficher les demi-arêtes composant une face source
        - Afficher les faces voisines d'une face source

- ## Exercice 3 - Modifier la géométrie

> Chercher les transformations dans PMP.

- Charger un maillage
- Appliquer une transformation affine passée en argument
- Sauvegarder le maillage transformé

## Exercice 4 - Visualisation et couleurs

> Voir la [documentation du module de visualisation](https://www.pmp-library.org/group__visualization.html).
> Voir les exemples d'applications fournis avec PMP.

- Charger un maillage
- Afficher ses sommets, aretes et faces dans une GUI
- Ajouter un bouton à la GUI permettant de colorer le maillage

## Exercice 5 - Visualisation et GUI (bonus)

> Fouiller le net pour plus d'infos sur la bibliothèque ImGui.

- Charger deux maillages
- Avoir une combo box qui selectionne lequel afficher

## Exercice 6 - Propriétés et coloration

> Voir le tutorial PMP et chercher des infos sur les propriétés dans la documentation.

- Charger un maillage
- Ajouter une propriété aux sommets qui stockera leur valence
- Ajouter une propriété aux faces qui stockera leur aire
- Ajouter des boutons à la GUI pour visualiser ces informations selon une carte de couleurs (proposition: utiliser la représentation HLS des couleurs pour obtenir une carte allant du bleu au rouge)

## Exercice 7 - Où tout s'assemble

> Utiliser ce que vous avez construit jusqu'ici !

- Charger un maillage
- Identifier les composantes connexes et les afficher dans une couleur différente lors du click utilisateur sur un bouton de la GUI.