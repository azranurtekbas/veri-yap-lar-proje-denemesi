#include<iostream>
#include<iomanip>
#include<fstream> 

using namespace std;


  
int main() 
{
  ifstream    dosya("veriler.txt");
    
   
    if(dosya.is_open())
     {
       string satir;
       std::getline(dosya,satir);
       cout<< satir<<endl;

       /*int nextsayi;
       stringstream satirokuyucu(satir);

       while(satirokuyucu>>nextsayi)
       cout<<nextsayi;
     */
    }
 
}


  