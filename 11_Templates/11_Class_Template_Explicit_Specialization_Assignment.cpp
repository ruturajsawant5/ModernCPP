#include <iostream>
#include <vector>
#include <string>

template<typename T>
class PrettyPrinter {
    T *m_pData;
public:
    PrettyPrinter(T *data) :m_pData(data) {

    }
    void Print() {
        std::cout << "{" << *m_pData << "}" << std::endl;
    }

    T * GetData() {
        return m_pData;
    }
};

// Explicit specialization of a member function for std::vector<int>
template<>
void PrettyPrinter<std::vector<int>>::Print() {
    std::cout << "{";
    bool first = true;
    for (const auto &x : *m_pData) {
        if (!first) {
            std::cout << ",";
        }
        std::cout << x;
        first = false;
    }
    std::cout << "}" << std::endl;
}

// Explicit specialization of the class for char*
template<>
class PrettyPrinter<char*> {
    char *m_pData;
public:
    PrettyPrinter(char *data) :m_pData(data) {

    }
    void Print() {
        std::cout << "{" << m_pData << "}" << std::endl;
    }
    char * GetData() {
        return m_pData;
    }
};

// Explicit specialization of only the Print member function for std::vector<std::vector<int>>
template<>
void PrettyPrinter<std::vector<std::vector<int>>>::Print() {
    std::cout << "{" << std::endl;
    bool firstOuter = true;
    for (const auto &innerVec : *m_pData) {
        if (!firstOuter) {
            std::cout << "," << std::endl;
        }
        std::cout << "\t{";
        bool firstInner = true;
        for (const auto &x : innerVec) {
            if (!firstInner) {
                std::cout << ",";
            }
            std::cout << x;
            firstInner = false;
        }
        std::cout << "}";
        firstOuter = false;
    }
    std::cout << std::endl << "}" << std::endl;
}

int main() {
    char *p{ "Hello world" };
    PrettyPrinter<char*> p3(p);
    p3.Print();
    char *pData = p3.GetData();

    std::vector<int> v{ 1,2,3,4,5 };
    PrettyPrinter<std::vector<int>> pv(&v);
    pv.Print();

    std::vector<std::vector<int>> vv{ {1, 2, 3}, {4, 5, 6} };
    PrettyPrinter<std::vector<std::vector<int>>> pvv(&vv);
    pvv.Print();

    return 0;
}