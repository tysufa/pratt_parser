#pragma once
#include "lexer.hh"


int precedence(Token t);

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

  std::string prattParserV1(int precedence);
  
  private:
    Lexer _lexer;
    Token _curTok;
    Token _peekTok;
};


