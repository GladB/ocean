#ifndef WAVE_MODEL
#define WAVE_MODEL


class WaveModel
{
public :

	double dirX;
	double dirY;
	double alignVagueVent;
	double intensite;
	double lOndeMoy;
	double ajustHautVague;

	virtual double operator () (int x, int y, int t)=0;

	WaveModel();
	WaveModel(double dirX, double dirY=0, double alignVagueVent=0, double intensite=0, double lOndeMoy=0, double ajustHautVague=0);
	~WaveModel();
	WaveModel(WaveModel const& w);
	WaveModel & operator=(const WaveModel & w);

	double getDirX(void) const;
	double getDirY(void) const;
	double getAlignVagueVent(void) const;
	double getIntensite(void) const;
	double getLOndeMoy(void) const;
	double getAjustHautVague(void) const;

};

#endif
