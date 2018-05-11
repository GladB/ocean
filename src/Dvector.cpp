#include <limits>
#include "Dvector.h"


Dvector::Dvector()
{
  this->dim = 0;
  val=NULL;
}


Dvector::Dvector(int n, double v)
{
  this->dim = n;
  val=new double[n];
  for (int i=0; i<n; i++)
    {
      val[i]=v;
    }

    //cout<<"Dvector constructeur"<<endl;
}

Dvector::~Dvector()
{
  delete [] val;
  //cout<<"Dvector destructeur"<<endl;
}

void Dvector::display(std::ostream& str)
{
  for (int i=0; i<this->dim; i++)
  {
    str<<val[i]<<"\n";
  }
}

int Dvector::size(void) const
{
  return this->dim;
}

void Dvector::fillRandomly(void)
{
  srand(time(NULL));

  for (int i = 0; i<this->dim; i++){
    this->val[i]=(rand()%100)/100.0;
  }
}

Dvector::Dvector(Dvector const& dv){
  int n = dv.dim;
  this->dim = n;
  this->val = new double[n];
  for (int i = 0; i<n; i++){
    this->val[i]=dv.val[i];
  }
  //memcpy(val, dv.val, n*sizeof(double))
}

Dvector::Dvector(std::string filename){
  ifstream fichier(filename.c_str(), ios::in);  // on ouvre le fichier en lecture
  if(fichier)  // si l'ouverture a réussi
        {

	  int nbLignes = 0;

	  while(fichier.ignore(numeric_limits<int>::max(), '\n')){

	    nbLignes++;
	  }
	  fichier.clear();
	  fichier.seekg(0, ios::beg);
	  // instructions

	  dim=nbLignes;
	  std::string ligne;
	  int i=0;
	  while (getline(fichier,ligne)){
	    fichier >> val[i];
	    i++;
	  }
	  fichier.close();  // on ferme le fichier
	}

        else  // sinon
	  {
	    this->dim=0;
	    this->val=NULL;
	  }

}

double & Dvector::operator()(int i) const{
  assert(i>=0 && i<size());
  return val[i];
}

double & Dvector::operator()(int i) {
  assert(i>=0 && i<size());
  return val[i];
}

Dvector & Dvector::operator+=(const Dvector &D) {
  if (size()!=D.size()){
    exit(-1);
  }
  Dvector &Dv = *this;
  for (int i=0; i<size(); i++){
    Dv(i)+=D(i);
  }
  return Dv;
}

Dvector & Dvector::operator+=(const double d) {
  Dvector &Dv = *this;
  for (int i=0; i<size(); i++){
    Dv(i)+=d;
  }
  return Dv;
}


Dvector & Dvector::operator-=(const Dvector &D) {
  if (size()!=D.size()){
    exit(-1);
  }
  Dvector &Dv = *this;
  for (int i=0; i<size(); i++){
    Dv(i)-=D(i);
  }
  return Dv;
}

Dvector & Dvector::operator-=(const double d) {
  Dvector &Dv = *this;
  for (int i=0; i<size(); i++){
    Dv(i)-=d;
  }
  return Dv;
}

Dvector & Dvector::operator*=(const double d) {
  Dvector &Dv = *this;
  for (int i=0; i<size(); i++){
    Dv(i)*=d;
  }
  return Dv;
}

Dvector & Dvector::operator/=(const double d) {
  Dvector &Dv = *this;
  for (int i=0; i<size(); i++){
    Dv(i)/=d;
  }
  return Dv;
}


Dvector & Dvector::operator=(const Dvector &D){
  if (size()!=D.size()){
    exit(-1);
  }
  Dvector &Dv = *this;
  for (int i=0; i<size(); i++){
    Dv(i)=D(i);
  }
  return Dv;
}

// à faire avec memcpy

bool Dvector::operator==(const Dvector &D){
  if (size()!=D.size()){
    return false;
  }
  for (int i=0; i<size(); i++){
    if (val[i]!=D(i)){
      return false;
    }
  }
  return true;
}




Dvector operator+(const Dvector &D, const double d){
  Dvector Dv(D);
  int max = D.size();
  for (int i=0; i<max; i++){
    Dv(i)+=d;
  }
  return Dv;
}

Dvector operator-(const Dvector &D, const double d){
  Dvector Dv(D);
  for (int i=0; i<D.size(); i++){
    Dv(i)-=d;
  }
  return Dv;
}

Dvector operator*(const Dvector &D, const double d){
  Dvector Dv(D);
  for (int i=0; i<D.size(); i++){
    Dv(i)*=d;
  }
  return Dv;
}

Dvector operator/(const Dvector &D, const double d){
  Dvector Dv(D);
  for (int i=0; i<D.size(); i++){
    Dv(i)/=d;
  }
  return Dv;
}

Dvector operator+(const Dvector &D1, const Dvector &D2){
  assert(D1.size()==D2.size());
  Dvector Dv(D1);
  for (int i=0; i<D1.size();i++){
    Dv(i)+=D2(i);
  }
  return Dv;
}

Dvector operator-(const Dvector &D1, const Dvector &D2){
  assert(D1.size()==D2.size());
  Dvector Dv(D1);
  for (int i=0; i<D1.size();i++){
    Dv(i)-=D2(i);
  }
  return Dv;
}

Dvector operator-(const Dvector &D){
  Dvector Dv(D.size());
  for (int i=0; i<D.size();i++){
    Dv(i)-=D(i);
  }
  return Dv;
}

ostream & operator <<(ostream &Out, const Dvector &D){
  for (int i=0; i<D.size(); i++){
    Out << D(i) << " ";
  }
  Out << endl;
  return Out;
}

istream & operator >>(istream &In, const Dvector &D){
  for (int i = 0; i<D.size(); i++){
    In >> D(i);
  }
  return In;
}
