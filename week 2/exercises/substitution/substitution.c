#include <cs50.h>
#include <stdio.h>
#include <string.h>


// Functions
bool validateInputs(int argc, string argv[]); // Validate the inputs of the application.
bool isUpperCase(char letter); // Verify if a given char is in upper case or not.
bool isLowerCase(char letter); // Verify if a given char is in lower case or not.
bool isAllAlphabetic(string key); // Verify if all characters is alphabetics.
bool hasDuplications(string key); // Verify is a given string has duplicated characters.

char toUpperCase(char letter); // Convert a char to upper case.
char toLowerCase(char letter); // Convert a char to lower case.

void cipher(string plaintext, string secret); // substitution cipher


// Constants
const char LINE_END = '\0'; // NULL terminating character


// Program
int main(int argc, string argv[])
{
    int isValid = validateInputs(argc, argv);
    if (!isValid)
    {
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    cipher(plaintext, argv[1]);

    return 0;
}


// Functions implementations
void cipher(string plaintext, string secret)
{
    int length = strlen(plaintext);
    char ciphertext[length];
    char letter;

    for (int i = 0; i <= length; i++)
    {
        if (isLowerCase(plaintext[i]))
        {
            letter = secret[plaintext[i] - 'a'];

            if (isLowerCase(letter))
            {
                ciphertext[i] = letter;
                continue;
            }

            ciphertext[i] = toLowerCase(letter);
        }
        else if (isUpperCase(plaintext[i]))
        {
            letter = secret[plaintext[i] - 'A'];

            if (isUpperCase(letter))
            {
                ciphertext[i] = letter;
                continue;
            }

            ciphertext[i] = toUpperCase(letter);
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    ciphertext[length + 1] = LINE_END;

    printf("ciphertext: %s\n", ciphertext);
}


bool validateInputs(int argc, string argv[])
{
    if (argc < 2 || argc > 2)
    {
        printf("%s\n", "Usage: ./substitution key");
        return false;
    }

    int arrayLength = strlen(argv[1]);

    if (arrayLength < 26 || arrayLength > 26)
    {
        printf("%s\n", "Key must contain 26 characters.");
        return false;
    }

    if (!isAllAlphabetic(argv[1]))
    {
        printf("%s\n", "Key must contain only alphabetic character.");
        return false;
    }

    if (hasDuplications(argv[1]))
    {
        printf("%s\n", "Key must not have duplicated characters.");
        return false;
    }

    return true;
}

bool isUpperCase(char letter)
{
    return (letter >= 'A') && (letter <= 'Z');
}

bool isLowerCase(char letter)
{
    return (letter >= 'a') && (letter <= 'z');
}

char toUpperCase(char letter)
{
    return letter - 32;
}

char toLowerCase(char letter)
{
    return letter + 32;
}

bool isAllAlphabetic(string key)
{
    int arrayLength = strlen(key);

    for (int i = 0; i < arrayLength; i++)
    {
        if (!isUpperCase(key[i]) && !isLowerCase(key[i]))
        {
            return false;
        }
    }

    return true;
}

bool hasDuplications(string key)
{
    int arrayLength = strlen(key);

    for (int i = 0; i <= arrayLength; i++)
    {
        for (int j = i + 1; j <= arrayLength; j++)
        {
            if (key[i] == key[j])
            {
                return true;
            }
        }
    }

    return false;
}
