//
//  main.cpp
//  cpp_class_II_10
//
//  Created by Paul Kuznetsov on 04/05/15.
//  Copyright (c) 2015 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

#include "ProprietarySoftware.h"

using namespace std;

int main() {
    
    Software* soft[3];
    
    FreeSoftware* frSoft = new FreeSoftware;
    frSoft->setDeveloperName("Petya");
    frSoft->setSoftwareName("FancyApp");
    
    SharewareSoftware* swSoft = new SharewareSoftware;
    swSoft->setSoftwareName("AnyDownloader");
    swSoft->setDeveloperName("reSoft");
    swSoft->setInstalationDate("2009/3/12");
    
    ProprietarySoftware* pSoft = new ProprietarySoftware;
    pSoft->setSoftwareName("physicsSym");
    pSoft->setDeveloperName("FERMI Lab");
    pSoft->setSoftwarePrice(999);
    pSoft->setInstalationDate("2014/1/1");
    
    soft[0] = frSoft;
    soft[1] = swSoft;
    soft[2] = pSoft;
    
    
    for (int i = 0; i < 3; ++i) {
        
        if (typeid(*(soft[i])) == typeid(FreeSoftware)) {
            
            cout << "–––––––––Free software–––––––––" << endl;
            
            frSoft = (FreeSoftware *)soft[i];
            frSoft -> showDeveloperName();
            frSoft -> showSoftwareName();
        }
        else if (typeid(*(soft[i])) == typeid(SharewareSoftware)) {
            
            cout << "–––––––––Shareware software–––––––––" << endl;
            
            swSoft = (SharewareSoftware *)soft[i];
            swSoft -> showSoftwareName();
            swSoft -> showDeveloperName();
            swSoft -> showExpirationDate();
            
        }
        else if (typeid(*(soft[i])) == typeid(ProprietarySoftware)) {
            
            cout << "–––––––––Proprietary software–––––––––" << endl;
            
            pSoft = (ProprietarySoftware *)soft[i];
            pSoft -> showSoftwareName();
            pSoft -> showDeveloperName();
            pSoft -> showSoftwarePrice();
            pSoft -> showUsageTimeDate();
            
        }
        
    }
    
    return 0;
}
