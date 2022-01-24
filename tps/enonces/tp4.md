# Géométrie Numérique - TP 4 : Remaillage de surfaces (module *algorithms* de PMP)

## Objectifs théoriques

- Maîtriser la notion d'arêtes vives et son utilité
- Explorer les approches de remaillage vues en cours
- Comprendre leur différences
- Décoder un code qui n'est pas le votre

## Objectifs pratiques

- Détecter et mettre en valeur les arêtes vives sur un maillage
- Développer un algorithme de remaillage basé sur l'existant

![Stanford bunny remaillé](./assets/img/tp4_bunny_remesh.png "Stanford bunny remaillé")

## Exercice 1 - Arêtes vives sur un maillage

Les arêtes vives (*feature edges*) d'un maillage sont définies comme les arêtes dont l'angle diédral, (angle formé par les normales aux deux faces incidentes) est supérieur à un seuil fixé par l'utilisateur.
Les sommets incidents à au moins une arête vive sont appelés sommets caractéristiques (*feature vertices*).
Dans la bibliothèque *PMP*, c'est la méthode `SurfaceFeatures` qui
implémente les sommets caractéristiques et les arêtes vives.
Parcourez le code pour comprendre cette implémentation.
Ajoutez une méthode qui colorie les sommets caractéristiques d'un maillage selon le nombre d'arêtes vives auxquelles ils sont incidents :

- en rouge les sommets incidents à une seule arête
vive
- en bleu les sommets incidents à exactement deux arêtes vives
- en vert les sommets incidents à au moins trois arêtes vives

Testez votre algorithme sur les fichiers OFF fournis, en faisant varier la valeur du seuil pour l'angle diédral.

## Exercice 2 - Remaillage isotrope

La méthode `uniform_remeshing()` de la classe `SurfaceRemeshing` implémente l'algorithme de remaillage isotrope de Botsch et Kobbelt vu en cours [1].
Pour rappel, il s'agit d'un algorithme itératif utilisant les opérateurs locaux de modification de la topologie et de la géométrie du
maillage.
Lisez attentivement le code de cette méthode ainsi que celui des méthodes qu'elle appelle (regardez notamment `is_too_short()` et `is_too_long()`, implémentées dans le fichier d'entête).

## Exercice 3 - Conservation des arêtes vives

Cet algorithme peut être étendu afin de conserver les arêtes vives.
Pour cela, les restrictions supplémentaires suivantes doivent s'appliquer :

1. Les sommets incidents à exactement une ou au moins trois arête(s) vive(s), appelés coins, sont exclus de toutes les opérations locales de modification du maillage
2. Les sommets incidents à deux arêtes vives ne peuvent être effondrés (*edge collapse*) que selon leurs arêtes vives
3. Une arête vive peut être coupée en deux (*edge split*), mais les deux nouvelles arêtes sont alors également des arêtes vives
4. Les arêtes vives ne peuvent jamais être échangées (*edge flip*)
5. Le lissage tangentiel (*vertex relocation*) de sommets incidents à deux arêtes vives doit être univarié le long de ses arêtes vives

Ces cinq règles ont déjà été implémentées dans les méthodes de la classe `SurfaceRemeshing`.
Parcourez leur code et repérez où et comment ces règles interviennent.
En utilisant les deux classes, adaptez la méthode `uniform_remeshing()` afin qu'elle conserve toutes les arêtes vives, selon un angle seuil défini par l'utilisateur.
Testez votre algorithme sur les fichiers OFF fournis, en faisant varier la valeur d'angle seuil.

## Bibliographie

1. M. Botsch, L. Kobbelt. *A remeshing approach to multiresolution modeling*. In Proceedings of Eurographics Symposium on Geometry Processing, 2004.