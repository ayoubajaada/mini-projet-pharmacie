#ifndef Medicament_hpp
#define Medicament_hpp


#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Medicament{
private:
    string libelle;
    double prix;
    int qteStock;
    
public:
    Medicament(const string& libelle,const double prix,const int qteStock);
    void affichageMedicament()const;
   const  string& getLibelle()const;

    double getPrix()const;
    int getQteStock()const;
    void augmenterStock(const int qte);
    void reduireStock(const int qte);

};


#endif /* Medicament_hpp */
