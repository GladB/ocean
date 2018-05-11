#ifndef PHILIPS_WAVE_MODEL
#define PHILIPS_WAVE_MODEL
#include <vector>
#include <complex>
#include "WaveModel.h"
#include "Ocean.h"
using namespace std;

extern Ocean * ocean;

class PhilipsWaveModel : public WaveModel
{

private:

     int nx;
     int ny;
     int Lx;
     int Ly;
    vector< complex<double> > matriceH;
    vector<double> matriceW;

public:
  /*!
 *  \brief Constructeur
 *
 *  \param dirX : direction du vent selon X
 *
 *  \param dirY : direction du vent selon Y
 *
 *  \param alignVagueVent : alignement moyen entre les vagues et le vent
 *
 *  \param intensite : intensite du vent
 *
 *  \param lOndeMoy : longueur d'onde moyenne des vagues
 *
 *  \param ajustHautVague
 *
 */
    PhilipsWaveModel(double dirX, double dirY, double alignVagueVent, double intensite, double lOndeMoy, double ajustHautVague, int _lx, int _ly, int _nx, int _ny);

    /*!
   *  \brief Initialisation
   *
   *  Calcul des facteurs de Phillips selon k, ainsi que des fréquences w selon k
   *
   */
    void init();
    ~PhilipsWaveModel();

    /*!
    *  \brief Foncteur
    *
    *	 Calcul de la hauteur de l'onde en sommant celle de chaque onde de la liste en x,y à t
    *
    *  \param x : int - ligne
    *
    *  \param y : int - colonne
    *
    *  \param t : int  - temps
    *
    */
    double operator ()(int x, int y, int t) ;
};

#endif
