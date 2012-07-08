#include "Address_book.h"
#include <iostream>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

void AddressBook::Run()
{
    LoadFile();
    string command;
    while (1)
    {   
        cout<<"Please write your command"<<endl;
        cin>>command;
        if(command == "add")
            AddInfo();
        else if(command =="search")
            SearchInfo();
        else if(command == "delete")
            DeleteInfo();
        else if(command == "!help")
            GetHelp();
        else if(command =="!save")
            SaveFile();
        else if(command == "!quit")
        {
            SaveFile();
            return;
        }
        else
            cout<<"Wrong command! If you need help, wirte !help"<<endl; 
    }
}

void AddressBook::LoadFile()
{
    infolist.clear();
    ifstream infile;
    infile.open("./My_AddressBook");
    string entry;
    Info newinfo;
    while(infile>>entry)
    {
        if(entry=="name:")
        {
            infile>>newinfo.name;
            if(infile>>entry&& entry=="mobile:")
            {
                infile>>newinfo.mobile;
                if(infile>>entry && entry == "address:")
                {
                    infile>>newinfo.address;
                }
            }

        }
        infolist.push_back(newinfo);
    }
    cout<<"File Loaded!"<<endl;
}

void AddressBook::SaveFile()
{
    ofstream outfile;
    outfile.open("./My_AddressBook");
    list<Info>::iterator ite;
    for(ite= infolist.begin();ite!= infolist.end();++ite)
    {
        outfile<<"name:     "<<ite->name<<endl;
        outfile<<"mobile:   "<<ite->mobile<<endl;
        outfile<<"address: "<<ite->address<<endl;
        outfile<<endl;
    }

    cout<<"File Saved!"<<endl;
}
void AddressBook::AddInfo()
{
    Info newinfo;
    cout<<"name :";
    cin>>newinfo.name;
    cout<<"mobile :";
    cin>>newinfo.mobile;
    cout<<"address :";
    cin>>newinfo.address;
    infolist.push_back(newinfo);
    cout<<"address entry added"<<endl;
}


void AddressBook::SearchInfo()
{
    vector<list<Info>::iterator> searchresults = SearchResults();
    PrintInfoResults(searchresults);
}

void AddressBook::DeleteInfo()
{
    vector<list<Info>::iterator> searchresults = SearchResults();
    DeleteInfoResults(searchresults);
}


vector<list<Info>::iterator> AddressBook::SearchResults()
{
    vector<list<Info>::iterator> SearchResults;
    cout<<"by (name|mobile|address) :";
    string SearchEntry,TobeSearched;
    cin>>SearchEntry;
    while(SearchEntry != "name" && SearchEntry!= "mobile" &&SearchEntry!="address")
    {
        cout<<"Wrong entry! Please write the right entry (name|mobile|address)"<<endl;
        cin>>SearchEntry;
    }
    cin>>TobeSearched;
    int SearchedSize = TobeSearched.size();
    list<Info>::iterator ite;
    if(SearchEntry== "name")
    {
        if(TobeSearched.substr(SearchedSize-2) != ".*")
        {
            for(ite= infolist.begin(); ite!= infolist.end();++ite)
            {
                if(ite->name == TobeSearched)
                {
                    SearchResults.push_back(ite);
                }
            }
        }
        else
        {
            string SubSearched = TobeSearched.substr(0,SearchedSize-2);
            for(ite = infolist.begin(); ite!= infolist.end(); ++ite)
            {
                if((ite->name).size()>=SearchedSize-2 && (ite->name).substr(0,SearchedSize-2)==SubSearched)
                {
                    SearchResults.push_back(ite);
                }
            }
        }
    }
    else if(SearchEntry == "mobile")
    {
        if(TobeSearched.substr(SearchedSize-2) != ".*")
        {
            for(ite= infolist.begin(); ite!= infolist.end();++ite)
            {
                if(ite->mobile == TobeSearched)
                {
                    SearchResults.push_back(ite);
                }
            }
        }
        else
        {
            string SubSearched = TobeSearched.substr(0,SearchedSize-2);
            for(ite = infolist.begin(); ite!= infolist.end(); ++ite)
            {
                if((ite->mobile).size()>=SearchedSize-2 && (ite->mobile).substr(0,SearchedSize-2)== SubSearched)
                {
                    SearchResults.push_back(ite);
                }
            }
        }

    }
    else if(SearchEntry == "address")
    {
        if(TobeSearched.substr(SearchedSize-2) != ".*")
        {
            for(ite= infolist.begin(); ite!= infolist.end();++ite)
            {
                if(ite->address == TobeSearched)
                {
                    SearchResults.push_back(ite);
                }
            }
        }
        else
        {
            string SubSearched = TobeSearched.substr(0,SearchedSize-2);
            for(ite = infolist.begin(); ite!= infolist.end(); ++ite)
            {
                if((ite->address).size()>=SearchedSize-2 && (ite->address).substr(0,SearchedSize-2)==SubSearched)
                {
                    SearchResults.push_back(ite);
                }
            }
        }
    }
    return SearchResults;
}


void AddressBook::PrintInfoResults(const vector<list<Info>::iterator>& searchresults)
{
    list<Info>::iterator iteresult;
    if(searchresults.size()==0)
    {
        cout<<"No matched result!"<<endl;
        return;
    }
    cout<<searchresults.size()<<" results matched!"<<endl;
    for(int i=0;i!= searchresults.size(); ++i)
    {
        iteresult = searchresults[i];
        cout<< iteresult->name<<endl;
        cout<< iteresult->mobile<<endl;
        cout<< iteresult->address<<endl;
        cout<<endl;
    }
}

void AddressBook::DeleteInfoResults(const vector<list<Info>::iterator>& searchresults)
{
    if(searchresults.size()==0)
    {
        cout<<"No matched result!"<<endl;
        return;
    }
    list<Info>::iterator iteresult;
    for(int i=0;i!= searchresults.size(); ++i)
    {
        iteresult = searchresults[i];
        infolist.erase(iteresult);
    }
    cout<<searchresults.size()<<" matched results have been deleted!"<<endl;
}


void AddressBook::GetHelp()
{
    cout<<"--------------------------------HELP--------------------------------"<<endl;
    cout<<"This program is an address book that can store personal information"<<endl;
    cout<<"The following are commands in this program"<<endl;
    cout<<"add        add a new address, including the name, mobile and address"<<endl;
    cout<<"search     search the address book and print all the matched results"<<endl;
    cout<<"delete     delete the address that you don't want to save"<<endl;
    cout<<"!help      watch the help information"<<endl;
    cout<<"!save      save the address information right now"<<endl;
    cout<<"!quit      quit this program and save immediately"<<endl;
}



