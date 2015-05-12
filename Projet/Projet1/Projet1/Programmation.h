#ifndef PROGRAMMATION
#define PROGRAMMATION

#include "evenement.h"
#include "timing.h"

class Programmation {
private:
	const Tache* tache;
	TIME::Date date;
	TIME::Horaire horaire;

public:
	Programmation(const Tache& t, const TIME::Date& d, const TIME::Horaire& h) :tache(&t), date(d), horaire(h){}
	const Tache& getTache() const { return *tache; }
	const TIME::Date& const getDate() const { return date; }
	const TIME::Horaire& const getHoraire() const { return horaire; }
	~Programmation() {}
};


class Agenda {
private:
	Programmation** prog;
	int nbProg;
public:
	Agenda() : prog(nullptr), nbProg(0){}
	//a faire : gestion du tableau de Programmation
	/*
	void ajouterProg();
	void supprimmerProg();
	get/set, ....
	~Agenda()
	*/
};


#endif