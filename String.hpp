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

    /**
     * Vérifie si l'index fournit est une position d'un char valide
     *
     * @param index Index à vérifier
     * @throw out_of_range si le l'index n'est pas valide
     */
    void isIndexValid(size_t index) const;
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
    String(const String& other);

    /**
     * Constructeur par copie avec un c-string (char* avec le "null terminator")
     *
     * @param other String à copier (sous forme de c-string)
     */
    explicit String(const char* chars);

    /**
     * Constructeur de copie avec un char* (sans le "null terminator")
     *
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
     * Retourne le caractère à l'index donné
     *
     * @param index Index du caractère voulu
     * @return Caractère correspondant à l'index
     * @throw out_of_range si le l'index n'est pas valide
     */
    const char& at(size_t index) const;

    /**
     * Retourne le caractère à l'index donné
     *
     * @param index Index du caractère voulu
     * @return Caractère correspondant à l'index
     * @throw out_of_range si le l'index n'est pas valide
     */
    char& at(size_t index);

    /**
     * Obtiens la valeur du String
     *
     * @return Valeur du String sans le caractère null
     */
    const char* getValue() const;

    /**
     * Retourne une sous chaine depuis l'index start jusqu'à la fin
     *
     * @param start Index servant à définir le premier char de la sous chaine
     * @return Sous chaine voulue au format String
     * @throw out_of_range si le l'index n'est pas valide
     */
    String substr(size_t start) const;

    /**
     * Retourne une sous chaine depuis l'index start de longueur length
     *
     * @param start Index servant à définir le premier char de la sous chaine
     * @param length Longueur de la sous chaine
     * @return Sous chaine voulue au format String
     * @throw out_of_range si le l'index n'est pas valide
     */
    String substr(size_t start, size_t length) const;

    /**
     * Concatène la valeur courrante de la chaine avec le caractère donné
     *
     * @param c Caractère à concatener
     */
    void append(char c);

    /**
     * Concatène la valeur courrante de la chaine avec la chaîne de caractères donnée
     *
     * @param chars Chaine de caractère à concatener
     */
    void append(const char* chars);

    /**
     * Concatène la valeur courrante de la chaine avec le String
     *
     * @param other String à concatener
     */
    void append(const String& other);

    /**
     * Operateur servant à obtenir un caractère à un index donné
     *
     * @param index Index du caractère voulu
     * @return Caractère voulu
     * @throw out_of_range si le l'index n'est pas valide
     */
    const char& operator [] (size_t index) const;

    /**
     * Operateur servant à obtenir un caractère à un index donné
     *
     * @param index Index du caractère voulu
     * @return Caractère voulu
     * @throw out_of_range si le l'index n'est pas valide
     */
    char& operator [] (size_t index);

    /**
     * Vérifie si la valeur du String est égale à la valeur courante
     *
     * @param string String à vérifier
     * @return True si les deux valeurs sont égales, false sinon
     */
    bool operator == (const String& string) const;

    /**
     * Vérifie si la chaine de caractères est égale à la valeur courante
     *
     * @param string Chaine de caractères à vérifier
     * @return True si les deux valeurs sont égales, false sinon
     */
    bool operator == (const char* string) const;

    /**
     * Vérifie si la valeur du String est différente de la valeur courante
     *
     * @param string String à vérifier
     * @return True si les deux valeurs sont différentes , false sinon
     */
    bool operator != (const String& string) const;

    /**
     * Vérifie si la chaine de caractères est différente de la valeur courante
     *
     * @param string Chaine de caractères à vérifier
     * @return True si les deux valeurs sont différentes , false sinon
     */
    bool operator != (const char* string) const;

    /**
     * Opérateur d'affectation
     *
     * @param string String a affecter
     * @return Résultat de l'affectation
     */
    String& operator = (const String& string);

    /**
     * Opérateur d'affectation
     *
     * @param string Chaine de caractère à affecter
     * @return Résultat de l'affectation
     */
    String& operator = (const char* string);

    /**
     * Concatène la valeur courante avec celle passée en paramètre
     *
     * @param other String contenant la valeur à concaténer
     * @return Résultat de la concaténation
     */
    String operator + (const String& other);

    /**
     * Concatène la valeur courante avec la chaine de caractères passée en paramètre
     *
     * @param chars Chaine de caractères a concaténer
     * @return Résultat de la concaténation
     */
    String operator + (const char* chars);

    /**
     * Concatène la valeur courante avec celle passée en paramètre
     * et assigne le résultat à la valeur courante
     *
     * @param chars Chaine de caractères a concaténer
     * @return Résultat de la concaténation
     */
    String& operator += (const String& other);

    /**
     * Concatène la valeur courante avec la chaine de caractères passée en paramètre
     * et assigne le résultat à la valeur courante
     *
     * @param chars Chaine de caractères a concaténer
     * @return Résultat de la concaténation
     */
    String& operator += (const char* other);

    /**
     * Surcharge de l'opérateur de flux entrant
     *
     * @param is Flux entrant
     * @param string String entrant
     * @return
     */
    friend std::istream& operator >> (std::istream& is, const String& string);

    /**
     * Surcharge de l'opérateur de flux sortant
     *
     * @param os Flux sortant
     * @param string String à afficher
     * @return Valeur à afficher
     */
    friend std::ostream& operator << (std::ostream& os, const String& string);

    /**
     * Destructeur
     */
    virtual ~String();

};
