//
//  Client.hpp
//  miniprojetpharmacie
//
//  Created by Ay JM on 29/3/2021.
//
#ifndef Client_hpp
#define Client_hpp

#include <iostream>

#include <stdio.h>
#include <string>

using namespace std;
class Client{
private:
    string nom;
    double credit;
    
public:
    Client(const string& nom,const double credit);
    void affichageClient()const;
    const  string& getNom()const;
    double getCredit()const;
    void debiterCredit(const double som);

};

#endif /* Client_hpp */
