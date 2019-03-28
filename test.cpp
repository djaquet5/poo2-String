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

// fonctions utilitaires pour les tests

void free(const char* value) {
    delete[] value;
}

bool pass() {
    cout << "pass" << endl;
    return true;
}

bool pass(const char* value) {
    free(value);
    pass();
}

bool fail() {
    cout << "fail" << endl;
    return false;
}

bool fail(const char* value) {
    free(value);
    fail();
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
    const char* value;
    String s;

    cout << "emptyConstructorTests : ";

    // On vérifie que le constructeur vide initialise l'objet correctement (chaine vide)
    value = s.getValue();
    if(s.getSize() != 0 || value[0] != '\0') {
        return fail(value);
    }

    return pass(value);
}

bool stringConstructorTests() {
    const char* value;
    String s("abc");

    String s1(s);

    cout << "stringConstructorTests : ";

    // On vérifie que le constructeur par copie fonctionne
    value = s1.getValue();
    if(s1.getSize() != 3 || strcmp(value, "abc") != 0) {
        return fail(value);
    }

    s.append('d');

    // On vérifie l'encapsulation des données en vérifiant que s1 n'a pas changé
    free(value);
    value = s1.getValue();
    if(s1.getSize() != 3 || strcmp(value, "abc") != 0) {
        return fail(value);
    }

    return pass(value);
}

bool cstringConstructorTests() {
    const char* value;
    String s("string");

    cout << "cstringConstructorTests : ";
    value = s.getValue();
    if(s.getSize() != 6 || strcmp(value, "string") != 0) {
        return fail(value);
    }

    return pass(value);
}

bool charArrayConstructorTests() {
    const char* value;
    char chars[5] = {'a', 'b', 'c', 'd', 'e'};
    String s(chars, 5);

    cout << "charArrayConstructorTests : ";
    value = s.getValue();
    if(s.getSize() != 5 || strcmp(value, "abcde") != 0) {
        return fail(value);
    }

    return pass(value);
}

bool charConstructorTests() {
    const char* value;
    String s('X');

    cout << "charConstructorTests : ";
    value = s.getValue();
    if(s.getSize() != 1 || strcmp(value, "X") != 0) {
        return fail(value);
    }

    return pass(value);
}

bool intConstructorTests() {
    const char* value;
    String s(2019);
    String s1(-2019);
    String s2(0);

    cout << "intConstructorTests : ";
    value = s.getValue();
    if(s.getSize() != 4 || strcmp(value, "2019") != 0) {
        return fail(value);
    }

    free(value);
    value = s1.getValue();
    if(s1.getSize() != 5 || strcmp(value, "-2019") != 0) {
        return fail(value);
    }

    free(value);
    value = s2.getValue();
    if(s2.getSize() != 1 || strcmp(value, "0") != 0) {
        return fail(value);
    }

    return pass(value);
}

// TODO comportement to_string (explication)
bool doubleConstructorTests() {
    const char* value;
    String s(1234.005);
    String s1(-987.123);
    String s2(000.000);

    cout << "doubleConstructorTests : ";
    value = s.getValue();
    if(s.getSize() != 11 || strcmp(value, "1234.005000") != 0) {
        return fail(value);
    }

    free(value);
    value = s1.getValue();
    if(s1.getSize() != 11 || strcmp(value, "-987.123000") != 0) {
        return fail(value);
    }

    free(value);
    value = s2.getValue();
    if(s2.getSize() != 8 || strcmp(value, "0.000000") != 0) {
        return fail(value);
    }

    return pass(value);
}

bool boolConstructorTests() {
    const char* value;
    String s(true);
    String s1(false);

    cout << "boolConstructorTests : ";
    value = s.getValue();
    if(s.getSize() != 1 || strcmp(value, "1") != 0) {
        return fail(value);
    }

    free(value);
    value = s1.getValue();
    if(s1.getSize() != 1 || strcmp(value, "0") != 0) {
        return fail(value);
    }

    return pass(value);
}

/* ----- Tests des méthodes de String ----- */

bool equalsTests() {
    const char* str = "equalsTests";
    String string1(str);
    String string2(str);

    cout << "equalsTests : ";
    // On vérifie que le equals avec une chaine de caractère
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

bool getSizeTests() {
    String string("Size");

    cout << "getSizeTests : ";
    if(string.getSize() != 4) {
        return fail();
    }

    // On teste que la taille change bien après y avoir ajouté des caractères
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

    // On teste le comportement normal
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

    // On teste qu'un accès illégal retourne une exception
    try {
        string.at(size);
        return fail();
    } catch(out_of_range& e) {}

    // On vérifie qu'on peut modifier un String qui n'est pas const
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
    const char* value;
    String s("test 1 2 3");
    String s1("");

    cout << "getValueTests : ";
    value = s.getValue();
    if(strcmp(value, "test 1 2 3") != 0) {
        return fail(value);
    }

    free(value);
    value = s1.getValue();
    if(strcmp(value, "") != 0) {
        return fail(value);
    }

    return pass(value);
}

bool substringTests() {
    const char* value;
    const String s("hello world");

    String s1 = s.substr(0);

    // On teste du comportement normal de substr avec un paramètre
    cout << "substringTests : ";
    value = s1.getValue();
    if(s1.getSize() != 11 || strcmp(value, "hello world") != 0) {
        return fail(value);
    }

    s1 = s.substr(3);
    free(value);
    value = s1.getValue();
    if(s1.getSize() != 8 || strcmp(value, "lo world") != 0) {
        return fail(value);
    }

    s1 = s.substr(s.getSize());
    free(value);
    value = s1.getValue();
    if(s1.getSize() != 0 || strcmp(value, "") != 0) {
        return fail(value);
    }

    // On vérifie que substr retourne une exception si on utilise un paramètre illégal
    try {
        s1 = s.substr(s.getSize() + 1);
        return fail();
    } catch(out_of_range& e) {}

    // On teste le comportement normal de substr avec 2 paramètres
    s1 = s.substr(6,3);
    free(value);
    value = s1.getValue();
    if(s1.getSize() != 3 || strcmp(value, "wor") != 0) {
        return fail(value);
    }

    // On teste le cas où la longueur voulue est plus grande que la taille du String
    s1 = s.substr(6, 100);
    free(value);
    value = s1.getValue();
    if(s1.getSize() != 5 || strcmp(value, "world") != 0) {
        return fail(value);
    }

    return pass(value);
}

bool appendTests() {
    const String constStr("Constante");

    String string1("String1");
    String string2("String2");

    cout << "appendTests : ";
    // On teste append avec un char
    string1.append(' ');
    if(!string1.equals("String1 ")) {
        return fail();
    }

    // On teste append avec un c-string
    string1.append("et ");
    if(!string1.equals("String1 et ")) {
        return fail();
    }

    // On teste append avec un String
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
    const char* value;
    const String s("string");
    String s1;

    cout << "affectationOperatorTests : ";
    s1 = s;
    value = s1.getValue();
    if(s1.getSize() != s.getSize() || strcmp(value, "string") != 0) {
        return fail(value);
    }

    s1 = "other string";
    free(value);
    value = s1.getValue();
    if(s1.getSize() != 12 || strcmp(value, "other string") != 0) {
        return fail(value);
    }

    return pass(value);
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