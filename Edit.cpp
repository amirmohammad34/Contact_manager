//
//  Edit.cpp
//  Final
//
//  Created by Amirmohammad yousefi on 1402/10/28.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>

#include "Edit.h"
#include "ContactClass.h"
#include "Check.h"
#include "Inputs.h"
#include "Exceptions.h"
#include "Add_Contact.h"
#include "Delete.h"
#include "Print.h"
#include "Search.h"
using namespace std;

void editNameManager(Contact *copyContactPtr)
{
    const string &name = getNameToEdit();
    if (checkNameToEdit(name))
    {
        copyContactPtr->editName(name);
        cout << "the contact's name edited successfully (:" << endl;
    }
}

void editSpecificNumberManager(Contact *copyContactPtr)
{
    size_t phoneNumbersSize = copyContactPtr->numbersSize();
    size_t index = 0;
    if(phoneNumbersSize > 1)
        index = getNumberIndex(phoneNumbersSize);
    else
        index = phoneNumbersSize - 1;
    const string& numberRef = getNumberToEdit();
    if (checkNumberToEdit(numberRef))
    {
        try
        {
            copyContactPtr->editPhoneNumber(numberRef, index);
        }
        catch (RepeatedPhoneNumberException &repeatedPhoneNumberException)
        {
            cout << "Exception occured : " << repeatedPhoneNumberException.what() << endl;
            cout << "Do you want to continue with editing the contact's phone numbers?" << endl;
            cout <<"1-Yes\n0-No" << endl;
            if (checkUserSelection(0, 1))
                editSpecificNumberManager(copyContactPtr);
            return;
        }
        catch (OutOfRangeIndexException &outOfRangeIndexException)
        {
            cout << "Exception occured : " << outOfRangeIndexException.what() << endl;
            return;
        }
        cout << "the contact's number edited successfully (:" << endl;
    }
}

void editNumberManager(Contact *copyContactPtr)
{
    if(copyContactPtr->numbersSize())
    {
        switch (getNumberEditionMode())
        {
            case 1:
                addNumberManager(copyContactPtr);
                break;
            case 2:
                editSpecificNumberManager(copyContactPtr);
                break;
            case 3:
                deleteAllNumbersManager(copyContactPtr);
                break;
                
            default:
                cout << "error switch case" << endl;
                break;
        }
    }
    else
    {
        cout << "your selected contact doesn't have any number" << endl;
        cout << "Do you want to add new phone number to the contact ?" << endl;
        cout <<"1-Yes\n0-No" << endl;
        if (checkUserSelection(0, 1))
            addNumberManager(copyContactPtr);
    }
}

void editSpecificEmailManager(Contact *copyContactPtr)
{
    size_t emailsSize = copyContactPtr->emailsSize();
    size_t index = 0;
    if(emailsSize > 1)
        index = getEmailIndex(emailsSize);
    else
        index = emailsSize - 1;
    const string& emailRef = getEmailToEdit();
    if (checkEmailToEdit(emailRef))
    {
        try
        {
            copyContactPtr->editEmail(emailRef, index);
        }
        catch (RepeatedPhoneNumberException &repeatedPhoneNumberException)
        {
            cout << "Exception occured : " << repeatedPhoneNumberException.what() << endl;
            cout << "Do you want to continue with editing the contact's Emails?" << endl;
            cout <<"1-Yes\n0-No" << endl;
            if (checkUserSelection(0, 1))
                editSpecificEmailManager(copyContactPtr);
            return;
        }
        catch (OutOfRangeIndexException &outOfRangeIndexException)
        {
            cout << "Exception occured : " << outOfRangeIndexException.what() << endl;
            return;
        }
        cout << "the contact's Email edited successfully (:" << endl;
    }
}
        
void editEmailManager(Contact *copyContactPtr)
{
    if(copyContactPtr->emailsSize())
    {
        switch (getEmailEditionMode())
        {
            case 1:
                addEmailManager(copyContactPtr);
                break;
            case 2:
                editSpecificEmailManager(copyContactPtr);
                break;
            case 3:
                deleteAllEmailsManager(copyContactPtr);
                break;
                
            default:
                cout << "error switch case" << endl;
                break;
        }
    }
    else
    {
        cout << "your selected contact doesn't have any Email" << endl;
        cout << "Do you want to add new Email to the contact ?" << endl;
        cout <<"1-Yes\n0-No" << endl;
        if (checkUserSelection(0, 1))
            addEmailManager(copyContactPtr);
    }
        
}

void editManager(const vector<const Contact*> & resultsPtrsRef)
{
    size_t resultsSize = resultsPtrsRef.size();
    if (resultsSize)
    {
        size_t index = 0;
        try
        {
            index = getContactIndex(resultsSize);
        }
        catch (OutOfRangeIndexException &outOfRangeIndexException)
        {
            cout << "Exception occured : " << outOfRangeIndexException.what() << endl;
            index = getContactIndex(resultsSize);
        }
        Contact *copyContactPtr = new Contact();
        *copyContactPtr = (*resultsPtrsRef[index]);
        printContactInformation(index, copyContactPtr);
        switch (getEditMode())
        {
            case 1:
                editNameManager(copyContactPtr);
                break;
            case 2:
                editNumberManager(copyContactPtr);
                break;
            case 3 :
                editEmailManager(copyContactPtr);
                break;
            case 4 :
                deleteContactManager(copyContactPtr);
                return;
            default:
                cout << "error switch case" << endl;
                break;
        }
        if (checkEditedContact(copyContactPtr))
        {
            copyContactPtr->addContact();
            resultsPtrsRef[index]->deleteContact();
        }
    }
    cout << "Do you want to continue with edit?" << endl;
    cout << "1-Yes\n0-No" << endl;
    if(checkUserSelection(0, 1))
        editManager(searchManager());
}
