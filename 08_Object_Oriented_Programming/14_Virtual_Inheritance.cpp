#include <iostream>

class Stream
{
    int ss;
public:
    Stream(int _ss) : ss(_ss)
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

class IStream : virtual public Stream
{
    int is;
public:
    IStream(int _is, int _ss): Stream(_ss), is(_is)
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

class OStream : virtual public Stream
{
    int os;
public:
    OStream(int _os, int _ss): Stream(_ss), os(_os)
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
    IOStream(int _ios, int _ss, int _os, int _is) : Stream(_ss), IStream(_is, _ss), OStream(_os, _ss), ios(_ios)
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
    IOStream ios(1, 2, 3, 4);
    ios.display();
    return 0;
    /*
    Stream()
    IStream()
    OStream()
    IOStream()
    2
    ~IOStream()
    ~OStream()
    ~IStream()
    ~Stream()
    */
}