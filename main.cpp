#include <string>
#include <vector>
#include "parser.hh"



std::vector<Token> tokenizer(std::string s){
  std::vector<Token> res;
  for (int i = 0; i < s.length(); i++){
    if (s[i] >= '0' && s[i] <= '9'){
      std::string number(1, s[i]);
      while (i+1 < s.length() && s[i+1] >= '0' && s[i+1] <= '9'){
        number += s[i+1];
        i++;
      }
      res.push_back(Token{TokenType::NUMBER, number});
    }
    else if (s[i] == '+')
      res.push_back(Token{TokenType::PLUS, std::string(1, s[i])});
    else if (s[i] == '-')
      res.push_back(Token{TokenType::MINUS, std::string(1, s[i])});
    else if (s[i] == '*')
      res.push_back(Token{TokenType::STAR, std::string(1, s[i])});
    else if (s[i] == '/')
      res.push_back(Token{TokenType::SLASH, std::string(1, s[i])});
    else if (s[i] == '(')
      res.push_back(Token{TokenType::LPAR, std::string(1, s[i])});
    else if (s[i] == ')')
      res.push_back(Token{TokenType::RPAR, std::string(1, s[i])});
  }

  return res;
}


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

std::string pratt_parser(int precLimit, std::vector<Token> tokens, int &curTok){
  std::string left = tokens[curTok].value;
  Token tok = tokens[curTok];
  if (tok.type == TokenType::MINUS){
    curTok++;
    std::string right = pratt_parser(10, tokens, curTok);
    left = "(" + left + right + ")";
  } else if (tok.type == TokenType::LPAR){
    curTok++;
    left = pratt_parser(precedence(tok), tokens, curTok);
    curTok++; // consomme le token ), (on admet que les expressions sont bien parenthésées)
  } else {
    curTok++;
  }

  while(curTok < tokens.size()){
    Token tok = tokens[curTok];
    if (tok.type != TokenType::PLUS && tok.type != TokenType::MINUS && tok.type != TokenType::STAR && tok.type != TokenType::SLASH){
      return left;
    }
    int prec = precedence(tok);

    if (prec > precLimit){
      curTok++;
      std::string right = pratt_parser(prec, tokens, curTok);
      left = "(" +left + tok.value + right + ")";
    } else {
      return left;
    }
  }
  return left;
}

int main(){
  std::vector<Token> tokens = tokenizer("(-1+2)*3");
  int curToken = 0;
  Lexer lexer("*(-1+2)*(3-4)/5");
  Parser parser(lexer);

  std::cout << parser.prattParser(0) << std::endl;;
  /*std::cout << pratt_parser(0, tokens, curToken) << std::endl;*/

  return 0;
}
