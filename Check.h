//
//  Check.h
//  Final
//
//  Created by Amirmohammad yousefi on 1402/10/27.
//

#ifndef Check_h
#define Check_h



#include "ContactClass.h"

unsigned short int checkUserSelection(const unsigned short int firstMenu,const unsigned short int lastMenu);
bool checkAddedName(const std::string& name);
bool checkAddedNumber(const std::string& number);
bool checkAddedEmail(const std::string& email);
bool checkNameExpression(const std::string& name);
bool checkNumberExpression(const std::string& number);
bool checkEmailExpression(const std::string& email);
bool checkSearchResults(const std::vector<const Contact*> & resultsPtrsRef);//reference pass
bool checkNameToEdit(const std::string& name);
bool checkNumberToEdit(const std::string& number);
bool checkEmailToEdit(const std::string& email);
bool checkEditedContact(const Contact *contactPtr);

#endif /* Check_h */
