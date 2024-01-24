/** 
* @file G201210034 include AvlTree.hpp
* @description AvlTree işlemleri için AvlTree.hpp sınıfı oluşturularak gerekli tanımlamalar yapıldı.
* @course 1. Öğretim C grubu
* @assignment 2.Ödev
* @date 11 Aralık 2023
* @author Sude Özkanoğlu sude.ozkanoglu@ogr.sakarya.edu.tr
*/
#ifndef AVLTREE_HPP
#define AVLTREE_HPP
#include "AvlTreeNode.hpp"

class AvlTree
{
    public:
    
        int avlToplamDugumDeger;
        char asciiValue;
        AvlTree();
        ~AvlTree();
        void createDugum(int num);
        void controlNum(int num);
        void findAsciiValue();
        void deleteTree(AvlTreeNode *t);
        void postOrderTest(AvlTreeNode *t);
        int calculateHeight(AvlTreeNode* currentNode);
        int returnToplamDugumDeger();
        bool traversalTree(int num, AvlTreeNode* currentNode);
        char returnAsciiValue();
        AvlTreeNode* insertDugum(int num, AvlTreeNode* currentNode);
        AvlTreeNode* rightRotate(AvlTreeNode* currentNode);
        AvlTreeNode* leftRotate(AvlTreeNode* currentNode);
        AvlTreeNode* returnHead();
        AvlTreeNode* postOrderStackInsertion(AvlTreeNode* currentTree);
        
    private:
        AvlTreeNode* node = nullptr;
};

#endif 