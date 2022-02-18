flex essay.l
bison -d projetc.y 
gcc lex.yy.c projetc.tab.c -o compile.exe
compile.exe<essay.txt
compile.exe<essay2.txt
