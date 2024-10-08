//
//  Exceptions.h
//  Final
//
//  Created by Amirmohammad yousefi on 1402/10/27.
//

#ifndef Exceptions_h
#define Exceptions_h

#include <stdexcept>

class RepeatedPhoneNumberException : public std::logic_error
{
public:
    RepeatedPhoneNumberException()
    :std::logic_error("attempted to enter an used Phone Number!"){}
};

class RepeatedEmailException : public std::logic_error
{
public:
    RepeatedEmailException()
    :std::logic_error("attempted to enter an used Email!"){}
};

class OutOfRangeSelectionException : public std::logic_error
{
public:
    OutOfRangeSelectionException()
    :std::logic_error("attempted to enter an out of range selection!"){}
};

class OutOfRangeIndexException : public std::logic_error
{
public:
    OutOfRangeIndexException()
    :std::logic_error("attempted to enter an out of range index!"){}
};

#endif /* Exceptions_h */
