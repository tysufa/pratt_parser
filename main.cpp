#include "parser.hh"

int main(){
  Lexer lexer("(-1+2)*(3-4)/5");
  Parser parser(lexer);

  std::cout << parser.prattParser(0) << std::endl;;

  return 0;
}
