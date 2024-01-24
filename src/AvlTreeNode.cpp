/** 
* @file G201210034 src AvlTreeNode.cpp
* @description AvlTree işlemleri için AvlTreeNode sınıfı oluşturularak avl ağaçları için atamalar yapıldı.
* @course 1. Öğretim C grubu
* @assignment 2.Ödev
* @date 11 Aralık 2023
* @author Sude Özkanoğlu sude.ozkanoglu@ogr.sakarya.edu.tr
*/
#include "AvlTreeNode.hpp"
#include <iostream>
using namespace std;

AvlTreeNode::AvlTreeNode()
{
	sayi = 0;
	sag = NULL;
	sol = NULL;
}

AvlTreeNode::AvlTreeNode(int sayi)
{
	this->sayi = sayi;
	this->sag = NULL;
	this->sol = NULL;
    this->yukseklik = 1;
}

AvlTreeNode::~AvlTreeNode()
{
    AvlTreeNode* temp = sag;
    while(temp != nullptr)
    {
        AvlTreeNode* sil = temp->sag; 
        AvlTreeNode* sil2 = temp->sol;
        temp = temp->sag;
        delete sil,sil2;

    }

	temp = sol;
	while(temp != nullptr)
    {
        AvlTreeNode* sil = temp->sag; 
        AvlTreeNode* sil2 = temp->sol;
        temp=temp->sol;
        delete sil,sil2;
    }
}