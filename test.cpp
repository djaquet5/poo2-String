//
// Created by jostoph on 3/27/19.
//

#include <iostream>

#include "test.hpp"

using namespace std;

void pass() {
    cout << "pass" << endl;
}

void fail() {
    cout << "fail" << endl;
}

void runAllTests() {
    cout << "/********** Test de la classe String **********/" << endl << endl;

    if(constructorTests() && methodTests() && operatorTests()) {
        cout << "Tous les tests passents !" << endl << endl;
    }

    cout << "********** Fin des tests **********" << endl;
}

bool constructorTests() {
    cout << "-------- Tests des constructeurs --------" << endl << endl;

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
    cout << "-------- Tests des méthodes --------" << endl << endl;

    return equalsTests() &&
            getSizeTests() &&
            atTests() &&
            getValueTests() &&
            substringTests() &&
            appendTests();
}

bool operatorTests() {
    cout << "-------- Tests des opérateurs --------" << endl << endl;

    return atOperatorTests() &&
            equalsOperatorTests() &&
            notEqualsOperatorTests() &&
            affectationOperatorTests() &&
            plusOperatorTests() &&
            plusEqualOperatorTests() &&
            fluxOperatorTests();
}

/* ----- Tests des constructeurs de String ----- */

bool emptyConstructorTests() {
    String s;

    cout << "emptyConstructorTests : ";
    if(s.getSize() != 0 || s.getValue()[0] != '\0') {
        fail();
        return false;
    }

    pass();
    return true;
}

bool stringConstructorTests() {

}

bool cstringConstructorTests() {
    String s("string");

    cout << "cstringConstructorTests : ";
    if(s.getSize() != 6 || strcmp(s.getValue(), "string") != 0) {
        fail();
        return false;
    }

    pass();
    return true;
}

bool charArrayConstructorTests() {

}

bool charConstructorTests() {

}

bool intConstructorTests() {

}

bool doubleConstructorTests() {

}

bool boolConstructorTests() {

}

/* ----- Tests des méthodes de String ----- */

bool equalsTests() {

}

bool getSizeTests() {

}

bool atTests() {

}

bool getValueTests() {

}

bool substringTests() {

}

bool appendTests() {

}

/* ----- Tests des opérateurs de String ----- */

bool atOperatorTests() {

}

bool equalsOperatorTests() {

}

bool notEqualsOperatorTests() {

}

bool affectationOperatorTests() {

}

bool plusOperatorTests() {

}

bool plusEqualOperatorTests() {

}

bool fluxOperatorTests() {

}