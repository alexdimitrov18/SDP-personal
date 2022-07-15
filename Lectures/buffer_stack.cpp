#include <string>
#include "buffer_stack.h"
#include <stack>
using namespace std;

    //! All dynamic allocation and deallocation is managed by <stack> class,
    //! which means no work for constructors and destructors
    EditorBuffer::EditorBuffer(){}

    EditorBuffer::~EditorBuffer(){}

    void EditorBuffer::moveCursorForward()
    {
       if(!after.empty())
       {
           before.push(after.top());
           after.pop();
       }
    }

    void EditorBuffer::moveCursorBackward()
    {
        if(!before.empty())
        {
            after.push(before.top());
            before.pop();
        }
    }

    void EditorBuffer::moveToStart()
    {
        while(!before.empty())
        {
            after.push(before.top());
            before.pop();
        }
    }

    void EditorBuffer::moveToEnd()
    {
        while(!after.empty())
        {
            before.push(after.top());
            after.pop();
        }
    }

    void EditorBuffer::insertCharacter(char ch)
    {
        before.push(ch);
    }

    void EditorBuffer::deleteCharacter()
    {
        if(!after.empty())
        {
            after.pop();
        }
    }

    /* Simple getter methods */
    string EditorBuffer::getText() const
    {
        stack<char> beforeCopy=before;
        stack<char> afterCopy=after;
        string str="";
        while (!beforeCopy.empty())
        {
            str=beforeCopy.top()+str;
            beforeCopy.pop();
        }
        while (!afterCopy.empty())
        {
            str+=afterCopy.top();
            afterCopy.pop();
        }
        return str;
    }

    int EditorBuffer::getCursor() const
    {
        return before.size();
    }

