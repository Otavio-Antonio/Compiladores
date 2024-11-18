#ifndef COMPILER_LEXER
#define COMPILER_LEXER

#include <unordered_map>
#include <string>
#include <sstream>
#include "tokens.h"
#include <FlexLexer.h>
using std::stringstream;
using std::unordered_map;
using std::string;

// classe para representar tokens
struct Token
{	
	int tag;
	string lexeme;

	Token() : tag(0) {}
	Token(char ch) : tag(int(ch)), lexeme({ch}) {}
	Token(int t, string s) : tag(t), lexeme(s) {}
};

// analisador léxico
class Lexer
{
private:
	yyFlexLexer scanner;
	int token_id;

	char peek;			// último caractere lido
	Token token;		// último token retornado
	int yylineno;		// número da linha atual

	// tabela para identificadores e palavras-chave
	unordered_map<string, Token> token_table;

public:
	Lexer();			// construtor
	int Lineno();		// retorna linha atual
	Token * Scan();		// retorna próximo token da entrada
};

#endif
