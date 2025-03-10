#include <iostream>
#include <vector>

int main()
{
    std::vector<int> data;
    std::vector<int> s{1,2,3,4,5,6,7,8,9,10};

    data.push_back(15);

    //access
    std::cout << s[0] << std::endl;
    s[0] = 10;
    s.at(5) = 20;

    for(auto x : s)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    for(auto it = s.begin() ; it != s.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    //Delete
    auto it = s.begin();
    it += 2;
    s.erase(it);

    //insert
    it = s.begin();
    it++;
    s.insert(it, 500);

    return 0;
}