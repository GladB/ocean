#ifndef DVECTORH
#define DVECTORH
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <assert.h>

using namespace std;

/*!
 * \file Dvector.h
 * \brief Vecteur de base (TP1 et TP2)
 * \author baudetgl-romeroq
 */


 /*! \class Dvector
  * \brief classe representant un vecteur de double
  *
  *  La classe gere la création, destruction et opérations s'appliquant aux vecteurs de double
  */

class Dvector
{
private :
  int dim; /**< Taille du vecteur */
  double *val; /**< Vecteur en lui-même */

  /**
  * Constructeurs, destructeurs
  */

  Dvector();

  public :

  /*!
 *  \brief Constructeur
 *
 *  Constructeur de la classe Dvector
 *
 *  \param n : int - taille du vecteur
 *  \param v : double - valeur initialement présente dans toutes les cases du vecteur
 */
  Dvector(int n, double v=0.0);

  /*!
 *  \brief Destructeur
 *
 *  Destructeur de la classe CPlayer
 */
  ~Dvector();

  /*!
 *  \brief Constructeur
 *
 *  Constructeur par copie de la classe Dvector
 *
 *  \param dv : Dvector - vecteur que l'on veut copier
 */
  Dvector(Dvector const&);

  /*!
 *  \brief Constructeur
 *
 *  Constructeur depuis un fichier de la classe Dvector
 *
 *  \param str : string - nom du fichier où se trouvent les valeurs que l'on veut mettre dans le Dvector
 */
  Dvector(std::string);

  /*!
   *  \brief Affichage d'un Dvector
   *
   */
  void display(std::ostream& str);


  int size(void) const;

  /*!
 *  \brief Remplissage aléatoire du vecteur
 *
 */
  void fillRandomly(void);

  /*!
   *  \brief Accès au i-ème élément du vecteur
   *
   * \param i : indice
   *
   */
  double & operator ()(int i);
  double & operator ()(int i) const;


  Dvector & operator+=(const Dvector &);
  Dvector & operator+=(const double);
  Dvector & operator-=(const Dvector &);
  Dvector & operator-=(const double);
  Dvector & operator*=(const double);
  Dvector & operator/=(const double);

  Dvector & operator=(const Dvector &);

  bool operator==(const Dvector &);

};

Dvector operator+(const Dvector &, const double d);
Dvector operator-(const Dvector &, const double d);
Dvector operator*(const Dvector &, const double d);
Dvector operator/(const Dvector &, const double d);

Dvector operator+(const Dvector &, const Dvector &);
Dvector operator-(const Dvector &, const Dvector &);
Dvector operator-(const Dvector &);

ostream & operator <<(ostream &Out, const Dvector &D);
istream & operator >>(istream &In, const Dvector &D);
#endif
