#ifndef EVENEMENT
#define EVENEMENT

#include <iostream>
#include "timing.h"


class Evenement{
private:
	std::string  titre;
protected:
	Evenement(std::string t) : titre(t){};
public:
	const std::string& const getTitre() const { return titre; };
};



class Tache : public Evenement{
private:
	TIME::Date dateDispo;
	TIME::Date echeanceGlobale;
protected:
	Tache(TIME::Date dDispo, TIME::Date dEcheanceGlobale, std::string titre) : Evenement(titre), dateDispo(dDispo), echeanceGlobale(dEcheanceGlobale){};
public:
	const TIME::Date& const getDateDispo() const {return dateDispo;};
	const TIME::Date& const getEcheanceGlobale() const {return echeanceGlobale;};

};


class TacheComposite : public Tache{
private:
	Tache** sousTaches;
	int nbSousTaches;
protected:
	TacheComposite(TIME::Date dDispo, TIME::Date dEcheanceGlobale, std::string titre) : Tache(dDispo, dEcheanceGlobale, titre), sousTaches(nullptr), nbSousTaches(0){};
	///////////////faire les fonctions pour gérer le tableau !!!!!!!!!!!!///////
	/*
	void ajouterSousTache(const Tache& const sousTache);
	void supprimmerTache(Tache& sousTache);
	*/
};



class TacheUnitaire : public Tache{
protected:
	TacheUnitaire(TIME::Date dDispo, TIME::Date dEcheanceGlobale, std::string titre) : Tache(dDispo, dEcheanceGlobale, titre){};
};



class TacheUnitairePreemptee : public TacheUnitaire{
private :
	TIME::Duree dureeEffectuee;
	TIME::Duree dureeInitiale;
public:
	TacheUnitairePreemptee(TIME::Date dDispo, TIME::Date dEcheanceGlobale, std::string titre, TIME::Duree d) : TacheUnitaire(dDispo, dEcheanceGlobale, titre), dureeInitiale(d), dureeEffectuee(0){};
	const TIME::Duree& const getDureeEffectuee() const {return dureeEffectuee;};
	const TIME::Duree getDureeRestante() const;
	void setDureeEffectuee(TIME::Duree dEffectuee) {dureeEffectuee = dEffectuee;}
	void ajouterDureeEffectuee(TIME::Duree dEffectuee);
};



class TacheUnitaireNonPreemptee : public TacheUnitaire{
private:
	TIME::Duree duree;
public:
	TacheUnitaireNonPreemptee(TIME::Date dDispo, TIME::Date dEcheanceGlobale, std::string titre, TIME::Duree d) : TacheUnitaire(dDispo, dEcheanceGlobale, titre), duree(d){};
};

class ActiviteTraditionnelle : public Evenement{
private:
	std::string lieu;
	TIME::Duree duree;
protected:
	ActiviteTraditionnelle(std::string titre, std::string lieu, TIME::Duree duree) : Evenement(titre), duree(duree), lieu(lieu){}
public:
	const std::string& const getLieu() const { return lieu; }
	const TIME::Duree& const getDuree() const{ return duree; }
	void setLieu(std::string nouveauLieu) { lieu = nouveauLieu; }
	void setDuree(TIME::Duree nouvelleDuree) { duree = nouvelleDuree; }
};

class Reunion : public ActiviteTraditionnelle {
private:
	int nbParticipants;
	std::string participants;
public:
	Reunion(std::string titre, std::string lieu, TIME::Duree duree, int nbParticipants, std::string participants) : ActiviteTraditionnelle(titre, lieu, duree), nbParticipants(nbParticipants), participants(participants){}
	const int& const getNbParticipants() const { return nbParticipants; }
	const std::string& const getParticipants() const { return participants; }
};

class Rdv : public ActiviteTraditionnelle{
private:
	std::string interlocuteur;
public:
	Rdv(std::string titre, std::string lieu, TIME::Duree duree, std::string interlocuteur) : ActiviteTraditionnelle(titre, lieu, duree), interlocuteur(interlocuteur){}
	const std::string& const getInterlocuteur() const { return interlocuteur; }
};

#endif
