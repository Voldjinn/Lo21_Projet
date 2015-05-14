#include "tacheediteur.h"


TacheUnitaireEditeur::TacheUnitaireEditeur(TacheUnitaire& tacheToEdit, QWidget* parent){
	box = new QGridLayout(parent);
    setLayout(box);

    label_id = new QLabel("identificateur");
    id = new QLineEdit(tacheToEdit.getId());
    pre = new QCheckBox();
    pre->setChecked(tacheToEdit.isPreemptive());
    label_pre = new QLabel("preemptive");
    box->addWidget(label_id,0,0);
    box->addWidget(id,0,1,1,4);
    box->addWidget(pre,0,5);
    box->addWidget(label_pre,0,6);

    label_t = new QLabel("titre");
    titre = new QTextEdit(tacheToEdit.getTitre());
    box->addWidget(label_t,1,0);
    box->addWidget(titre,1,1,7,1);

    label_dispo = new QLabel("disponibilité");
    dispo = new QDateEdit(tacheToEdit.getDateDisponibilite());
    label_echeance = new QLabel("échéance");
    echeance = new QDateEdit(tacheToEdit.getDateEcheance());
    label_duree = new QLabel("durée");
    heureDebut = new QSpinBox(this);
    minDebut = new QSpinBox(this);
	heureDebut->setValue(tacheToEdit.getDuree().getDureeEnHeures());
    heureDebut->setSuffix(" heure(s)");
	minDebut->setValue(tacheToEdit.getDuree().getDureeEnMinutes());
    minDebut->setSuffix(" minute(s)");
	heureDebut = new QSpinBox(this);
	minDebut = new QSpinBox(this);
	label_dureeEffectue = new QLabel("durée Effectuée (si préemptive)");
	heureEffectue->setValue(tacheToEdit.getDureeEffectuee().getDureeEnHeures());
	heureEffectue->setSuffix(" heure(s)");
	minEffectue->setValue(tacheToEdit.getDureeEffectuee().getDureeEnMinutes());
	minEffectue->setSuffix(" minute(s)");
    box->addWidget(label_dispo,2,0);
    box->addWidget(dispo,2,1);
    box->addWidget(label_echeance,2,2);
    box->addWidget(echeance,2,3);
    box->addWidget(label_duree,2,4);
    box->addWidget(heureDebut,2,5);
	box->addWidget(minDebut, 2, 6);
	box->addWidget(label_duree, 3, 4);
	box->addWidget(heureEffectue,3,5);
	box->addWidget(minEffectue,3,6);

    annuler = new QPushButton("annuler");
    QObject::connect(annuler,SIGNAL(clicked()),this,SLOT(close()));
    saveButton = new QPushButton("sauvegarder",this);
    QObject::connect(saveButton,SIGNAL(clicked()),this,SLOT(save()));
    box->addWidget(annuler,4,0,1,3);
    box->addWidget(saveButton,4,4,1,4);

    tache = &tacheToEdit;
}

/*
void TacheUnitaireEditeur::save(){
    Duree d(heure->value(),min->value());
    if(id->text()==tache->getId()){
        tache->setTitre(titre->toPlainText());
        tache->setDatesDisponibiliteEcheance(dispo->date(),echeance->date());
        tache->setDuree(d);
        if(pre->isChecked())
            tache->setPreemptive();
        else
            tache->setNonPreemptive();
    }
}
*/