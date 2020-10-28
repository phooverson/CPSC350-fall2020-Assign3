//header file GenStack.h
#include <iostream>
using namespace std;

template <class myType>
class GenStack{
public:
  GenStack(){
    myArray = new myType[128];
    mSize=128;
    top= -1;
  }

  GenStack(int maxSize){
    myArray = new myType[maxSize];
    mSize = maxSize;
    top = -1;
  }

  ~GenStack(){
    delete myArray;
  }

  void push(myType data){
    //check if full before procceding
    if(isFull()){
      resize();
    }
    myArray[++top] = data;
  }

  myType pop(){
    //check if empty before proceeding
    if(isEmpty()){
      return '\0';
    }
    return myArray[top--];
  }

  myType peek(){
    if(isEmpty()){
      return '\0';
    }//check if empty first return'\0'
    return myArray[top];
  }

  bool isFull(){
    return(top==mSize-1);
  }

  bool isEmpty(){
    return (top==-1);
  }

  int getSize(){
    return top+1;
  }

  void resize(){
    mSize = mSize*2;
    myType *newArray = new myType[mSize];

    for(int i = 0; i<sizeof(myArray);i++){
      newArray[i] = myArray[i];
    }
    delete myArray;
    myArray = newArray;

  }

  int top;
  int mSize;

  myType *myArray;
};
