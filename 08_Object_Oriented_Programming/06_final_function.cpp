#include <iostream>

class Document
{
public:
    virtual void Serialize(float version) final
    {
        std::cout << "Document::Serialize" << std::endl;
    }
};

class Text : public Document
{
public:
    //'Document::Serialize': function declared as 'final' cannot be overridden by 'Text::Serialize'
    void Serialize(float version)
    {
        std::cout << "Text::Serialize" << std::endl;
    }
};

int main()
{
    Text t;
    Document& doc = t;
    doc.Serialize(1.0);
    return 0;
}