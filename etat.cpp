#include "etat.h"

bool E0::transition(Automate & automate, Symbole * s) {
    switch (*s){
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case INT:
            automate.decalage(s, new E3);
            break;
        case EXPR:
            automate.transitionNonTerminal(s, new E1);
            break;
    }
    return false;
}

bool E1::transition(Automate & automate, Symbole * s) {
    switch (*s){
        case PLUS:
            automate.decalage(s, new E4);
            break;
        case MULT:
            automate.decalage(s, new E5);
            break;
        case FIN:
            return 1;
    }
    return false;
}

bool E2::transition(Automate & automate, Symbole * s) {
    switch (*s){
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case INT:
            automate.decalage(s, new E3);
            break;
        case EXPR:
            automate.transitionNonTerminal(s, new E6);
            break;
    }
    return false;
}

bool E3::transition(Automate & automate, Symbole * s) {
    switch (*s){
        case CLOSEPAR:
            automate.reduction(1, s);
            break;
        case PLUS:
            automate.reduction(1, s);
            break;
        case MULT:
            automate.reduction(1, s);
            break;
        case FIN:
            automate.reduction(1, s);
            break;
    }
    return false;
}

bool E4::transition(Automate & automate, Symbole * s) {
    switch (*s){
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case INT:
            automate.decalage(s, new E3);
            break;
        case EXPR:
            automate.transitionNonTerminal(s, new E7);
            break;
    }
    return false;
}

bool E5::transition(Automate & automate, Symbole * s) {
    switch (*s){
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case INT:
            automate.decalage(s, new E3);
            break;
        case EXPR:
            automate.transitionNonTerminal(s, new E8);
            break;
    }
    return false;
}

bool E6::transition(Automate & automate, Symbole * s) {
    switch (*s){
        case CLOSEPAR:
            automate.decalage(s, new E9);
            break;
        case PLUS:
            automate.decalage(s, new E4);
            break;
        case MULT:
            automate.decalage(s, new E5);
            break;
    }
    return false;
}

bool E7::transition(Automate & automate, Symbole * s) {
    switch (*s){
        case CLOSEPAR:
            automate.reduction(3, s);
            break;
        case PLUS:
            automate.reduction(3, s);
            break;
        case MULT:
            automate.decalage(s, new E5);
            break;
        case FIN:
            automate.reduction(3, s);
            break;
    }
    return false;
}

bool E8::transition(Automate & automate, Symbole * s) {
    switch (*s){
        case CLOSEPAR:
            automate.reduction(3, s);
            break;
        case PLUS:
            automate.reduction(3, s);
            break;
        case MULT:
            automate.reduction(3, s);
            break;
        case FIN:
            automate.reduction(3, s);
            break;
    }
    return false;
}

bool E9::transition(Automate & automate, Symbole * s) {
    switch (*s){
        case CLOSEPAR:
            automate.reduction(3, s);
            break;
        case PLUS:
            automate.reduction(3, s);
            break;
        case MULT:
            automate.reduction(3, s);
            break;
        case FIN:
            automate.reduction(3, s);
            break;
    }
    return false;
}
