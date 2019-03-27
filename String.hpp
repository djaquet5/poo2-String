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

//      We don't need that :'(
//    /**
//     * Ajoute le caractère '\0' a la fin de value
//     */
//    void addEndOfStringChar();
public:
    /**
     * Constructeur vide, l'attribut value aura uniquement le caractère '\0'
     */
    explicit String();

    /**
     * Constructeur par copie avec un String
     *
     * @param other String à copier
     */
    explicit String(const String& other);

    /**
     * Constructeur par copie avec un c-string (char* avec le "null terminator")
     *
     * @param other String à copier (sous forme de c-string)
     */
    explicit String(const char* chars);

    /**
     * Constructeur de copie avec un char* (sans le "null terminator")
     * @param chars tableau de char à copier
     * @param n taille du tableau de char
     */
    explicit String(const char* chars, size_t n);

    /**
     * Constructeur par copie avec un char
     *
     * @param value Char à copier
     */
    explicit String(char c);

    /**
     * Constructeur par copie avec un int
     *
     * @param value Int à copier
     */
    explicit String(int i);

    /**
     * Constructeur par copie avec un double
     *
     * @param value Double à copier
     */
    explicit String(double d);

    /**
     * Constructeur par copie avec un bool
     *
     * @param value Bool à copier
     */
    explicit String(bool b);

    /**
     * Indique si la valeur du String est égal à celle du String passé en paramètre
     *
     * @param string String a tester
     * @return True si les valeurs sont égales, False sinon
     */
    bool equals(const String& other) const;

    /**
     * Indique si la du String est égale au c-string en paramètre (avec le caractère null)
     *
     * @param chars le c-string à comparer
     * @return True si la valeur du String et le c-string sont égales
     */
    bool equals(const char* chars) const;

    /**
     * Retourne la taille de value sans le caractère '\0'
     *
     * @return Nombre de caractère au format size_t
     */
    size_t getSize() const;

    /**
     *
     * @param index
     * @return
     */
    char& at(size_t index) const;

    const char* getValue() const;

    String substr(size_t start) const;
    String substr(size_t start, size_t length) const;

    void append(char c);
    void append(const char* chars);
    void append(const String& other);

    //TODO : Operateur a implémenter tous, sauf const char*
    // getCharAt
    char operator [] (size_t index) const;
    char& operator [] (size_t index);

    // equals
    bool operator == (const String& string) const;
    bool operator == (const char* string) const;

    // not equals
    bool operator != (const String& string) const;
    bool operator != (const char* string) const;

    // assign
    String& operator = (const String& string);
    String& operator = (const char* string);

    // append
    String& operator + (const String& other);
    String& operator + (const char* chars);

    // append + assign
    String& operator += (const String& other);
    String& operator += (const char* other);

    // >>
    friend std::istream& operator >> (std::istream& is, const String& string);

    // getValue
    friend std::ostream& operator << (std::ostream& os, const String& string);

    virtual ~String();

};
