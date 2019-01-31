yacc -dv mycalc.y
lex mycalc.l
cc -o mycalc.out y.tab.c lex.yy.c
