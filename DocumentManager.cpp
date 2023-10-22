#include<set>
#include<map>
#include<string>
#include"DocumentManager.h"
using namespace std;

void DocumentManager::addDocument(string name, int id, int license_limit)
{
    documents[id] = {name, license_limit};
}

void DocumentManager::addPatron(int patronID)
{
    patrons.insert(patronID);
}

int DocumentManager::search(std::string name)
{
    for (const auto& document : documents) {
            if (document.second.first == name) {
                return document.first;
            }
        }
    return 0;
}

bool DocumentManager::borrowDocument(int docid, int patronID)
{
    if (patrons.find(patronID) == patrons.end() || documents.find(docid) == documents.end()) {
        return false;
    }

    int& remaining_licenses = documents[docid].second;
    if (remaining_licenses > 0) {
        remaining_licenses--;
        return true;
    }
    return false;
}

void DocumentManager::returnDocument(int docid, int patronID)
{
    if (patrons.find(patronID) != patrons.end() && documents.find(docid) != documents.end()) 
    {
        documents[docid].second++;
    }
}