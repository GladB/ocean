#ifndef FFT
#define FFT

#include <complex>
#include <vector>
#include <cmath>
#include <math.h>
#include <iostream>

#include "Ocean.h"

using namespace std;
typedef vector <complex<double> > vect;

extern Ocean* ocean;

/*!
*  \brief Calcul 1D de la FFT
*
*  \param x : vecteur de complexes dont on veut calculer la fft
*
*  \param deb : indice de début du sous-tableau sur lequel on applique la fft
*
*  \param fin : indice de fin(+1) du sous-tableau sur lequel on applique la fft
*
*/
void fft(vector <complex<double> > & x, int deb, int fin);

/*!
*  \brief Calcul 1D de la FFT inverse
*
*  \param x : vecteur de complexes dont on veut calculer la ifft
*
*  \param deb : indice de début du sous-tableau sur lequel on applique la ifft
*
*  \param fin : indice de fin(+1) du sous-tableau sur lequel on applique la ifft
*
*/
void ifft(vector <complex<double> > & x, int deb, int fin);

/*!
*  \brief Echange de deux valeurs par référence
*
*  \param a : première valeur
*
*  \param b : seconde valeur
*
*/
void swap(double &a, double &b);

/*!
*  \brief Calcul de la transposée d'une matrice carrée
*
*  \param h : matrice carrée sur laquelle on veut appliquer la transposition
*
*/
void transpose(vector <complex<double> > & h);

/*!
*  \brief Calcul 2D de la FFT
*
*  \param h : matrice carrée de côté de taille 2^n sur laquelle on veut appliquer la FFT
*
*/
void fft2D(vector <complex<double> > & h);

/*!
*  \brief Calcul 2D de la FFT inverse
*
*  \param h : matrice carrée de côté de taille 2^n sur laquelle on veut appliquer la iFFT
*
*/
void ifft2D(vector <complex<double> > & h);

#endif
