/** 
* @file G201210034 include AvlTreeNode.hpp
* @description AvlTreeNode işlemleri için AvlTreeNode.hpp sınıfı oluşturularak gerekli tanımlamalar yapıldı.
* @course 1. Öğretim C grubu
* @assignment 2.Ödev
* @date 11 Aralık 2023
* @author Sude Özkanoğlu sude.ozkanoglu@ogr.sakarya.edu.tr
*/
#ifndef AVLTREENODE_HPP
#define AVLTREENODE_HPP

class AvlTreeNode
{
    public:
        int sayi;
        int yukseklik;
        AvlTreeNode* sol;
        AvlTreeNode* sag;
        AvlTreeNode();
        ~AvlTreeNode();
        AvlTreeNode(int sayi);
};

#endif