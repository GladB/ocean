#ifndef GERSTNER_WAVE_MODEL
#define GERSTNER_WAVE_MODEL
#include "WaveModel.h"
#include "GerstnerWave.h"
#include <vector>

/*! \class GerstnerWaveModel
 * \brief Modèle de Gerstner
 *
 *  Contient une liste d'ondes de Gerstner dont on fait la somme en chaque point pour trouver la hauteur de la houle
 */

class GerstnerWaveModel :
public WaveModel
{
 public:
    std::vector<GerstnerWave> listeGerstnerWave; /**< Liste des ondes */

    GerstnerWaveModel();
    ~GerstnerWaveModel();
    GerstnerWaveModel(double dirX, double dirY=0, double alignVagueVent=0, double intensite=0, double lOndeMoy=0, double ajustHautVague=0,int n=10);

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
    double operator () (int x, int y, int t);
};

#endif
