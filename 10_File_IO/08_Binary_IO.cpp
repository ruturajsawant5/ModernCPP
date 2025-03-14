#include <iostream>
#include <fstream>
#include <string>

struct IP
{
    int ip;
    std::string name;
    IP(int _ip, std::string _name):ip(_ip),name(_name){}
    IP():IP(0,""){}
};

void store_binary()
{
    std::fstream file;
    file.open("binary.bin", std::ios::out | std::ios::binary  | std::ios::trunc);
    if(!file)
    {
        std::cout<<"Can't open file" << std::endl;
        return;
    }

    int recs = 5;
    IP ip[] = {{1, "lorem"},{2, "ipsum"},{3, "Contxt"},{4, "Singaling"},{5, "Harry Potter"}};

    file.write((char*)&recs, sizeof(int));

    for(int i = 0; i < recs; i++)
        file.write((char*)&ip[i], sizeof(IP));

	file.close();
}

void retrieve_binary()
{
    std::fstream file;
    file.open("binary.bin", std::ios::in | std::ios::binary);
    if(!file)
    {
        std::cout<<"Can't open file" << std::endl;
        return;
    }

    int recs = -1;
    file.read((char*)&recs, sizeof(int));
	std::cout << recs << std::endl;
	IP ip{};
    
    for(int i = 0; i < recs; i++)
    {
		file.read((char*)&ip, sizeof(IP));
        std::cout<<ip.ip<<std::endl;
        std::cout<<ip.name<<std::endl;
    }

	file.close();
}
int main()
{
    store_binary();
    retrieve_binary();
    return 0;
}