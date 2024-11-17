%{
#include <iostream>
#include "tokens.h"

using std::cout;
using std::string;

unsigned long lineCount = 0;

%}

%option noyywrap
delim       [ \t\n]
brancos     {delim}+
letra       [A-Za-z]
digito      [0-9]
id          ({letra}|_)({letra}|{digito}|_)*
num         {digito}+(\.{digito}+)?(E[+-]?{digito}+)?
string      \"([^\"\\\n]|\\.)*\"


%%
{brancos}           ;
"main"              return MAIN;
"int"               return TYPE;
"float"             return TYPE;
"bool"              return TYPE;
"true"              return TRUE;
"false"             return FALSE;
"if"                return IF;
"while"             return WHILE;
"do"                return DO;
"&&"                return AND;
"||"                return OR;
"=="                return EQ;
"!="                return NEQ;
">="                return GTE;
"<="                return LTE;
{id}                return ID;
"<"                 return '<';
">"                 return '>';
"="                 return '=';
"+"|"-"|"*"|"/"     return *yytext;
.                   return *yytext;

%%
