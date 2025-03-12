#include <iostream>

class Document
{
    public:
        virtual void Serialize() const
        {
            std::cout << "Serializing..." << std::endl;
        }
};

class XMLDocument : public Document
{
    // I dont implement Serialize even though I should
    // Document cant force XMLDocument to implement Serialize
};

int main()
{
    XMLDocument *doc =  new XMLDocument();
    doc->Serialize();
    return 0;
}