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

// empty string or -->  = default ???
String::String() {
    value = new char[1];
    value[0] = '\0';
}

String::~String() {
    delete[] value;
}

String::String(const char* string) {
    
}

String::String(const String& string) {

}

String::String(int value) {

}

String::String(double value) {

}

String::String(bool value) {

}

size_t String::getSize() const {
    return strlen(value);
}

char& String::getCharAt(size_t index) {
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
    // return charAt ??? etc
}

// isEqual
bool String::operator == (const String& string) const {

}

//=
String& String::operator = (const String& string) {

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
