#include "lexer.h"
#include "tokens.h"
#include <fstream>
#include <sstream>
using namespace std;
using std::stringstream;
extern std::ifstream fin;

// construtor 
Lexer::Lexer()
{
	// insere palavras-reservadas na tabela
	token_table["main"]  = Token{ Tag::MAIN, "main" };
	token_table["int"]   = Token{ Tag::TYPE, "int" };
	token_table["float"] = Token{ Tag::TYPE, "float" };
	token_table["bool"] = Token{ Tag::TYPE, "bool" };
	token_table["true"]  = Token{ Tag::TRUE, "true" };
	token_table["false"] = Token{ Tag::FALSE, "false" };
	token_table["if"]    = Token{ Tag::IF,    "if" };
	token_table["while"] = Token{ Tag::WHILE, "while" };
	token_table["do"]    = Token{ Tag::DO,    "do" };
	
	// altera entrada para arquivo
	scanner.switch_streams(&fin);  

}

// retorna número da linha atual
int Lexer::Lineno()
{	
	//cout<<"linha atual"<<scanner.lineno();
	return scanner.lineno();
}
// retorna tokens para o analisador sintático
Token* Lexer::Scan()
{    
	const int token_id = scanner.yylex();
	const char *lexema_atual = scanner.YYText();

	switch (token_id)
	{
		case ID: {
			auto pos = token_table.find(lexema_atual);

			if (pos != token_table.end()) {
				token = pos->second; // Retorna o token existente
			}else{
				Token t {Tag::ID, lexema_atual}; // Cria novo token
				token_table[lexema_atual] = t;  // Adiciona à tabela de símbolos
				token = t; // Retorna o novo token
			}
			
    	}
		break;
	case 0:
		token =  Token{EOF};
		break;

	case INTEGER:
		token = Token{Tag::INTEGER, lexema_atual};
		break;
	case FLOATING:
		token = Token{Tag::FLOATING, lexema_atual};
		break;
	case AND:
		token = Token{Tag::AND, lexema_atual};
		break;
	case OR:
		token = Token{Tag::OR, lexema_atual};
		break;
	case EQ:
		token = Token{Tag::EQ, lexema_atual};
		break;
	case NEQ:
		token = Token{Tag::NEQ, lexema_atual};
		break;
	case GTE:
		token = Token{Tag::GTE, lexema_atual};
		break;
	case LTE:
		token = Token{Tag::LTE, lexema_atual};
		break;
	default:
		token = Token{*lexema_atual};
		break;
	}
	return &token;
}