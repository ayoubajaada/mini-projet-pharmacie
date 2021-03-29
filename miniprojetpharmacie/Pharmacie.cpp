
#include "Pharmacie.hpp"

Pharmacie::Pharmacie(const string nom):nom(nom)
{
    
}

//return no de pharmacie
string Pharmacie::getNom()const{
    
    return nom;
}
//return nombre des clients
long Pharmacie::nClients()const{
    long n= listclient.size();

    return n;
}
//return nombre des medicamanets
long Pharmacie::nMedicaments()const{
    long n=listmedicament.size();
    
    return n;
}
//enregistrer Client
void  Pharmacie::enregistrerClient(const Client& c){
    
    listclient.push_back(c);
}
//enregistrer Medicament
void  Pharmacie::enregistrerMedicament(const Medicament& m){
    
    listmedicament.push_back(m);
}


//verifier Client et cout son adresse
void  Pharmacie::verifierClient(const string& nom) const{
    
    for (int i=0; i<nClients(); i++) {
        if (nom==listclient[i].getNom()) {
            cout<<" Adresse de client :"<<listclient[i].getNom()<<" est :"<<i<<endl;
            }
    }
    
    
}
//verifier Medicament et cout son adresse
int Pharmacie::verifierMedicament(const string& libelle) const{
    int a=-1;
    
    for (int i=0; i<nMedicaments(); i++) {
        if (libelle==listmedicament[i].getLibelle()) {
            //cout<<" Adresse de medicament  :"<<listmedicament[i].getLibelle()<<" est :"<<i<<endl;
            a=i;
            }
    }
    return a;
}

//affichage des clients
void Pharmacie::affichageClient()const{
    
    if(nClients()>0){
        for (int i=0; i<nClients(); i++) {
            cout<<" Client :"<<listclient[i].getNom()<<endl;
            cout<<" Credit :"<<listclient[i].getCredit()<<endl;
            }
    }
    else{
        cout<<"\t------ Aucun client n'a été enrigistré!! ------"<<endl;
        
    }
}

//affichage des medicaments
void Pharmacie::affichageMedicament(){
    
    if(nMedicaments()>0){
        for (int i=0; i<nMedicaments(); i++) {
            cout<<"Libelle :"<<listmedicament[i].getLibelle()<<endl;
            cout<<" Prix :"<<listmedicament[i].getPrix()<<endl;
            cout<<" Qte stock :"<<listmedicament[i].getQteStock()<<endl;
            }
    }
    else{
        cout<<"\t------ Aucun medicament n'a été enrigistré!! ------"<<endl;
        
    }
}

//approvisionner


void Pharmacie::approvisionner(const string &libelle,const int qte){
    int i=Pharmacie::verifierMedicament(libelle);
    if (i>=0) {
        listmedicament[i].augmenterStock(qte);
    }
}


//verifierAchat

bool Pharmacie::verifierAchat(const string& libelle,const int qte){
    bool n=false;
    for (int i=0; i<nMedicaments(); i++) {
        if (libelle==listmedicament[i].getLibelle()) {
            if (listmedicament[i].getQteStock()>=qte) {
              //  cout<<" l’achat de "<<listmedicament[i].getLibelle()<<" est possible"<<endl;
                n=true;
                   }
            else{
                cout<<" l’achat de "<<listmedicament[i].getLibelle()<<" est impossible"<<endl;

                }
            }
        else{
            cout<<" Ce medicament n'existe pas "<<endl;
              }
        }
    return n;
}


// achat


void Pharmacie::achat(const string & nom){
    for(int i =0;i<nClients();i++){
               if (listclient[i].getNom()==nom) {
                   string libelle1;
                   int qte;
                   cout<<"Libelle de medicament :";
                   cin>>libelle1;

                   if( verifierMedicament(libelle1)>=0)
                   {
                            cout<<"Qte : ";
                            cin>>qte;
                       if(verifierAchat(libelle1,qte)==true)
                       { double som;
                           som=qte*listmedicament[verifierMedicament(libelle1)].getPrix();
                           listclient[i].debiterCredit(som);
                           listmedicament[verifierMedicament(libelle1)].reduireStock(qte);
                           cout<<"L'achat a été bien effectué  "<<endl;
                        }
                       else{
                           cout<<"erreur !!!!  ";
                       }
               }
                
                   
               }
               else{
                   
                   cout<<"\t------ Aucun client n'a été enrigistré!! ------"<<endl;
               }
       
           }
    }
    
    
    //les noms des clients ayant un crédit inférieur à 0

string Pharmacie::fichDebit_nom()const
{
    string n;
    for (int i=0; i<nClients(); i++) {
        if (listclient[i].getCredit()<0) {
            n= listclient[i].getNom();
         
        }
    }
    return n;
}
    //les noms des clients ayant un crédit supérieur à 0
string Pharmacie::fichCredit_nom()const
{
    string n;
    for (int i=0; i<nClients(); i++) {
        if (listclient[i].getCredit()>0) {
            n= listclient[i].getNom();
         
        }
    }
    return n;
}


