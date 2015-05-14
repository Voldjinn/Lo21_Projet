#include "Duree.h"

Duree Duree::operator-(Duree const & other) const{
	return Duree(nbMinutes - other.nbMinutes);
}

Duree Duree::operator+=(Duree const & other){
	nbMinutes += other.nbMinutes;
	return *this;
}