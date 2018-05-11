#include "GerstnerWaveModel.h"
#include <cstdlib>
#include <ctime>
#include <iostream>


GerstnerWaveModel::GerstnerWaveModel(double dirX, double dirY, double alignVagueVent, double intensite, double lOndeMoy, double ajustHautVague,int n):WaveModel(dirX, dirY, alignVagueVent, intensite, lOndeMoy, ajustHautVague)
{
  srand(time(NULL));
  for (int i=0;i<n;i++){
    double r1=(((double)rand()/(double)RAND_MAX) - 0.1)*alignVagueVent;
    double r2=(((double)rand()/(double)RAND_MAX) - 0.1)*alignVagueVent;
    double ampl=intensite*ajustHautVague;
    GerstnerWave gw=GerstnerWave(ampl,0,dirX+r1,dirY+r2);
    listeGerstnerWave.push_back(gw);
}
}

GerstnerWaveModel::~GerstnerWaveModel(){

}

double GerstnerWaveModel::operator ()(int x, int y, int t){
  double s=0;
  for(int i=0;i<listeGerstnerWave.size();i++){
    s+=listeGerstnerWave[i](x,y,t);
  }
  return s;
}
