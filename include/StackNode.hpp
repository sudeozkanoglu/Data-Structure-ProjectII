/** 
* @file G201210034 include StackNode.hpp
* @description StackNode işlemleri için StackNode.hpp sınıfı oluşturularak gerekli tanımlamalar yapıldı.
* @course 1. Öğretim C grubu
* @assignment 2.Ödev
* @date 11 Aralık 2023
* @author Sude Özkanoğlu sude.ozkanoglu@ogr.sakarya.edu.tr
*/
#ifndef STACKNODE_HPP
#define STACKNODE_HPP
#include "AvlTreeNode.hpp"

class StackNode
{
    public:
        AvlTreeNode *leaf;
        StackNode *next;
        int avlNumber = 0;
        StackNode();
        ~StackNode();
        StackNode(AvlTreeNode*& leaf);
        void setNumbers(int num);
};

#endif