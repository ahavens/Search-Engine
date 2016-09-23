#include "docobject.h"

DocObject::DocObject(string text, int p)
{
    textToClean = text;
    pageNum = p;
}

void DocObject::setPageNum(int p)
{
    pageNum = p;
}

int DocObject::getPageNum()
{
    return pageNum;
}

void DocObject::addToStrings(string s)
{
    myDoc.push_back(s);
}

//this pushes words onto the vector
void DocObject::cleanStrings()
{
    //take the text and parse it
    string temp = "";
    string buffString = "";
    const char* buffer;
    if(textToClean == "")
        cout << "empty" << endl;
    if(textToClean != "")
    {
        stringstream s(textToClean);
        cout << "after assigning text to clean" << endl;

        while(s >> temp)
        {
            //clean the string and restore it
            temp = bleachString(temp);


            //I have seen words come in where they are web addresses; I don't find these to be necessary,
            //so the buff is meant to take care of that

            //I want to see the first four characters
            if(temp.length() >= 4)
            {
                buffer = temp.c_str();
                for(int i = 0; i < 4; i++)
                {
                    buffString += buffer[i];
                }
            }
            //here we check to see what the words are and whether they should be put on the vector
            //if temp is an empty string do nothing
            if(temp == " ")
            {

            }

            else if(buffString == "http")
            {

            }
            else
            {
                //if none of the words match, then we add it onto the vector
                myDoc.push_back(temp);
            }
        }
    }
    cout << "end of string clean" << endl;

}

//function returns an actual cleaned string, minus all the weird little non ascii characters
string DocObject::bleachString(string s)
{
    //create a buffer to go through the string
    const char* buffer = s.c_str();
    string tempString = "";
    int i = 0;

    while(i < s.length())
    {
        if(buffer[i] >= 65 && buffer[i] <= 90)
        {
            //add onto the string
            tempString += buffer[i];
        }
        else if(buffer[i] >= 97 && buffer[i] <= 122)
        {
            //add onto the string
            tempString += buffer[i];
        }
        //for some reason, non ascii characters have this in them and so we have to account for it
        else if(buffer[i] == '&')
        {
            //parse the buffer until we reach the semicolon or the end (if we go past the end, we cause a seg fault)
            while(buffer[i] != ';' && i <= s.length())
            {
                i++;
            }
        }
        i++;
    }

    //once we have cleaned the string then we return it
    return tempString;

}

void DocObject::returnFirstString()
{
    cout << myDoc[0] << endl;
}
