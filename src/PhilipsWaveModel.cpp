#include "PhilipsWaveModel.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <random>
#include "FFT.h"

PhilipsWaveModel::PhilipsWaveModel(double dirX, double dirY, double alignVagueVent, double intensite, double lOndeMoy, double ajustHautVague, int _lx, int _ly, int _nx, int _ny):WaveModel(dirX, dirY, alignVagueVent, intensite, lOndeMoy, ajustHautVague)
{
  nx=_nx;
  ny=_ny;
  Lx=_lx;
  Ly=_ly;
  init();
}

PhilipsWaveModel::~PhilipsWaveModel(){

}

void PhilipsWaveModel::init(){
  // vecteur k
  double kx;
  double ky;
  double k2; /**< norme au carré de k */
  double k4; /**< norme exposant 4 de k */

  double w; /**< fréquence */

  double A = 1;
  double L = 10;
  double ph; /**< Coefficient de Phillips */

  double h;

  for(int n=-(nx/2); n<nx/2+1;n++){
    for (int m=-ny/2; m<ny/2+1;m++){

      kx = 2*M_PI*n/Lx;
      ky = 2*M_PI*m/Ly;
      k2 = kx*kx+ky*ky;
      k4 = k2*k2;

      w = sqrt(9.81*sqrt(k2));
      matriceW.push_back(w);

      if (k2 < 0.0001) {
        ph = 0;
      }
      else {
        ph = A*exp(-1/((k2)*L*L))*pow(kx*dirX+ky*dirY,2)/(k2);
      }

      h = (1/sqrt(2))*sqrt(ph);
      matriceH.push_back(h);

    }
  }

}

double PhilipsWaveModel::operator ()(int x, int y, int t) {


  vector< complex<double> > res;

  double r1, r2;
  default_random_engine generator;
  normal_distribution<double> distribution(0.0,1.0);

  for(int p=0; p<nx*ny; p++){

    r1=distribution(generator);
    r2=distribution(generator);

    complex<double> tmp(0, matriceW[p]*t);
    complex<double> r(r1, r2);

    complex<double> ajout (matriceH[p]*(exp(tmp)*r + conj(exp(tmp)*r)));
    res.push_back(ajout);
  }

  ifft2D(res);


  for (int i=0;i<ocean->getNx();i++){
    for (int j=0;j<ocean->getNy();j++){
      cout<<matriceH[i*ocean->getNy()+j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;

  return(real(res[x*ny+y]));

}
