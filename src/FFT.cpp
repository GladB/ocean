#include "FFT.h"


void fft(vector <complex<double> > & x, int deb, int fin){
    
    int N = fin-deb;
    if(N<=1){
        return;
    }

    vector <complex<double> > even;
    vector <complex<double> > odd;

    for (int i=deb; i<deb+N; i=i+2){
        even.push_back(x[i]);
    }
    for (int j=deb+1; j<deb+N; j=j+2){
        odd.push_back(x[j]);
    }

    fft(even, 0, N/2);
    fft(odd, 0, N/2);

    for (int k=deb; k<deb+N/2; k++){
        complex<double> c(0.0,-2.0*M_PI*k/N);
        complex<double> t = odd[k-deb]*exp(c);
        x[k]=even[k-deb]+t;
        x[k+N/2]=even[k-deb]-t;
    }
    return;
}

void ifft(vector <complex<double> > & x, int deb, int fin){
    int N = fin-deb;
    if (N<=1){
        return;
    }
    //for(int i=0; i<N; i++){}
    for(int i=deb; i<deb+N; i++){
        x[i]=std::conj(x[i]);
    }
    fft(x,deb,fin);

    //for_each(xx.begin(),xx.end(),std::conj);
    for(int i=deb; i<deb+N; i++){
        x[i]=std::conj(x[i]);
    }
    return;
}

///////////////////////////////////////////////////

void swap(double &a, double &b){
    double c = a;
    a=b;
    b=c;
}

void transpose(vect& h){
    int nx = ocean->getNx();
    int ny = ocean->getNy();
    for(int j=0; j<ny; j++){
        for(int i=j+1; i<nx; i++){
        swap(h[i*ny+j],h[i+j*nx]);
        }
    }
}

////////////////////////////////////////////////////

void fft2D(vector <complex<double> > & h){
    int nx = ocean->getNx();
    int ny = ocean->getNy();
    for (int i=0; i<nx; i++){
        fft(h,i*ny, (i+1)*ny);
    }
    transpose(h);
    for(int j=0; j<ny; j++){
        fft(h, j*nx, (j+1)*nx);
    }
}

void ifft2D(vector <complex<double> > & h){
    int nx = ocean->getNx();
    int ny = ocean->getNy();
    for (int i=0; i<nx; i++){
        ifft(h,i*ny, (i+1)*ny);
    }
    transpose(h);
    for(int j=0; j<ny; j++){
        ifft(h, j*nx, (j+1)*nx);
    }
}
