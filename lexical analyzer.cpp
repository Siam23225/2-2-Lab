#include <bits/stdc++.h>
using namespace std;

// Set of keywords for the language (we're using a simple subset)
set<string> keywords =
{
    "int", "float", "if", "else", "while", "for", "return", "string", "char", "bool", "true", "false"
};

// Function to check if a string is a keyword
bool isKeyword( string str)
{
    return keywords.find(str) != keywords.end();
}



// Function to check if a character is an operator
bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '>' || ch == '<');
}

// Function to check if a string is a number
bool isNumber( string str)
{
    for (char c : str)
    {
        if (!isdigit(c)) return false;
    }
    return true;
}

// Function to check if a string is a valid identifier (starts with a letter or underscore)
bool isIdentifier( string str)
{
    if (isdigit(str[0])) return false;  // An identifier can't start with a number
    for (char c : str)
    {
        if (!isalnum(c) && c != '_') return false;
    }
    return true;
}

// Lexical Analyzer function
void lexicalAnalysis( string sourceCode)
{
    int i = 0;
    int len = sourceCode.length();

    while (i < len)
    {
        // Ignore whitespace
        if (isspace(sourceCode[i]))
        {
            i++;
            continue;
        }

        // Identify keywords, identifiers, or numbers
        if (isalpha(sourceCode[i]) || sourceCode[i] == '_')
        {
            string token = "";
            while (i < len && (isalnum(sourceCode[i]) || sourceCode[i] == '_'))
            {
                token += sourceCode[i++];
            }
            if (isKeyword(token))
            {
                cout << "Keyword: " << token << endl;
            }
            else if (isIdentifier(token))
            {
                cout << "Identifier: " << token << endl;
            }
        }

        // Identify numbers
        else if (isdigit(sourceCode[i]))
        {
            string token = "";
            while (i < len && isdigit(sourceCode[i]))
            {
                token += sourceCode[i++];
            }
            if (isNumber(token))
            {
                cout << "Number: " << token << endl;
            }
        }

        // Identify operators
        else if (isOperator(sourceCode[i]))
        {
            cout << "Operator: " << sourceCode[i] << endl;
            i++;
        }

        // Identify delimiters

        else  i++;

    }
}

int main()
{
    string sourceCode;
    cout << "Enter a C++ program (end with Ctrl+D or Ctrl+Z):\n";

    // Take input from user (entire program)
    char c;
    while (cin.get(c))
    {
        sourceCode += c;
    }

    cout << "\nLexical Analysis:\n";
    lexicalAnalysis(sourceCode);

    return 0;
}

