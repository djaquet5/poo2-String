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

static const char NULL_CHAR = '\0';

String::String() : String("") {}

String::String(const char* chars) {
    size_t size = strlen(chars);

    value = new char[size + 1];
    value[size] = NULL_CHAR;

    strncpy(value, chars, size);
}

String::String(const char* chars, size_t n) {
    value = new char[n + 1];

    strncpy(value, chars, n);
    value[n] = NULL_CHAR;
}

String::String(char c) {
    value = new char[2];

    value[0] = c;
    value[1] = NULL_CHAR;
}

String::String(const String& other) {
    size_t size = other.getSize();
    value = new char[size + 1];

    strcpy(value, other.value);
}

String::String(int i) {
    size_t size = (size_t) snprintf(nullptr, 0, "%d", i) + 1;
    value = new char[size];

    // TODO : Pas sur que ça marche, sinon, passer par un buffer et faire strcpy
    snprintf(value, size, "%d", i);
}

String::String(double d) {
    size_t size = (size_t) snprintf(nullptr, 0, "%f", d) + 1;
    value = new char[size];

    // TODO : Pas sur que ça marche, sinon, passer par un buffer et faire strcpy
    snprintf(value, size, "%f", d);
}

String::String(bool b): String(b ? 1 : 0) {}

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

// TODO
const char& String::at(size_t index) const {
    isIndexValid(index);
    return value[index];
}

// TODO
char& String::at(size_t index) {
    isIndexValid(index);
    return value[index];
}

const char* String::getValue() const {
    size_t size = getSize();
    char* valueCopy = new char[size + 1];

    return strncpy(valueCopy, value, size + 1);
}

String String::substr(size_t start) const {
    return substr(start, getSize());
}

String String::substr(size_t start, size_t length) const {
    size_t size = getSize();

    if(start == size) {
        return String();
    }

    isIndexValid(start);

    if(start + length > size) {
        length = size - start;
    }

    char result[length + 1];
    result[length] = NULL_CHAR;

    strncpy(result, value + start, length);

    return String(result);
}

void String::append(const String& other) {
    append(other.getValue());
}

void String::append(const char* chars) {
    size_t thisSize = getSize();
    size_t otherSize = strlen(chars);

    char* newValue = new char[thisSize + otherSize + 1];
    newValue[thisSize + otherSize] = NULL_CHAR;

    strncpy(newValue, value, thisSize + 1);
    strncat(newValue, chars, otherSize);

    delete[] value;
    value = newValue;
}

void String::append(char c) {
    size_t size = getSize();

    char* newValue = new char[size + 2];

    newValue[size] = c;
    newValue[size + 1] = NULL_CHAR;

    strncpy(newValue, value, size);

    delete[] value;
    value = newValue;
}

const char& String::operator [] (const size_t index) const {
    return at(index);
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

bool String::operator != (const String& other) const {
    return !equals(other);
}

bool String::operator != (const char* chars) const {
    return !equals(chars);
}

String& String::operator = (const String& other) {
    if(this != &other) {
        // TODO c'est juste ça ???
        *this = other.value;
    }

    return *this;
}

String& String::operator = (const char* chars) {
    if(strcmp(value, chars) != 0) {
        delete[] value;

        size_t otherSize = strlen(chars);

        char* valueCopy = new char[otherSize + 1];
        valueCopy[otherSize] = NULL_CHAR;

        value = strncpy(valueCopy, chars, otherSize);
    }

    return *this;
}

String String::operator + (const String& other) {
    String result(value);
    result.append(other);

    return result;
}

String String::operator + (const char* chars) {
    String result(value);
    result.append(chars);

    return result;
}

String& String::operator += (const String& other) {
    append(other);
}

String& String::operator += (const char* chars) {
    append(chars);
}

std::istream& operator >> (std::istream& is, const String& string) {
    is >> string.value;

    return is;
}

std::ostream& operator << (std::ostream& os, const String& string) {
    os << string.value;

    return os;
}

void String::isIndexValid(size_t index) const {
    if(index >= getSize()) {
        throw std::out_of_range("Index out of range");
    }
}

String::~String() {
    delete[] value;
}