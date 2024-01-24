/** 
* @file G201210034 src Stack.cpp
* @description Stack işlemleri için Stack sınıfı oluşturularak stackler yaratıldı.
* @course 1. Öğretim C grubu
* @assignment 2.Ödev
* @date 11 Aralık 2023
* @author Sude Özkanoğlu sude.ozkanoglu@ogr.sakarya.edu.tr
*/
#include "Stack.hpp"
#include <iostream>
using namespace std;

Stack::Stack()
{
    head = nullptr;
    toplamDugumDeger = 0;
}

StackNode* Stack::returnHead()
{
    return head;
}

StackNode* Stack::setHead()
{
}

StackNode* Stack::returnTop()
{
    return top;
}

int Stack::returnToplamDugumDeger()
{
    return toplamDugumDeger;
}

void Stack::setNumbers(int num)
{
    this->avlNumber = num;
}

void Stack::insertLeaf(AvlTreeNode* leaf, int num)
{
    if(leaf->sayi == num)
    {
        this->toplamDugumDeger = calculateToplamDugumDeger(leaf,num);
        return;
    }
    if(leaf->sol != nullptr || leaf->sag != nullptr)
    {
        this->toplamDugumDeger = calculateToplamDugumDeger(leaf,num);
        return;
    }
    //cout << "Insert: " << leaf->sayi << endl;
    StackNode *stackNode = new StackNode(leaf);

    if(head == nullptr)
    {
        head = stackNode;
        return;
    }

    StackNode *temp = head;

    /* while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = stackNode; */

    stackNode->next = temp;
    head = stackNode;
    top = stackNode;
}

void Stack::postOrderInsertion(AvlTreeNode* currentTree, int num)
{
    if(currentTree != nullptr)
    {
        postOrderInsertion(currentTree->sol, num);
        postOrderInsertion(currentTree->sag, num);
        return insertLeaf(currentTree, num);
    }
}

StackNode* Stack::findNewHeadForUnique()
{
    StackNode* temp = top;

    if(temp->next != nullptr)
    {
        //head = head->next;
        top = top->next;
        return top;
    }
}

int Stack::calculateToplamDugumDeger(AvlTreeNode* currentTree, int num)
{
    if(currentTree != nullptr)
    {
        /* calculateToplamDugumDeger(currentTree->sol, num);
        calculateToplamDugumDeger(currentTree->sag, num); */
        return calculateHelper(currentTree, num);
    }
}

void Stack::setAsciiValue(char ascii)
{
    this->asciiValue = ascii;
}

char Stack::returnAsciiValue()
{
    return asciiValue;
}

int Stack::calculateHelper(AvlTreeNode* leaf, int num)
{
    if(leaf->sayi == num)
    {
        toplamDugumDeger = toplamDugumDeger + leaf->sayi;
    }
    else if(leaf->sol != nullptr || leaf->sag != nullptr)
    {
        toplamDugumDeger = toplamDugumDeger + leaf->sayi;
    }

    return toplamDugumDeger;
    /* int ascii = AVLToplamDugumDeger%(26) + 65; */
}

bool Stack::configureStack(Stack* lowestNode)
{
    StackNode* temp = top;

    //Find Stack
    while(temp != nullptr)
    {
        if(temp->leaf->sayi == lowestNode->returnTop()->leaf->sayi && top->next != nullptr)
        {
            //head = head->next;
            top = top->next;
            return true;
        }
        else if(temp->leaf->sayi == lowestNode->returnTop()->leaf->sayi && top->next == nullptr)
        {
            return false;
        }
        temp = temp->next;
    }
}

Stack::~Stack()
{
    StackNode* temp = top;
    while(top != nullptr)
    {
        StackNode* sil = top;
        top = top->next;
        delete sil;
    }
}



