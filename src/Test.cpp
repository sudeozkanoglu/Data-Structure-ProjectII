/** 
* @file G201210034 src Test.cpp
* @description Test işlemleri için dosyadan okuma yapıldı ve ekrana yazma işlemi gerçekleştirildi.
* @course 1. Öğretim C grubu
* @assignment 2.Ödev
* @date 11 Aralık 2023
* @author Sude Özkanoğlu sude.ozkanoglu@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include "AvlTreeNode.hpp" 
#include "AvlTree.hpp"
#include "AvlTreeList.hpp"
#include "Stack.hpp"
#include "StackNode.hpp"
#include "StackList.hpp"
using namespace std;

int main()
{
    string line,val;
    ifstream newfile;
    int data = 0;
    int count = 0;
    AvlTreeList *avlTreeList = new AvlTreeList();
    StackList *stackList = new StackList();
    newfile.open("Veri.txt");
    if(!newfile.is_open())
    {
        cout << "Unable to open the file." <<endl;
        return 0;
    }
    system("cls");
    while(getline(newfile,line))
    {
        AvlTree *avlTree = new AvlTree();
        istringstream resultedLine(line);
        while(getline(resultedLine, val, ' '))
        {
            data = stol(val, nullptr);
            bool cond = avlTree->traversalTree(data, nullptr);
            if(cond)
            {
                avlTree->createDugum(data);
            }
        }
        count++;
        avlTreeList->insertTree(avlTree);
    }
    //----------------------------------------------------//
    //OLUSAN AGACLARIN STACK ICERISINE INSERTION YAPILMASI//
    //----------------------------------------------------//

    AvlTreeListNode* avlTreeListHead = avlTreeList->returnNodeHead();
    int x = 1;
    while(avlTreeListHead != nullptr)
    {
        Stack *stack = new Stack();
        AvlTree* avlTreeInList = avlTreeListHead->avlTree;  
        int num = avlTreeInList->returnHead()->sayi; 
        stack->postOrderInsertion(avlTreeInList->returnHead(), num);
        stackList->insertStack(stack);
        stack->avlNumber = x;
        avlTreeListHead = avlTreeListHead->next;
        x++;
    }

    
    //----------------------------------------------------------//
    //AVL TOPLAM DUGUM DEGER DEGİSKENİNİN HESAPLANMASI ISLEMLERİ//
    //          AVL ASCII VALUE HESAPLANMASI ISLEMLERİ          //
    //----------------------------------------------------------//

    StackListNode* stackListHead = stackList->returnHead();
    avlTreeListHead = avlTreeList->returnNodeHead();
    while(avlTreeListHead != nullptr)
    {
        AvlTree* avlTreeInList = avlTreeListHead->avlTree;  
        int num = avlTreeInList->returnHead()->sayi;

        avlTreeInList->avlToplamDugumDeger = stackListHead->stack->returnToplamDugumDeger();
        avlTreeInList->findAsciiValue();
        stackListHead->stack->setAsciiValue(avlTreeInList->returnAsciiValue());
        stackListHead = stackListHead->next;
        avlTreeListHead = avlTreeListHead->next;
    }

    //----------------------------------------------------------//
    //--------------EKRANA BASMA İŞLEMLERİ----------------------//  
    //----------------------------------------------------------//
    

    StackListNode* stackListNodes = stackList->returnHead();
    StackListNode* tempNode = stackList->returnHead();
    StackListNode* mainHead = stackList->returnHead();
    StackListNode* lowest = stackList->returnHead();
    StackListNode* biggest = stackList->returnHead();
    Stack* lastOne = nullptr;
    int finalNum = 0;
    int finalValue = 0;
    bool changeDirection = true;
    bool deleted = false;
    bool stackNotFinished;
    int stackTopValue = 0;

    //---------------------------//
    //İlk Durum
    stackListHead = stackList->returnHead();
    avlTreeListHead = avlTreeList->returnNodeHead();
    while(avlTreeListHead != nullptr)
    {
        AvlTree* avlTreeInList = avlTreeListHead->avlTree;
        cout << avlTreeInList->returnAsciiValue();
        avlTreeListHead = avlTreeListHead->next;
    }
    //----------------------------//
    //      STACK ISLEMLERI       //
    while(finalNum != 1 /* stackList->returnHead() != nullptr */) 
    {   
        if(stackListNodes->next == nullptr)
        {
            stackListNodes = stackList->returnHead();
        }

        lowest = stackList->returnHead();
        biggest = stackList->returnHead();
        tempNode = stackList->returnHead();
        finalValue = 0;

        if(deleted)
        {
            stackListHead = stackList->returnHead();
            avlTreeListHead = avlTreeList->returnNodeHead();

            while(tempNode != nullptr)
            {
                cout << tempNode->stack->returnAsciiValue();
                tempNode = tempNode->next;
            }
            system("cls");

            tempNode = stackList->returnHead();
            while(tempNode != nullptr)
            {
                tempNode->stack->top = tempNode->stack->returnHead();
                tempNode = tempNode->next;
                changeDirection=true;
            }
            tempNode = stackList->returnHead();
        }
        
        while(tempNode != nullptr)
        {
            stackTopValue = tempNode->stack->returnTop()->leaf->sayi;
            
            if(tempNode->next == nullptr && tempNode == stackList->returnHead()/*prev de null olmalı.*/)
            {
                StackNode* final = tempNode->stack->findNewHeadForUnique();
                finalNum++;
            }
            
            if(tempNode->stack->returnTop()->leaf->sayi < lowest->stack->returnTop()->leaf->sayi)
            {
                lowest = tempNode;
            }

            if(tempNode->stack->returnTop()->leaf->sayi > biggest->stack->returnTop()->leaf->sayi)
            {
                biggest = tempNode;
            }
            tempNode = tempNode->next;
        }
        
        if(changeDirection)
        {
            //cout << "Silinecek:::" << lowest->stack->returnTop()->leaf->sayi << endl;

            stackNotFinished = lowest->stack->configureStack(lowest->stack);
            if(!stackNotFinished)
            {
                // Stack bitti demektir.
                //delete lowest->stack;
                stackList->findPositionOfStackNode(lowest->stack);
                lastOne = stackListNodes->stack;

                //Deleting avl tree and stack.
                lowest->stack->~Stack();
                lowest->stack->returnHead()->leaf->~AvlTreeNode();
                deleted = true;
            }
            else
            {
                deleted = false;
            }
            changeDirection = false;
        }
        else
        {
            stackNotFinished = biggest->stack->configureStack(biggest->stack);
            if(!stackNotFinished)
            {
                // Stack bitti demektir.
                stackList->findPositionOfStackNode(biggest->stack);
                lastOne = stackListNodes->stack;

                biggest->stack->~Stack();
                biggest->stack->returnHead()->leaf->~AvlTreeNode();
                deleted = true;
            }
            else
            {
                deleted = false;
            }
            changeDirection = true;
        }
    
        if(stackListNodes->next != nullptr)
        {
            stackListNodes = stackListNodes->next;
        }
    }

    avlTreeListHead = avlTreeList->returnNodeHead();
    AvlTree* avlTreeInList = avlTreeListHead->avlTree;  
    avlTreeInList->avlToplamDugumDeger = lastOne->returnToplamDugumDeger();
    avlTreeInList->findAsciiValue();
   
    // PRINT //
    cout << "=============================="<< endl;
    cout << "|                            |"<< endl;
    cout << "|                            |"<< endl;
    cout << "|     Son Karakter: " << avlTreeInList->returnAsciiValue() << "        |"<<endl;
    cout << "|     AVL No      : " << lastOne->avlNumber << "      |"<<endl;
    cout << "|                            |"<< endl;
    cout << "|                            |"<< endl;
    cout << "=============================="<< endl;

    stackList->~StackList();
    stackList->returnTop()->~StackListNode();
}