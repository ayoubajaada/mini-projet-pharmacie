
#ifndef Pharmacie_hpp
#define Pharmacie_hpp

#include <stdio.h>
#include "Client.hpp"
#include "Medicament.hpp"

#include <string>
#include <iostream>
#include <vector>


class Pharmacie{
    
private:
    
    string nom;
    vector<Client> listclient;
    vector<Medicament> listmedicament;
    
    void afficherStocks() const;
    void afficherCredits() const;
    bool lireMedicament(int& nc) const;
    bool lireClient(int& nc) const;
    
public:
    
    Pharmacie(const string nom);
    string getNom()const;
    long nClients() const;
    long nMedicaments() const;
    void enregistrerClient(const Client& c);
    void enregistrerMedicament(const Medicament& m);
    void verifierClient(const string& nom) const;
    int verifierMedicament(const string& libelle) const;
    void approvisionner(const string& libelle,const int qte);
    bool verifierAchat(const string& libelle ,const int qte);
    void achat(const string &nom);
    void affichageClient()const;
    void affichageMedicament();
    
    string fichDebit_nom()const;
  
   string fichCredit_nom()const;
  

    

    
    
    
};

using namespace std;





#endif /* Pharmacie_hpp */
