
#include "Medicament.hpp"
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

Medicament :: Medicament (const string&libelle,const double prix,const int qteStock)
    :libelle(libelle),prix(prix),qteStock(qteStock){}


const string& Medicament::getLibelle()const{
    return libelle;
}
double Medicament::getPrix()const{
  
    return prix;
}
int Medicament::getQteStock()const{
  
    return qteStock;
}

void Medicament::affichageMedicament()const{
    
    cout<<"-------------------------------------"<<endl;
    cout<<"\tLibelle :"<<" "<<this->getLibelle()<<"\n\tPrix :"<<" "<<this->getPrix()<<"\n\tla quantité en stock :"<<" "<<this->getQteStock()<<endl;}

//augmenter Stock
void Medicament::augmenterStock(const int qte){
    
    qteStock+=qte;
    
}
void Medicament::reduireStock(const int qte){
    
    qteStock-=qte;
    
}

