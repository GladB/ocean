#include <cstdlib>
#include <ctime>
#include <iostream>

/** @todo Inclure les fichiers de définition du problème */

#include "Ocean.h"
#include "camera.hxx"
#include "window.hxx"
#include "WaveModelConst.h"
#include "GerstnerWave.h"
#include "GerstnerWaveModel.h"
#include "PhilipsWaveModel.h"

Ocean* ocean;
int mainwindow;

int main(int argc, char** argv) {
  /** @todo Initialiser des paramètres de simulation */
// lx, ly, nx, ny
  int lx = 100;
  int ly = 100;
  int nx = 100;
  int ny = 100;

  /** @todo Initialiser du modèle*/
  GerstnerWaveModel wm=GerstnerWaveModel(1,1,1,1,1,0.1,10);
  cout << "testInit __" << " Y : " << wm.getDirY() << ", intensité : " << wm.getIntensite() << endl;
  //PhilipsWaveModel wm=PhilipsWaveModel(1,1,1,1,1,0.1);




  //WaveModelConst wm = WaveModelConst();
  /** @todo Initialiser du champ de hauteur */
  /*
  Ocean ocean2(lx, ly, nx, ny, &wm);
  ocean=&ocean2;
  */
  /** @todo Initialiser de l'océan */

  //delete ocean;

  return 0;

}
