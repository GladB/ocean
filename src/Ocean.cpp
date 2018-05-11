#include "Ocean.h"

Ocean::Ocean(double _lx, double _ly, int _nx, int _ny, WaveModel *_model){
  lx = _lx;
  ly = _ly;
  nx = _nx;
  ny = _ny;
  hauteur = Height(lx, ly, nx, ny);
  hauteur.init(0.0);
  model=_model;
}
Ocean::~Ocean(){
}

void Ocean::generateHeight(double h){
  hauteur = Height(lx, ly, nx, ny);
  hauteur.init(h);
}

void Ocean::main_computation(int t){
  for (int i=0; i<nx; i++){
    for(int j=0; j<ny; j++){
      hauteur(i,j)=(*model)(i,j,t);
    }
  }
}

int Ocean::getNx(){
  return nx;
}
int Ocean::getNy(){
  return ny;
}

double Ocean::get_ly(){
  return ly;
}

double Ocean::get_lx(){
  return lx;
}

void Ocean::init_gl_VertexArrayX(const int y, double* const vertices) const {
  for(int x=0 ; x<nx ; x++) {
    vertices[3*x]   = (lx/nx)*x;
    vertices[3*x+2] = (ly/ny)*y;
  }
  vertices[3*nx]   = lx;
  vertices[3*nx+2] = (ly/ny)*y;
}

void Ocean::init_gl_VertexArrayY(const int x, double* const vertices) const {
  for(int y=0 ; y<ny ; y++) {
    vertices[3*y]   = (lx/nx)*x;
    vertices[3*y+2] = (ly/ny)*y;
  }
  vertices[3*ny]   = (lx/nx)*x;
  vertices[3*ny+2] = ly;
}

void Ocean::gl_VertexArrayX(const int y, double* const vertices) const {
  for(int x=0 ; x<nx ; x++) {
    vertices[3*x+1] = hauteur(x,y); // pow ?
  }
  //vertices[3*nx+1] = hauteur(x,y); // pow ? // dafuq - x not even existing
}

void Ocean::gl_VertexArrayY(const int x, double* const vertices) const {
  for(int y=0 ; y<ny ; y++) {
    vertices[3*y+1] = hauteur(y,x);
  }
  vertices[3*ny+1]  = hauteur(0,x);
}
