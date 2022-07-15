#include <iostream>
#include <string>
#include "buffer_stack.h"

using namespace std;

void executeCommand(EditorBuffer & buffer, string line);
void displayBuffer(EditorBuffer & buffer);
void printHelpText();

int main()
{
    EditorBuffer buffer;
    while(true)
    {
        string command;
        cout << "*";
        getline(cin, command);
        if (command != "") executeCommand(buffer, command);
    }
    return 0;
}


void executeCommand(EditorBuffer & buffer, string line)
{   int n=line.length();
    switch(toupper(line[0]))
    {
        case 'I':
        for (int i=1; i<n; i++)
        {
            buffer.insertCharacter(line[i]);
        }
        displayBuffer(buffer);
        break;
        case 'D': buffer.deleteCharacter();  displayBuffer(buffer); break;
        case 'F': buffer.moveCursorForward(); displayBuffer(buffer); break;
        case 'B': buffer.moveCursorBackward(); displayBuffer(buffer); break;
        case 'J': buffer.moveToStart(); displayBuffer(buffer); break;
        case 'E': buffer.moveToEnd(); displayBuffer(buffer); break;
        case 'H': printHelpText(); break;
        case 'Q': exit(0);
        default: cout << "Illegal command" << endl; break;
    }
}

void displayBuffer(EditorBuffer & buffer)
{

    string str=buffer.getText();
    int n = str.length();
    for (int i=0; i<n; i++)
    {
        cout << " " << str[i];
    }
    cout << endl;
    cout << string (2*buffer.getCursor(), ' ') << "^" << endl;
}

void printHelpText()
{
    cout << "Editor commands:" << endl;
    cout << "  Iabc  Inserts the characters abc at the cursor position" << endl;
    cout << "  F Moves the cursor forward one character" << endl;
    cout << "  B Moves the cursor backward one character" << endl;
    cout << "  Deletes the character after the cursor" << endl;
    cout << "  J Jumps to the beginning of the buffer" << endl;
    cout << "  E Jumps to the end of the buffer" << endl;
    cout << "  H Prints this message" << endl;
    cout << "  Q Exits from the editor program" << endl;

}
