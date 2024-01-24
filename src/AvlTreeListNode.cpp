/** 
* @file G201210034 src AvlTreeListNode.cpp
* @description AvlTreeList işlemleri için AvlTreeListNode sınıfı oluşturularak liste elemanları yaratıldı.
* @course 1. Öğretim C grubu
* @assignment 2.Ödev
* @date 11 Aralık 2023
* @author Sude Özkanoğlu sude.ozkanoglu@ogr.sakarya.edu.tr
*/
#include "AvlTreeListNode.hpp"
#include "AvlTreeList.hpp"
#include <iostream>
using namespace std;

AvlTreeListNode::AvlTreeListNode()
{
    next = NULL;
}

AvlTreeListNode::AvlTreeListNode(AvlTree*& avlTree)
{
    this->avlTree = avlTree;
    this->next = NULL;
}

AvlTreeListNode::~AvlTreeListNode()
{
    AvlTreeListNode *temp = next;
    while(temp != nullptr)
    {
        AvlTreeListNode* sil = temp;
        temp = temp->next;
        delete sil;
    }
}



