/** 
* @file G201210034 include AvlTreeListNode.hpp
* @description AvlTreeListNode işlemleri için AvlTreeListNode.hpp sınıfı oluşturularak gerekli tanımlamalar yapıldı.
* @course 1. Öğretim C grubu
* @assignment 2.Ödev
* @date 11 Aralık 2023
* @author Sude Özkanoğlu sude.ozkanoglu@ogr.sakarya.edu.tr
*/
#ifndef AVLTREELISTNODE_HPP
#define AVLTREELISTNODE_HPP
#include "AvlTree.hpp"

class AvlTreeListNode
{
    public:
        AvlTree *avlTree;
        AvlTreeListNode *next;
        AvlTreeListNode(AvlTree*& avlTree);
        AvlTreeListNode();
        ~AvlTreeListNode();

};

#endif