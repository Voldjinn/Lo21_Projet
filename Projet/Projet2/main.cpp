#include <QApplication>
#include "fenetre_depart.h"


int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	FenetreDepart fenetre;
	fenetre.show();
    return app.exec();
}

/*
 *
 *      Reste à faire :
 *              implementer les classes : Projet / ProjetManager /
 *              terminer les classes programmation/ programmationManager
 *              implémenter les fonctions pour lecture/ecriture XML
 *                      ->lors de l'ouverture de la fenetre principale :
 *                              -creer instances ProgrammationManager/TacheManager
 *                              -leur demander de creer les evenements / programmations correspondants au XML
 *                      ->lors du changement de fenetre : passer adresse des Manager en arguments pour pouvoir les utiliser
 *                      -> utiliser les Managers dans le reste de l'interface pour obtenir les infos voulues
 *                      ->implementer les fonctions pour sauvegarder dans le XML a chaque fois qu'on modifie/ajoute/enleve un evenement/programmation
 *
 *
*/
