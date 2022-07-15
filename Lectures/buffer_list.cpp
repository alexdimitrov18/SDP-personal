#include <string>
#include "buffer_list.h"

using namespace std;


    EditorBuffer::EditorBuffer()
    {
        start = cursor = new Node;
        start->next=nullptr;
    }

    EditorBuffer::~EditorBuffer()
    {
        Node* current=start;
        Node* todelete;
        while(current!=nullptr)
        {
            todelete=current;
            current=current->next;
            delete todelete;

        }
    }

    void EditorBuffer::moveCursorForward()
    {
       if (cursor->next!=nullptr)
       {
           cursor=cursor->next;
       }
    }

    void EditorBuffer::moveCursorBackward()
    {
        Node* current=start;
        if (start!=cursor)
        {
            while(current->next!=cursor)
            {
                current=current->next;
            }
            cursor=current;
        }
    }

    void EditorBuffer::moveToStart()
    {
        cursor=start;
    }

    void EditorBuffer::moveToEnd()
    {
        while(cursor->next!=nullptr)
        {
            cursor=cursor->next;
        }
    }

    void EditorBuffer::insertCharacter(char ch)
    {
        Node* cp = new Node;
        cp->data=ch;
        cp->next=cursor->next;
        cursor->next=cp;
        cursor=cp;
    }

    void EditorBuffer::deleteCharacter()
    {
        if(cursor->next!=nullptr)
        {
            Node* todelete=cursor->next;
            cursor->next=cursor->next->next;
            delete todelete;
        }
    }

    /* Simple getter methods */
    string EditorBuffer::getText() const
    {
        string str="";
        Node* current=start->next;
        while (current!=nullptr)
        {
            str+=current->data;
            current=current->next;
        }
        return str;
    }

    int EditorBuffer::getCursor() const
    {
        int nchars=0;
        Node* cp=start;
        while(cp!=cursor)
        {
            nchars++;
            cp=cp->next;
        }
        return nchars;
    }


