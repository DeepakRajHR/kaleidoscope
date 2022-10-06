#include <string>

enum Token { tok_eof = -1, tok_number = -5 };

class Tokenizer {
private:
  static int getToken();
  static bool isNumChar(char c);

public:
  Tokenizer() = delete;
  ///static void InitTokenizer(void);
  static int CurrToken;
  static void moveToNextToken();
  static std::string CurrIdStr;
};

/// EOF
