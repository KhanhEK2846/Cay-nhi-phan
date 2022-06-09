#include "BinaryTree.h"

void Init(TREE& t)
{
	t = NULL;
}

int IsEmpty(TREE t)
{
	if (t == NULL)
		return 1;
	return 0;
}

NODE* GetNode(int x)
{
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}

int InsertNode(TREE& t, int x)
{
	if (t != NULL)
	{
		if (t->info < x)
			return InsertNode(t->pRight, x);
		if (t->info > x)
			return InsertNode(t->pLeft, x);
		return 0;
	}
	t = GetNode(x);
	if (t == NULL)
		return -1;
	return 0;

}

void Xuat(TREE t)
{
	if (!t)
		return;
	Xuat(t->pLeft);
	cout << t->info << " ";
	Xuat(t->pRight);
}



void CreFile(const char* File)
{
	FILE* f = fopen(File, "w+");
	fclose(f);
}

void Xuat(FILE* fp, TREE t)
{
	if (!t)
		return;
	Xuat(fp, t->pLeft);
	fwrite(&t->info, sizeof(t->info), 1, fp);
	Xuat(fp, t->pRight);
}

void CreFile(const char* fi, TREE t)
{
	FILE* fp = fopen(fi, "w+");
	Xuat(fp, t);
	fclose(fp);
}

int DemNode(TREE t)
{
	if (t == NULL)
		return 0;
	int a = DemNode(t->pLeft);
	int b = DemNode(t->pRight);
	return(a + b + 1);
}

int DemHaiCon(TREE t)
{
	if (!t)
		return 0;
	int a = DemHaiCon(t->pLeft);
	int b = DemHaiCon(t->pRight);
	if (t->pLeft && t->pRight)
		return (a + b + 1);
	return (a + b);
}

int DemLa(TREE t)
{
	if (!t)
		return 0;
	int a = DemLa(t->pLeft);
	int b = DemLa(t->pRight);
	if (!t->pLeft && !t->pRight)
		return (a + b + 1);
	return(a + b);
}

NODE* TimKiem(TREE t, int x)
{
	if (!t)
		return NULL;
	if (t->info == x)
		return t;
	if (t->info < x)
		return TimKiem(t->pRight, x);
	return TimKiem(t->pLeft, x);
}

int ChieuCao(TREE t)
{
	if (!t)
		return 0;
	int a = ChieuCao(t->pLeft);
	int b = ChieuCao(t->pRight);
	if (a > b)
		return a + 1;
	return b + 1;
}

void RemoveAll(TREE& t)
{
	if (!t)
		return;
	RemoveAll(t->pLeft);
	RemoveAll(t->pRight);
	delete t;
}

void Input(TREE& t)
{
	srand((int)time(0));
	Init(t);
	for (int i = 0; i < 20; ++i)
	{
		int r = rand() % 999 + 1;
		InsertNode(t, r);
	}
}

int Input(const char* fn, TREE& t)
{
	FILE* fp = fopen(fn, "r");
	if (fp == NULL)
		return 0;
	int tmp;
	Init(t);
	while (fread(&tmp,sizeof(int),1, fp) == 1)
	{
		InsertNode(t, tmp);
	}
	fclose(fp);
	return 1;
}



void XuatF(FILE* fp, TREE t)
{
	if (!t)
		return;
	XuatF(fp, t->pLeft);
	fprintf(fp, "%d ", t->info);
	XuatF(fp, t->pRight);
}

void CreFileF(const char* FileName, TREE t)
{
	FILE* fp = fopen(FileName, "w+");
	fprintf(fp, "%d\n", DemNode(t));
	XuatF(fp, t);
	fclose(fp);
}


NODE* SearchStandFor(TREE& p, TREE& q)
{
	if (p->pRight)
		return SearchStandFor(p->pRight, q);
	/*
	if(p->pLeft)
		return SearchStandFor(p->pLeft,q);
	*/
	NODE* tmp = q;
	q->info = p->info;
	p = p->pLeft;
	//p=p->pRight;
	return tmp;
}

void _Delete(TREE& t)
{
	NODE* tmp = t;
	if (!t->pLeft && !t->pRight)
	{
		t = NULL;
		delete tmp;
		return;
	}
	if (t->pLeft && !t->pRight)
	{
		t = t->pLeft;
		delete tmp;
		return;
	}
	if (!t->pLeft && t->pRight)
	{
		t = t->pRight;
		delete tmp;
		return;
	}
	tmp = SearchStandFor(t->pLeft, t);
	//tmp = SearchStandFor(t->pRight, t);
	delete tmp;
}

int BSTDelete(TREE& t, int x)
{
	if (!t)
		return 0;
	if (t->info > x)
		return BSTDelete(t->pLeft, x);
	if (t->info < x)
		return BSTDelete(t->pRight, x);
	_Delete(t);
	return 1;
}

int Tong(TREE t)
{
	if (!t)
		return 0;
	int a = Tong(t->pLeft);
	int b = Tong(t->pRight);
	return (a + b + t->info);
}

double TB(TREE t)
{
	return (double)Tong(t) / DemNode(t);
}

void XuatTang(TREE t,int k)
{
	if (!t)
		return;
	if (k == 0)
	{
		cout << t->info << " ";
		return;
	}
	XuatTang(t->pLeft, k - 1);
	XuatTang(t->pRight, k - 1);
}

void InputF(const char* fi, TREE& t)
{
	int tmp;
	FILE* fp = fopen(fi, "r");
	if (fp == NULL)
		return;
	Init(t);
	int n;
	tmp=fscanf(fp, "%d\n", &n);
	for (int i = 0; i < n; ++i)
	{
		int m;
		tmp=fscanf(fp, "%d ", &m);
		InsertNode(t, m);
	}
	fclose(fp);
}

void XuatTang(FILE* fp, TREE t, int k)
{
	if (!t)
		return;
	if (k == 0)
	{
		fprintf(fp, "%d ", t->info);
		return;
	}
	XuatTang(fp, t->pLeft, k - 1);
	XuatTang(fp, t->pRight, k - 1);
}

void CreFiTree(const char* fi, TREE t)
{
	FILE* fp = fopen(fi, "w+");
	for (int i = 0; i < ChieuCao(t); ++i)
	{
		XuatTang(fp, t, i);
		fprintf(fp, "\n");
	}
	fclose(fp);
}


