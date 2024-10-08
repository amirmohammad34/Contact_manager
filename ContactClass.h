//
//  ContactClass.h
//  Final
//
//  Created by Amirmohammad yousefi on 1402/10/27.
//

#ifndef ContactClass_h
#define ContactClass_h

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>


class Contact
{
    friend void searchInNames(const std::string& expression , std::vector<const Contact*> &contactsPtrsRef);
    friend void searchInPhoneNumbers(const std::string& expression , std::vector<const Contact*> &contactsPtrsRef);
    friend void searchInEmails(const std::string& expression , std::vector<const Contact*> &contactsPtrsRef);
public:
    Contact(const std::string & = "a",const std::vector<std::string>& = std::vector<std::string>(),const std::vector<std::string>& = std::vector<std::string>());
    //
    void addName(const std::string &name);
    void addPhoneNumber(const std::string &number);
    void addEmail(const std::string &email);
    void addContact() const;
    //
    void editName(const std::string& name);
    void editPhoneNumber(const std::string& number, const size_t index);
    void editEmail(const std::string& email, const size_t index);
    size_t numbersSize() const;
    size_t emailsSize() const;
    //
    void clearPhoneNumbers();
    void clearEmails();
    void deleteContact() const;
    //
    void printName() const;
    void printPhoneNumbers() const;
    void printEmails() const;
    //
    static void writeToFile();
    static void readFromFile();
    
private:
    std::string name;
    std::vector<std::string>numbers;
    std::vector<std::string>emails;
    //statics
    static std::vector<const Contact*>contacts;
    //
    
    bool checkRepeatedPhoneNumber(const std::string &addedNumber) const;
    bool checkRepeatedEmail(const std::string &addedNumber) const;
    //
};
#endif /* ContactClass_h */

