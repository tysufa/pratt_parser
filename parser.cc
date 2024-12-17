#include "parser.hh"
#include "lexer.hh"

int Parser::precedence(Token t){
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

std::string Parser::parsePrefix(){
  std::string res = "";
  if (_curTok.type == TokenType::MINUS){
    res = "(" + _curTok.value;
    nextToken();
    res += prattParser(10) + ")";
    
  } else if (_curTok.type == TokenType::NUMBER){
    res = _curTok.value; 
    nextToken();
  } else if (_curTok.type == TokenType::LPAR){
    int prec = precedence(_curTok);
    nextToken();
    res = prattParser(prec);
    nextToken();
  } else {
    throw(_curTok.type);
  }

  return res;
}

std::string Parser::prattParser(int precedenceLimit){
  std::string left = parsePrefix();

  while (_curTok.type != TokenType::END && _curTok.type != TokenType::ILLEGAL){

    if (!isOperator(_curTok)){
      return left;
    }

    int prec = precedence(_curTok);

    if (prec > precedenceLimit){
      std::string op = _curTok.value;
      nextToken();
      std::string right = prattParser(prec);
      left = "(" + left + op + right + ")";
    } else {
      return left;
    }
  }

  return left;
}

