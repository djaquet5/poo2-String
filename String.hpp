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
    String();

    ~String();

    explicit String(const char* string);

    explicit String(const String& string);

    explicit String(int value);

    explicit String(double value);

    explicit String(bool value);

    bool equals(const String& string) const;

    size_t getSize() const;

    char& at(size_t index) const;

    const char* getValue() const; //(not const) char* ??? => non, c'est pas un getteur a proprement parlé (voir donnée 3.2)

    String substr(size_t start, size_t end) const;

    //TODO : Operateur a implémenter tous, sauf const char*
    // getCharAt
    char& operator [] (size_t index);

    // equals
    bool operator == (const String& string) const;

    //=
    String& operator = (const String& string);
    String& operator = (const char* string);

    //+
    String& operator + (const String& string);

    //+=
    String& operator += (const String& string);

    //>>
    friend std::istream& operator >> (std::istream& is, const String& string);

    //<<
    friend std::ostream& operator << (std::ostream& os, const String& string);

};
