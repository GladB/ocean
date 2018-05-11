#include <cstdlib>
#include <ctime>
#include <iostream>


#include "Ocean.h"
#include "camera.hxx"
#include "window.hxx"
#include "GerstnerWave.h"
#include "GerstnerWaveModel.h"
#include "PhilipsWaveModel.h"

Ocean* ocean;
int mainwindow;

int main(int argc, char** argv) {
  int lx = 300;
  int ly = 300;
  int nx = 160;
  int ny = 160;

  GerstnerWaveModel wm=GerstnerWaveModel(0.1,0.1,1,1,0.1,0.1,30);
  //PhilipsWaveModel wm=PhilipsWaveModel(1,0,1,1,1,0.1,lx,ly,nx,ny);

  Ocean ocean2(lx, ly, nx, ny, &wm);
  ocean=&ocean2;

  /* Initialisation de la fenêtre d'affichage */
  Window::init(WIDTH, HEIGHT, "Houle", argc, argv, "AZERTY", 50, 0.1);
  /* Execute la simulation */
  Window::launch();

  /* Libère la mémoire */
  Window::quit();
  delete ocean;

  return 0;

}
