bison -d parse_ljx_mogai.y
flex lexical_ljx.l
gcc parse_ljx_mogai.tab.c -lfl -ly -o parser