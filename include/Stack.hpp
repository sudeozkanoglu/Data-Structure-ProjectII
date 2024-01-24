/** 
* @file G201210034 include Stack.hpp
* @description Stack işlemleri için Stack.hpp sınıfı oluşturularak gerekli tanımlamalar yapıldı.
* @course 1. Öğretim C grubu
* @assignment 2.Ödev
* @date 11 Aralık 2023
* @author Sude Özkanoğlu sude.ozkanoglu@ogr.sakarya.edu.tr
*/
#ifndef STACK_HPP
#define STACK_HPP
#include "AvlTree.hpp"
#include "StackNode.hpp"

class Stack
{
    public:
        int toplamDugumDeger;
        int avlNumber = 0;
        int asciiValue = 0;
        Stack();
        ~Stack();
        StackNode *head;
        StackNode *top;
        StackNode* returnHead();
        StackNode* returnTop();
        StackNode* setHead();
        StackNode* findNewHeadForUnique();
        void setNumbers(int num);
        void setAsciiValue(char value);
        void insertLeaf(AvlTreeNode* leaf, int num);
        void postOrderInsertion(AvlTreeNode* currentTree, int num);
        int calculateToplamDugumDeger(AvlTreeNode* currentTree, int num);
        int calculateHelper(AvlTreeNode* leaf, int num);
        int returnToplamDugumDeger();
        char returnAsciiValue();
        bool configureStack(Stack* lowestNode);
};

#endif