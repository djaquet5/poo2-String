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

#include <cstdio> // stdio.h ???
#include <iostream>
#include <string.h>
#include <exception>

/**
 * Spécification de la classe String
 */
class String {
    // TODO : A demander si string est immuable en C++
    char* value; // const ???

public:
    String();

    ~String();

    explicit String(const char* string);

    explicit String(const String& string);

    explicit String(int value);

    explicit String(double value);

    explicit String(bool value);

    size_t getSize() const;

    char& getCharAt(size_t index);

    const char* getValue() const; //(not const) char* ??? => non, c'est pas un getteur a proprement parlé (voir donnée 3.2)

    String substr(size_t start, size_t end) const;

    //TODO : Operateur a implémenter tous, sauf const char*
    // getCharAt
    char& operator [] (size_t index);

    // isEqual
    bool operator == (const String& string) const;

    //=
    String& operator = (const String& string);

    //+
    String& operator + (const String& string);

    //+=
    String& operator += (const String& string);

    //>>
    friend std::istream& operator >> (std::istream& is, const String& string);

    //<<
    friend std::ostream& operator << (std::ostream& os, const String& string);

};
