#pragma once
#include "lexer.hh"



class Parser{
public:
  Parser(Lexer const & l):
    _lexer(l){
    _curTok = _lexer.getToken();
    _peekTok = _lexer.getToken();
  };

  void nextToken(){
    _curTok = _peekTok;
    _peekTok = _lexer.getToken();
  }

  std::string parsePrefix();
  std::string prattParser(int precedence);

private:
  Lexer _lexer;
  Token _curTok;
  Token _peekTok;

  int precedence(Token t);
  bool isOperator(Token t) { return !(_curTok.type != TokenType::PLUS && _curTok.type != TokenType::STAR && _curTok.type != TokenType::MINUS && _curTok.type != TokenType::SLASH);};
};


