#include<iostream>
#include<string>
#include<map>
#include<set>
#include"DocumentManager.h"
using namespace std;


int main() {
    DocumentManager manager;

    // 添加文档
    manager.addDocument("Document1", 1, 3);
    manager.addDocument("Document2", 2, 2);

    // 添加用户
    manager.addPatron(101);
    manager.addPatron(102);

    // 搜索文档
    int docID = manager.search("Document1");
    if (docID != 0) {
        std::cout << "Found document: " << docID << std::endl;
    } else {
        std::cout << "Document not found." << std::endl;
    }

    // 借用文档
    if (manager.borrowDocument(1, 101)) {
        std::cout << "Document 1 borrowed by Patron 101." << std::endl;
    } else {
        std::cout << "Failed to borrow Document 1." << std::endl;
    }

    // 归还文档
    manager.returnDocument(1, 101);

    return 0;
}