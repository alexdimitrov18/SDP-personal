#include <string>
#include "buffer_arr.h"

using namespace std;


    EditorBuffer::EditorBuffer()
    {
        capacity=INITIAL_CAPACITY;
        arr= new char[capacity];
        length = 0;
        cursor = 0;
    }

    EditorBuffer::~EditorBuffer()
    {
        delete [] arr;
    }

    void EditorBuffer::moveCursorForward()
    {
       if (cursor < length) cursor++;
    }

    void EditorBuffer::moveCursorBackward()
    {
        if (cursor > 0) cursor--;
    }

    void EditorBuffer::moveToStart()
    {
        cursor=0;
    }

    void EditorBuffer::moveToEnd()
    {
        cursor=length;
    }

    void EditorBuffer::insertCharacter(char ch)
    {
        if(length==capacity) expandCapacity();
        for (int i=length; i>cursor; i--)
        {
            arr[i]=arr[i-1];
        }
        arr[cursor]=ch;
        length++;
        cursor++;
    }

    void EditorBuffer::deleteCharacter()
    {
        if(cursor<length)
        {
            for (int i=cursor+1; i<length; i++)
            {
                arr[i-1]=arr[i];
            }
            length--;
        }
    }

    /* Simple getter methods */
    string EditorBuffer::getText() const
    {
        return string(arr, length);
    }

    int EditorBuffer::getCursor() const
    {
        return cursor;
    }


    void  EditorBuffer::expandCapacity()
    {

       char* oldarr=arr;
       capacity*=2;
       arr = new char[capacity];
       for(int i=0; i<length; i++)
       {
           arr[i]=oldarr[i];
       }
       delete [] oldarr;
    }


