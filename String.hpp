/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : cstring.h
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 07.03.2019

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/

#pragma once

#include <cstdio>

/**
 * Spécification de la classe String
 */
class String {
    char* value;

public:
    String();

    explicit String(const char* string);

    explicit String(const String& string);

    explicit String(const int value);

    explicit String(const double value);

    explicit String(const bool value);

    size_t getSize() const;

    char& getCharAt(const size_t index);

    const char* getValue() const;

    String substr(const size_t start, const size_t end) const;

    //TODO : Operateur a implémenter tous, sauf const char*
    // getCharAt
    char& operator[] (const size_t index);

    // isEqual
    bool operator== (const String& string) const;

    //=
    String operator= (const String& string);

    //+
    String operator+ (const String& string);

    //+=
    String operator+= (const String& string);

    //>>
    istream& operator>> (istream& is, String& string);

    //<<
    ostream& operator<< (ostream& os, String% string);


};
