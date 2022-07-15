#ifndef BUFFER_LIST_H_INCLUDED
#define BUFFER_LIST_H_INCLUDED

class EditorBuffer
{
public:
    EditorBuffer();
    ~EditorBuffer();
    void moveCursorForward();
    void moveCursorBackward();
    void moveToStart();
    void moveToEnd();
    void insertCharacter(char ch);
    void deleteCharacter();

    std::string getText() const;
    int getCursor() const;

private:

     /*Type for linked list node*/
    struct Node
    {
        char data;
        Node* next;
    };

    /* Instance variables */
    Node* start;
    Node* cursor;

    /*Make it illegal to copy editor buffers */
    EditorBuffer(const EditorBuffer& other){};
    const EditorBuffer& operator=(const EditorBuffer& other){return *this;}

};

#endif // BUFFER_LIST_H_INCLUDED
