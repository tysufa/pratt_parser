#include "lexer.hh"

Token Lexer::getToken(){
  if (_curPos > _input.size()){ // not >= because last character is '\0'
    return Token{TokenType::ILLEGAL};
  }
  char curChar = _input[_curPos];
  // on ne veut pas traiter les espaces
  while (curChar == ' '){
    _curPos++;
    curChar = _input[_curPos];
  }

  std::string value = ""; 
  TokenType type;

  switch (curChar){
    case '-':
      type = TokenType::MINUS;
      value = "-";
    break;
    case '+':
      type = TokenType::PLUS;
      value = "+";
    break;
    case '*':
      type = TokenType::STAR;
      value = "*";
    break;
    case '/':
      type = TokenType::SLASH;
      value = "/";
    break;
    case '(':
      type = TokenType::LPAR;
      value = "(";
    break;
    case ')':
      type = TokenType::RPAR;
      value = ")";
    break;
    case '\0':
      type = TokenType::END;
      value = "";
    break;
    default:
      if (isNumber(curChar)){
        type = TokenType::NUMBER;
        value += charToString(curChar);
        while (_curPos+1 < _input.size() && isNumber(_input[_curPos+1])){ 
          _curPos++;
          curChar = _input[_curPos];
          value += charToString(curChar);
        } 
      }
      break;
  }
  _curPos++;
  return Token{type, value};
}

