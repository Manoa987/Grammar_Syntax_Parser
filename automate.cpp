#include "automate.h"
#include "etat.h"

Automate::Automate(Lexer* lexer)
{ 
    l = lexer;
//    symbolstack = new stack<Symbole*>();
//  statestack = new stack<Etat*>();
    cout<<"init stack E0\r\n"<<endl;
    statestack.push(new E0());    
}

void Automate::decalage(Symbole * s, Etat * e) {
    cout<<"decalage\r\n"<<endl;
    e->print();
    s->Affiche();
    symbolstack.push(s);
    statestack.push(e);
    l->Avancer();
}

void Automate::transitionNonTerminal(Symbole * s, Etat * e) {
    cout<<"transitionNonTerminal\r\n"<<endl;
    e->print();
    s->Affiche();
    symbolstack.push(s);
    statestack.push(e);
}

void Automate::reduction(int n,Symbole * s) {
    cout<<"reduction "<<endl;
    s->Affiche();

    // Vérification que symbolstack a au moins n éléments
    if (symbolstack.size() < n) {
        cerr << "Erreur de réduction : pas assez d'éléments dans symbolstack" << endl;
        return;
    }

    //int nouvelleValeur = 0;
    Symbole** tab = new Symbole*[n];
    Symbole* final;
    for (int i=0;i<n;i++)
    {
        tab[i] = symbolstack.top();
        //delete(symbolstack.top());
        //symbolstack.pop();
        delete(statestack.top());
        statestack.pop();
    }

    for (int i=0;i<n;i++)
    {
        tab[i]->Affiche();
        if (n==1){
            cout<<"cas val"<<endl;
            final = new Entier(tab[0]->getValeur());
            cout<<"-----------"<<endl;
            final->Affiche();
        }else{
            switch (tab[1]->getIdent()){
                case PLUS:
                    final = new Expression(tab[0]->getValeur()+tab[2]->getValeur());
                    cout<<"cas +"<<endl;
                    break;
                case MULT:
                    final = new Expression(tab[0]->getValeur()*tab[2]->getValeur());
                    cout<<"cas *"<<endl;
                    break;
                case EXPR:
                    final = new Expression(tab[1]->getValeur());
                    cout<<"cas (E)"<<endl;
                    break;
            }
        }
    }
    statestack.top()->transition(*this,final);
}