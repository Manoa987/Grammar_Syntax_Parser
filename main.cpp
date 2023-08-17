#include <iostream>
#include "etat.h"
#include "automate.h"



int main(void) {
   string chaine("(1+34)*123");

   Lexer l(chaine);
   Automate automate(&l);

   Symbole * s;
   
   while(*(s=l.Consulter())!=FIN) {
      //s->Affiche();
      //automate.getSymbolestack().push(s);
      automate.getStatestack().top()->transition(automate,s);
      //calculer le prochain état et push dans la pile d'etat
      //l.Avancer();
   }
   return 0;
}