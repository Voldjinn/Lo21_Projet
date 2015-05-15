#include <QApplication>
#include "fenetre_depart.h"


int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	FenetreDepart fenetre;
	fenetre.show();
    return app.exec();
}

