#include <iostream>

class Document
{
public:
    virtual void Serialize() const = 0;
};

class XMLDocument : public Document
{
public:
    void Serialize() const
    {
        std::cout  << "XML Document Serialized" << std::endl;
    }
};

int main()
{
    XMLDocument *doc =  new XMLDocument();
    doc->Serialize();
    return 0;
}