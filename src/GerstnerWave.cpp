#include "GerstnerWave.h"
#include <cmath>

GerstnerWave::GerstnerWave(){
    ampl=0;
    phase=0;
    dirX=0;
    dirY=0;
    freq=0;
}

GerstnerWave::GerstnerWave(double a, double p, double dx, double dy){
    ampl=a;
    phase=p;
    dirX=dx;
    dirY=dy;
    freq=sqrt(9.81*sqrt(pow(dx,2)+pow(dy,2)))/300;
}

GerstnerWave::GerstnerWave(GerstnerWave const& gw){
    ampl=gw.ampl;
    phase=gw.phase;
    dirX=gw.dirX;
    dirY=gw.dirY;
    freq=gw.freq;
}

GerstnerWave::~GerstnerWave(){
}

GerstnerWave & GerstnerWave::operator = (const GerstnerWave &w){
    GerstnerWave &gw=*this;
    gw.dirX=w.dirX;
    gw.dirY=w.dirY;
    gw.ampl=w.ampl;
    gw.phase=w.phase;
    gw.freq=w.freq;
    return gw;
}

double GerstnerWave::getAmpl(void) const{
    return ampl;
}

double GerstnerWave::getPhase(void) const{
    return phase;
}

double GerstnerWave::getDirX(void) const{
    return dirX;
}

double GerstnerWave::getDirY(void) const{
    return dirY;
}

double GerstnerWave::getFreq(void) const{
    return freq;
}


double GerstnerWave::operator ()(int x, int y, int t) const{
    return((cos(dirX*x+dirY*y-freq*t+phase))*ampl);
}
