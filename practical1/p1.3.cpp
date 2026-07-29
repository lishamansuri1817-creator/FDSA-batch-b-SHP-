#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str, word, longest;
    cout<<"Enter string:";
    getline(cin, str);
    str = str + " ";
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] != ' ')
        {
            word = word + str[i];
        }
        else{
            if(word.length() > longest.length())
                longest = word;
                word = "";
        }
    }
    cout <<"The winning word is ===  "<< longest<<"  ===  " << endl;
    cout <<"With total letters " <<longest.length();
    return 0;
}
