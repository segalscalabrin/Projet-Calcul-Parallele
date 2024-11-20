#ifndef INCLUDE_H
#define INCLUDE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <functional>

// #include "mpi.h"

using namespace std;

struct Parameters {
    // -------------------------------------------- //
    //              Parametres géométrique
    // -------------------------------------------- //

    // Taille du domaine
    double Lx;
    double Ly;
    double xmin;
    double ymin;

    // Nombre d'éléments par dimension
    int Nx;
    int Ny;

    // -------------------------------------------- //
    //              Parametres de l'équation
    // -------------------------------------------- //

    // Pas d'espace
    double dx;
    double dy;

    // Pas de temps
    double dt;

    // Coefficien D
    double D;

    // Temps max
    double Tmax;

    // -------------------------------------------- //
    //              Parametres des schémas
    // -------------------------------------------- //

    int Schema;

    // -------------------------------------------- //
    //              Autres parametres
    // -------------------------------------------- //

    // Cas
    int Cas;

    // -------------------------------------------- //
    //              Parametres de MPI
    // -------------------------------------------- //

    // Nombre de proc
    int nprocs;

    // Numéro du proc
    int rang;
};


struct Fonctions {
    // -------------------------------------------- //
    //                Fonctions
    // -------------------------------------------- //

    // Differentes fonctions f, g, h
    function<double(double, double, double, Parameters*)> f;
    function<double(double, double, double, Parameters*)> g;
    function<double(double, double, double, Parameters*)> h;
};


#endif // INCLUDE_H