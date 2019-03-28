/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : test.cpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 27.03.2019

 But         : Liste des différents tests pour la classe String

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/

#include <iostream>

#include "String.hpp"
#include "test.hpp"

using namespace std;

bool pass() {
    cout << "pass" << endl;
    return true;
}

bool fail() {
    cout << "fail" << endl;
    return false;
}

void runAllTests() {
    cout << "/********** Test de la classe String **********/" << endl << endl;

    if(constructorTests() && methodTests() && operatorTests()) {
        cout << "Tous les tests passents !" << endl << endl;
    }

    cout << "********** Fin des tests **********" << endl;
}

bool constructorTests() {
    cout << endl << "-------- Tests des constructeurs --------" << endl << endl;

    return emptyConstructorTests() &&
            stringConstructorTests() &&
            cstringConstructorTests() &&
            charArrayConstructorTests() &&
            charConstructorTests() &&
            intConstructorTests() &&
            doubleConstructorTests() &&
            boolConstructorTests();
}

bool methodTests() {
    cout << endl << "-------- Tests des methodes --------" << endl << endl;

    return equalsTests() &&
            getSizeTests() &&
            atTests() &&
            getValueTests() &&
            substringTests() &&
            appendTests();
}

bool operatorTests() {
    cout << endl << "-------- Tests des operateurs --------" << endl << endl;

    return atOperatorTests() &&
            equalsOperatorTests() &&
            notEqualsOperatorTests() &&
            affectationOperatorTests() &&
            plusOperatorTests() &&
            plusEqualOperatorTests() &&
            fluxOperatorTests();
}

/* ----- Tests des constructeurs de String ----- */

// TODO : revérifier commentaire de constructeurss
bool emptyConstructorTests() {
    String s;

    cout << "emptyConstructorTests : ";

    // On vérifie que le constructeur vide initialise l'objet correctement (chaine vide)
    if(s.getSize() != 0 || s.getValue()[0] != '\0') {
        return fail();
    }

    return pass();
}

bool stringConstructorTests() {
    String s("abc");

    String s1(s);

    cout << "stringConstructorTests : ";

    // On vérifie que le constructeur par copie fonctionne
    if(s1.getSize() != 3 || strcmp(s1.getValue(), "abc") != 0) {
        return fail();
    }

    s.append('d');

    // On vérifie l'encapsulation des données en vérifiant que s1 n'a pas changé
    if(s1.getSize() != 3 || strcmp(s1.getValue(), "abc") != 0) {
        return fail();
    }

    return pass();
}

bool cstringConstructorTests() {
    String s("string");

    cout << "cstringConstructorTests : ";
    if(s.getSize() != 6 || strcmp(s.getValue(), "string") != 0) {
        return fail();
    }

    return pass();
}

bool charArrayConstructorTests() {
    char chars[5] = {'a', 'b', 'c', 'd', 'e'};
    String s(chars, 5);

    cout << "charArrayConstructorTests : ";
    if(s.getSize() != 5 || strcmp(s.getValue(), "abcde") != 0) {
        return fail();
    }

    return pass();
}

bool charConstructorTests() {
    String s('X');

    cout << "charConstructorTests : ";
    if(s.getSize() != 1 || strcmp(s.getValue(), "X") != 0) {
        return fail();
    }

    return pass();
}

bool intConstructorTests() {
    String s(2019);
    String s1(-2019);
    String s2(0);

    cout << "intConstructorTests : ";
    if(s.getSize() != 4 || strcmp(s.getValue(), "2019") != 0) {
        return fail();
    }

    if(s1.getSize() != 5 || strcmp(s1.getValue(), "-2019") != 0) {
        return fail();
    }

    if(s2.getSize() != 1 || strcmp(s2.getValue(), "0") != 0) {
        return fail();
    }

    return pass();
}

bool doubleConstructorTests() {
    String s(1234.005);
    String s1(-987.123);
    String s2(000.000);

    cout << "doubleConstructorTests : ";
    if(s.getSize() != 11 || strcmp(s.getValue(), "1234.005000") != 0) {
        return fail();
    }

    if(s1.getSize() != 11 || strcmp(s1.getValue(), "-987.123000") != 0) {
        return fail();
    }

    if(s2.getSize() != 8 || strcmp(s2.getValue(), "0.000000") != 0) {
        return fail();
    }

    return pass();
}

bool boolConstructorTests() {
    String s(true);
    String s1(false);

    cout << "boolConstructorTests : ";

    if(s.getSize() != 1 || strcmp(s.getValue(), "1") != 0) {
        return fail();
    }

    if(s1.getSize() != 1 || strcmp(s1.getValue(), "0") != 0) {
        return fail();
    }

    return pass();
}

/* ----- Tests des méthodes de String ----- */

bool equalsTests() {
    const char* str = "equalsTests";
    String string1(str);
    String string2(str);

    cout << "equalsTests : ";

    // On vérifique le equals avec une chaine de caractère
    if(!string1.equals(str)) {
        return fail();
    }

    // On vérifie le equals avec un String
    if(!string1.equals(string2)) {
        return fail();
    }

    string2.append(" not equals anymore");

    // On teste deux String qui ne sont pas égaux
    if(string2.equals(string1)) {
        return fail();
    }

    return pass();
}


// TODO : Finir depuis là
bool getSizeTests() {
    String string("Size");

    cout << "getSizeTests : ";
    if(string.getSize() != 4) {
        return fail();
    }

    string.append(" !");
    if(string.getSize() != 6) {
        return fail();
    }

    return pass();
}

bool atTests() {
    const String constStr("Constante");

    String string("atTests!");
    size_t size = string.getSize();

    cout << "atTests : ";
    if(string.at(0) != 'a') {
        return fail();
    }

    if(string.at(3) != 'e') {
        return fail();
    }

    if(string.at(size - 1) != '!') {
        return fail();
    }

    try {
        string.at(size);
        return fail();
    } catch(out_of_range& e) {}

    string.at(0) = 'b';
    if(string.at(0) != 'b') {
        return fail();
    }

    // Le test ci-dessous est commenté car il empêche la compilation.
    // Il s'agit du comportement voulu, on ne veut pas pouvoir modifier le contenu
    // d'un const String. Le test est donc validé
    // constStr.at(0) = 'A';

    return pass();
}

bool getValueTests() {
    String s("test 1 2 3");
    String s1("");

    cout << "getValueTests : ";
    if(strcmp(s.getValue(), "test 1 2 3") != 0) {
        return fail();
    }

    if(strcmp(s1.getValue(), "") != 0) {
        return fail();
    }

    return pass();
}

bool substringTests() {
    const String s("hello world");

    String s1 = s.substr(0);

    cout << "substringTests : ";
    if(s1.getSize() != 11 || strcmp(s.getValue(), "hello world") != 0) {
        return fail();
    }

    s1 = s.substr(3);
    if(s1.getSize() != 8 || strcmp(s1.getValue(), "lo world") != 0) {
        return fail();
    }

    s1 = s.substr(s.getSize());
    if(s1.getSize() != 0 || strcmp(s1.getValue(), "") != 0) {
        return fail();
    }

    try {
        s1 = s.substr(s.getSize() + 1);
        return fail();
    } catch(out_of_range& e) {}

    s1 = s.substr(6,3);
    if(s1.getSize() != 3 || strcmp(s1.getValue(), "wor") != 0) {
        return fail();
    }

    s1 = s.substr(6, 100);
    if(s1.getSize() != 5 || strcmp(s1.getValue(), "world") != 0) {
        return fail();
    }

    return pass();
}

bool appendTests() {
    const String constStr("Constante");

    String string1("String1");
    String string2("String2");

    cout << "appendTests : ";
    string1.append(' ');
    if(!string1.equals("String1 ")) {
        return fail();
    }

    string1.append("et ");
    if(!string1.equals("String1 et ")) {
        return fail();
    }

    string1.append(string2);
    if(!string1.equals("String1 et String2")) {
        return fail();
    }

    // Le test ci-dessous est commenté car il empêche la compilation.
    // Il s'agit du comportement voulu, on ne veut pas pouvoir modifier le contenu
    // d'un const String. Le test est donc validé
    // constStr.append(" ne compile pas !");

    return pass();
}

/* ----- Tests des opérateurs de String ----- */

bool atOperatorTests() {
    const String constStr("Constante");

    String string("atOperatorTests!");
    size_t size = string.getSize();

    cout << "atOperatorTests : ";
    if(string[0] != 'a') {
        return fail();
    }

    if(string[3] != 'p') {
        return fail();
    }

    if(string[size - 1] != '!') {
        return fail();
    }

    try {
        string[size];
        return fail();
    } catch(out_of_range& e) {}

    string[0] = 'b';
    if(string[0] != 'b') {
        return fail();
    }

    // Le test ci-dessous est commenté car il empêche la compilation.
    // Il s'agit du comportement voulu, on ne veut pas pouvoir modifier le contenu
    // d'un const String. Le test est donc validé
    // constStr[0] = 'A';

    return pass();
}

bool equalsOperatorTests() {
    const char* str = "equalsOperatorTests";
    String string1(str);
    String string2(str);

    cout << "equalsOperatorTests : ";
    if(!(string1 == str)) {
        return fail();
    }

    if(!(string1 == string2)) {
        return fail();
    }

    string2.append(" not equals anymore");
    if(string1 == string2) {
        return fail();
    }

    return pass();
}

bool notEqualsOperatorTests() {
    const char* str = "notEqualsOperatorTests";
    String string1(str);
    String string2(str);

    cout << "notEqualsOperatorTests : ";
    if(string1 != str) {
        return fail();
    }

    if(string1 != string2) {
        return fail();
    }

    string2.append(" now equals");
    if(!(string1 != string2)) {
        return fail();
    }

    return pass();
}

bool affectationOperatorTests() {
    const String s("string");
    String s1;

    cout << "affectationOperatorTests : ";
    s1 = s;
    if(s1.getSize() != s.getSize() || strcmp(s1.getValue(), s.getValue()) != 0) {
        return fail();
    }

    s1 = "other string";
    if(s1.getSize() != 12 || strcmp(s1.getValue(), "other string") != 0) {
        return fail();
    }

    return pass();
}

bool plusOperatorTests() {
    String string1("String1");
    String string2("String2");

    cout << "plusOperatorTests : ";
    if((string1 + ' ') != "String1 ") {
        return fail();
    }

    if((string1 + " !") != "String1 !") {
        return fail();
    }

    if((string1 + string2) != "String1String2") {
        return fail();
    }

    return pass();
}

bool plusEqualOperatorTests() {
    const String constStr("Constante");

    String string1("String1");
    String string2("String2");

    cout << "plusEqualOperatorTests : ";

    string1 += ' ';
    if(string1 != "String1 ") {
        return fail();
    }

    string1 += "et ";
    if(!string1.equals("String1 et ")) {
        return fail();
    }

    string1 += string2;
    if(!string1.equals("String1 et String2")) {
        return fail();
    }

    // Le test ci-dessous est commenté car il empêche la compilation.
    // Il s'agit du comportement voulu, on ne veut pas pouvoir modifier le contenu
    // d'un const String. Le test est donc validé
    // constStr += " ne compile pas !";

    return pass();
}

bool fluxOperatorTests() {

}