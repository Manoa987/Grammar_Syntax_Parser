# Syntax Parser

LALR(1) automaton for a bottom-up parser using ambiguous grammar :
- E'->E
- E -> E + E
- E -> E * E
- E -> ( E )
- E -> val