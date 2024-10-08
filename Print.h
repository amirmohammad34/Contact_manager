//
//  Print.h
//  Final
//
//  Created by Amirmohammad yousefi on 1402/10/28.
//

#ifndef Print_h
#define Print_h

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>

#include "ContactClass.h"

void printSearchResults(const std::vector<const Contact*> & resultsPtrsRef);//reference pass
void printContactInformation(const size_t index,const Contact* contactPtr);//reference pass

#endif /* Print_h */
