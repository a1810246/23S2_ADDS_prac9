#include<string>
#include<map>
#include<set>
using namespace std;

class DocumentManager
{
    public:
        void addDocument(string name, int id, int license_limit);
        void addPatron(int patronID);
        int search(string name);
        bool borrowDocument(int docid, int patronID);
        void returnDocument(int docid, int patronID);

    private:
        std::map<int, std::pair<std::string, int>> documents;
        std::set<int> patrons;
}