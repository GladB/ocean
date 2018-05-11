#ifndef GERSTNERWAVE
#define GERSTNERWAVE

/*! \class GerstnerWave
 * \brief classe representant une onde de Gerstner
 *
 */

class GerstnerWave
{

public :
	double ampl; /**< Amplitude de la vague */
	double phase; /**< Phase de l'onde */
	double dirX; /**< direction de l'onde en x, proche de direction moyenne du vent */
	double dirY; /**< direction de l'onde en y, proche de direction moyenne du vent */
	double freq; /**< Fréquence de l'onde */


public :

	GerstnerWave();
	GerstnerWave(double a, double p=0, double dx=0, double dy=0);
	GerstnerWave(GerstnerWave const&);
	~GerstnerWave();
	GerstnerWave & operator = (const GerstnerWave &);

	double getAmpl(void) const;
	double getPhase(void) const;
	double getDirX(void) const;
	double getDirY(void) const;
	double getFreq(void) const;

	/*!
	*  \brief Foncteur
	*
	*	 Calcul de la hauteur de l'onde en x,y à t
	*
	*  \param x : int - ligne
	*
	*  \param y : int - colonne
	*
	*  \param t : int  - temps
	*
	*/
	double operator ()(int x, int y, int t) const;
};
#endif
