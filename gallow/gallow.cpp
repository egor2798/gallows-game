#include <fstream>
#include <iostream>
#include <time.h>
#include <string>
#include <cctype>
#include <vector>
#include <stdio.h> 
#include <time.h> 
#include "windows.h"

using namespace std;

void paint(int allNumberErrors, string Word)
{
    system("cls");


    if (allNumberErrors == 0)
    {

        ifstream fin1;
        string print;
        fin1.open("texture1.txt");

        int i = 0;
        while (!fin1.eof())
        {
            getline(fin1, print);
            cout << print << endl;
        }

        fin1.close();

    }
    if (allNumberErrors == 1) {

        ifstream fin1;
        string print;
        fin1.open("texture2.txt");

        int i = 0;
        while (!fin1.eof())
        {
            getline(fin1, print);
            cout << print << endl;
        }
        cout << endl << endl;
        fin1.close();
    }
    if (allNumberErrors == 2) {


        ifstream fin1;
        string print;
        fin1.open("texture3.txt");

        int i = 0;
        while (!fin1.eof())
        {
            getline(fin1, print);
            cout << print << endl;
        }
        cout << endl << endl;
        fin1.close();
        cout << endl << endl;

    }
    if (allNumberErrors == 3) {


        ifstream fin1;
        string print;
        fin1.open("texture4.txt");

        int i = 0;
        while (!fin1.eof())
        {
            getline(fin1, print);
            cout << print << endl;
        }
        cout << endl << endl;
        fin1.close();
    }
    if (allNumberErrors == 4)
    {


        ifstream fin1;
        string print;
        fin1.open("texture5.txt");

        int i = 0;
        while (!fin1.eof())
        {
            getline(fin1, print);
            cout << print << endl;
        }
        cout << endl << endl;
        fin1.close();
        cout << endl << endl;

    }
    if (allNumberErrors == 5)
    {

        // cout << Word;

        ifstream fin1;
        string print;
        fin1.open("texture6.txt");

        int i = 0;
        while (!fin1.eof())
        {
            getline(fin1, print);
            cout << print << endl;
        }
        cout << endl << endl;
        fin1.close();
        cout << endl << endl;
    }
    if (allNumberErrors == 6) {


        ifstream fin1;
        string print;
        fin1.open("texture7.txt");

        int i = 0;
        while (!fin1.eof())
        {
            getline(fin1, print);
            cout << print << endl;
        }
        cout << endl << endl;
        fin1.close();
        cout << endl << endl;
    }
    if (allNumberErrors == 7)
    {


        ifstream fin1;
        string print;
        fin1.open("texture8.txt");

        int i = 0;
        while (!fin1.eof())
        {
            getline(fin1, print);
            cout << print << endl;
        }

        fin1.close();
        cout << endl << endl << "игра окончена. вы проиграли.\n";
    }
}

class Gallows
{
    string Word;
public:
    Gallows()
    {
        time_t start, end;

        time(&start);
        ifstream fin;

        fin.open({ "rand.txt" });

        srand((unsigned int)std::time(0));

        int random = rand() % 2073;

        if (!fin.is_open())
        {
            std::cout << "ERROR, FILE IS NOT FOUND" << endl;
            exit(0);
        }
        for (int i = 0; i < random; i++)
        {
            getline(fin, Word);
        }
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);

        fin.close();

        srand((unsigned int)std::time(0));

        int g = 0, numberCorrectLetter = 0, numberErrors = 0;
        int l = 0;

        char letter;

        vector<char> vectorWords;

        int d = 0;
        int wSize = (Word.size() * 2);
        char* randWord = new char[wSize - 1];
        int allNumberErrors = 0;

        while (d < (wSize))
        {
            randWord[d] = '_';
            d++;
            randWord[d] = ' ';
            d++;
        }
        d = 0;
        while (true)
        {
            cout << endl;
            if (allNumberErrors == 0)
            {
                paint(allNumberErrors, Word);

                while (d < (wSize - 1))
                {
                    cout << randWord[d];
                    d++;
                }

                cout << endl;
            }

            cout << endl;
            cout << "введите букву -> ";
            cin >> letter;
            vectorWords.push_back(letter);
            d = 0;

            for (int i = 0; i < Word.size(); i++)
            {

                if (Word[i] == letter)
                {
                    randWord[d] = letter;
                    numberCorrectLetter++;
                    cout << numberCorrectLetter;
                }

                else
                {
                    numberErrors++;
                }

                if (numberErrors == Word.size())
                {
                    allNumberErrors++;
                }

                d = d + 2;
            }

            d = 0;
            numberErrors = 0;

            paint(allNumberErrors, Word);

            cout << "\nигрок использовал эти буквы:\n";

            while (d < vectorWords.size())
            {
                cout << d + 1 << ") " << vectorWords[d] << endl;
                d++;
            }

            if (allNumberErrors == 7)
            {
                break;
            }

            if (numberCorrectLetter == Word.size())
            {
                system("cls");
                cout << "игра окончена. Вы победили.";
                break;
            }

            cout << endl;
            d = 0;

            while (d < (wSize - 1))
            {
                cout << randWord[d];
                d++;
            }

            l = 0;

        }

        time(&end);

        double seconds = difftime(end, start);

        cout << "\nигрок затратили " << seconds << " секунд.";
        cout << "\nискомое слово -> " << Word;
        cout << endl << "игрок использовал " << d << " попыток" << endl << endl;

    }

};

int main()
{
    setlocale(LC_ALL, "rus");
    Gallows obj;
}
