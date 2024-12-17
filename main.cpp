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

/*std::string pratt(std::vector<Token> tokens){*/
/**/
/*}*/

/*int precedence(Token t){*/
/*  if (t.t == TokenType::PLUS || t.t == TokenType::MINUS){*/
/*    return 2;*/
/*  } else if (t.t == TokenType::STAR || t.t == TokenType::SLASH){*/
/*    return 3;*/
/*  } else if (t.t == TokenType::LPAR || t.t == TokenType::RPAR){*/
/*    return 1;*/
/*  } else{*/
/*    return 0;*/
/*  }*/
/*}*/

/*std::string pratt_parser(int precLimit, std::vector<Token> tokens, int &curTok){*/
/*  std::string left = tokens[curTok].value;*/
/*  Token tok = tokens[curTok];*/
/*  if (tok.t == TokenType::MINUS){*/
/*    curTok++;*/
/*    std::string right = pratt_parser(10, tokens, curTok);*/
/*    left = "(" + left + right + ")";*/
/*  } else if (tok.t == TokenType::LPAR){*/
/*    curTok++;*/
/*    left = pratt_parser(precedence(tok), tokens, curTok);*/
/*    curTok++; // consomme le token ), (on admet que les expressions sont bien parenthésées)*/
/*  } else {*/
/*    curTok++;*/
/*  }*/
/**/
/*  while(curTok < tokens.size()){*/
/*    Token tok = tokens[curTok];*/
/*    if (tok.t != TokenType::PLUS && tok.t != TokenType::MINUS && tok.t != TokenType::STAR && tok.t != TokenType::SLASH){*/
/*      return left;*/
/*    }*/
/*    int prec = precedence(tok);*/
/*    std::cout << prec << " " << precLimit << std::endl;*/
/*    if (prec > precLimit){*/
/*      curTok++;*/
/*      std::string right = pratt_parser(prec, tokens, curTok);*/
/*      left = "(" +left + tok.value + right + ")";*/
/*    } else {*/
/*      return left;*/
/*    }*/
/*  }*/
/*  return left;*/
/*}*/

int main(){
  std::vector<Token> tokens = tokenizer("-(1+2)*2+(-3-5)");
  int curToken = 0;
  Lexer lexer("1 + 2 * 3");
  Parser parser(lexer);

  std::cout << parser.prattParserV1(0) << std::endl;;
  /*std::cout << pratt_parser(0, tokens, curToken) << std::endl;*/

  return 0;
}
