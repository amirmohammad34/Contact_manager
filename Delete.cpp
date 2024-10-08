//
//  Delete.cpp
//  Final
//
//  Created by Amirmohammad yousefi on 1402/10/28.
//

#include <iostream>

#include "Delete.h"
#include "ContactClass.h"
#include "Check.h"

using namespace std;

void deleteAllNumbersManager(Contact *copyContactPtr)
{
    cout << "Are you sure about delete all phone numbers of the contact?!!!" << endl;
    cout << "1-Yes\n0-No" << endl;
    if (checkUserSelection(0, 1))
    {
        copyContactPtr->clearPhoneNumbers();
        cout << "All contact's phone numbers deleted successfully" << endl;
    }
}

void deleteAllEmailsManager(Contact *copyContactPtr)
{
    cout << "Are you sure about delete all Emails of the contact?!!!" << endl;
    cout << "1-Yes\n0-No" << endl;
    if (checkUserSelection(0, 1))
    {
        copyContactPtr->clearEmails();
        cout << "All contact's phone numbers deleted successfully" << endl;
    }
}

void deleteContactManager(Contact *copyContactPtr)
{
    cout << "Are you sure about delete this contact?!!!" << endl;
    cout << "1-Yes\n0-No" << endl;
    if (checkUserSelection(0, 1))
    {
        copyContactPtr->deleteContact();
        cout << "the contact deleted successfully (:" << endl;
    }
}
