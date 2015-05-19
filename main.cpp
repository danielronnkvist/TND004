/**********************************************
* File: main.cpp                              *
* Author: Aida Nordman                        *
* Course: TND004, Lab 3                       *
* Date: VT2, 2015                             *
* Description: frequency table                *
* DO NOT MODIFY                               *
***********************************************/

#include "threaded_BST.h"
#include "BiIterator.h"

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>

using namespace std;



/*******************************
* 2. Main function             *
********************************/


int main()
{
    MAP table;

    string name;

    /******************************************************
    * PHASE 0: Load the words in the text file            *
    *          into a the table                           *
    *******************************************************/

    cout << "File name? ";
    getline(cin, name);

    ifstream textFile(name);

    if (!textFile)
    {
        cerr << "Text file could not be opened!!" << endl;
        exit(1);
    }

    cout << "Loading the words from " << name << " ...\n";
    string s;
    int count = 0;
    //Read words and load them in the table
    while (textFile >> s)
    {
        //remove non-alphanumeric chars
        s.erase(remove_if(s.begin(), s.end(), ::ispunct), s.end());

        //convert to lower-case letters
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        if (!s.size()) continue; //skip numbers and punctuation signs

        table[s].second++;  //if s is not in the table then it is inserted

        count++;
    }


    /******************************************************
    * PHASE 1: Display                                    *
    * - number of words in the text                       *
    * - number of unique words (occurring only once)      *
    * - frequency table                                   *
    *******************************************************/

    cout << "Number of words in the file: " << count << endl;
    cout << "Number of unique words in the file: " << table.size() << endl;
    
    BiIterator it = table.begin();
    
    cout << "  \tKEY" << "\tCOUNTER" << endl;
    cout << "==============================\n";
    for( ; it != table.end(); it++)
    {
        cout << setw(10) << it->first
        << setw(12) << it->second << endl;
    }

    /******************************************************
    * PHASE 3: remove all words with counter 1            *
    *          and display table again                    *
    *******************************************************/

    string wait;
    getline(cin, wait);

    std::vector<string> ones;
    for(BiIterator it = table.begin(); it != table.end(); ++it)
    {
        if(it->second == 1)
            ones.push_back(it->first);
    }
    
    for(std::vector<string>::iterator it = ones.begin() ; it != ones.end(); ++it)
        table.remove(*it);
    
    cout << "Number of words in the file: " << count << endl;
    cout << "Number of unique words in the file: " << table.size() << endl;
    
    it = table.begin();
    
    cout << "  \tKEY" << "\tCOUNTER" << endl;
    cout << "==============================\n";
    for( ; it != table.end(); it++)
    {
        cout << setw(10) << it->first
        << setw(12) << it->second << endl;
    }

    /***********************************************************
    * PHASE 4: request two words to the user w1 and w2         *
    *          then display all words in the interval [w1,w2]  *
    ************************************************************/

    string word1, word2;
    cout << "Word 1: ";
    cin >> word1;
    cout << "Word 2: ";
    cin >> word2;

    it = table.find(word1);
    BiIterator it2 = table.find(word2);
    if(*it < *it2)
    {
        for(; it->first != word2 || it != table.end(); it++)
            cout << it->first << endl;
        cout << it->first << endl;
    }else{
        cout << "Words are not in order or in the table..." << endl;
    }

    return 0;
}
