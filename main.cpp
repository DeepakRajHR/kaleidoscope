#include "Parser.h"
#include <fstream>

int main() {

  fprintf(stderr, "expr> ");

  Tokenizer::CurrToken = getToken();
  Parser PInstance;
  PInstance.Parse();

  return 0;
}

/// EOF
