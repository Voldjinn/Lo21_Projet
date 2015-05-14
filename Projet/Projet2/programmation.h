#ifndef PROGRAMMATION_H
#define PROGRAMMATION_H

#include <QDateTime>
#include "evenement.h"

class Programmation{
private:
	QString id;
	QDate dateChoisie;
	QTime horaireChoisi;
	Duree duree;
	Evenement * evt;
public:
	Programmation(int id, const QDate & dateChoisie, const QTime& horaireChoisi, Evenement * evt) : id(id), dateChoisie(dateChoisie), horaireChoisi(horaireChoisi), evt(evt){
		if (evt->isTache()){
			if (((Tache*)evt)->isComposite()){
				///erreur : pas de programmation de taches composees
			}
			else{
				if (((TacheUnitaire*)evt)->isPreemptive()){
					//afficher fenetre pour choisir la duree
				}
				else
					duree = ((TacheUnitaireNonPreemptee*)evt)->getDuree();
				//on initialise la duree egale a la duree de la tache;
			}
		}
		else{
			duree = ((ActiviteTraditionnelle*)evt)->getDuree();
		}
	}
	const QDate& getDateChoisie() const {return dateChoisie; }
	const QTime& getHoraireChoisi() const {return horaireChoisi; }
	const Duree& getDuree();
	
	~Programmation() {};
};

class ProgrammationManager{ //designe pattern singleton (un seul emploi du temps) + iterator pour naviguer dans les programmations
private:
	int nbProg;
	int nbMaxProg;
	Programmation** prog;
	/*
	
	
	
	*/
	static int idProg;  //sert a donner un id a chaque programmation
	ProgrammationManager();
	~ProgrammationManager();
public:
	ProgrammationManager& getInstance();
	ProgrammationManager& delInstance();



};


#endif