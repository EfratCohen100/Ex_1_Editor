#include "Document.h"
#include <string>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

class Editor{
    
    private:
        Document inputDoc;
    
    public:
        Editor();
        void loop();
        std::vector<std::string>split(std::string str,std::string sep)
        {
                    char* cstr=const_cast<char*>(str.c_str());
                    char* current;
                    std::vector<std::string> arr;
                    current=strtok(cstr,sep.c_str());
                    while(current!=NULL)
                    {
                        arr.push_back(current);
                        current=strtok(NULL,sep.c_str());
                    }
                    return arr;
        }
};
