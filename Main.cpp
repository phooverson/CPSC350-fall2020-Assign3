#include "assign3.h"

using namespace std;

int main(int argc, char** argv){
  SyntaxChecker *mySyntaxChecker = new SyntaxChecker();

  string line;
  string usersInput;
  string usersFileName;
  int lineCount = 0;
  bool errorFound = false;
  bool hasFileToAnalyze = true;
  bool usersInputIsBad = true;
  bool usersFileInputIsBad = true;
  ifstream myFile;
  usersFileName = argv[1];
  myFile.open(usersFileName);

  while(hasFileToAnalyze){
    usersFileName = "";
    usersInput = "";
    usersInputIsBad = true;
    usersFileInputIsBad = true;
    if(myFile.is_open()){
      while(getline(myFile,line)){
        lineCount++;
        if(!errorFound){
          errorFound = mySyntaxChecker->checkLine(line, lineCount);
        }
        else{
          mySyntaxChecker->printError();
          usersInputIsBad = false;
          errorFound = true;
          break;
        }
      }
      if(mySyntaxChecker->stackNotEmpty()){
        usersInputIsBad = false;
        errorFound = true;
        mySyntaxChecker->printErrorEndOfFile();
      }
    }
    else{
      cout << "Error: File does not exist." << endl;
    }
    myFile.close();
    if(!errorFound){
    while(usersInputIsBad){
        cout << "Delimiter syntax is correct, would you like to analyze anoyther file? (yes or no)" << endl;
        cin >> usersInput;
        if(usersInput == "yes" || usersInput == "no"){
          usersInputIsBad = false;
        }
        else{
          cout << "please enter yes or no." << endl;
        }
      }
    }

    if(usersInput == "yes"){
      cout << "what is the name of the file you would like to analyze?" << endl;
      cin >> usersFileName;
      myFile.open(usersFileName);
    }
    else{
      hasFileToAnalyze = false;
    }
  }

  delete mySyntaxChecker;
  return 0;
}
