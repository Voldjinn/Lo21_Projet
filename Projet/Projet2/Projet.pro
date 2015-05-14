QT+= widgets
    gui
    core
    xml

DISTFILES += \
    evenements.xml \
    programmations.xml \
    Projet.pro.user

HEADERS += \
    duree.h \
    emploidutemps.h \
    evenement.h \
    fenetre_depart.h \
    programmation.h \
    projet.h \
    tacheediteur.h

SOURCES += \
    duree.cpp \
    emploidutemps.cpp \
    evenement.cpp \
    fenetre_depart.cpp \
    main.cpp \
    programmation.cpp \
    projet.cpp \
    tacheediteur.cpp
