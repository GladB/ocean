#include "WaveModel.h"


WaveModel::WaveModel(){
    dirX=0;
    dirY=0;
    alignVagueVent=0;
    intensite=0;
    lOndeMoy=0;
    ajustHautVague=0;
}
WaveModel::~WaveModel(){
}

WaveModel::WaveModel(double _dirX, double _dirY, double _alignVagueVent, double _intensite, double _lOndeMoy, double _ajustHautVague){
    dirX=_dirX;
    dirY=_dirY;
    alignVagueVent=_alignVagueVent;
    intensite=_intensite;
    lOndeMoy=_lOndeMoy;
    ajustHautVague=_ajustHautVague;
}

WaveModel::WaveModel(WaveModel const& w){
    dirX=w.dirX;
    dirY=w.dirY;
    alignVagueVent=w.alignVagueVent;
    intensite=w.intensite;
    lOndeMoy=w.lOndeMoy;
    ajustHautVague=w.ajustHautVague;
}

WaveModel & WaveModel::operator=(const WaveModel & w){
    WaveModel &wm=*this;
    wm.dirX=w.dirX;
    wm.dirY=w.dirY;
    wm.alignVagueVent=w.alignVagueVent;
    wm.intensite=w.intensite;
    wm.lOndeMoy=w.lOndeMoy;
    wm.ajustHautVague=w.ajustHautVague;
    return wm;
}

double WaveModel::getDirX(void) const{
    return(dirX);
}

double WaveModel::getDirY(void) const{
    return(dirY);
}

double WaveModel::getAlignVagueVent(void) const{
    return(alignVagueVent);
}

double WaveModel::getIntensite(void) const{
    return(intensite);
}

double WaveModel::getLOndeMoy(void) const{
    return(lOndeMoy);
}

double WaveModel::getAjustHautVague(void) const{
    return(ajustHautVague);
}
