#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

class Line
{
public:
    string word_a, word_b, word_a_sorted, word_b_sorted;


Line(string l)
{
    string word;
    stringstream ss_line(l);
    bool first = 1;

    while(getline(ss_line, word, ' '))
    {
        if(first)
        {
            word_a = word;
            first = 0;
        }
        else
            word_b = word;
    }

    word_a_sorted = word_a;
    word_b_sorted = word_b;
    sort(word_a_sorted.begin(), word_a_sorted.end());
    sort(word_b_sorted.begin(), word_b_sorted.end());
}

bool check_if_anagram()
{
    return (word_a_sorted == word_b_sorted);
}

};

int main()
{
    string line;
    fstream file;
    int answer_a = 0, answer_b = 0;
    vector<string> words_sorted;

    file.open("dane_anagramy.txt", ios::in);
    while(getline(file, line))
    {
        Line anagram(line);

        if(anagram.check_if_anagram())
            answer_a++;


        words_sorted.push_back(anagram.word_a_sorted);
        words_sorted.push_back(anagram.word_b_sorted);
    }
    file.close();
    cout << "A.\nLiczba wierszy z anagramami: " << answer_a << endl;

    for (string w : words_sorted)
    {
        int freq = 0;

        for ( string a : words_sorted)
        {
            if (w == a)
                freq++;
        }
        if (freq > answer_b)
            answer_b = freq;
    }
    cout << "B.\nMaksymalna liczba anagramow: " << answer_b << endl;
    return 0;
}
