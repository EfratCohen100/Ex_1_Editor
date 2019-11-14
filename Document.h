#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Document
{
  public:
  std::vector<string> vec{};
  int numLine;
  int TheLastSearch;
  string TheLastString;
  
  Document();
  void printCurrentLine();  //prints the current line
  void printNumLine(); //prints line number of current line followed by TAB followed by current line
  void printAll(); //prints all lines
  void currentIndexLine(int numOfline); //makes line #number the current line
  void newText(); //appends new text after the current line
  void insert(); //inserts new text before the current line
  void changeText(); //changes the current line for text that follows
  void Delete();//deletes the current line
  void search(string wordSearch);//searches forward after current line for the specified text
  void repeatSearch();//Repeat search
  void searchBackward(string wordSearch);//searches backward
  void replaceOldString(string oldString,string newString);//replaces old string with new in current line
  void Ouit();//Quits the editor without saving
 
};