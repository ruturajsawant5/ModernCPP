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
         //silly mistake here wanted to override
         void Serialize(int version)
         {
             std::cout << "Text::Serialize" << std::endl;
         }
 };

 int main()
 {
     Text t;
     Document& doc = t;
     doc.Serialize(1); //Document::Serialize called even when virtual

     return 0;
 }