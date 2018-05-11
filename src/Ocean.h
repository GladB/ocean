#ifndef OCEANH
#define OCEANH

#include "Height.h"
#include "WaveModel.h"

/*! \class Ocean
 * \brief classe faisant la synthèse de toutes les données - calculs des hauteurs
 *
 */

class Ocean
{
 private :
  double lx;
  double ly;
  int nx;
  int ny;
  int t; /**< Temps */
  Height hauteur; /**< Tableau des hauteurs */
  WaveModel *model; /**< Choix du modèle */

 public :
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
*  \param _model : WaveModel - modèle de calcul de houle choisi
*
*/
  Ocean(double _lx, double _ly, int _nx, int _ny, WaveModel *_model);

  Ocean & operator =(const Ocean&);

  ~Ocean();

  /*!
 *  \brief Initialisation
 *
 * \param h : double - création et initialisation du tableau des hauteurs
 *
 */
  void generateHeight(double h);

  /*!
 *  \brief Calcul
 *
 * Calcul du tableau des hauteurs de houle au temps t
 *
 * \param t : int - temps
 *
 */
  void main_computation(int t); // calculer hauteur de la houle à l'instant t
  int getNx();
  int getNy();
  double get_lx();
  double get_ly();

/** Initialise la grille dans la direction x
 *  param[in]   y        abscisse de la colonne à parcourir
 *  param[out]  vertices buffer contenant les coordonnées des noeuds
 */
  void init_gl_VertexArrayX(const int y, double* const vertices) const ;

/** Initialise la grille dans la direction y
 *  param[in]   x        abscisse de la ligne à parcourir
 *  param[out]  vertices buffer contenant les coordonnées des noeuds
 */
  void init_gl_VertexArrayY(const int x, double* const vertices) const ;

/** Convertit le champs de hauteur en tabeau directement utilisable
 *  par OpenGL pour un y donné
 *  param[in]   y        abscisse de la colonne à parcourir
 *  param[out]  vertices buffer contenant les valeurs aux noeuds
 */
  void gl_VertexArrayX(const int y, double* const vertices) const ;

/** Convertit le champs de hauteur en tabeau directement utilisable
 *  par OpenGL pour un x donné
 *  param[in]   x        abscisse de la ligne à parcourir
 *  param[out]  vertices buffer contenant les valeurs aux noeuds
 */
  void gl_VertexArrayY(const int x, double* const vertices) const ;

};
#endif
