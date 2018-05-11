#include "Height.h"
//#include "WaveModel.h"
#include "GerstnerWave.h"
#include "Ocean.h"
#include "camera.hxx"
#include "window.hxx"


Ocean* ocean;
int mainwindow;

int main(){
    Height h;
    h = Height(10,10,10,10);
    h.init(2.0);
    cout<<h(2,2)<<endl;
    cout<<h;
    return 0;
}


/*
int main(){
cout<<"Début\n";
Dvector dv = Dvector(4);
Dvector dv2 = dv;
cout<<dv2.size()<<endl;

}
*/
