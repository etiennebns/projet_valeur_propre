#include <iostream>
#include "fonctions.h"
#include <random>
using namespace std;

int main() {

    int n = 3;
    double eps=0.00001;
    // ========================
    // Test vecteurs
    // ========================
    double x[3] = {3, 4, 0};
    double y[3] = {1, 1, 1};

    cout << "Vecteur x : ";
    affiche_vecteur(x, n);

    cout << "Norme de x : " << norme(x, n) << endl;

    normalise(x, n);
    cout << "x normalise : ";
    affiche_vecteur(x, n);

    double* diff = difference(x, y, n);
    cout << "x - y : ";
    affiche_vecteur(diff, n);

    // ========================
    // Test matrices
    // ========================
    double **A = new double*[n];
    double **B = new double*[n];

    for(int i = 0; i < n; i++) {
        A[i] = new double[n];
        B[i] = new double[n];
    }

    // Initialisation
    double valA[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    double valB[3][3] = {
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            A[i][j] = valA[i][j];
            B[i][j] = valB[i][j];
        }
    }

    cout << "\nMatrice A :" << endl;
    affiche_matrice(A, n);

    cout << "\nMatrice B :" << endl;
    affiche_matrice(B, n);

    // Produit matrice-vecteur
    double* Ax = produit_matrice_vecteur(A, x, n);
    cout << "\nA * x : ";
    affiche_vecteur(Ax, n);

    // Produit matriciel
    double** C = produit_matricielle(A, B, n);
    cout << "\nA * B :" << endl;
    affiche_matrice(C, n);

    // Max triangle inférieur
    cout << "\nMax triangle inferieur de A : "
    << max_triangle_inferieur(A, n) << endl;

    //Methode de la puissance
    cout << "\nMethode de la puissance pour A :  "
    << methode_puissance(A,n,eps) << endl;
    // ========================
    // Libération mémoire
    // ========================
    for(int i = 0; i < n; i++) {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }

    delete[] A;
    delete[] B;
    delete[] C;
    delete[] diff;
    delete[] Ax;

    return 0;
}

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
//pour la méthode de la puissance il ne faut pas que x soit orthogonal aux vecteur que l'on essaye d'approcher, en choisissant x de maniere aléatoire on a une probabilité nul que cela arrive
double methode_puissance(double * * A,int n, double eps){
    double * x;
    x = new double [n];
    for (int i=0;i<n;i++)
        x[i]=double(rand());    //ici x ne change pas entre les appels de fonction, on pourrait cependant le faire varier a chaque appel
    normalise(x,n);
    double * y, *s;
    y= produit_matrice_vecteur(A,x,n);
    normalise(y,n);
    s=difference(x,y,n);
    while (norme(s,n)>eps){
        delete[] s;
        delete[] x;
        x=y;
        y= produit_matrice_vecteur(A,x,n);
        normalise(y,n);
        s=difference(x,y,n);
    }
    delete x;
    x=y;
    y= produit_matrice_vecteur(A,x,n);
    double lambda=norme(y,n);
    delete[] x;
    delete[] y;
    delete[] s;
    return lambda;
}















