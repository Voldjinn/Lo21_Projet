#include "Calendar.h"

/*
    implementation singleton :
    1)declarer les constructeurs/destructeurs/operateurs d'affectation en private
        -> fonctions incassecibles utilisateur
        -> tachemanager se g�re tout seul
    2) on declare un attribut statique dans TacheManager
        -> cet attribut est commun � tous les objets TacheManager
    3) On donne acc�s � cet attribut via la m�thode static getInstance
        -> utilisable sans objet TacheManager existant
    4) LibererInstance() permet de supprimmer l'instance unique


*/

int main(){
	TacheManager &manager = TacheManager::getInstance();
	manager.load("taches.dat");
	//manager.ajouterTache("AW1","Partage des scenarii",Duree(1,30),Date(1,1,2015),Date(1,9,2015));
	//manager.ajouterTache("AW2","Identification des competences",Duree(2,30),Date(1,1,2015),Date(1,12,2015));
	manager.save("taches.dat");

	TacheManager::libererInstance();
	system("pause");
	return 0;
}
