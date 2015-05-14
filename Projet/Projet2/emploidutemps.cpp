#include "emploidutemps.h"




EmploiDuTemps::EmploiDuTemps(QDate date, QObject *parent){
	date.addDays(-date.dayOfWeek() + 1);   //permet d'avoir le lundi correspondant à n'importe quel jour d'une semaine
	/*
	
		Chercher dans les événements tous les événements planifiés pour entre date et date+6
		les inséderer dans le tableau	
	
	*/	
	
	addEvent = new QPushButton("Ajouter Evenement");
	exportXML = new QPushButton("Exporter la semaine en XML");
	exportText = new QPushButton("Exporter la semaine en Texte");
	quitter = new QPushButton("Fermer");
	tab = new QTableWidget(15,7);
	lay = new QGridLayout();
	week = new QStringList();
	hours = new QStringList();
	*week << "Lundi" << "Mardi" << "Mercredi" << "Jeudi" << "Vendredi" << "Samedi" << "Dimanche";
	for (int i(7); i < 22; i++)
		*hours << (QString::number(i) + "h");

	setLayout(lay);
	resize(1000, 700);
	lay->addWidget(addEvent,0,0);
	lay->addWidget(exportXML,0,3);
	lay->addWidget(exportText,0,4);
	lay->addWidget(tab,1,0,4,5);
	lay->addWidget(quitter,5,4);
	tab->setVerticalHeaderLabels(*hours);
	tab->setHorizontalHeaderLabels(*week);
	tab->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  //permet au tableau de changer de taille dynamiquement
	tab->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	
		
	tab->setSelectionBehavior(QAbstractItemView::SelectItems); //limite la selection a un item
	tab->setSelectionMode(QAbstractItemView::SingleSelection);
	QObject::connect(tab, SIGNAL(clicked(index)), this, SLOT(editItem(index)));  //Rend les cases renseignées du tableau cliquables : elles ouvrent la fenetre de modification d'événement


	QObject::connect(quitter, SIGNAL(clicked()), this, SLOT(close()));
}


void EmploiDuTemps::editItem(QModelIndex& index){
	/*
		lance la fenetre d'edition de tache sur la tache pointée par "tab->indexWidget(index)"
	
	
	
	
	*/

}

EmploiDuTemps::~EmploiDuTemps(){
	delete addEvent;
	delete exportXML;
	delete exportText;
	delete quitter;
	delete lay;
	delete tab;
	delete week;
	delete hours;
}