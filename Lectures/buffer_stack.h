#ifndef BUFFER_STACK_H_INCLUDED
#define BUFFER_STACK_H_INCLUDED
#include <stack>

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

    /* instant variables */
    std::stack<char> before;
    std::stack<char> after;

    /*Make it illegal to copy editor buffers */
    EditorBuffer(const EditorBuffer& other){};
    const EditorBuffer& operator=(const EditorBuffer& other){return *this;}


};

#endif // BUFFER_STACK_H_INCLUDED
