#include "parser.hh"
#include "lexer.hh"

int precedence(Token t){
  if (t.type == TokenType::PLUS || t.type == TokenType::MINUS){
    return 2;
  } else if (t.type == TokenType::STAR || t.type == TokenType::SLASH){
    return 3;
  } else if (t.type == TokenType::LPAR || t.type == TokenType::RPAR){
    return 1;
  } else{
    return 0;
  }
}


std::string Parser::prattParserV1(int precedenceLimit){
  std::string left = _curTok.value;
  nextToken();

  while (_curTok.type != TokenType::END && _curTok.type != TokenType::ILLEGAL){
    if (_curTok.type != TokenType::PLUS && _curTok.type != TokenType::STAR && _curTok.type != TokenType::MINUS && _curTok.type != TokenType::SLASH){
      return left;
    }

    int prec = precedence(_curTok);

    if (prec > precedenceLimit){
      std::string op = _curTok.value;
      nextToken();
      std::string right = prattParserV1(prec);
      left = "(" + left + op + right + ")";
    } else {
      return left;
    }
    
  }

  return left;
}

