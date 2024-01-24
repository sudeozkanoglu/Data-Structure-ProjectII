/** 
* @file G201210034 src AvlTree.cpp
* @description AvlTree işlemleri için AvlTree sınıfı oluşturularak avl ağaçları yaratıldı.
* @course 1. Öğretim C grubu
* @assignment 2.Ödev
* @date 11 Aralık 2023
* @author Sude Özkanoğlu sude.ozkanoglu@ogr.sakarya.edu.tr
*/
#include "AvlTree.hpp"
#include <iostream>
using namespace std;

AvlTree::AvlTree()
{
    avlToplamDugumDeger = 0;
}
AvlTreeNode* AvlTree::returnHead()
{
    return node;
}

int AvlTree::returnToplamDugumDeger()
{
    return avlToplamDugumDeger;
}

char AvlTree::returnAsciiValue()
{
    return asciiValue;
}

void AvlTree::createDugum(int num)
{
    node = insertDugum(num, node);
}

AvlTreeNode* AvlTree::insertDugum(int num, AvlTreeNode* avlNode)
{
    if(avlNode == nullptr)
    {
        return new AvlTreeNode(num);
    }
    else if(avlNode->sayi < num)
    {
        avlNode->sag = insertDugum(num, avlNode->sag);

        int rightHeight = calculateHeight(avlNode->sag);
        int leftHeight = calculateHeight(avlNode->sol);
        int condition = rightHeight - leftHeight;

        if(condition > 1)
        {
            if(avlNode->sag->sayi < num)
            {
                avlNode = leftRotate(avlNode);
            }
            else
            {
                avlNode->sag = rightRotate(avlNode->sag);
                avlNode = leftRotate(avlNode);
            }
        }
    }
    else if(avlNode->sayi > num)
    {
        avlNode->sol = insertDugum(num, avlNode->sol);

        int rightHeight = calculateHeight(avlNode->sag);
        int leftHeight = calculateHeight(avlNode->sol);
        int condition = leftHeight - rightHeight;

        if(condition > 1)
        {
            if(avlNode->sol->sayi > num)
            {
                avlNode = rightRotate(avlNode);
            }
            else
            {
                avlNode->sol = leftRotate(avlNode->sol);
                avlNode = rightRotate(avlNode);
            }
        }
    }
    return avlNode;
}

AvlTreeNode* AvlTree::rightRotate(AvlTreeNode* currentNode)
{
    AvlTreeNode* avlNode = currentNode->sol;
    currentNode->sol = avlNode->sag;
    avlNode->sag = currentNode;

    return avlNode;
}

void AvlTree::findAsciiValue()
{
    int ascii = avlToplamDugumDeger%(90-65+1) + 65;
    char realValue = ascii;

    this->asciiValue = realValue;
}

AvlTreeNode* AvlTree::leftRotate(AvlTreeNode* currentNode)
{
    AvlTreeNode* avlNode = currentNode->sag;
    currentNode->sag = avlNode->sol;
    avlNode->sol = currentNode;

    return avlNode;

}

void AvlTree::postOrderTest(AvlTreeNode* currentTree)
{
    if(currentTree != nullptr)
    {
        postOrderTest(currentTree->sol);
        postOrderTest(currentTree->sag);
        cout << currentTree->sayi << " ";
    }
}

int AvlTree::calculateHeight(AvlTreeNode* currentNode) 
{ 
	int height = 0;

    if(currentNode != nullptr)
    {
        int leftHeight = calculateHeight(currentNode->sol);
        int rightHeight = calculateHeight(currentNode->sag);

        if(leftHeight > rightHeight)
        {
            height = leftHeight + 1;
        }
        else if(rightHeight <= leftHeight)
        {
            height = rightHeight + 1;
        }

        return 1 + max(calculateHeight(currentNode->sol), calculateHeight(currentNode->sag));
    }
    
    return -1;
}

AvlTreeNode* AvlTree::postOrderStackInsertion(AvlTreeNode* currentNode)
{
    
    if(currentNode != nullptr)
    {
        postOrderStackInsertion(currentNode->sol);
        postOrderStackInsertion(currentNode->sag);
        return currentNode;
    }
}

bool AvlTree::traversalTree(int num, AvlTreeNode* tempHead)
{
    AvlTreeNode *temp = nullptr;
    if(tempHead == nullptr)
    {   
        temp = node;
    }
    else
    {
        temp = tempHead;
    }

    if(temp == nullptr)
    {
        return true;
    }

    if(num < temp->sayi)
    {
        if(temp->sol != nullptr && num != temp->sayi)
        {
            temp = temp->sol;
            traversalTree(num, temp);
        }
        else if(num == temp->sayi)
        {
            return false;
        }
        else if(num != temp->sayi && temp->sol == nullptr)
        {
            return true;
        }
    }
    else if(num > temp->sayi)
    {
        if(temp->sag != nullptr)
        {
            temp = temp->sag;
            traversalTree(num, temp);
        }
        else if(num == temp->sayi)
        {
            return false;
        }
        else if(num != temp->sayi && temp->sag == nullptr)
        {
            return true;
        }
    }
    else if(num == temp->sayi)
    {
        return false;
    }
}

void AvlTree::deleteTree(AvlTreeNode* currentTree)
{
    if(currentTree != nullptr)
    {
        deleteTree(currentTree->sol);
        deleteTree(currentTree->sag);
    }
}

AvlTree::~AvlTree()
{
    AvlTreeNode* temp = node;
    while(temp != nullptr)
    {
        AvlTreeNode* sil = temp;
        temp = temp->sol;
        delete sil;
    }
    
    temp = node;
    while(temp != nullptr)
    {
        AvlTreeNode* sil = temp;
        temp = temp->sag;
        delete sil;
    }
}
