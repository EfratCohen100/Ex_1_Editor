#include <iostream>
#include <string>
#include <vector>
#include "Editor.h"

using namespace std;
    
 Editor::Editor()
 {
     Document inputDoc;
     loop();
}
  
 void Editor::loop()
 {
    string strInput;
    
    while(1)
    {
         getline(cin,strInput);

         if(strInput=="p")
         {
             cout<<"p"<<endl;
             inputDoc.printCurrentLine();
            
         }

         else if(strInput=="n")
         {
             cout<<"n"<<endl;
             inputDoc.printNumLine();
            // break;
         }
         else if(strInput=="%p")
         {
              cout<<"%p"<<endl;
             inputDoc.printAll();
         }
        
         else if(isdigit(strInput[0])==1 || (isdigit(strInput[0])==1 && isdigit(strInput[1])==1))//#7
         {
            int numOfline;
           numOfline=stoi(strInput);
           cout<<numOfline<<endl;
           inputDoc.currentIndexLine(numOfline);

         }
        
         else if(strInput=="a")
         {
              cout<<"a"<<endl;
             inputDoc.newText();
         }
        
         else if(strInput=="i")
         {
              cout<<"i"<<endl;
             inputDoc.insert();
         }
        
         else if(strInput=="c")
         {
              cout<<"c"<<endl;
             inputDoc.changeText();
         }

          else if(strInput=="d")
         {
             cout<<"d"<<endl;
             inputDoc.Delete();
         }

         else if(strInput=="Q")
         {
             cout<<"Q"<<endl;
             inputDoc.Ouit();
         }

          else if(strInput=="/")
         {
             cout<<"/"<<endl;
             inputDoc.repeatSearch();
         }
        else if(strInput.length()>1 && strInput[0]=='/')
        {
          cout<<"/"<<strInput.substr(1,strInput.length()-1)<<endl;
         inputDoc.search(strInput.substr(1,strInput.length()-1));
        } 
                              
         else if(strInput[0]=='?')
         {
             cout<<"?"<<strInput.substr(1,strInput.length()-1)<<endl;
             inputDoc.searchBackward(strInput.substr(1,strInput.length()-1));
         }
          

          else if(strInput[0]=='s' && strInput[1]=='/')//s/old/new
         {
              string oldString;
              string newString;
            std::vector<std::string> arr;
            arr=split(strInput,"/");
                oldString=arr[1];
                newString=arr[2];

            cout<<"s/"<<oldString<<"/"<<newString<<"/"<<endl;
            inputDoc.replaceOldString(oldString,newString);
         }
            
 }
 };


  