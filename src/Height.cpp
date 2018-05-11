#include "Height.h"


Height::Height()
{
  this->lx=10;
  this->ly=10;
  this->nx=1;
  this->ny=1;
}

Height::Height(double _lx, double _ly, int _nx, int _ny)
{
  this->lx=_lx;
  this->ly=_ly;
  this->nx=_nx;
  this->ny=_ny;
  for (int i=0; i<_nx*_ny; i++){
      this->h.push_back(0.0);
  }
}


Height::~Height(){
  //(this->h).~Dvector();
}

Height::Height(Height const& hgt)
{
  this->lx=hgt.getLx();
  this->ly=hgt.getLy();
  this->nx=hgt.getnx();
  this->ny=hgt.getny();
  this->h=hgt.h;
}

  //redef de =
Height & Height::operator=(const Height &hgt)
{

  this->lx=hgt.getLx();
  this->ly=hgt.getLy();
  this->nx=hgt.getnx();
  this->ny=hgt.getny();
  this->h=hgt.h;

  return *this;
}


void Height::init(double _h){
  for(int i=0; i<nx*ny; i++){
    h[i]=_h;
  }
}

  //redef de () (foncteur)
double & Height::operator () (int i, int j)
{
  int ind = (this->nx)*i+j;
  if (ind<0 || ind>=(this->nx)*(this->ny))
    {
      exit(-1);
    }
  return (this->h)[ind];
}

double Height::operator () (int i, int j) const
{
  int ind = (this->ny)*i+j;
  if (ind<0 || ind>=(this->nx)*(this->ny))
    {
      exit(-1);
    }
  return (this->h)[ind];
}

  //accesseurs
double Height::getLx(void) const
{
  return this->lx;
}
double Height::getLy(void) const
{
  return this->ly;
}
int Height::getnx(void) const
{
  return this->nx;
}
int Height::getny(void) const
{
  return this->ny;
}

ostream & operator <<(ostream &Out, Height const &hgt){
  //Height hh(hgt.lx, hgt.ly,hgt.nx, hgt.ny);
  for (int i=0; i<hgt.getnx(); i++){
    for (int j=0; j<hgt.getny(); j++) {
      Out << i << " " << j << " "<< hgt(i,j) << endl;
    }
    Out << endl;
  }
  Out << endl;

  return Out;
}
