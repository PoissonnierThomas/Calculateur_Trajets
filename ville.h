#include <string>
#include <region.h>
#ifndef VILLE_H
#define VILLE_H

class Ville
{
private :
    std::string nom, nom_ASCII, nomsalternatifs;
    double latitude, longitude;
    std::string pays, iso2, iso3;
    std::string région, capital;
    double densité, population, population_zone;
    short int ranking;
    std::string fuseau;
    bool nom_identique;
    size_t id;
public:
    Ville(std::istream &is);
    ~Ville();
    friend std::string operator<<(std::ostream &os, Ville);
    inline size_t getId()const{return id;}  ;
};

#endif // VILLE_H
