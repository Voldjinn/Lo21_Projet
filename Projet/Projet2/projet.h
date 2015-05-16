#ifndef PROJET_H
#define PROJET_H
#include "duree.h"
#include <QDate>
#include <QTime>
#include "evenement.h"
#include <QString>



class Projet
{
private :
    QString titre;
    QDate debut;
    QDate fin;
    Tache ** taches;
    int nb;
    int nbmax;
    QString file;



public:
    Projet(const QString & t, const QDate & deb,const QDate & fin);
    ~Projet();
    Projet(const Projet& um);
    Projet& operator=(const Projet& um);

   Tache& ajouterTache(const QString& t, const QDate& dispo, const QDate& deadline, bool preemp, bool unitaire, const Duree & dur=0);
   Tache* trouverTache(const QString & t)const;
   Tache& getTache(const QString & t)const;
   //const Tache& getTache(int id)const;
   void addItem(Tache* t);
    //const Tache * existe(const QString & id) const;
    const QString getTitre()const {return titre;}
    const QDate getDebut()const {return debut;}
    const QDate getFin()const {return fin;}
    int getNb()const {return nb;}
    int getNbmax()const {return nbmax;}

    class Iterator{
        friend class Projet;
    private:
        Tache **pt;
        /*unsigned int nbRestant;
        Iterator(): pt(0), nbRestant(0) {}
        Iterator(Tache **pt, unsigned int nbRestant): pt(pt), nbRestant(nbRestant) {}  inutile */
        Iterator(): pt(0) {}
        Iterator(Tache **pt): pt(pt) {}
    public:
        Tache& current() const;
        bool operator!=(const Iterator &other) const {return pt!=other.pt;}
        void operator++() {++pt;}
        Tache& operator*() const {return **pt;}
        //void next(); inutile
    };

};

class ProjetManager
    {
    Projet** projets;
    int Nb;
    int Nbmax;
    static ProjetManager *instance;


    ProjetManager();
    ~ProjetManager();
    ProjetManager(const ProjetManager& um);
    ProjetManager& operator=(const ProjetManager& um);
    void addItem(Projet* p);
    Projet* ProjetManager::trouverProjet(const QString &t)const;
public :
    static ProjetManager& getInstance();
    static void libererInstance();
    Projet& ajouterProjet(const QString& t, const QDate& dispo, const QDate& echeance);
    Projet& getProjet(const QString & t);
    const Projet& getProjet(const QString & t) const;
    int getNb()const{return Nb;}
    int getNbmax()const{return Nbmax;};

    class Iterator{
        friend class ProjetManager;
    private:
        Tache **pt;
        /*unsigned int nbRestant;
        Iterator(): pt(0), nbRestant(0) {}
        Iterator(Tache **pt, unsigned int nbRestant): pt(pt), nbRestant(nbRestant) {}  inutile */
        Iterator(): pt(0) {}
        Iterator(Tache **pt): pt(pt) {}
    public:
        Tache& current() const;
        bool operator!=(const Iterator &other) const {return pt!=other.pt;}
        void operator++() {++pt;}
        Tache& operator*() const {return **pt;}
        //void next(); inutile
    };

};




#endif
