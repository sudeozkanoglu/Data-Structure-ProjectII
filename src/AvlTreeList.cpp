/** 
* @file G201210034 src AvlTreeList.cpp
* @description AvlTreeList işlemleri için AvlTreeList sınıfı oluşturularak liste yaratıldı.
* @course 1. Öğretim C grubu
* @assignment 2.Ödev
* @date 11 Aralık 2023
* @author Sude Özkanoğlu sude.ozkanoglu@ogr.sakarya.edu.tr
*/
#include "AvlTreeList.hpp"
#include <iostream>
using namespace std;

AvlTreeList::AvlTreeList()
{
    head = nullptr;
}

AvlTree* AvlTreeList::returnHead()
{
    return head->avlTree;
}

AvlTreeListNode* AvlTreeList::returnNodeHead()
{
    return head;
}

void AvlTreeList::insertTree(AvlTree *avlTree)
{
    AvlTreeListNode *avlTreeList = new AvlTreeListNode(avlTree);

    if(head == nullptr)
    {
        head = avlTreeList;
        return;
    }

    AvlTreeListNode *temp = head;

    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = avlTreeList;
}

AvlTreeList::~AvlTreeList()
{
    AvlTreeListNode *temp = head;

    while(temp != nullptr)
    {
        AvlTreeListNode* sil = temp;
        temp = temp->next;
        delete sil;
    }
}