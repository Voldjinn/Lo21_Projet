#ifndef TACHEEDITEUR_H
#define TACHEEDITEUR_H

#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QBoxLayout>
#include <QString>
#include <QFileDialog>
#include <QSpinBox>
#include <QDateEdit>
#include <QLabel>
#include <QCheckBox>
#include "evenement.h"

class TacheUnitaireEditeur : public QWidget{
    Q_OBJECT
private:
    QGridLayout* box;
    QLineEdit* id;
    QTextEdit* titre;
    QSpinBox* heureDebut,*minDebut;
	QSpinBox* heureEffectue, *minEffectue;
    QDateEdit* dispo,*echeance;
    QLabel* label_id,*label_pre,*label_t,*label_dispo,*label_echeance,*label_duree,*label_dureeEffectue;
    QCheckBox* pre;
    QPushButton* annuler,*saveButton;
    Tache* tache;
public:
    explicit TacheUnitaireEditeur(TacheUnitaire& tacheToEdit, QWidget *parent = 0);
public slots:
    //void save();
};

#endif // TACHEEDITEUR_H
