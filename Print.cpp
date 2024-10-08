//
//  Print.cpp
//  Final
//
//  Created by Amirmohammad yousefi on 1402/10/28.
//
#include <iostream>
#include <vector>
#include <cstddef>

#include "Print.h"
#include "ContactClass.h"

using namespace std;

void printSearchResults(const vector<const Contact*> & resultsPtrsRef)//reference pass
{
    size_t counter = 0;
    cout << "Results : " << endl;
    for (const Contact* resultPtr : resultsPtrsRef)
    {
        cout << "contact " << counter + 1 << ":" << endl;
        resultPtr->printName();
        resultPtr->printPhoneNumbers();
        resultPtr->printEmails();
        counter++;
    }
}

void printContactInformation(const size_t index,const Contact* contactPtr)//reference pass
{
    cout << "contact " << index + 1 << " informations :" << endl;
    contactPtr->printName();
    contactPtr->printPhoneNumbers();
    contactPtr->printEmails();
}

//void printContainers()
//{
//    for (string name : names) {
//        cout<<name<<endl;
//    }
//    for (string number : numbers) {
//        cout<<number<<endl;
//    }
//    for (string email : emails) {
//        cout<<email<<endl;
//    }
//    for (long int unique : namesUniques) {
//        cout<<unique<<endl;
//    }
//    for (long int unique : numbersUniques) {
//        cout<<unique<<endl;
//    }
//    for (long int unique : emailsUniques) {
//        cout<<unique<<endl;
//    }
//}
