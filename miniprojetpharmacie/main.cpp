

#include <iostream>
#include <algorithm>
#include <vector>
#include "Pharmacie.hpp"
#include "Client.hpp"
#include "Medicament.hpp"
#include <fstream>


//globale variable
string nompharmacie;
   //variable de client
   string nomclient;
   double creditclient;
   //variable de medicament
   string libellem;
   double prixm;
   int qtem;


int cl=0;
int me=0;



string expharmacie="cette pharmacie n'existe pas !!";


//verify pharmacie par sa nom et return index

int verifyp(string nom,vector<Pharmacie> &p){
   int n=-1;
   for (int i=0; i<p.size(); i++) {
       if (nom==p[i].getNom()) {
        
           n=i;
       }
      }
   return n;
   
}


//fonction d'ajouter un client
void ajouterclient(vector<Pharmacie> &p){
  
   cout<<"-------------------------------------"<<endl;
   cout<<"---------enregistrer Client----------"<<endl;
   cout<<"Nom de pharmacie :";
  cin>>nompharmacie;

   if (verifyp(nompharmacie, p)>-1)
       {
           
           cout<<"Nom de client :";
           cin>>nomclient;
           cout<<" credit de client :";
           cin>>creditclient;
           Client c(nomclient,creditclient);
          p[verifyp(nompharmacie, p)].enregistrerClient(c);
           cl=1;
       }
   else{
       cout<<expharmacie<<endl;
   }
}


//fonction d'ajouter un medicament
void ajoutermedicament(vector<Pharmacie> &p){
   
       cout<<"-------------------------------------"<<endl;
       cout<<"-------enregistrer Medicament--------"<<endl;
       cout<<"Nom de pharmacie :";
       cin>>nompharmacie;
       
       if (verifyp(nompharmacie, p)>-1)
           {
               
               cout<<"Libelle :";
               cin>>libellem;
               cout<<" Prix :";
               cin>>prixm;
               cout<<" Qte stock :";
               cin>>qtem;
               
               Medicament m(libellem,prixm,qtem);
               p[verifyp(nompharmacie, p)].enregistrerMedicament(m);
               me=1;
           }
       else{
           cout<<expharmacie<<endl;
       }
}

//fonction d'afficher un client

void afficherclient(vector<Pharmacie> &p){
   
       cout<<"-------------------------------------"<<endl;
       cout<<"---------Liste des Clients----------"<<endl;
       cout<<"Nom de la pharmacie :";
       cin>>nompharmacie;
       if (verifyp(nompharmacie, p)>-1) {
           p[verifyp(nompharmacie, p)].affichageClient();
       }
       
       else{
           cout<<expharmacie<<endl;
       }
}
//fonction d'afficher un medicament
void affichermedicament(vector<Pharmacie> &p){
   
       cout<<"-------------------------------------"<<endl;
       cout<<"--------Liste des Medicament---------"<<endl;
       cout<<"Nom de la pharmacie :";
       cin>>nompharmacie;
       if (verifyp(nompharmacie, p)>-1) {
           p[verifyp(nompharmacie, p)].affichageMedicament();
       }
       
       else{
           cout<<expharmacie<<endl;
       }
}

//achat

void achat(vector<Pharmacie> &p){
    cout<<"-------------------------------------"<<endl;
    cout<<"--------Liste des Medicament---------"<<endl;
    cout<<"Nom de la pharmacie :";
    cin>>nompharmacie;
    if (verifyp(nompharmacie, p)>-1) {
        cout<<"Nom de client :";
        cin>>nomclient;
        p[verifyp(nompharmacie, p)].achat(nomclient);
    }
    else{
        cout<<"Cette pharmacie n'existe pas !!"<<endl;
    }
    
}

char mainlist(){
   char rep;
   cout<<"----------------------------------------------------------"<<endl;
   cout << "\tEnter  : 'P' pour enregistrer une Pharmacie"<<endl;
   cout << "\tEnter  : 'I' pour afficher les listes des Pharmacies"<<endl;
   cout << "\tEnter  : 'C' pour enregistrer un client"<<endl;
   cout << "\tEnter  : 'M' pour enregistrer un medicament"<<endl;
   cout << "\tEnter  : 'A' pour l'affichage\n";
   cout << "\tEnter  : 'U' pour approvisionner\n";
   cout << "\tEnter  : 'T' pour  traiter l’achat\n";
    
   cout << "\tEnter  : 'R' pour  rechercher un medicament dnas les pharmacies\n";
   cout << "\tEnter  : 'V' pour  verifier l'achat d'un medicament\n";
    
   cout << "\tEnter  : 'Q' pour quitter\n";
   cout<<"----------------------------------------------------------"<<endl;

   cout<<"\tRéponse : ";
   cin>>rep;
   return rep;
}
char minimainlist(){
   char rep;
   cout<<"-------------------------------------"<<endl;
   cout<<"\tEnter votre prochaine étape "<<endl;
   cout<<"\tOu 'L' pour afficher la liste  : "<<endl;;

   cin>>rep;
   return rep;
}

int secondlist(){
  int  rep;
   cout<<"----------------------------------------------------"<<endl;
   cout << "\tEnter numero : '1' pour afficher les clients"<<endl;
   cout << "\tEnter numero : '2' pour affichager les medicaments"<<endl;
   cout << "\tEnter numerp : '0' pour returner \n"<<endl;
   cout<<"----------------------------------------------------"<<endl;
   cout<<"\tRéponse : ";
   cin>>rep;
   return rep;
}
int minisecondlist(){
   int  rep;
   cout<<"----------------------------------------------------"<<endl;
   cout<<"\tEnter votre prochaine étape "<<endl;
   cout<<"\tOu '3' pour afficher la liste  : ";
   cin>>rep;
   return rep;
}



//sauvegar des Clients
void sauvegarderClients(vector<Pharmacie> &p){
    
    ofstream fichDebit,fichCredit;

//    fichDebit.open("/Users/mac/Documents/LUS genie informatique/Algorithmique et programmation en C++/pharmacie1/fichDebit.txt");
    fichDebit.open("fichDebit.dat");
    for (int i=0; i<p.size(); i++) {
        fichDebit<< "---------------------------------------"<<endl;
        fichDebit<< "\t\t\tPharmacie :"<<p[i].getNom()<<endl;
        for (int i=0; i<p.size(); i++) {
            
            fichDebit<< "Nom de client :"<<p[i].fichDebit_nom()<<endl;
           
        }
       
    }
   

    fichDebit.close();
    
//    fichCredit.open("/Users/mac/Documents/LUS genie informatique/Algorithmique et programmation en C++/pharmacie1/fichCredit.txt");
    fichCredit.open("fichCredit.dat");
    for (int i=0; i<p.size(); i++) {
        fichDebit<< "---------------------------------------"<<endl;
        fichDebit<< "\t\t\tPharmacie :"<<p[i].getNom()<<endl;
        for (int i=0; i<p.size(); i++) {
            
            fichDebit<< "Nom de client :"<<p[i].fichCredit_nom()<<endl;
           
        }
       
    }
   
    fichCredit.close();
    cout<<"sauvegarder Clients seccuss!!"<<endl;
}



//rechercher un medicament dnas touts les pharmacies

void rechermedicament(vector<Pharmacie> &p){
    int l=0;
    cout<<"---------- Recherche Medicament"<<endl;
    cout<<"Tape libelle de medicament : ";
    cin>>libellem;
    for (int i=0; i<p.size(); i++) {
        if (p[i].verifierMedicament(libellem)>=0) {
            cout<<"Le medicament :"<<libellem<<"\texiste dans la pharmacie\t "<<p[i].getNom()<<endl;
            l=1;
        }
    }
    if (l==0) {
        cout<<"Ce medicament n'existe pas !!"<<endl;
    }
    
    
}


int main(int argc, const char * argv[]) {
   
    vector<Pharmacie>p;

  
   
    

    //reponse de switch
    char reponse;


   
    reponse= mainlist();

while(reponse!='q')
{

    switch (reponse)
        {
//Ajouter pharmacie
        case 'p':
        case 'P':{
        
                cout<<"Nom de pharmacie :";
                cin>>nompharmacie;
                p.push_back(nompharmacie);
              
            reponse=minimainlist();
            break;
        
        }
        
//--afficher pharmacie
        case 'i':
        case 'I':{
        
            for (int i=0; i<p.size(); i++) {
                cout<<"Pharmacie :"<<p[i].getNom()<<endl;
            }
            reponse=minimainlist();
            break;
        
        }
        
///ajouter client
        
    case 'c':
    case 'C':
            {while(cl==0){
                ajouterclient(p);
            }
                cl=0;
          

        reponse=minimainlist();
            break;
        }
///ajouter medicament
                
            case 'm':
            case 'M':
            {   while(me==0){
                  ajoutermedicament(p);
                
                    }
                me=0;
                  reponse=minimainlist();
                    break;
                }
//Afficher medicament et client
        
    case 'A':
    case 'a':
            {
                    int rep;
                            rep=secondlist();
                
                
                    while (rep!=0) {
                                    switch (rep)
                                    {
                                            
                            //afficher clinet
                                case 1:
                                        {
                                            afficherclient(p);
                                        rep=minisecondlist();
                                    
                                    break;}
                                case 2:
                                        {
                                            affichermedicament(p);
                                            rep=minisecondlist();
                                
                                    break;}
                                case 3:
                                        {
                                  rep=secondlist();
                                            
                                    break;}
                                        default:
                                        {
                                            cout<<"-------------------------------------"<<endl;
                                            cout<<"Le character incorrect !! :"<<endl;
                                            cout<<"\tEnter votre prochaine étape  "<<endl;
                                            cout<<"\tOu '3' pour afficher la liste  : ";
                                            cin >> reponse;
                                            break;}
                                    }
                                    
                                }
   
                    cout<<"-------------------------------------"<<endl;
                    cout<<"\tEnter votre prochaine étape  "<<endl;
                    cout<<"\tOu 'L' pour afficher la liste  : ";
             
                    cin >> reponse;
                break;
                }
                
////   approvisionner
                
            case 'u':
            case 'U':{
                cout<<"-------------------------------------"<<endl;
                cout<<"---------approvisionner----------"<<endl;
                cout<<"Nom de la pharmacie :";
                cin>>nompharmacie;
                
                cout<<"libelle de medicament:";
                cin>>libellem;
                cout<<"qte a augmenter:";
                cin>>qtem;
                    p[verifyp(nompharmacie, p)].approvisionner(libellem, qtem);
            
                reponse=minimainlist();
                
                    break;
                }
    ////Achat
            case 't':
            case 'T':
                {
                    achat(p);

                reponse=minimainlist();
                    break;
                }
                
    ///verfier achat
            case 'v':
            case 'V':
                {
                    cout<<"libelle de medicament:";
                    cin>>libellem;
                    cout<<"qte a augmenter:";
                    cin>>qtem;
                    
                    p[verifyp(nompharmacie, p)].verifierAchat(libellem, qtem);
                reponse=minimainlist();
                    break;
                }
                
                
    ///sauvgarder des client
            case 'd':
            case 'D':{
                sauvegarderClients(p);
                 reponse=mainlist();
                    break;
                }
                
    ///rechercher medicament
            case 'r':
            case 'R':{
              
                rechermedicament(p);
                 reponse=mainlist();
                    break;
                }
                
  ///afficher la liste
    case 'L':
    case 'l':{
         reponse=mainlist();
            break;
        }

    default:
    {
            cout<<"-------------------------------------"<<endl;
            cout<<"Le character incorrect !! :"<<endl;
            cout<<"\tEnter votre prochaine étape  "<<endl;
            cout<<"\tOu 'L' pour afficher la liste  : ";
            cin >> reponse;
        break;}
    
        }
    }
    
    
    return 0;
}

