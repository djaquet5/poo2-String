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

#include "String.hpp"

String::String() {
    value = new char[1];

    addEndOfStringChar();
}

virtual String::~String() {
    delete[] value;
}

String::String(const char* string) {

}

String::String(const String& string) {
    size_t size = string.getSize() + 1;
    value = new char[size];

    for(size_t i = 0; i < size; i++) {
        value[i] = string.at(i);
    }
}

String::String(int value) {

}

String::String(double value) {

}

String::String(bool value) {

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

String String::substr(size_t start, size_t end) const {

}

char& String::operator [] (const size_t index) {
    return at(index);
}

// isEqual
bool String::operator == (const String& other) const {
    return equals(other);
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
String& String::operator + (const String& string) {

}

//+=
String& String::operator += (const String& string) {

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