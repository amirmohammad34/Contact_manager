//
//  Inputs.h
//  Final
//
//  Created by Amirmohammad yousefi on 1402/10/27.
//

#ifndef Inputs_h
#define Inputs_h

#include <iostream>

unsigned short int getUserSelection(const unsigned short int firstMenu,const unsigned short int lastMenu);
std::string& getName();
std::string& getNumber();
std::string& getEmail();
unsigned short int getSearchMode();
std::string& getNameExpression();
std::string& getNumberExpression();
std::string& getEmailExpression();
size_t getContactIndex(const size_t size);
size_t getNumberIndex(const size_t size);
size_t getEmailIndex(const size_t size);
unsigned short int getEditMode();
unsigned short int getNumberEditionMode();
unsigned short int getEmailEditionMode();
std::string& getNameToEdit();
std::string& getNumberToEdit();
std::string& getEmailToEdit();


#endif /* Inputs_h */
