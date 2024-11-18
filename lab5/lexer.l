%{
#include <iostream>
#include "tokens.h"

using std::cout;
using std::string;

%}

%option noyywrap
%option yylineno
delim       [ \t\n]
brancos     {delim}+
letra       [A-Za-z]
digito      [0-9]
integer     {digito}+
id          ({letra})({letra}|{digito})*
floating    {digito}+(\.{digito}+)?(E[+-]?{digito}+)?


%%
{brancos}           ;
{id}                return Tag::ID;
{integer}           return Tag::INTEGER;
{floating}          return Tag::FLOATING;
"&&"                return Tag::AND;
"||"                return Tag::OR;
"=="                return Tag::EQ;
"!="                return Tag::NEQ;
">="                return Tag::GTE;
"<="                return Tag::LTE;
.                   return Tag::CHAR;

%%
