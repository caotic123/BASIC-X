// Basic X é uma linguagem de script escrita em C
// basic_x trabalha com variaveis com apenas duas constantes com valores 1(adiciona) ou 0(diminui) embora possa representar qualquer numero diretamente com casas que sejam de 1 ou 0 (ou seja 0, 1, 10, 11, 100, 111, 1000 etc...)
// basic_x trabalha com qualquer valor inteiro, embora não possa representa esses valores diretamente no script
// a unica variavel é x com n dimensões, x é estado
// estrutura de repetição e condicional são as unicas estruturas logicas completas
// todo restante logico deve ser construido com regras
// regras são as explorações e construção de operadores logicos, funções e tipos
// basic_x é uma linguagem procedural orientada em regras logicas

//Some scripts...
//Operador (*) de multiplicaçao https://pastebin.com/nHifv0Kp
//Declaring Variable https://pastebin.com/gWpxJPWm
//Fibonacci https://pastebin.com/YjusmEqs
//Multiplos de 3 https://pastebin.com/wK7tXin2

//Insira o codigo no INPUT caso ira apenas testar

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int find_char(char* str, char* str_, int r)
{
    bool t;
    int y = 0;
    int s = 0;
    for (int i = 0; i <= strlen(str); i++) {
        if (t && str[i] == str_[y]) {
            t = true;
            y++;
        }
        else {
            t = false;
            y = 0;
        }

        if (!t && (char)str[i] == (char)str_[0]) {
            t = true;
            y = y + 1;
        }

        if (y == strlen(str_)) {
            if (s >= r) {
                return i + 1;
            }
            s++;
            t = false;
            y = 0;
        }
    }

    return 0;
}

bool findStr(char* str, char* x)
{
    bool y = true;
    for (int i = 0; i <= strlen(x) - 1; i++) {
        if (str[i] != x[i]) {
            y = false;
        }
    }

    return y;
}

bool equalStr(char* str, char* x)
{
    return strcmp(str, x) != 0 ? false : true;
}

typedef struct {
    int* i;
    char** basic_struct;
    char** r_;
    int _r_;
    int r_r;
    int** p_;
    int _p;
    bool r__;
    int y;
    bool aloc_bool;
    int aloc;
    int index;
    int c_;
    int _;
    int __;
    int lp;
} x_;

char* c(char* y, int t, int a)
{
    int i = 0;
    char* str = malloc(sizeof(char) * (a - t) + 1);
    for (t; t <= a; t++) {
        str[i] = y[t];
        i++;
    }

    return str;
}

int _basic_int(char* y)
{
    int n;
    int s = 0;
    int buf;
    int _ = 1;
    int len = strlen(y);
    for (int i = 0; i <= strlen(y) - 1; i++) {
        if (y[i] == '>') {
            buf = find_char(c(y, 0, strlen(y) - 1), ">", _) == 0 ? strlen(y) - 1 : find_char(c(y, 0, strlen(y) - 1), ">", _) - 2;

            if (atoi(c(y, i + 1, buf)) == 0) {
                s = s - 1;
            }
            else {
                s = s + atoi(c(y, i + 1, buf));
            }

            _++;
        }
    }

    return s;
}

int get_x_c (char* l) {
  int x = 0;
  while(find_char(l, ">x", x) != 0) {
    x++;
  }

  return x;
}

void basic_x_command(x_* x, char* script, int y)
{

    if (x->c_ >= 1 && findStr(script, "[")) {
        x->c_++;
        return;
    }

    if (x->c_ > 0 && findStr(script, "]")) {
        x->c_ = x->c_ - 1;
        return;
    }

    if (x->c_ >= 1) {
        return;
    }

    if (findStr(script, "x~")) {
        int memory = _basic_int(c(script, 2, strlen(script) - 1));
        x->aloc_bool = true;
        x->aloc = memory;
        x->i = malloc(sizeof(int) * memory);
        return;
    }


    if (findStr(script, "x>>")) { //movimentação de index

        if ((findStr(script, "x>>0"))) {
            x->index = x->index - 1;
            return;
        }
  
        if (findStr(script, "x>>x<")) {
         int x__ = get_x_c(script);
         int s=0;
         for(int i=0; x__ >= i; i++) {
           s += x->i[x->index - (i+1)];
         }
         x->i[x->index] = s;
        }

        if ((equalStr(script, "x>>x>x"))) { // add past variables
            x->i[x->index + 1] = x->i[x->index + 1] + x->i[x->index];
            x->index++;
            return;
        }

        if (findStr(script, "x>>x")) {
            if (!findStr(script, "x>>x>")) {
                x->i[x->index + 1] = x->i[x->index];
                x->index = x->index + 1;
                return;
            }

            x->i[x->index + 1] = x->i[x->index] + x->index + _basic_int(c(script, 4, strlen(script) - 1));
            x->index++;
            return;
        }

        x->index = x->index + _basic_int(c(script, 2, strlen(script) - 1));

        return;
    } //fim de movimentação

    if ((equalStr(script, "<<x"))) { // index back to 0
        x->index = 0;
        return;
    }

    if (findStr(script, "x-")) { // comparasion of value of x index
        if (x->i[x->index] == atoi(c(script, 2, find_char(script, "[", 0) - 1))) {
            return;
        }

        x->c_++;
    }

    if (findStr(script, "x>")) {
        x->i[x->index] = x->i[x->index] + _basic_int(c(script, 1, strlen(script) - 1));
        return;
    }

    if (equalStr(script, "x<<")) {
        printf("%d\n", x->i[x->index]);
        return;
    }

    if (findStr(script, "{")) {
        if (equalStr(script, "{x")) {
            x->lp = x->i[x->index];
            x->_ = y;
            return;
        }

        x->lp = atoi(c(script, 1, strlen(script)));
        x->_ = y;
        return;
    }

    if (findStr(script, "}")) {
        x->__ = y;
        return;
    }

    if (findStr(script, "x<>x")) {
        scanf("%d", &x->i[x->index]);
        return;
    }

    if (findStr(script, "x ")) {
        _c_role(x, rol(x, c(script, 2, strlen(script) - 1)));
        return;
    }
}

void r_(x_* x)
{
    for (int i = x->_p; x->y >= i; i++) {

        if (x->__ != 0) {
            for (int i_ = 1; x->lp > i_; i_++) {
                for (int i__ = x->_ + 1; x->__ - 1 >= i__; i__++) {
                    basic_x_command(x, x->basic_struct[i__], i__);
                }
            }
            x->lp, x->_, x->__ = 0;
        }

        basic_x_command(x, x->basic_struct[i], i);
    }
}

void r__(x_* x, int p)
{
    for (int i = x->p_[p][0]; x->p_[p][1] >= i; i++) {
        if (x->__ != 0) {
            for (int i_ = 1; x->lp > i_; i_++) {
                for (int i__ = x->_ + 1; x->__ - 1 >= i__; i__++) {
                    basic_x_command(x, x->basic_struct[i__], i__);
                }
            }
            x->lp, x->_, x->__ = 0;
        }

        basic_x_command(x, x->basic_struct[i], i);
    }
}

void _c_role(x_* x, int p)
{
    r__(x, p);
    return;
}

int rol(x_* x, char* s)
{
    for (int y = 0; x->_r_ >= y; y++) {
        if (strcmp(x->r_[y], s) == 0) {
            return y;
        }
    }
    return NULL;
}

void add_(x_* x, char* line)
{

    if (findStr(line, "()")) {

        x->_p = x->y + 1;
    }

    if (x->_p == 0 && find_char(line, "(", 0) && !x->r__) {
        x->r_[x->_r_] = malloc(sizeof(char*) * (strlen(line) + 1));

        strcpy(x->r_[x->_r_], c(line, 0, find_char(line, "(", 0) - 2));

        x->p_[x->_r_] = malloc(sizeof(int) * 3);
        x->p_[x->_r_][0] = x->y + 1;
        x->r__ = true;
    }

    if (x->_p == 0 && findStr(line, ")") && x->r__) {
        x->p_[x->_r_][1] = x->y - 1;
        x->r__ = false;
        x->_r_++;
    }

    x->basic_struct[x->y] = malloc(sizeof(char) * (strlen(line) + 1));
    strcpy(x->basic_struct[x->y], line);
    x->y++;
}

void basic_x_read(x_* x, char* script)
{

    x->basic_struct = malloc(sizeof(char*) * 1000);
    x->r_ = malloc(sizeof(char**) * 1000);

    x->p_ = malloc(sizeof(int**) * 1000);

    x->y = 0;
    x->_r_ = 0;
    x->r__ = false;
    x->_p = 0;

    char* r;
    r = strtok(script, "\n");
    while (r != NULL) {
        add_(x, r);
        r = strtok(NULL, "\n");
    }

    r_(x);
}

int main()
{
    char buffer[1000];
    x_* basic_x = malloc(2 * sizeof(x_));
    read(STDIN_FILENO, buffer, 1000);
    basic_x_read(basic_x, buffer);

    return 1;
}
