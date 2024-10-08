//
//  Add_Contact.cpp
//  Final
//
//  Created by Amirmohammad yousefi on 1402/10/27.
//

#include <iostream>
#include <string>
#include <cstddef>

#include "Add_Contact.h"
#include "ContactClass.h"
#include "Inputs.h"
#include "Check.h"
#include "Exceptions.h"

using namespace std;

bool addNameManager(Contact *contactPtr)
{
    const string& name = getName();
    if (checkAddedName(name))
    {
        contactPtr->addName(name);
        cout<<"the name added successfully (:"<<endl;
        contactPtr->addContact();
        return true;
    }
    else
        return false;
}

void addNumberManager(Contact *contactPtr)
{
    const string& number = getNumber();
    if (checkAddedNumber(number))
    {
        try
        {
            contactPtr->addPhoneNumber(number);
        }
        catch (RepeatedPhoneNumberException &repeatedPhoneNumberException)
        {
            cout << "Exception occured : " << repeatedPhoneNumberException.what() << endl;
            cout << "Do you want to try another Phone Number ?" << endl;
            cout <<"1-Yes\n0-No" << endl;
            if (checkUserSelection(0, 1))
                addNumberManager(contactPtr);
            return;
        }
        cout << "the Phone number added successfully (:" << endl;
        cout << "Do you want to add another Phone number to the new contact?" << endl;
        cout << "1-Yes\n0-No" << endl;
        if (checkUserSelection(0, 1))
            addNumberManager(contactPtr);
    }
}

void addEmailManager(Contact *contactPtr)
{
    const string& email = getEmail();
    if (checkAddedEmail(email))
    {
        try
        {
            contactPtr->addEmail(email);
        }
        catch (RepeatedEmailException &repeatedEmailException)
        {
            cout << "Exception occured : " << repeatedEmailException.what() << endl;
            cout << "Do you want to add another Email to the new contact?" << endl;
            cout << "1-Yes\n0-No" << endl;
            if (checkUserSelection(0, 1))
                addEmailManager(contactPtr);
            return;
        }
        cout << "the Email added successfully (:" << endl;
        cout << "Do you want to add another Email to the new contact?" << endl;
        cout << "1-Yes\n0-No" << endl;
        if (checkUserSelection(0, 1))
            addEmailManager(contactPtr);
    }
}

void addContactsManager()
{
    Contact *contactPtr = new Contact();
//    Contact &contactRefer = contact;
    cout<<"First , you should enter the name of the new contact"<<endl;
    if (addNameManager(contactPtr))
    {
        cout<<"Do you want to add phone number to the new contact?"<<endl;
        cout <<"1-Yes\n0-No" << endl;
        if (checkUserSelection(0, 1))
            addNumberManager(contactPtr);
        cout<<"Do you want to add Email to the new contact?"<<endl;
        cout <<"1-Yes\n0-No" << endl;
        if (checkUserSelection(0, 1))
            addEmailManager(contactPtr);
        cout<<"the contact added successfully (:"<<endl;
        cout<<"Do you want to Add another contact ?"<<endl;
        cout<<"1-Yes\n0-No I want to back to main menu"<<endl;
        if (checkUserSelection(0, 1))
            addContactsManager();
    }
}


