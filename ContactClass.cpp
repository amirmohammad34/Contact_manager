//
//  ContactClass.cpp
//  Final
//
//  Created by Amirmohammad yousefi on 1402/10/27.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstddef>

#include "ContactClass.h"
#include "Exceptions.h"

using namespace std;

Contact::Contact(const string & argName,const vector<string>&argNumbers,const vector<string>&argEmails)
    : name(argName),numbers(argNumbers),emails(argEmails)
{
    
}
    


//Add functions

void Contact::addName(const string &name)
{
    this->name = name;
}

bool Contact::checkRepeatedPhoneNumber(const string &addedNumber) const
{
    bool found = false;
    for (const Contact* contactPtr : contacts)
    {
        for (const string &number : contactPtr->numbers)
        {
            size_t found = number.find(addedNumber);
            if (found != variant_npos)
            {
                found = true;
                return found;
            }
        }
    }
    return found;
}

bool Contact::checkRepeatedEmail(const string &addedEmail) const
{
    bool found = false;
    for (const Contact* contactPtr : contacts)
    {
        for (const string &email : contactPtr->emails)
        {
            size_t found = email.find(addedEmail);
            if (found != variant_npos)
            {
                found = true;
                return found;
            }
        }
    }
    return found;
}

void Contact::addPhoneNumber(const string &number)
{
    if(checkRepeatedPhoneNumber(number))
        throw RepeatedPhoneNumberException();
    else
        numbers.push_back(number);
}

void Contact::addEmail(const string &email)
{
    if(checkRepeatedEmail(email))
        throw RepeatedEmailException();
    else
        emails.push_back(email);
}

void Contact::addContact() const
{
    contacts.push_back(this);
}

void Contact::printName() const
{
    cout << "Name : " << name << endl;
}

void Contact::printPhoneNumbers() const
{
    if (numbers.size())
    {
        cout << "Phone numbers :" << endl;
        size_t counter = 0;
        for (const string& number : numbers)
        {
            cout << "Phone " << counter + 1 << ": " << number << endl;
            counter++;
        }
    }
    else
        cout << "Phone numbers : None !" << endl;
}

void Contact::printEmails() const
{
    if (emails.size())
    {
        cout << "Emails :" << endl;
        size_t counter = 0;
        for (const string& email : emails)
        {
            cout << "Email " << counter + 1 << ": " << email << endl;
            counter++;
        }
        
    }
    else
        cout << "Emails : None !" << endl;
}

void Contact::editName(const string& name)
{
    this->name = name;
}

void Contact::editPhoneNumber(const string& number, const size_t index)
{
    if (checkRepeatedPhoneNumber(number))
        throw RepeatedPhoneNumberException();
    if (index > (numbers.size() - 1))
    {
        throw OutOfRangeIndexException();
    }
    numbers[index] = number;
}

void Contact::editEmail(const string& email, const size_t index)
{
    if (index > (emails.size() - 1))
    {
        throw OutOfRangeIndexException();
    }
    emails[index] = email;
}

size_t Contact::numbersSize() const
{
    return numbers.size();
}

size_t Contact::emailsSize() const
{
    return emails.size();
}

void Contact::clearPhoneNumbers()
{
    numbers.clear();
}

void Contact::clearEmails()
{
    emails.clear();
}

void Contact::deleteContact() const
{
    size_t counter = 0;
    for (const Contact* contactPtr : contacts)
    {
        if (contactPtr == this)
        {
            contacts.erase(contacts.begin() + counter);
            break;
        }
        counter++;
    }
    delete this;
    
}

//Friend fucntions
void searchInNames(const string& expression , vector<const Contact*> &contactsPtrsRef)
{
    for (const Contact* contact : Contact::contacts)
    {
        size_t found = contact->name.find(expression);
        if (found != variant_npos)
            contactsPtrsRef.push_back(contact);
    }
}

void searchInPhoneNumbers(const string& expression , vector<const Contact*> &contactsPtrsRef)
{
    for (const Contact* contact : Contact::contacts)
    {
        for (const string &number : contact->numbers)
        {
            size_t found = number.find(expression);
            if (found != variant_npos)
            {
                contactsPtrsRef.push_back(contact);
                break;
            }
        }
    }
}

void searchInEmails(const string& expression , vector<const Contact*> &contactsPtrsRef)
{
    for (const Contact* contact : Contact::contacts)
    {
        for (const string &email : contact->emails)
        {
            size_t found = email.find(expression);
            if (found != variant_npos)
            {
                contactsPtrsRef.push_back(contact);
                break;
            }
        }
    }
}

void Contact::writeToFile()
{
    ofstream contactsFile(R"(/Users/amirmohammadyousefi/Downloads/C++:Test/Final/Files/Contact.txt)");
    for (const Contact* contactPtr : contacts)
    {
        contactsFile << ';' << endl;
        contactsFile << contactPtr->name << endl;
        contactsFile << ';' << endl;
        for (const string &number : contactPtr->numbers)
        {
            contactsFile << number << endl;
        }
        contactsFile << ';' << endl;
        for (const string &email : contactPtr->emails)
        {
            contactsFile << email << endl;
        }
        contactsFile << ';' << endl;
    }
    contactsFile.close();
}

void Contact::readFromFile() 
{
    size_t counter = 0;
    static string expression = "";
    static string name = "";
    static vector<string>numbers;
    static vector<string>emails;
    ifstream contactsFile(R"(/Users/amirmohammadyousefi/Downloads/C++:Test/Final/Files/Contact.txt)");
    if(contactsFile.is_open())
    {
        while (contactsFile >> expression)
        {
            if (expression == ";")
            {
                counter++;
                if (counter > 3)
                {
                    counter = 0;
                    Contact *contactPtr = new Contact(name,numbers,emails);
                    contactPtr->addContact();
                    numbers.clear();
                    emails.clear();
                }
                continue;
            }
            switch (counter)
            {
                case 1:
                    name = expression;
                    break;
                case 2:
                    numbers.push_back(expression);
                    break;
                case 3:
                {
                    emails.push_back(expression);
                    break;
                }
                default:
                    cout << "counter error!!!" << endl;
                    break;
            }
        }
    }
    contactsFile.close();
}


vector<const Contact*>Contact::contacts;
