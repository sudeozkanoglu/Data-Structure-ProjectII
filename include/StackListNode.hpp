/** 
* @file G201210034 include StackListNode.hpp
* @description StackListNode işlemleri için StackListNode.hpp sınıfı oluşturularak gerekli tanımlamalar yapıldı.
* @course 1. Öğretim C grubu
* @assignment 2.Ödev
* @date 11 Aralık 2023
* @author Sude Özkanoğlu sude.ozkanoglu@ogr.sakarya.edu.tr
*/
#ifndef STACKLISTNODE_HPP
#define STACKLISTNODE_HPP
#include "Stack.hpp"

class StackListNode
{
    public:
        Stack *stack;
        StackListNode *next;
        StackListNode(Stack*& stack);
        StackListNode();
        ~StackListNode();
};

#endif