/** 
* @file G201210034 src StackListNode.cpp
* @description Stack Listesi işlemleri için StackListNode sınıfı oluşturularak gerekli atamalar yapıldı.
* @course 1. Öğretim C grubu
* @assignment 2.Ödev
* @date 11 Aralık 2023
* @author Sude Özkanoğlu sude.ozkanoglu@ogr.sakarya.edu.tr
*/
#include "StackListNode.hpp"
#include <iostream>
using namespace std;

StackListNode::StackListNode()
{
    stack = nullptr;
    next = nullptr;
}

StackListNode::StackListNode(Stack*& stack)
{
    this->stack = stack;
    this->next = nullptr;
}

StackListNode::~StackListNode()
{
    StackListNode *temp = next;
    while(temp != nullptr)
    {
        StackListNode* sil = temp;
        temp = temp->next;
        delete sil;
    }
}
