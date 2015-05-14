#ifndef FENETRE_DEPART_H
#define FENETRE_DEPART_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QScrollArea>
#include "emploidutemps.h"

class FenetreDepart : public QWidget{
	Q_OBJECT
private:
	QVBoxLayout *layout;
	QPushButton *affichageEdt;
	QPushButton *exportEdt;
	QPushButton *gestionProjet;
	QPushButton *exit;
public slots:
	void accesEdt();
	void accesProjet();
public:
	FenetreDepart(QWidget *parent = 0);
	~FenetreDepart();

};


class ChoixSemaine : public QWidget {
	Q_OBJECT
private:
	QGridLayout *lay;
	QPushButton *valider;
	QLabel *text;
	QDateEdit *choix;
public:
	ChoixSemaine(QWidget *parent = 0);
	~ChoixSemaine();
public slots:
	void accesEdT();
};


class ChoixProjet : public QWidget {
	Q_OBJECT
private:
	QGridLayout *lay;
	QPushButton *valider;
	QPushButton *newProjet;
	QPushButton *delProjet;
	QLabel *text;
	QScrollArea *listeProjets;
public:
	ChoixProjet(QWidget *parent = 0);
	~ChoixProjet();
};


#endif // FENETRE_DEPART_H
