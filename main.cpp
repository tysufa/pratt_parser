#include "parser.hh"
#include <string>

int main(int argc, char *argv[]){
  std::string input = "";

  while (true){
    std::cout << "> ";
    std::getline(std::cin, input);

    Lexer lexer(input);
    Parser parser(lexer);

    std::cout << parser.prattParser(0) << std::endl;;
  }
 

  return 0;
}
