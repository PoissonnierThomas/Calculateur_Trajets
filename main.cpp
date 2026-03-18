#include "mainwindow.h"
#include "ville.h"
#include "trajet.h"
#include <fstream>
#include <QApplication>
#include <QLabel>


void chargerDonnees() {
    try {
        // Lecture du fichier des villes
        std::ifstream fichierVilles("villes.csv");
        if (!fichierVilles.is_open()) {
            statusLabel->setText("Erreur: Impossible d'ouvrir le fichier villes.csv");
            return;
        }

        // Ignorer la ligne d'en-tête
        std::string entete;
        std::getline(fichierVilles, entete);

        // Lire les villes
        while (fichierVilles.good() && !fichierVilles.eof()) {
            Ville* ville = new Ville(fichierVilles);
            if (fichierVilles.good()) {
                villes.push_back(ville);
                villesParId[ville->getId()] = ville;
            }
        }
        fichierVilles.close();

        // Lecture du fichier des trajets
        std::ifstream fichierTrajets("temps.csv");
        if (!fichierTrajets.is_open()) {
            statusLabel->setText("Erreur: Impossible d'ouvrir le fichier temps.csv");
            return;
        }

        // Ignorer la ligne d'en-tête
        std::getline(fichierTrajets, entete);

        // Lire les trajets
        while (fichierTrajets.good() && !fichierTrajets.eof()) {
            Trajet* trajet = new Trajet(fichierTrajets);
            if (fichierTrajets.good()) {
                trajets.push_back(trajet);
            }
        }
        fichierTrajets.close();

        // Résoudre les références entre les trajets et les villes
        resoudreReferences();

        // Afficher les données dans l'interface
        afficherDonnees();

        statusLabel->setText("Données chargées avec succès!");

    } catch (const std::exception& e) {
        statusLabel->setText(QString("Erreur lors du chargement des données: %1").arg(e.what()));
    }
}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
