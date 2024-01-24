/** 
* @file G201210034 src StackNode.cpp
* @description Stack işlemleri için StackNode sınıfı oluşturularak gerekli atamalar yapıldı.
* @course 1. Öğretim C grubu
* @assignment 2.Ödev
* @date 11 Aralık 2023
* @author Sude Özkanoğlu sude.ozkanoglu@ogr.sakarya.edu.tr
*/
#include "StackNode.hpp"
#include <iostream>
using namespace std;

StackNode::StackNode()
{
    leaf = nullptr;
    next = nullptr;
}

void StackNode::setNumbers(int num)
{
    this->avlNumber = num;
}

StackNode::StackNode(AvlTreeNode*& leaf)
{
    this->leaf = leaf;
    this->next = nullptr;
}

StackNode::~StackNode()
{
    StackNode* temp = next;
    while(temp != nullptr)
    {
        StackNode* sil = temp;
        temp = temp->next;
        delete sil;
    }
}
