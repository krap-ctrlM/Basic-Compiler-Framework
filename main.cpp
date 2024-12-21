#include <iostream>
#include <ctype.h>
#include <stdlib.h>

using namespace std;

// Constant Declarations
const char TAB = '\t';

// Variable Declarations
char Look; // Lookahead Character

// Read New Character From Input Stream
void GetChar() {
    cin.get(Look);
}

// Report an Error
void Error(string s) {
    cout << endl;
    cout << '\a' << "Error: " << s << "." << endl;
}

// Report Error and Halt
void Abort(string s) {
    Error(s);
    exit(EXIT_FAILURE);
}

// Report What Was Expected
void Expected(string s) {
    Abort(s + " Expected");
}

// Match a Specific Input Character
void Match(char x) {
    if (Look == x) {
        GetChar();
    } else {
        string s = "'";
        s += x;
        s += "'";
        Expected(s);
    }
}

// Recognize an Alpha Character
bool IsAlpha(char c) {
    return isalpha(c) != 0;
}

// Recognize a Decimal Digit
bool IsDigit(char c) {
    return isdigit(c) != 0;
}

// Get an Identifier
char GetName() {
    if (!IsAlpha(Look)) {
        Expected("Name");
    }

    char c = toupper(Look);
    GetChar();
    return c;
}

// Get a Number
char GetNum() {
    if (!IsDigit(Look)) {
        Expected("Integer");
    }

    char c = Look;
    GetChar();
    return c;
}

// Output a String with Tab
void Emit(string s) {
    cout << TAB << s;
}

// Output a String with Tab and CRLF
void EmitLn(string s) {
    Emit(s);
    cout << endl;
}

// Initialize
void Init() {
    GetChar();
}

// Main Program
int main() {
    Init();
    return 0;
}
