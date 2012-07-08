#ifndef ADDRESSBOOK
#define ADDRESSBOOK
#include <list>
#include <string>
#include <vector>

using std::list;
using std::string;
using std::vector;

struct Info
{
    string name;
    string mobile;
    string address;
};


class AddressBook
{
    public:
    void Run();

    private:

    list<Info> infolist;
    void LoadFile();
    void SaveFile();
    void AddInfo();
    void SearchInfo();
    void DeleteInfo();
    void GetHelp();
    vector<list<Info>::iterator> SearchResults();
    void PrintInfoResults (const vector<list<Info>::iterator>&);
    void DeleteInfoResults (const vector<list<Info>::iterator>&);
};


#endif
