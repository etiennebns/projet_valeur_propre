#include <iostream>
#include "fonctions.h"
using namespace std;

double *  difference(double * x,double * y,int n){
    double * z;
    z=new double[n];
    for (int i=0;i<n;i++)
        z[i]=x[i]-y[i];
    return z;
}

void normalise(double * x,int n){
    double n_x = norme(x,n);
    for (int i=0;i<n;i++)
        x[i]/=n_x;
}

double * * produit_matricielle(double * * A,double * * B,int n){
    double * * M;
    M = new double*[n];
    for (int i=0;i<n;i++){
        M[i]=new double[n];
        for (int j=0;j<n;j++){
            M[i][j]=0;
            for (int k =0;k<n;k++)
                M[i][j]+=A[i][k]+B[k][j];
        }
    }
    return M;
}

double max_triangle_inferieur(double * * A,int n){
    double m = 0;
    for (int i=1;i<n;i++){
        for (int j=0;j<i;j++){
            m=max(m,abs(A[i][j]));
            }
    }
    return m;
}

double norme (double * x, int n){
    double m =abs(x[0]);
    for (int i=1;i<n;i++)
        m=max(m,abs(x[i]));
    return m;
}

double * produit_matrice_vecteur(double * * A,double * x, int n){
    double * y =new double[n];
    for (int i =0;i<n;i++){
        y[i]=0;
        for (int j =0;j<n;j++){
            y[i]+=A[i][j]*x[j];
        }
    }
    return y;
}

void affiche_matrice(double **A, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << std::endl;
    }
}

void affiche_vecteur(double *x, int n) {
    for(int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    cout <<endl;
}
