/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : String.cpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 07.03.2019
 But         : Implémentation de la classe String

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/

#include <cmath>
#include "String.hpp"

// TODO replace all addEndOfStringChar() with value[i] = '\0'

String::String() {
    value = new char[1];

    // We can't use the method addEndOfStringChar because
    // strlen use the null char ('\0')
    value[0] = '\0';
}

String::String(const char* chars) {
    size_t size = strlen(chars);
    value = new char[size];

    for(size_t i = 0; i < size; i++) {
        value[i] = chars[i];
    }
}

String::String(const char* chars, size_t n) {
    value = new char[n + 1];

    strncpy(value, chars, n);
    value[n] = '\0';
}

String::String(char c) {
    value = new char[2];
    value[0] = c;

    addEndOfStringChar();
}

String::String(const String& other) {
    size_t size = other.getSize() + 1;
    value = new char[size];

    for(size_t i = 0; i < size; i++) {
        value[i] = other.at(i);
    }
}

String::String(int i) {
}

String::String(double d) {

}

String::String(bool b) {
    value = new char[2];
    value[0] = b;

    addEndOfStringChar();
}

bool String::equals(const String& other) const {
    return equals(other.value);
}

bool String::equals(const char* chars) const {
    size_t thisSize = getSize();
    size_t otherSize = strlen(chars);

    return thisSize == otherSize && !strncmp(value, chars, thisSize);
}

size_t String::getSize() const {
    return strlen(value);
}

char& String::at(size_t index) const {
    if(index >= getSize()) {
        throw std::out_of_range("index out of range");
    }

    return value[index];
}

const char* String::getValue() const {
    size_t size = getSize();
    char* valueCopy = new char[size + 1];

    return strncpy(valueCopy, value, size + 1);
}

String String::substr(size_t start) const {

}

String String::substr(size_t start, size_t length) const {
    size_t size = getSize();
    String subString;

    if(start > size) {
        // TODO : Cannot instantiate ?
//        return String();
    }

    if(start + length > size) {
        // TODO : Cannot instantiate ?
//        return substr(start);
    }



    for(size_t i = 0; i < length; i++) {
        subString.append(value[start + i]);
    }

//    return subString;
}

void String::append(const String& other) {
    append(other.getValue());
}

void String::append(const char* chars) {
    size_t thisSize = getSize();
    size_t otherSize = strlen(chars);

    char* newValue = new char[thisSize + otherSize + 1];
    newValue[thisSize + otherSize] = '\0';

    strncpy(newValue, value, thisSize + 1);
    strncat(newValue, chars, otherSize);

    delete[] value;
    value = newValue;
}

void String::append(char c) {
    size_t size = getSize();

    char* newValue = new char[size + 2];

    newValue[size] = c;
    newValue[size + 1] = '\0';

    delete[] value;
    value = newValue;
}

char String::operator [] (size_t index) const {

}

char& String::operator [] (const size_t index) {
    return at(index);
}

bool String::operator == (const String& other) const {
    return equals(other);
}

bool String::operator == (const char* chars) const {
    return equals(chars);
}

//=
String& String::operator = (const String& string) {
    if(this != &string) {
        delete[] value;

        //new value ???
    }

    return *this;
}

String& String::operator = (const char* string) {

}

//+
String& String::operator + (const String& other) {

}

String& String::operator + (const char* chars) {
}

//+=
String& String::operator += (const String& string) {

}

String& String::operator += (const char* other) {

}

//>>
std::istream& operator >> (std::istream& is, const String& string) {

}

//<<
std::ostream& operator << (std::ostream& os, const String& string) {

}

void String::addEndOfStringChar() {
    value[getSize() + 1] = '\0';
}

String::~String() {
    delete[] value;
}