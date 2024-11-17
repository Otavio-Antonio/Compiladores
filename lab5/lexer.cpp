#include "lexer.h"
#include "tokens.h"
#include <fstream>
#include <sstream>
using namespace std;
using std::stringstream;
extern std::ifstream fin;

int yylineno; // Linha atual do analisador léxico

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
	
	// inicia leitura da entrada
	//peek = fin.get();

}

// retorna número da linha atual
int Lexer::Lineno()
{	
	return line;
}
// retorna tokens para o analisador sintático
Token* Lexer::Scan()
{    
	scanner.switch_streams(&fin);  // altera entrada para arquivo
    
	token_id = scanner.yylex();
	string lexema_atual = scanner.YYText();

    if (token_id == 0){ // EOF
		
        token =  Token{EOF};
		cout << token.tag<<"--------"<<token.lexeme<< endl;
		return &token;
	}

    token = Token{token_id, lexema_atual}; // Cria o Token com base no token_id e lexema
	cout<<token.tag<<" ------ "<<token.lexeme<<endl;

    return &token;
}