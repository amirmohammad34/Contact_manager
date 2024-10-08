//
//  Inputs.cpp
//  Final
//
//  Created by Amirmohammad yousefi on 1402/10/27.
//

#include <iostream>
#include <string>
#include <cstddef>
#include <limits>

#include "Inputs.h"
#include "Exceptions.h"
#include "Check.h"
using namespace std;

unsigned short int getUserSelection(const unsigned short int firstMenu,const unsigned short int lastMenu)
{
    unsigned short int option = 0;
    cout << "Please Select an option from " << firstMenu << " to " << lastMenu << " : ";
    cin >> option;
    if(option > lastMenu || option < firstMenu)
        throw OutOfRangeSelectionException();
    return option;
}
string& getName()
{
    static string name = "";
    cout << "Please enter the name : ";
//    getline(cin, name);
    cin >> name;
    static string& nameRef = name;
    return nameRef;
}

string& getNumber()
{
    static string number = "";
    cout<<"Please enter the Phone number : ";
//    getline(cin, number);
    cin >> number;
    static string& numberRef = number;
    return numberRef;
}

string& getEmail()
{
    static string email = "";
    cout<<"Please enter the Email : ";
//    getline(cin, email);
    cin >> email;
    static string& emailRef = email;
    return emailRef;
}

unsigned short int getSearchMode()
{
    cout << "Please enter the search's mode :" << endl;
    cout << "1-Search based on names" << endl;
    cout << "2-Search based on phone numbers" << endl;
    cout << "3-Search based on Emails" << endl;
    return checkUserSelection(1, 3);
}
string& getNameExpression()
{
    static string expression = "";
    cout << "Search mode : Names" << endl;
    cout << "Please enter the expression to search in names : ";
//    getline(cin, expression);
    cin >> expression;
    static string& expressionRef = expression;
    return expressionRef;
}

string& getNumberExpression()
{
    static string expression = "";
    cout << "Search mode : Phone numbers" << endl;
    cout << "Please enter the phone number to search : ";
//    getline(cin, expression);
    cin >> expression;
    static string& expressionRef = expression;
    return expressionRef;
}

string& getEmailExpression()
{
    static string expression = "";
    cout << "Search mode : Emails" << endl;
    cout << "Please enter the expression to search in Emails : ";
//    getline(cin, expression);
    cin >> expression;
    static string& expressionRef = expression;
    return expressionRef;
}

size_t getContactIndex(const size_t size)
{
    size_t index = 0;
    cout << "which contact do you want to edit?" << endl;
    cout << "Please Select an option from 1" << " to " << size << " : ";
    cin >> index;
    if(index > size || index < 1)
        throw OutOfRangeIndexException();
    index--;
    return index;
}

size_t getNumberIndex(const size_t size)
{
    size_t index = 0;
    cout << "which phone number do you want to edit?" << endl;
    cout << "Please Select an option from 1" << " to " << size << " : ";
    cin >> index;
    index--;
    return index;
}

size_t getEmailIndex(const size_t size)
{
    size_t index = 0;
    cout << "which Email do you want to edit?" << endl;
    cout << "Please Select an option from 1" << " to " << size << " : ";
    cin >> index;
    index--;
    return index;
}

unsigned short int getEditMode()
{
    cout << "what Do you want to edit?" << endl;
    cout << "1-Edit contact's name" << endl;
    cout << "2-Edit contact's phone numbers" << endl;
    cout << "3-Edit contact's Emails" << endl;
    cout << "4-Delete contact !!!" << endl;
    return checkUserSelection(1, 4);
}
unsigned short int getNumberEditionMode()
{
    cout << "What do you want to do ?" << endl;
    cout << "1-Add new Phone number to the contact" << endl;
    cout << "2-Edit contact's specific phone number" << endl;
    cout << "3-Delete All contact's phone numbers !!!" << endl;
    return checkUserSelection(1, 3);
    
}

unsigned short int getEmailEditionMode()
{
    cout << "What do you want to do ?" << endl;
    cout << "1-Add new Email to the contact" << endl;
    cout << "2-Edit contact's specific Email" << endl;
    cout << "3-Delete All contact's Emails !!!" << endl;
    return checkUserSelection(1, 3);
}

string& getNameToEdit()
{
    static string name = "";
    cout << "Please enter the new name to edit the contact : ";
//    getline(cin, name);
    cin >> name;
    static string& nameRef = name;
    return nameRef;
}

string& getNumberToEdit()
{
    static string number = "";
    cout << "Please enter the new phone number to edit the contact : ";
//    getline(cin, number);
    cin >> number;
    static string& numberRef = number;
    return numberRef;
}
string& getEmailToEdit()
{
    static string email = "";
    cout << "Please enter the new Email to edit the contact : ";
//    getline(cin, email);
    cin >> email;
    static string& emailRef = email;
    return emailRef;
}

