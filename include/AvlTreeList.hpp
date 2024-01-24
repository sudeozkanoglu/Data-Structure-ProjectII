/** 
* @file G201210034 include AvlTreeList.hpp
* @description AvlTreeList işlemleri için AvlTreeList.hpp sınıfı oluşturularak gerekli tanımlamalar yapıldı.
* @course 1. Öğretim C grubu
* @assignment 2.Ödev
* @date 11 Aralık 2023
* @author Sude Özkanoğlu sude.ozkanoglu@ogr.sakarya.edu.tr
*/
#ifndef AVLTREELIST_HPP
#define AVLTREELIST_HPP
#include "AvlTree.hpp"
#include "AvlTreeListNode.hpp"

class AvlTreeList
{
    AvlTreeListNode *head = nullptr;

    public:
        AvlTreeList();
        ~AvlTreeList();
        void insertTree(AvlTree* avlTree);
        AvlTree* returnHead();
        AvlTreeListNode* returnNodeHead();
};

#endif