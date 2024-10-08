//
//  Manager.cpp
//  Final
//
//  Created by Amirmohammad yousefi on 1402/10/28.
//

#include <iostream>

#include "Manager.h"
#include "Check.h"
#include "Add_Contact.h"
#include "Search.h"
#include "Edit.h"
#include "ContactClass.h"

using namespace std;

void contactsManager()
{
    static unsigned short int counter = 0;
    if (!counter)
        Contact::readFromFile();
    counter++;
    cout << "Welcome to the contacts manager by amirmohammad yousefi (:" << endl;
    cout << "What can I do for you ?" << endl;
    cout << "1-Create a new contact\n2-Search in contacts\n3-Edit a contact" << endl;
    switch (checkUserSelection(1, 3))
    {
        case 1:
            addContactsManager();
            break;
        case 2:
        {
            searchManager();
            break;
        }
        case 3:
        {
            editManager(searchManager());
            break;
        }
        default:
            cout << "error!" << endl;
            break;
    }
    cout << "Do you want to save changes and exit ?" << endl;
    cout<<"1-Yes\n0-No"<<endl;
    if (checkUserSelection(0, 1))
    {
        Contact::writeToFile();
        cout << "Changes have been successfully saved (:" << endl;
        cout << "Goodbye (:" << endl;
    }
    else
        contactsManager();
}

