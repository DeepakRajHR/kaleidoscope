#include <iostream>
#include <cstdlib>

#include "Parser.h"
#include "Tokenizer.h"

Parser::Parser() {
  /// Tokenizer::InitTokenizer();
  InitParser();
}

void Parser::InitParser(void) {
  PrecedenceMap['+'] = 20;
  PrecedenceMap['-'] = 20;
  PrecedenceMap['*'] = 30;
}

UniqueExprPtr Parser::ParseNumberExpr() {
  auto NumExpr = std::make_unique<NumberExpr>(
      NumberExpr(strtod(Tokenizer::CurrIdStr.c_str(), nullptr)));
  Tokenizer::moveToNextToken();
  return NumExpr;
}

UniqueExprPtr Parser::ParsePrimary() {
  switch (Tokenizer::CurrToken) {
  default:
    std::cout << "unknown token; expecting an expression!";
    return nullptr;
  case tok_number:
    return ParseNumberExpr();
  }
}

UniqueExprPtr Parser::ParseBinOprRHS(int CurrExprWeight, UniqueExprPtr LHS) {

  while (true) {
    /// Implement operator precedence here
    break;
  }
  return nullptr;
}

UniqueExprPtr Parser::ParseTopLevelExpr(void) {
  auto LHS = ParsePrimary();
  if (!LHS)
    return nullptr;

  return ParseBinOprRHS(0, std::move(LHS));
}

void Parser::HandleTopLevelExpression(void) { ParseTopLevelExpr(); }

void Parser::Parse(void) {
  while (true) {
    fprintf(stderr, "expr> ");

    switch (Tokenizer::CurrToken) {
    case tok_eof:
      return;

    default:
      HandleTopLevelExpression();
      break;
    }
  }
}

/// EOF
