#pragma once

#include <string>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR" };

class Symbole {
   public:
      Symbole(int id, bool t) : ident(id), terminal(t) {}
      virtual ~Symbole() { }
      virtual void Affiche();
      virtual int getValeur();
      void print();
      int getIdent(){return ident;}
      bool isTerminal() { return terminal; }
      operator int() const { return ident; }

   protected:
      int ident;
      bool terminal;
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT,true), valeur(v) { }
      ~Entier() { }
      virtual void Affiche();
      int getValeur(){return valeur;}
   protected:
      int valeur;
};

class Expression : public Symbole {
   public:
      Expression(int v):Symbole(EXPR,false), valeur(v) {}
      virtual ~Expression() {}
      int getValeur(){return valeur;}
   protected:
      int valeur;
};