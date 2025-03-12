#include <iostream>

class Stream
{
    int ss;
    public:
        Stream()
        {
            std::cout  << "Stream()" << std::endl;
        }
        ~Stream()
        {
            std::cout  << "~Stream()" << std::endl;
        }
        void display() const
        {
            std::cout << ss << std::endl;
        }
};

class IStream : public Stream
{
    int is;
    public:
        IStream()
        {
            std::cout  << "IStream()" << std::endl;
        }
        ~IStream()
        {
            std::cout  << "~IStream()" << std::endl;
        }
        void idisplay() const
        {
            std::cout << is << std::endl;
        }
};

class OStream : public Stream
{
    int os;
public:
    OStream()
    {
        std::cout  << "OStream()" << std::endl;
    }
    ~OStream()
    {
        std::cout  << "~OStream()" << std::endl;
    }
    void odisplay() const
    {
        std::cout << os << std::endl;
    }
};

class IOStream : public IStream, public OStream
{
    int ios;
public:
    IOStream()
    {
        std::cout  << "IOStream()" << std::endl;
    }
    ~IOStream()
    {
        std::cout  << "~IOStream()" << std::endl;
    }
    void iodisplay() const
    {
        std::cout << ios << std::endl;
    }
};

int main()
{
    IOStream ios;
    //ambiguous access of 'display'
    ios.display();
    return 0;
    /*
    Stream()-------------->TWICE
    IStream()
    Stream()
    OStream()
    IOStream()
    ~IOStream()
    ~OStream()
    ~Stream()
    ~IStream()
    ~Stream()
    */
}