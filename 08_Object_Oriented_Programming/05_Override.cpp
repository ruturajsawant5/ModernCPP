#include <iostream>

class Document
{
    public:
        virtual void Serialize(float version)
        {
            std::cout << "Document::Serialize" << std::endl;
        }
};

class Text : public Document
{
    public:
        //'Text::Serialize': method with override specifier 'override' did not override any base class method
        void Serialize(int version) override
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