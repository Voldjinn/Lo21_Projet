#include "fenetre_depart.h"

FenetreDepart::FenetreDepart(){
	layout = new QVBoxLayout;
	affichageEdt = new QPushButton("afficher Emploi du Temps");
	exportEdt = new QPushButton("exporter EdT");
	gestionProjet = new QPushButton("Gestion de Projets");
	exit = new QPushButton("Quitter");
	
	
	this->setLayout(layout);
	layout->addWidget(affichageEdt);
	layout->addWidget(exportEdt);
	layout->addWidget(gestionProjet);
	layout->addWidget(exit);


	QObject::connect(exit, SIGNAL(clicked()), this, SLOT(close()));
	QObject::connect(affichageEdt, SIGNAL(clicked()), this, SLOT(accesEdt()));
	QObject::connect(gestionProjet, SIGNAL(clicked()), this, SLOT(accesProjet()));
}

void FenetreDepart::accesEdt(){
	ChoixSemaine *popup = new ChoixSemaine;
	popup->show();
}
void FenetreDepart::accesProjet(){
	ChoixProjet *popup = new ChoixProjet;
	popup->show();
}


FenetreDepart::~FenetreDepart(){
	delete layout;
	delete affichageEdt;
	delete exportEdt;
	delete gestionProjet;
	delete exit;
}



ChoixSemaine::ChoixSemaine(){
	lay = new QGridLayout;
	valider = new QPushButton("valider");
	text = new QLabel("date :");
	choix = new QDateEdit;
    setLayout(lay);
	lay->addWidget(text, 0, 0);
	lay->addWidget(choix,1,0,1,3);
	lay->addWidget(valider, 2, 1, 1, 1);



	QObject::connect(valider, SIGNAL(clicked()), this, SLOT(accesEdT()));
}
void ChoixSemaine::accesEdT(){
	EmploiDuTemps *edt = new EmploiDuTemps(choix->date());
	edt->show();
	close();
}

ChoixSemaine::~ChoixSemaine(){
	delete lay;
	delete valider;
	delete text;
	delete choix;
}


ChoixProjet::ChoixProjet(){
	lay = new QGridLayout;
	valider = new QPushButton("Valider");
	newProjet = new QPushButton("Nouveau Projet");
	delProjet = new QPushButton("Supprimmer Projet");
	text = new QLabel("Projets disponibles : ");
	listeProjets = new QScrollArea;
	this->setLayout(lay);
    resize(450,250);
	lay->addWidget(text, 0, 0);
    lay->addWidget(listeProjets,1,0,5,1);
    lay->addWidget(newProjet,2,1);
    lay->addWidget(delProjet, 4, 1);
    lay->addWidget(valider,6,1);
    listeProjets->setWidgetResizable(true);
}

ChoixProjet::~ChoixProjet(){
	delete lay;
	delete valider;
	delete newProjet;
	delete delProjet;
	delete text;
	delete listeProjets;
}
