#include "assign3.h"



//default Constructor
SyntaxChecker::SyntaxChecker(){
  isDelimiterGood = true;
  lineNumber = 0;
}

//default destructor
SyntaxChecker::~SyntaxChecker(){
 //cout << "bye SyntaxChecker" << endl;
}

//checks the line for delimeters and sends the Delimiter to the appropriate place
bool SyntaxChecker::checkLine(string line, int lineCount){
  lineNumber = lineCount;
  for(int i = 0; i < line.length(); ++i){
    currentDelimiter = line.at(i);
    if (isDelimiter()){
      checkDelimiter();
      if(myStack->isEmpty()){
        if(currentDelimiter == ')' || currentDelimiter == '}' || currentDelimiter == ']'){
          cout << "Line " << lineNumber << ": Found " << currentDelimiter << " before an opening delimeter." << endl;
          return true;
        }
      }

      if(!isDelimiterGood){
        return true;
      }
    }
  }
  return false;
}

//prints the error out to the user
void SyntaxChecker::printError(){
  if(checkChar == '(')
    cout << "Line " << lineNumber << ": Expected )" << " and found " << currentDelimiter << endl;
  else if(checkChar == '{')
    cout << "Line " << lineNumber << ": Expected }" << " and found " << currentDelimiter << endl;
  else if(checkChar == '[')
    cout << "Line " << lineNumber << ": Expected ]" << " and found " << currentDelimiter << endl;
}

//checks if the char is a Delimiter
bool SyntaxChecker::isDelimiter(){
  if(currentDelimiter == '{' || currentDelimiter == '}' || currentDelimiter == '[' || currentDelimiter == ']' || currentDelimiter == '(' || currentDelimiter == ')')
    return true;
  return false;
}

//checks if the delimiter is an opening or a cloasing delimiter and sends it to the appropriate place
void SyntaxChecker::checkDelimiter(){
  if(currentDelimiter == '{' || currentDelimiter == '[' || currentDelimiter == '(')
    addDelimiterToStack();
  else if(currentDelimiter == '}' || currentDelimiter == ']' || currentDelimiter == ')'){
    //will try to pop when nothing is added to stack yet
    if(!myStack->isEmpty()){
      checkIfDelimiterHasOpen();
    }
  }
}

//adds the delimiter to the stack
void SyntaxChecker::addDelimiterToStack(){
  checkStackSize();
  myStack->push(currentDelimiter);
}

//checks if the closing delimiter has opening delimiter
void SyntaxChecker::checkIfDelimiterHasOpen(){
  checkChar = myStack->pop();
  if(currentDelimiter == ')'){
    if(checkChar != '('){
      isDelimiterGood = false;
    }
  }
  else if (currentDelimiter == '}'){
    if(checkChar != '{'){
      isDelimiterGood = false;
    }
  }
  else if (currentDelimiter == ']'){
    if(checkChar != '['){
      isDelimiterGood = false;
    }
  }
}

//checks the stack size and resizes if the stack is full
void SyntaxChecker::checkStackSize(){
  if(myStack->isFull()){
    myStack->resize();
  }
}

//checs if the stack is empty
bool SyntaxChecker::stackNotEmpty(){
  if(myStack->isEmpty())
    return false;
  return true;
}

//prints the error that the program reached the end of the file
void SyntaxChecker::printErrorEndOfFile(){
  checkChar = myStack->pop();
  if(checkChar == '(')
    cout << "Reached end of file: missing )" << endl;
  else if(checkChar == '{')
    cout << "Reached end of file: missing }" << endl;
  else if(checkChar == '[')
    cout << "Reached end of file: missing ]" << endl;
}
