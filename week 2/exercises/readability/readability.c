#include <stdio.h>
#include <cs50.h>
#include <math.h>

// Function
int letterCounter(string text); // returns the total number of letters in a given text.
int wordCounter(string text); // returns the total number of words in a given text.
int sentenceCounter(string text); // returns the total number of sentences in a given text.

bool isLetter(char ch); // verify if a char is a letter.
bool isSentenceEnd(char ch); // verify if it is the end of a sentence.

void readabilityGrade(int letters, int words, int sentences);

// Constants
const char LINE_END = '\0'; // NULL terminating character

int main(void)
{
    string text = get_string("Text: ");

    int letters = letterCounter(text);
    int words = wordCounter(text);
    int sentences = sentenceCounter(text);

    // printf("%i letter(s)\n", letters);
    // printf("%i word(s)\n", words);
    // printf("%i sentence(s)\n", sentences);

    readabilityGrade(letters, words, sentences);
}

void readabilityGrade(int letters, int words, int sentences)
{
    double l = (double) letters / (double) words * 100;
    double s = (double) sentences / (double) words * 100;
    double index = 0.0588 * l - 0.296 * s - 15.8;
    int grade = round(index);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
        return;
    }

    if (grade >= 16)
    {
        printf("Grade 16+\n");
        return;
    }

    printf("Grade %i\n",  grade);
}

int wordCounter(string text)
{
    int counter = 0;

    for (int i = 0; text[i] != LINE_END; i++)
    {
        if (text[i] == ' ')
        {
            counter++;
        }
    }

    if (counter > 0)
    {
        counter++;
    }

    return counter;
}

int letterCounter(string text)
{
    int counter = 0;

    for (int i = 0; text[i] != LINE_END; i++)
    {
        if (isLetter(text[i]))
        {
            counter++;
        }
    }

    return counter;
}

bool isLetter(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int sentenceCounter(string text)
{
    int counter = 0;

    for (int i = 0; text[i] != LINE_END; i++)
    {
        if (isSentenceEnd(text[i]))
        {
            counter++;
        }
    }

    return counter;
}

bool isSentenceEnd(char ch)
{
    return ch == '.' || ch == '!' || ch == '?';
}