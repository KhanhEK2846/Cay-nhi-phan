#pragma once
#include<iostream>
#include<fstream>
#include<time.h>
#include<string.h>
#include<cstring>
#include<ctime>
#include<stdio.h>
#pragma warning(disable:4996)
using namespace std;

struct node
{
	int info;
	struct node* pLeft;
	struct node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;

void Init(TREE& t);
int IsEmpty(TREE t);
NODE* GetNode(int x);
int InsertNode(TREE& t, int x);
void Xuat(TREE t);
void CreFile(const char* File);
void CreFile(const char* fi, TREE t);
int DemNode(TREE t);
int DemHaiCon(TREE t);
int DemLa(TREE t);
NODE* TimKiem(TREE t, int x);
int ChieuCao(TREE t);
void RemoveAll(TREE& t);
void Input(TREE& t);
int Input(const char* fn, TREE& t);
void CreFileF(const char* FileName, TREE t);
int BSTDelete(TREE& t, int x);
int Tong(TREE t);
double TB(TREE t);
void XuatTang(TREE t, int k=0);
void InputF(const char* fi, TREE& t);

void CreFiTree(const char* fi, TREE t);