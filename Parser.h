#include <map>
#include <memory>

class Expr {
public:
  virtual ~Expr() = default;
};

using UniqueExprPtr = std::unique_ptr<Expr>;

class NumberExpr : public Expr {
  double Value;

public:
  NumberExpr(double Value) : Value(Value) {}
};

class BinaryExpr : public Expr {
  int Opr;
  UniqueExprPtr LHS;
  UniqueExprPtr RHS;

public:
  BinaryExpr(char Opr, UniqueExprPtr LHS, UniqueExprPtr RHS)
      : LHS(std::move(LHS)), RHS(std::move(RHS)), Opr(Opr) {}
};

class Parser {

  std::map<char, int> PrecedenceMap;
  void InitParser();

  UniqueExprPtr ParseNumberExpr();
  UniqueExprPtr ParsePrimary();
  UniqueExprPtr ParseBinOprRHS(int CurrExprWeight, UniqueExprPtr LHS);

  UniqueExprPtr ParseTopLevelExpr(void);
  void HandleTopLevelExpression(void);

public:
  Parser();
  void Parse();
};

/// EOF
