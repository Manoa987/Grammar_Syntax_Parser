#pragma once

#include <string>
#include "symbole.h"
#include "lexer.h"
#include <stack>
using namespace std;
class Etat;

class Automate {
   public:
      Automate(Lexer* lexer);
      virtual ~Automate() { }
      void decalage(Symbole * s, Etat * e);
      void transitionNonTerminal(Symbole * s, Etat * e);
      void reduction(int n,Symbole * s);
      stack<Etat*> getStatestack(){return statestack;};
      stack<Symbole*> getSymbolestack(){return symbolstack;};

   protected:
      Lexer* l;
      stack<Symbole*> symbolstack;
      stack<Etat*> statestack;
};


