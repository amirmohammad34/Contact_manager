//
//  Search.cpp
//  Final
//
//  Created by Amirmohammad yousefi on 1402/10/28.
//

#include <iostream>
#include <string>
#include <vector>

#include "Search.h"
#include "ContactClass.h"
#include "Inputs.h"
#include "Check.h"

using namespace std;

void searchNameManager(vector<const Contact*> & resultsPtrsRef)
{
    const string& expression = getNameExpression();
    if(checkNameExpression(expression))
        searchInNames(expression,resultsPtrsRef);
    else
        searchNameManager(resultsPtrsRef);
}

void searchNumberManager(vector<const Contact*> & resultsPtrsRef)
{
    const string& expression = getNumberExpression();
    if (checkNumberExpression(expression))
        searchInPhoneNumbers(expression,resultsPtrsRef);
    else
        searchNumberManager(resultsPtrsRef);
}

void searchEmailManager(vector<const Contact*> & resultsPtrsRef)
{
    const string& expression = getEmailExpression();
    if (checkEmailExpression(expression))
        searchInEmails(expression,resultsPtrsRef);
    else
        searchEmailManager(resultsPtrsRef);
}

vector<const Contact*> & searchManager()
{
    static vector<const Contact*>resultsPtrs;
    static vector<const Contact*> & resultsPtrsRef = resultsPtrs;
    resultsPtrs.clear();
    unsigned short int mode = getSearchMode();
    switch (mode)
    {
        case 1:
            searchNameManager(resultsPtrs);
            break;
        case 2 :
            searchNumberManager(resultsPtrs);
            break;
        case 3 :
            searchEmailManager(resultsPtrs);
            break;
    }
    if(!checkSearchResults(resultsPtrs))
    {
        resultsPtrs = searchManager();
        return resultsPtrsRef;
    }
    return resultsPtrsRef;
}
