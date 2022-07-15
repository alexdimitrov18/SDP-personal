#ifndef BUFFER_ARR_H_INCLUDED
#define BUFFER_ARR_H_INCLUDED

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

    /* private constants */
    static const int INITIAL_CAPACITY =10;

    /* Instance variables */
    char* arr;
    int capacity;
    int length;
    int cursor;

    /*Make it illegal to copy editor buffers */
    EditorBuffer(const EditorBuffer& other){};
    const EditorBuffer& operator=(const EditorBuffer& other){return *this;}

    /* Private method prototypes */
    void expandCapacity();

};

#endif // BUFFER_ARR_H_INCLUDED
