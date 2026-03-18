#include "ville.h"
#ifndef TRAJET_H
#define TRAJET_H

class Trajet
{
private :
    Ville* ville1;
    Ville* ville2;
    size_t temps; //Indiqué ici en minutes comme pour le fichier .csv mais sera converti à l'affichage
public:
    Trajet(std::istream &is);
    ~Trajet();
    inline Ville* getVille1() const {return ville1;};
    inline Ville* getVille2() const {return ville2;};
    inline size_t getTemps() const {return temps;};
};

#endif // TRAJET_H
