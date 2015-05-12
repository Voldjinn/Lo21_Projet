#include "evenement.h"


const TIME::Duree TacheUnitairePreemptee::getDureeRestante() const{
	int d = dureeInitiale.getDureeEnMinutes() - dureeEffectuee.getDureeEnMinutes();
	return TIME::Duree(d / 60, d % 60);
}

void TacheUnitairePreemptee::ajouterDureeEffectuee(TIME::Duree dEffectuee) {
	int d = dureeEffectuee.getDureeEnMinutes() + dEffectuee.getDureeEnMinutes();
	dureeEffectuee.setDuree(d / 60, d % 60);
}

