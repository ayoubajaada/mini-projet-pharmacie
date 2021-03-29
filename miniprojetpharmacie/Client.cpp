
#include "Client.hpp"
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;


Client :: Client(const string&nom,const double credit)
    :nom(nom),credit(credit){}


const string& Client::getNom()const{
    return nom;
}
double Client::getCredit()const{
  
    return credit;
}

void Client::affichageClient()const{
    
    cout <<"-------------------------------------"<<endl;
    cout<<"\tNom de client :"<<" "<<getNom()<<"\n\tCredit :"<<" "<<getCredit()<<endl;
}

void Client::debiterCredit(const double som){
    
    credit-=som;
    
}
