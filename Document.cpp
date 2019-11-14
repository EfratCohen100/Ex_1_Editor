#include<iostream>
#include<string>
#include<vector>
#include "Document.h"

using namespace std;

Document::Document()
{
     vector<string>vec;
     numLine=-1;
     TheLastSearch=0;
}
 
    //function of command: p
    void Document::printCurrentLine()
    {
      if(vec.empty())
      {
        cout << "?" << endl;
      }
      else
            cout << vec[numLine] << endl;
      
    }

    // function of command: n
    void Document::printNumLine()
    {
        if(numLine!=-1)
        {
            cout << numLine+1 << '\t' << vec[numLine]<< endl;
        }
        else if(numLine==-1 || numLine>vec.size())
        {
          cout <<"?"<<endl;
        }
    }
    
    // function of command %p: 
    void Document::printAll()
    {
          if(vec.empty())
          {
          cout <<"?"<< endl;
          }
          else
          {
            for(int j=0; j<vec.size(); j++)
            {
               cout  << vec[j] <<endl;
            }
          }
    }
      
    // function of command 7: 
     void Document::currentIndexLine(int numOfline)
     {
        if(numOfline>vec.size() || numOfline<1)
         {
           cout<<"?" << endl;
         }
         else{
           numLine=numOfline-1;
           cout << vec[numLine] << endl;
         }
        
     }
     
    // function of command a: 
    void Document::newText()
    {      
      string inputWord="";
      while(getline(cin,inputWord) && inputWord!=".")
      {
                cout<<inputWord<<endl;
           
          vec.insert(vec.begin()+2+numLine-1,inputWord);
        
                  numLine++;
        } 
        cout<<"."<<endl;
    
    } 
    // function of command i: 
    void Document::insert()
    {
       string newInput="";
       while(getline(cin,newInput) && newInput!=".")
       {
       vec.insert(vec.begin()+numLine,newInput);
       cout<<newInput<<endl;
      if(numLine!=0)
      {
       numLine--;

      }
     
    }  
          cout<<"."<<endl;
 
   }

    // function of command c: 
    void Document::changeText()
    {
        string newInput="";
       
      while(getline(cin,newInput),newInput!=".") 
      {
        cout<<newInput<<endl;
          vec[numLine]=newInput;
      }
              cout<<"."<<endl;

     
    }
    // function of command d: 
    void Document::Delete()
    {
      if(vec.empty())
      {
        cout << "?" << endl;
      }
      else
        vec.erase(vec.begin()+numLine);
    }

     // function of command /text: 
    void Document::search(string wordSearch)
    {
      for (int i =0; i<=vec.size(); i++){
      bool ans = 0;
      string str = vec[i];
        if (str.find(wordSearch) != std::string::npos) 
        {
          ans = 1;
          numLine=i;
          TheLastSearch=i;
          TheLastString=wordSearch;
          printCurrentLine();
          break;
        }      
       if (ans == 0 && i == vec.size())
       {
           cout<<"?"<<endl;
       }
}
    }
    // function of command '/': 
    void Document::repeatSearch()
   {
     int idx=0;
     bool ans=0;
     if(TheLastSearch>vec.size())
     {
       cout<<"?"<<endl;
     }
     if(TheLastSearch!=vec.size()-1)
     {
       idx=TheLastSearch+1;
     }
        
     for(idx=TheLastSearch+1;idx<vec.size();idx++)
     {
       string s=vec[idx];
       if(s.find(TheLastString)!=string::npos)
       {
        cout<<vec[idx]<<endl;
        ans=1;
        numLine=idx;
        TheLastSearch=idx;
        break;
     
       }
       
     else 
     {
       cout<<vec[TheLastSearch]<<endl; 
      numLine=TheLastSearch;
 
     }
   }
   }
     // function of command ?text: 
    void Document::searchBackward(string wordSearch)
    {
       bool ans = 0;
       int i=0;
      for (i =vec.size()-1;i>=0; i--)
      {
      string str = vec[i];
        if (str.find(wordSearch) != std::string::npos) 
        {
          ans = 1;
          numLine=i;
          TheLastSearch=i;
          TheLastString=wordSearch;
          printCurrentLine();
          break;
        } 

      ans=0;   
     }
      if (ans == 0 && i == vec.size()-1)
       {
               cout<<"?"<<wordSearch<<"\n"<<"?"<<endl;

       }  
    }
    
     // function of command s//old/new/: 
    void Document::replaceOldString(string oldString,string newString)
    {
        if(vec.empty())
        {
          cout<<"?"<<endl;
        } 
            string myPlace=vec[numLine];
            int pos = (myPlace.find(oldString));
            if(myPlace.find(oldString) !=string::npos){
            myPlace.replace(pos,oldString.length(),newString);
            vec[numLine]=myPlace;
            
            }  
            else
          {
            cout<<"?"<< endl;
          }
          
        } 

    
     // function of command Q: 
    void Document::Ouit()
    {
        exit(0);
    }

 
