#ifndef EVENEMENT_H
#define EVENEMENT_H

#include <iostream>
#include <QDate>
#include <QTime>
#include "duree.h"

class Evenement{
private:
	QString titre;
	QString id;
public:
	Evenement(QString t) : titre(t){};
	virtual bool isTache() const = 0;
	const QString& getTitre() const { return titre; };
	const QString& getId() const { return id; }
};

/////////////////////// Taches //////////////////////////

class Tache : public Evenement{
protected:
	QDate dateDispo;
	QDate echeance;
public:
	Tache(QDate dDispo, QDate dEcheance, QString titre) : Evenement(titre), dateDispo(dDispo), echeance(dEcheance){};
	virtual const QDate& getDateEcheance() const = 0;
	virtual bool isTache() { return true; }
	virtual bool isComposite() { return false; }
	const QDate& getDateDisponibilite() const { return dateDispo; };
};




class TacheComposite : public Tache{
private:
	Tache** sousTaches;
	int nbSousTaches;
protected:
	TacheComposite(const QDate& dDispo, const QDate& dEcheanceGlobale,const QString& titre) : Tache(dDispo, dEcheanceGlobale, titre), sousTaches(nullptr), nbSousTaches(0){};
	virtual bool isComposite() { return true; }
	///////////////faire les fonctions pour gérer le tableau !!!!!!!!!!!!///////
	/*
	void ajouterSousTache(const Tache& const sousTache);
	void supprimmerTache(Tache& sousTache);
	virtual QDate getDateEcheance() const { //////RETURN LA DERNIERE echeance des taches unitaires }
	*/
};



/////////////////////////////// Tache Unitaire   //////////////////////////////////////
class TacheUnitaire : public Tache{
protected:
	TacheUnitaire(const QDate& dDispo, const QDate& dEcheance, const QString& titre) : Tache(dDispo, dEcheance, titre){};
public:
	virtual const QDate& getDateEcheance() const { return echeance; }
	virtual bool isPreemptive() const = 0;
	virtual const Duree& getDuree() const = 0;
	virtual const Duree& getDureeEffectuee() const { Duree * d = new Duree(0); return *d; }
};


class TacheUnitairePreemptee : public TacheUnitaire{
private:
	Duree dureeEffectuee;
	Duree dureeInitiale;
public:
	virtual bool isPreemptive() const { return true; }
	TacheUnitairePreemptee(const QDate& dDispo, const QDate& dEcheance, const QString& titre, const Duree& d) : TacheUnitaire(dDispo, dEcheance, titre), dureeInitiale(d), dureeEffectuee(0){};
	void setDureeEffectuee(const Duree& dEffectuee) { dureeEffectuee = dEffectuee; }
	void ajouterDureeEffectuee(const Duree& dEffectuee) { dureeEffectuee += dEffectuee;}
	virtual const Duree& getDuree() const { return dureeInitiale; }
	virtual const Duree& getDureeEffectuee() const { return dureeEffectuee; }
	Duree getDureeRestante() const { return dureeInitiale - dureeEffectuee; }
};

class TacheUnitaireNonPreemptee : public TacheUnitaire{
private:
	Duree duree;
public:
	virtual bool isPreemptive() const { return false; }
	virtual const Duree& getDuree() const { return duree; }
	TacheUnitaireNonPreemptee(const QDate& dDispo, const QDate& dEcheance, const QString& titre, const Duree& d) : TacheUnitaire(dDispo, dEcheance, titre), duree(d){};
};







///////////////////// Activités traditionnelles    //////////////////////////////




class ActiviteTraditionnelle : public Evenement{
private:
	QString lieu;
	Duree duree;
public:
	ActiviteTraditionnelle(const QString& titre, const QString& lieu, const Duree& duree) : Evenement(titre), duree(duree), lieu(lieu){}
	virtual bool isReunion() const { return false;}
	const QString& getLieu() const { return lieu; }
	const Duree& getDuree() const{ return duree; }
	void setLieu(QString nouveauLieu) { lieu = nouveauLieu; }
	void setDuree(Duree nouvelleDuree) { duree = nouvelleDuree; }

};




class Reunion : public ActiviteTraditionnelle {
private:
	int nbParticipants;
	QString participants;
public:
	virtual bool isReunion() const { return true; }
	virtual bool isTache() const { return false; }
	Reunion(const QString& titre, const QString& lieu, const Duree& duree, int nbParticipants, const QString& participants) : ActiviteTraditionnelle(titre, lieu, duree), nbParticipants(nbParticipants), participants(participants){}
	int getNbParticipants() const { return nbParticipants; }
	const QString& getParticipants() const { return participants; }
};



class Rdv : public ActiviteTraditionnelle{
private:
	QString interlocuteur;
public:
	virtual bool isTache() const { return false; }
	Rdv(const QString & titre, const QString& lieu, const Duree& duree, const QString& interlocuteur) : ActiviteTraditionnelle(titre, lieu, duree), interlocuteur(interlocuteur){}
	const QString& getInterlocuteur() const { return interlocuteur; }
};

#endif
