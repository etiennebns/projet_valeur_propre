#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
double * * Gram_Schmidt(double * * A,int n);
double * * * decomposition_qr(double * * A,int n);
double methode_puissance(double * * A,int n);
double * methode_qr(double * * A,int n);
void normalise(double * x,int n);//
double * produit_matrice_vecteur(double * * A,double * x, int n);//
double norme (double * x, int n);//
double *  difference(double * x,double * y,int n);//
double * * produit_matricielle(double * * A,double * * B,int n);//
double max_triangle_inferieur(double * * A,int n);//
void affiche_vecteur (double *x, int n);
void affiche_matrice(double **A, int n);
#endif // FONCTIONS_H_INCLUDED
