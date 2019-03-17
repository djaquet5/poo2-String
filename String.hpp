/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : String.hpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 07.03.2019

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/

#pragma once

#include <cstdio>
#include <iostream>
#include <cstring>
#include <exception>

/**
 * Spécification de la classe String
 */
class String {
    char* value;

    void addEndOfStringChar();
public:
    explicit String();

    explicit String(const String& string);

    explicit String(const char* string);

    explicit String(char value);

    explicit String(int value);

    explicit String(double value);

    explicit String(bool value);

    virtual ~String();

    bool isEqual(const String& string) const;

    size_t getSize() const;

    char& getCharAt(size_t index);

    const char* getValue() const;

    String substr(size_t start, size_t end) const;

    //TODO : Operateur a implémenter tous, sauf const char*
    // getCharAt
    char operator [] (size_t index) const;
    char& operator [] (size_t index);

    // isEqual
    bool operator == (const String& string) const;
    bool operator == (const char* string) const;

    // assign
    String& operator = (const String& string);
    String& operator = (const char* string);

    // append
    String& operator + (const String& left, const String& right);
    String& operator + (const String& left, const char* right);
    String& operator + (const char* left, const String& right);

    // append + assign
    String& operator += (const String& other);
    String& operator += (const char* other);

    // >>
    friend std::istream& operator >> (std::istream& is, const String& string);

    // getValue
    friend std::ostream& operator << (std::ostream& os, const String& string);

};
