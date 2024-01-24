/** 
* @file G201210034 include StackList.hpp
* @description StackList işlemleri için StackList.hpp sınıfı oluşturularak gerekli tanımlamalar yapıldı.
* @course 1. Öğretim C grubu
* @assignment 2.Ödev
* @date 11 Aralık 2023
* @author Sude Özkanoğlu sude.ozkanoglu@ogr.sakarya.edu.tr
*/
#ifndef STACKLIST_HPP
#define STACKLIST_HPP
#include "StackListNode.hpp"

class StackList
{
    public:
        StackListNode* head = nullptr;
        StackListNode* top = nullptr;
        StackList();
        ~StackList();
        void insertStack(Stack* stack);
        void findPositionOfStackNode(Stack* lowestNode);
        void setHead();
        StackListNode* stackCorrectorHelper(Stack* lowestNode);
        StackListNode* returnHead();
        StackListNode* returnTop();
};

#endif