//
//  Edit.h
//  Final
//
//  Created by Amirmohammad yousefi on 1402/10/28.
//

#ifndef Edit_h
#define Edit_h


#include "ContactClass.h"

void editNameManager(Contact *copyContactPtr);
void editSpecificNumberManager(Contact *copyContactPtr);
void editNumberManager(Contact *copyContactPtr);
void editSpecificEmailManager(Contact *copyContactPtr);
void editEmailManager(Contact *copyContactPtr);
void editManager(const std::vector<const Contact*> &);



#endif /* Edit_h */
