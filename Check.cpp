//
//  Check.cpp
//  Final
//
//  Created by Amirmohammad yousefi on 1402/10/27.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <limits>

#include "Check.h"
#include "Inputs.h"
#include "Exceptions.h"
#include "ContactClass.h"
#include "Print.h"


using namespace std;

unsigned short int checkUserSelection(const unsigned short int firstMenu,const unsigned short int lastMenu)
{
    unsigned short int option = 0;
    try
    {
        option = getUserSelection(firstMenu, lastMenu);
    }
    catch (OutOfRangeSelectionException &outOfRangeSelectionException)
    {
        cout << "Exception occured : " << outOfRangeSelectionException.what() << endl;
        option = getUserSelection(firstMenu, lastMenu);
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return option;
}

bool checkAddedName(const string& name)
{
    cout << "The contact's name is : " << name << endl;
    cout << "Do you want to continue ?" << endl;
    cout << "1-Yes\n0-No" << endl;
    if (checkUserSelection(0, 1))
        return true;
    else
        return false;
}

bool checkAddedNumber(const string& number)
{
    cout << "The contact's Phone number is : " << number << endl;
    cout << "Do you want to continue ?" << endl;
    cout << "1-Yes\n0-No" << endl;
    if (checkUserSelection(0, 1))
        return true;
    else
        return false;
}

bool checkAddedEmail(const string& email)
{
    cout << "The contact's Email is : " << email << endl;
    cout << "Do you want to continue ?" << endl;
    cout << "1-Yes\n0-No" << endl;
    if (checkUserSelection(0, 1))
        return true;
    else
        return false;
}

bool checkNameExpression(const string& name)
{
    cout << "Your expression : " << name << endl;
    cout<<"Do you want to continue ?"<<endl;
    cout<<"1-Yes\n0-No I want to enter another name for it"<<endl;
    if (checkUserSelection(0, 1))
        return true;
    else
        return false;
}

bool checkNumberExpression(const string& number)
{
    cout << "Your expression : " << number << endl;
    cout<<"Do you want to continue ?"<<endl;
    cout<<"1-Yes\n0-No I want to enter another phone number for it"<<endl;
    if (checkUserSelection(0, 1))
        return true;
    else
        return false;
}

bool checkEmailExpression(const string& email)
{
    cout << "Your expression : " << email << endl;
    cout<<"Do you want to continue ?"<<endl;
    cout<<"1-Yes\n0-No I want to enter another Email for it"<<endl;
    if (checkUserSelection(0, 1))
        return true;
    else
        return false;
}

bool checkSearchResults(const vector<const Contact*> & resultsPtrsRef)//reference pass
{
    if(resultsPtrsRef.size())
    {
        printSearchResults(resultsPtrsRef);
        cout << "Are you ok with these results?"<<endl;
        cout << "1-Yes\n0-No I want to search again"<< endl;
        if (checkUserSelection(0, 1))
            return true;
        else
            return false;
    }
    else
    {
        cout << "No results were found based on your expression ):"<<endl;
        cout << "Do you want to search again ?"<<endl;
        cout << "1-Yes\n0-No"<< endl;
        if (checkUserSelection(0, 1))
            return false;
        else
            return true;
        
    }
}

bool checkNameToEdit(const string& name)
{
    cout << "The new contact's Name : " << name << endl;
    cout<<"Do you want to continue ?"<<endl;
    cout<<"1-Yes\n0-No"<<endl;
    if (checkUserSelection(0, 1))
        return true;
    else
        return false;
}

bool checkNumberToEdit(const string& number)
{
    cout << "The new contact's Phone Number : " << number << endl;
    cout<<"Do you want to continue ?"<<endl;
    cout<<"1-Yes\n0-No"<<endl;
    if (checkUserSelection(0, 1))
        return true;
    else
        return false;
}

bool checkEmailToEdit(const string& email)
{
    cout << "The new contact's Email : " << email << endl;
    cout<<"Do you want to continue ?"<<endl;
    cout<<"1-Yes\n0-No"<<endl;
    if (checkUserSelection(0, 1))
        return true;
    else
        return false;
}

bool checkEditedContact(const Contact *contactPtr)
{
    cout << "The edited contact informations :" << endl;
    contactPtr->printName();
    contactPtr->printPhoneNumbers();
    contactPtr->printEmails();
    cout << "Are ok with these changes ?" << endl;
    cout<<"1-Yes\n0-No"<<endl;
    if (checkUserSelection(0, 1))
        return true;
    else
        return false;
}
