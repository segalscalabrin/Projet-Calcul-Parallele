#include "save_sol.h"

void save_solution(vector<double> *U, int ite, Parameters *param, bool exacte)
{
    string str_ite, str_Nx, str_Ny;
    str_ite = to_string(ite);
    str_Nx = to_string(param->Nx);
    str_Ny = to_string(param->Ny);
    string name_file;

    name_file = "solutions/";

    if (param->Cas == 4) {
        name_file += "personnalise_"+str_Nx+"_"+str_Ny+"/";
    }
    else if (param->Cas == 1) {
        name_file += "stationnaire_1_"+str_Nx+"_"+str_Ny+"/";
    }
    else if (param->Cas == 2) {
        name_file += "stationnaire_2_"+str_Nx+"_"+str_Ny+"/";
    }
    else if (param->Cas == 3) {
        name_file += "instationnaire_"+str_Nx+"_"+str_Ny+"/";
    }

    if (exacte)
    {
        name_file += ("sol_exacte/sol_exacte."+str_ite+".dat");  // Le nom de mon fichier
    }
    else 
    {
        name_file += ("sol/sol."+str_ite+".dat");  // Le nom de mon fichier
    }

    ofstream mon_flux;
    mon_flux.open(name_file, ios::out);  // Ouvre un fichier appelé name_file

    if (mon_flux)                        // Vérifie que le fichier est bien ouvert
    {
        double x, y;
        for (int j = 0; j<param->Ny; j++) {
            for (int i = 0; i<param->Nx; i++) {
                x = param->xmin + i*param->dx;
                y = param->ymin + j*param->dy;
                mon_flux << x << " " << y << " " << (*U)[j*param->Nx + i] << endl;
            }
        }        
    }
    else // Renvoie un message d'erreur si ce n'est pas le cas
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier de solution." << std::endl;
    }
    mon_flux.close(); // Ferme le fichier
}


void save_error (vector<double> *error, Parameters *param)
{
    string str_Nx, str_Ny;
    str_Nx = to_string(param->Nx);
    str_Ny = to_string(param->Ny);
    string name_file;

    name_file = "solutions/";

    if (param->Cas == 0) {
        name_file += "personnalise_"+str_Nx+"_"+str_Ny+"/";
    }
    else if (param->Cas == 1) {
        name_file += "stationnaire_1_"+str_Nx+"_"+str_Ny+"/";
    }
    else if (param->Cas == 2) {
        name_file += "stationnaire_2_"+str_Nx+"_"+str_Ny+"/";
    }
    else if (param->Cas == 3) {
        name_file += "instationnaire_"+str_Nx+"_"+str_Ny+"/";
    }

    name_file += "error.dat";

    ofstream mon_flux;
    mon_flux.open(name_file, ios::out);  // Ouvre un fichier appelé name_file

    if (mon_flux)                        // Vérifie que le fichier est bien ouvert
    {
        double t(0);
        int k(0);
        
        while(t < param->Tmax) {
            mon_flux << t << " " << (*error)[k] << endl;
            t += param->dt;
            k += 1;
        }   
    }
    else // Renvoie un message d'erreur si ce n'est pas le cas
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier d'erreur." << std::endl;
    }
    mon_flux.close(); // Ferme le fichier
}


/*
void save_solution_exacte (std::vector<double> U, int ite, double dx, double dy, int np, int me)
{
    int cas, Nx, Ny, space_scheme, time_scheme;
    double xmin, xmax, ymin, ymax, Tf, CFL;
    get_parameters(&cas, &Nx, &Ny, &space_scheme, &time_scheme, &xmin, &xmax, 
    &ymin, &ymax, &Tf, &CFL);

    double x, y;
    int k(0), iBeg, iEnd, i, j;

    charge(me, (Nx+1)*(Ny+1), np, &iBeg, &iEnd);
    int n_loc = iEnd-iBeg+1;

    string ps, str_me;
    ps = to_string(ite);
    str_me = to_string(me);
    string name_file("sol_exacte."+ps+".00"+str_me+".dat");  // Le nom de mon fichier
    ofstream mon_flux;
    mon_flux.open(name_file, ios::out);  // Ouvre un fichier appelé name_file

    if (mon_flux)                        // Vérifie que le fichier est bien ouvert
    {
        for (int k = 0; k<= n_loc ; k++)
        {
            j = (k+iBeg)/(Nx+1);
            i = (k+iBeg)-j*(Nx+1);
            x = xmin + i*dx;
            y = ymin + j*dy;
            mon_flux << x << " " << y << " " << U[k] << std::endl;
            x += dx;
        }
        
    }
    else // Renvoie un message d'erreur si ce n'est pas le cas
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
    mon_flux.close(); // Ferme le fichier
}*/