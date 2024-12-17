#include <string>
#include <iostream>

enum class TokenType {NUMBER, MINUS, PLUS, STAR, SLASH, LPAR, RPAR, END, ILLEGAL};

struct Token{
  TokenType type;
  std::string value;
  void printTok() {
    switch (type) {
      case TokenType::NUMBER:
        std::cout << "NUMBER : ";
        break;
      case TokenType::MINUS:
        std::cout << "MINUS : ";
        break;
      case TokenType::PLUS:
        std::cout << "PLUS : ";
        break;
      case TokenType::STAR:
        std::cout << "STAR : ";
        break;
      case TokenType::SLASH:
        std::cout << "SLASH : ";
        break;
      case TokenType::LPAR:
        std::cout << "LPAR : ";
        break;
      case TokenType::RPAR:
        std::cout << "RPAR : ";
        break;
      case TokenType::END:
        std::cout << "END : ";
        break;
      case TokenType::ILLEGAL:
        std::cout << "ILLEGAL : ";
        break;
    }
    std::cout << value << std::endl;
  }; 
};

class Lexer{
public:
  Lexer(std::string const & input):
    _input(input){_curPos = 0;}

  Token getToken();
  
private:
  std::string charToString(char c) {return std::string(1, c);};
  bool isNumber(char c){return c >= '0' && c <= '9';};

  std::string _input;
  int _curPos;
};
