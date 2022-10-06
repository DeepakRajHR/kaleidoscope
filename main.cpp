#include <fstream>

#include "Tokenizer.h"
#include "Parser.h"

std::string Tokenizer::CurrIdStr = "0";
int Tokenizer::CurrToken = 0;

int main() {

  fprintf(stderr, "expr> ");

  Parser PInstance;
  PInstance.Parse();

  return 0;
}

/// EOF
