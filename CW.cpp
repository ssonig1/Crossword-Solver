#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
void printC(vector<string> crossword)
{
    for (int i = 0; i < 10; i++)
    {
        cout << crossword[i] << endl;
    }
}
bool checkH(vector<string> crossword, string word, int i, int j)
{
    int a = 0; // for checking index of string
    int b = 0; // for checking length that filled
    int n = word.length();
    if ((j - 1) >= 0)
    {
        if (crossword[i][j - 1] != '+')
        {
            if (crossword[i][j - 1] == word[0])
            {
                a = 1;
                b = 1;
            }
            else if (crossword[i][j - 1] != word[0])
                return false;
        }
    }

    for (; j < 10 && a < n; j++, a++)
    {
        if (crossword[i][j] == '-')
            b++;
        else if (crossword[i][j] == word[a])
            b++;
    }
    if (b == n)
        return true;

    return false;
}
bool checkV(vector<string> crossword, string word, int i, int j)
{
    int a = 0;
    int b = 0;
    int n = word.length();
    if ((i - 1) >= 0)
    {
        if (crossword[i - 1][j] != '+')
        {
            if (crossword[i - 1][j] == word[0])
            {
                a = 1;
                b = 1;
            }
            else if (crossword[i - 1][j] != word[0])
                return false;
        }
    }

    for (; i < 10 && a < n; i++, a++)
    {
        if (crossword[i][j] == '-')
            b++;
        else if (crossword[i][j] == word[a])
            b++;
    }
    if (b == n)
        return true;

    return false;
}
void setH(vector<string> &crossword, string word, int i, int j)
{
    int b = 0; // for iteration over words
    if ((j - 1 >= 0))
    {
        if (crossword[i][j - 1] == word[0])
        {
            b = 1;
        }
    }
    for (; b < word.length(); j++, b++)
    {
        crossword[i][j] = word[b];
    }
}
void setV(vector<string> &crossword, string word, int i, int j)
{
    int b = 0; // for iteration over words
    if ((i - 1 >= 0))
    {
        if (crossword[i - 1][j] == word[0])
        {
            b = 1;
        }
    }
    for (; b < word.length(); i++, b++)
    {
        crossword[i][j] = word[b];
    }
}
void removeH(vector<string> &crossword, string word, int i, int j)
{
    int a = 0;
    if ((j - 1 >= 0))
    {
        if (crossword[i][j - 1] == word[0])
        {
            a = 1;
        }
    }
    for (; a < word.length(); a++)
    {
        crossword[i][a] = '-';
    }
}
void removeV(vector<string> &crossword, string word, int i, int j)
{
    int a = 0;
    if ((i - 1 >= 0))
    {
        if (crossword[i - 1][j] == word[0])
        {
            a = 1;
        }
    }
    for (a; a < word.length(); a++)
    {
        crossword[a][j] = '-';
    }
}

bool solve(vector<string> &crossword, vector<string> word)
{
    int i = -1;
    int j = -1;
    bool isEmpty = false;

    for (int row = 0; row < 10; row++)
    {
        for (int col = 0; col < 10; col++)
        {
            if (crossword[row][col] == '-')
            {
                i = row;
                j = col;
                isEmpty = true;
                break;
            }
        }

        if (isEmpty)
            break;
    }

    if (!isEmpty) // base case
    {
        return true;
    }
    for (string s : word)
    {
        if (checkH(crossword, s, i, j) == true)
        {
            setH(crossword, s, i, j);
            if (solve(crossword, word) == true)
                return true;
            removeH(crossword, s, i, j);
        }

        if (checkV(crossword, s, i, j) == true)
        {
            setV(crossword, s, i, j);
            if (solve(crossword, word) == true)
                return true;
            removeV(crossword, s, i, j);
        }
    }
    return false;
}
void crosswordPuzzle(vector<string> &crossword, string words)
{
    vector<string> word;
    string s = "";
    for (int i = 0; i < words.size(); i++)
    {
        if (words[i] == ';')
        {
            word.push_back(s);
            s = "";
            continue;
        }
        s.push_back(words[i]);
    }
    word.push_back(s);

    if (solve(crossword, word))
        printC(crossword);
    else
        cout << "   No Possible Solution (Mere Se Nhi Ho Rha ! ) " << endl;
}

int main()
{
    bool f = true;
    while (f)
    {
        system("CLS");
        f = false;
        vector<string> crossword(10);
        cout << "-----------------------------------------------------" << endl;
        cout << "     Enter Your Crossword Grid in 10 X 10 form" << endl;
        cout << "    Please Enter Your Crossword Grid in Row wise" << endl;
        cout << "   Press '+' for Block Space & '-' for Blank Space" << endl;
        cout << "\n"
             << endl;
        for (int i = 0; i < 10; i++)
        {
            string crossword_item;
            getline(cin, crossword_item);

            crossword[i] = crossword_item;
        }
        cout << endl;
        cout << "     Enter Your Word in Single Line seperated by ';'   " << endl;
        string words;
        cout << "     ";
        getline(cin, words);
        Sleep(2000);
        cout << "     Solving ";
        for (int i = 0; i < 3; i++)
        {
            Sleep(2000);
            cout << ".  ";
            for (int j = 0; j < 100; j++)
            {
                cout << "->";
                cout << "\b";
                cout << "\b";
            }
        }
        cout << endl;
        crosswordPuzzle(crossword, words);
        cout << "------------------------------------------------------" << endl;
        cout << "\n"
             << endl;

    here:
        cout << "   Do You Want To Continue? Press Y/N  ";
        char c;
        cin >> c;
        cout << endl;
        if (c == 'Y' || c == 'y')
            f = true;
        else if (c == 'N' || c == 'n')
        {
            f = false;
            Sleep(5000);
            system("CLS");
            cout << "             THANK YOU! ";
            system("pause");
            system("CLS");
        }
        else
        {
            system("CLS");
            cout << "     Press ONLY Y or N" << endl;
            Sleep(2000);
            goto here;
        }
    }

    return 0;
}
