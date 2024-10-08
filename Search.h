//
//  Search.h
//  Final
//
//  Created by Amirmohammad yousefi on 1402/10/28.
//

#ifndef Search_h
#define Search_h


#include "ContactClass.h"

void searchNameManager(const std::vector<const Contact*> & resultsPtrsRef);
void searchNumberManager(const std::vector<const Contact*> & resultsPtrsRef);
void searchEmailManager(const std::vector<const Contact*> & resultsPtrsRef);
std::vector<const Contact*> & searchManager();

#endif /* Search_h */
