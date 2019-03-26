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

String::String() {
    value = new char[1];

    // strlen() uses the \0 car ...
    addEndOfStringChar();
}

String::String(const char* chars) {
    size_t size = strlen(chars);
    value = new char[size];

    for(size_t i = 0; i < size; i++) {
        value[i] = chars[i];
    }
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

String::String(int d) {
}

String::String(double value) {

}

String::String(bool b) {
    value = new char[2];
    value[0] = b;

    addEndOfStringChar();
}

bool String::equals(const String& other) const {
    size_t size = getSize();

    // TODO test ref null ?
    if(size != other.getSize()) {
        return false;
    }

    for(size_t i = 0; i < size; i++) {
        if(value[i] != other.value[i]) {
            return false;
        }
    }
    return true;
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
    char* valueCopy = new char[getSize() + 1];

    return strcpy(valueCopy, value);
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

}

void String::append(const char* chars) {

}

void String::append(char c) {

}

char String::operator [] (size_t index) const {

}

char& String::operator [] (const size_t index) {
    return at(index);
}

// isEqual
bool String::operator == (const String& other) const {
    return equals(other);
}

bool String::operator == (const char* string) const {

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