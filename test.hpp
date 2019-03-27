/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : test.hpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 27.03.2019

 But         : Liste des différents tests pour la classe String

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/

#pragma once

/**
 * Lance tous les tests, dès qu'un test échoue le programme s'arrête
 */
void runAllTests();

/**
 * Lance tous les tests de constructeur
 */
bool constructorTests();


/**
 * Lance tous les tests de méthodes
 */
bool methodTests();

/**
 * Lance tous les tests d'opérateurs
 */
bool operatorTests();

/* ----- Tests des constructeurs de String ----- */

bool emptyConstructorTests();

bool stringConstructorTests();

bool cstringConstructorTests();

bool charArrayConstructorTests();

bool charConstructorTests();

bool intConstructorTests();

bool doubleConstructorTests();

bool boolConstructorTests();

/* ----- Tests des méthodes de String ----- */

bool equalsTests();

bool getSizeTests();

bool atTests();

bool getValueTests();

bool substringTests();

bool appendTests();

/* ----- Tests des opérateurs de String ----- */

bool atOperatorTests();

bool equalsOperatorTests();

bool notEqualsOperatorTests();

bool affectationOperatorTests();

bool plusOperatorTests();

bool plusEqualOperatorTests();

bool fluxOperatorTests();
