#include "Tokenizer.h"

bool Tokenizer::isNumChar(char c) { return isdigit(c) || c == '.'; }

/*
void Tokenizer::InitTokenizer(void) { CurrToken = getToken(); }
*/
/*
 * Idealy this function should return enum Token. But, to start with, we only
 * support numbers, operators, and whitespaces. We still return the ASCII value
 * for unsupported charaters and it's parser's jobs to detect and raise issues.
 */
int Tokenizer::getToken() {
  static int LastChar = ' ';

  while (isspace(LastChar)) // header
    LastChar = getchar();   // header

  if (isNumChar(LastChar)) {
    std::string NumStr;

    do {
      NumStr += LastChar;
      LastChar = getchar();
    } while (isNumChar(LastChar));

    CurrIdStr = NumStr;
    return tok_number;
  }

  if (LastChar == EOF)
    return tok_eof;

  int AChar = LastChar;
  LastChar = getchar();
  return AChar;
}

void Tokenizer::moveToNextToken()
{
  CurrToken = getToken();
}

/// EOF
