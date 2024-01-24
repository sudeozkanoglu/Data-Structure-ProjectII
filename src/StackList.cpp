/** 
* @file G201210034 src StackList.cpp
* @description StackListesi işlemleri için StackList sınıfı oluşturularak liste yaratıldı.
* @course 1. Öğretim C grubu
* @assignment 2.Ödev
* @date 11 Aralık 2023
* @author Sude Özkanoğlu sude.ozkanoglu@ogr.sakarya.edu.tr
*/
#include "StackList.hpp"
#include <iostream>
using namespace std;

StackList::StackList()
{
    head = nullptr;
}

StackListNode* StackList::returnHead()
{
    return head;
}

StackListNode* StackList::returnTop()
{
    return top;
}

void StackList::setHead()
{
    head = nullptr;
}

void StackList::insertStack(Stack *stack)
{
    StackListNode *stackListNode = new StackListNode(stack);

    if(head == nullptr)
    {
        head = stackListNode;
        return;
    }

    StackListNode *temp = head;

    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = stackListNode;
    top = head;
}

void StackList::findPositionOfStackNode(Stack* lowestNode)
{
    StackListNode* temp = head;
    StackListNode* prev = nullptr;

    while(temp != nullptr)
    {
        if(temp->stack == lowestNode && temp->stack == head->stack)
        {
            head = head->next;
        }
        else if(temp->next != nullptr && temp->stack == lowestNode)
        {
            //Ortada olma durumu.
            prev = stackCorrectorHelper(lowestNode);;
            prev->next = prev->next->next;
        }
        else if(temp->next == nullptr && temp->stack == lowestNode)
        {
            //Sonda olma durumu.
            prev = stackCorrectorHelper(lowestNode);
            prev->next = nullptr;

        }

        temp = temp->next;
    }
}

StackListNode* StackList::stackCorrectorHelper(Stack* lowestNode)
{
    StackListNode* temp = head;
    StackListNode* found = nullptr;

    while(temp != nullptr)
    {
        if(temp->next->stack == lowestNode)
        {
            found = temp;
            return temp;
        }
        temp = temp->next;
    }
}

StackList::~StackList()
{
    StackListNode *temp = head;

    while(temp != nullptr)
    {
        StackListNode* sil = temp;
        temp = temp->next;
        delete sil;
    }
}