#ifndef HEIGHTH
#define HEIGHTH

#include "Dvector.h"
#include<vector>
using namespace std;

/*! \class Height
 * \brief classe representant un tableau 2D de double
 *
 */

class Height
{
 private:
  double lx; /**< taille de la boite */
  double ly; /**< taille de la boite */
  int nx; /**< nb discretisation en x */
  int ny; /**< nb discretisation en y */


  std::vector<double> h; /**< Vecteur de double contenant les valeurs*/

    public:
  //constructeurs
  Height();

  /*!
 *  \brief Constructeur
 *
 * \param _lx : int - taille
 *
 *  \param _ly : taille
 *
 *  \param nx : int - nb discrétisation en x
 *
 *  \param ny : int - nb discretisation en y
 *
 */
  Height(double _lx, double _ly=1.0, int _nx=1, int _ny=1);

  ~Height();

  Height(Height const&);

  //redef de =
  Height & operator=(const Height&);

  /*!
 *  \brief Initialisation
 *
 *  Met tous les éléments du tableau à _h
 *
 * \param _h : double - valeur d'initialisation
 *
 */
  void init(double _h);

  //redef de () (foncteur) retourne tab(nx*i+j)
  /*!
 *  \brief Foncteur
 *
 *  Accès à l'élément (i,j) (indice : i*ny + j) en rvalue
 *
 * \param i : int - ligne
 *
 *  \param j : int - colonne
 *
 */
  double operator () (int i, int j) const;

  /*
  *  \brief Foncteur
  *
  *  Accès à l'élément (i,j) (indice : i*ny + j) en lvalue
  *
  * \param i : int - ligne
  *
  *  \param j : int - colonne
  *
  */

  double & operator () (int i, int j);

  //accesseurs

  /*!
 *  \brief Accesseur lx
 *
 */
  double getLx(void) const;
  /*!
 *  \brief Accesseur ly
 *
 */
  double getLy(void) const;
  /*!
 *  \brief Accesseur nx
 *
 */
  int getnx(void) const;
  /*!
 *  \brief Accesseur ny
 *
 */
  int getny(void) const;

};

/*
*  \brief Affichage
*
*  Affichage de h sur le stream Out
*
*/

  ostream & operator <<(ostream &Out, const Height &H);
#endif
