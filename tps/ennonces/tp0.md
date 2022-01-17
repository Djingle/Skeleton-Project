# Géométrie Numérique - TP 0

## Objectifs théoriques

- Suivre un tutorial
- Lire le code d'un autre développeur

## Objectifs pratiques

- Avoir un aperçu de la bibliothèque PMP, de sa structure et de ce qu'elle permet de faire
- Utiliser du code existant pour préparer des interfaces simples en ligne de commande

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

Utilisez les outils disponibles dans cli_tools.h pour :
- Ajouter trois arguments à votre programme : un int, un string et un double
- Récupérer leur valeur dans le main
- Afficher leur valeur