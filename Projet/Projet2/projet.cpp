#include "projet.h"
#include "evenement.h"
#include "exception.h"
#include "qfile.h"

ProjetManager * ProjetManager::instance =0;

ProjetManager& ProjetManager::getInstance(){
    if( instance==0)
        instance = new ProjetManager();
    return *instance;
}
void ProjetManager::libererInstance(){
    if(instance)
        delete instance;
    instance=0;
}


ProjetManager::ProjetManager():projets(0),Nb(0),Nbmax(0){++instance;}

void ProjetManager::addItem(Projet* p){
    if (Nb==Nbmax){
        Projet** newtab=new Projet*[Nbmax+10];
        for(int i=0; i<Nb; i++) newtab[i]=projets[i];
        // ou memcpy(newtab,taches,nb*sizeof(Tache*));
        Nbmax+=10;
        Projet** old=projets;
        projets=newtab;
        delete[] old;
    }
    projets[Nb++]=p;
}

Projet* ProjetManager::trouverProjet(const QString &t)const{
    for(int i=0; i<Nb; i++)
        if (t==projets[i]->getTitre()) return projets[i];
    return 0;
}

Projet& ProjetManager:: ajouterProjet(const QString& t, const QDate& dispo, const QDate& echeance){
    if (trouverProjet(t)) throw CalendarException("erreur, ProjetManager, projet deja existante");
    Projet* newt=new Projet(t,dispo,echeance);
    addItem(newt);
    return *newt;
}

Projet& ProjetManager::getProjet(const QString& t){
    Projet* p=trouverProjet(t);
    if (!p) throw CalendarException("erreur, ProjetManager, projet inexistante");
    return *p;
}

const Projet& ProjetManager::getProjet(const QString& t)const{
    return const_cast<ProjetManager*>(this)->getProjet(t);
}

ProjetManager::~ProjetManager(){
    for(int i=0; i<Nb; i++) {delete projets[i];}
    delete[] projets;
    Nb=0;
    Nbmax=0;
}

ProjetManager::ProjetManager(const ProjetManager& um):Nb(um.Nb),Nbmax(um.Nbmax), projets(new Projet*[um.Nb]){
    for(int i=0; i<Nb; i++) projets[i]=new Projet(*um.projets[i]);
}

ProjetManager& ProjetManager::operator=(const ProjetManager& um){
    if (this==&um) return *this;
    this->~ProjetManager();
    for(int i=0; i<um.Nb; i++) addItem(new Projet(*um.projets[i]));
    return *this;
}

/*
string identificateur;
    string titre;
    Duree duree;
    Date disponibilite;
    Date echeance;
*/





//*****************************************************************************************************



Projet::Projet(const QString & t, const QDate & deb,const QDate & fin): titre(t),debut(deb),fin(fin),nb(0),nbmax(0),taches(0){};



void Projet::addItem(Tache* t){
    if (nb==nbmax){
        Tache** newtab=new Tache*[nbmax+10];
        for(int i=0; i<nb; i++) newtab[i]=taches[i];
        // ou memcpy(newtab,taches,nb*sizeof(Tache*));
        nbmax+=10;
        Tache** old=taches;
        taches=newtab;
        delete[] old;
    }
    taches[nb++]=t;
}

Tache* Projet::trouverTache(const QString & t)const{
    for(int i=0; i<nb; i++)
        if (t==taches[i]->getTitre()) return taches[i];
    return 0;
}

Tache& Projet::ajouterTache(const QString& t, const QDate& dispo, const QDate& deadline, bool preemp, bool unitaire,const Duree & dur){
    if (trouverTache(t)) throw CalendarException("erreur, Projet, tache deja existante");
    if (deadline>fin) throw CalendarException("la deadline ne peut pas etre supérieur à celle du projet");

    Tache * newt;
    if(unitaire)
    {   if(dur.getDureeEnMinutes()==0){throw CalendarException("une duree de tache ne peut pas etre nulle");}
              else{
                        if (preemp)
                                 {

                                    newt =new TacheUnitairePreemptee(dispo,deadline,t,dur); //si c'est une tache premptive
                                 }
                     else        {
                                    if(dur.getDureeEnHeures()>12)
                                        {
                                            throw CalendarException("on ne peut pas avoir une durée supérieur à 12 h");}
                                    else
                                        {
                                        newt =new TacheUnitaireNonPreemptee(dispo,deadline,t,dur);//si c'est une tache non premptive
                                        }
                                }
                }
      }
     else {
              newt=new TacheComposite(dispo,deadline,t);//si c'est une tache composite
           }
    addItem(newt); //sur un malentendu ca peut passer ^^
    return *newt;
}

Tache& Projet::getTache(const QString & t) const{
    Tache* ta=trouverTache(t);
    if (!ta) throw CalendarException("erreur, Projet, tache inexistante");
    return *ta;
}

/*const Tache& Projet::getTache(int id)const{
    return const_cast<Projet*>(this)->getTache(id);
}
*/

//je sais pas comment fonctionne les files sur qt ...
Projet::~Projet(){
    for(int i=0; i<nb; i++) {taches[i];}
    delete[] taches;
    nb=0;
    nbmax=0;
}

Projet::Projet(const Projet& um):nb(um.nb),nbmax(um.nbmax), taches(new Tache*[um.nb]){
    for(int i=0; i<nb; i++) taches[i]=new Tache(*um.taches[i]);
}

Projet& Projet::operator=(const Projet& um){
    if (this==&um) return *this;
    this->~Projet();
    for(int i=0; i<um.nb; i++) addItem(new Tache(*um.taches[i]));
    return *this;
}

/*
string identificateur;
    string titre;
    Duree duree;
    Date disponibilite;
    Date echeance;
*/

/*

void Projet::load(const QString& f){
    if (file!=f) this->~Projet();
    file=f;
    ifstream fin(file.c_str()); // open file
    if (!fin) throw CalendarException("erreur, lors de l'ouverture du fichier de taches");
    char tmp[256];
    while (!fin.eof()&&fin.good()){
        fin.getline(tmp,256); // get code
        if (fin.bad()) throw CalendarException("erreur, fichier taches, lecture identificateur tache");
        string id=tmp;
        fin.getline(tmp,256); // get titre
        if (fin.bad()) throw CalendarException("erreur, fichier taches, lecture titre tache");
        string titre=tmp;

        Duree duree;
        fin>>duree;
        if (fin.bad()) throw CalendarException("erreur, fichier taches, lecture duree tache");

        Date dispo;
        fin>>dispo;
        if (fin.bad()) throw CalendarException("erreur, fichier taches, lecture date disponibilite");

        Date echeance;
        fin>>echeance;
        if (fin.bad()) throw CalendarException("erreur, fichier taches, lecture date echeance");
        while (fin.peek()=='\r') fin.ignore();
        while (fin.peek()=='\n') fin.ignore();
        std::cout<<"LOAD "<<id<<"-"<<titre<<"-"<<duree<<"-"<<dispo<<"-"<<echeance<<"\n";
        ajouterTache(id,titre,duree,dispo,echeance);
    }
    fin.close(); // close file
}

void  Projet::save(const string& f){
    file=f;
    ofstream fout(f.c_str(),ofstream::trunc); // toutes les taches existantes sont �cras�es
    for(unsigned int i=0; i<nb; i++){
        fout<<*taches[i];
    }
    fout.close();
}
*/
