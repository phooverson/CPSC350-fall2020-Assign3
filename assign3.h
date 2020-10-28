#include <iostream>
#include <fstream>
#include "GenStack.h"

using namespace std;

class SyntaxChecker{
public:
  SyntaxChecker();
  ~SyntaxChecker();

  void checkSyntax();
  bool checkLine(string line, int lineCount);
  void printError();
  bool stackNotEmpty();
  void printErrorEndOfFile();
private:
  char currentDelimiter;
  char checkChar;
  int lineNumber;
  bool isDelimiterGood;
  ifstream myFile;
  GenStack <char>*myStack = new GenStack<char>(10);

  bool isDelimiter();
  void checkDelimiter();
  void addDelimiterToStack();
  void checkIfDelimiterHasOpen();
  void checkStackSize();
protected:
};
