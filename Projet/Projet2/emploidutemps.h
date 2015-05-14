#ifndef EMPLOIDUTEMPS_H
#define EMPLOIDUTEMPS_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QTableWidget>
#include <QHeaderView>
#include <QDate>

class EmploiDuTemps : public QWidget{
	Q_OBJECT
private:
	QPushButton * addEvent;
	QPushButton * exportXML;
	QPushButton * exportText;
	QPushButton * quitter;
	QTableWidget * tab;
	QGridLayout * lay;
	QStringList * week;
	QStringList  * hours;
public:
    EmploiDuTemps(QDate date);
	~EmploiDuTemps();
public slots :
	void editItem(QModelIndex & index);
};

#endif // EMPLOIDUTEMPS_H
