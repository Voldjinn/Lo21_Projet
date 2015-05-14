#ifndef DUREE_H
#define DUREE_H


class Duree{
private:
	unsigned int nbMinutes;
public:
	Duree(unsigned int h, unsigned int m) :nbMinutes(h * 60 + m) {}
	Duree(unsigned int m = 0) :nbMinutes(m) {}
	void setDuree(unsigned int heures, unsigned int minutes) {nbMinutes = heures * 60 + minutes; }
	unsigned int getDureeEnMinutes() const { return nbMinutes; } //<!Retourne la duree en minutes
	double getDureeEnHeures() const { return double(nbMinutes) / 60; } //<!Retourne la duree en heures

	Duree operator-(Duree const & other) const;
	Duree operator+=(Duree const & other);
};


#endif