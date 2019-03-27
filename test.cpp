//
// Created by jostoph on 3/27/19.
//

#include <iostream>

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
        return fail();
    }

    return pass();
}

// TODO add test if s is modified after ?
bool stringConstructorTests() {
    String s("abc");

    String s1(s);

    cout << "stringConstructorTests : ";
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

}

bool getSizeTests() {

}

bool atTests() {

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