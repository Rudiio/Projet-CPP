# Projet-CPP : Modélisation de l'évacuation de stades
Réalisé par BAUDET Léo-Paul et FIDA CYRILLE Rudio

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![SDL2](https://img.shields.io/badge/Biblioth%C3%A9que-SDL2-blue)
![OpenMP](https://img.shields.io/badge/Biblioth%C3%A9que-OpenMP-red)
[![Rapport](https://img.shields.io/badge/Rapport-overleaf.com%2Fproject%2F6399d50c1b6cb4c2b234ed82-blue)](https://www.overleaf.com/project/6399d50c1b6cb4c2b234ed82)

Ce Projet a pour but de présenter nos acquis en programmation C++ et orientée objet du semestre 1 de 2022-2023. 

Le thème du projet est **"Coupe du monde"**

Nous avons choisi d'aborder le sujet de manière à pouvoir mêler les différents domaines de la spécialité MAIN dans ce projet. Ainsi, ce projet réunit programmation, mathématique, modélisation et HPC.

## Présentation du sujet

Le sujet de notre projet est la modélisation de l'évacuation de stades, notamment dans le contexte de la coupe du monde où de nombreuses personnes seront amenées à sortir des stades en même temps.
Cela est donc similiare à une modélisation des mouvements de foules mais en considérant un mouvement général vers une sortie.

### Présentation du modèle

Le modèle implémenté est un modèle microscopique qui calcule à chaque temps les forces appliquées sur chaque individu et les intègre avec une méthode d'Euler. Un individu est ici représenté par un disque, mais d'autres formes peuvent être implémentées. 

Les forces du modèles sont les suivantes:
- Force d'accélération individu - sortie
- Force sociale individu - individu
- Force de répulsion linéaire et glissante individu - individu
- Force sociale individu - mur
- Force de répulsion linéaire et glissante individu - mur

## Installation

La partie graphique du projet repose sur la bibliothèque graphique SDL2.
Pour télécharger la librairie SDL2 sous Ubuntu:
```sh
sudo apt install libsdl2-dev libsdl2-ttf-dev
```

Les boucles de calcul de forces et de positions ont été parallèlisées avec OpenMp pour augmenter les performances des simulation. 
Pour installer Openmp sous Ubuntu:
```sh
sudo apt install libomp-dev
```

Pour mettre à jour les packages, si l'installation des bibliothèques ne fait pas:
```sh
sudo apt-get upgrade
```

## Utilisation

Pour compiler le programme : 
```sh
make
```

Pour lancer les test :
```sh
make test
```

Pour lancer une simulation:
```sh
./foule
```

Les paramètres de la simulation sont tous accessibles et modifiables dans le fichier **parametres.hpp**. Un changement de paramètres nécessite ainsi une recompilation.

Il est possible de choisir parmi plus configuration de l'espace en changeant la variable **map** dans **parametres.hpp**.

Voici, les configurations disponibles : 

Voici, les configurations disponibles : 

-map=0 (map sans obstacles)

-map=1 (map avec mur central)

-map=2 (map avec mur central et obstacle devant celui ci)

-map=3 (map avec colonnes)

-map=4 (map avec mur central et deux obstacles)

-map=5 (map avec mur central et trois obstcles)

-map=6 (map avec obstacle diagonal devant le point d'arrivé)

-map=7 (map avec obstcale en L)

Il est également possible de modifier les coordonnées de la sortie en modifiant **i0** et **j0** dans **parametres.hpp**.

## Touches

**A** : Afficher/Cacher les axes (Ralentit énormément le programme)

**I** : Afficher/Cacher les informations de simulation (Ralentit énormément le programme)

**J** : Dézoom 

**K** : Zoom 

**echap** : Quitter la simulation

**← → ↑ ↓** : Se déplacer dans l'espace

## Images
<img width="526" alt="map_4" src="https://user-images.githubusercontent.com/92988071/214655323-7098a455-3571-4378-a48f-8b4daa4b0508.png">
<img width="521" alt="map_3" src="https://user-images.githubusercontent.com/92988071/214655370-c395cb2b-3ee6-465f-a30a-090b2316e830.png">
<img width="528" alt="map_5" src="https://user-images.githubusercontent.com/92988071/214655429-96c2c8fc-6709-4c83-ad44-1028f811c979.png">
<img width="514" alt="map_6" src="https://user-images.githubusercontent.com/92988071/214655471-a1dd25e0-3fa8-4a7c-b26f-ddf86b20c746.png">

