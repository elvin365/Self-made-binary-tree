#include<conio.h>
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<time.h>
struct BinTree
{
	int data_field=0;
	BinTree* left;
	BinTree* right;
};
BinTree* Head = NULL;


BinTree* CreateNewNode(int data)
{
	BinTree* NewNode = NULL;
	NewNode = (BinTree*)malloc(sizeof(BinTree));
	if (NewNode == NULL)
		return NULL;
	NewNode->data_field = data;
	NewNode->left = NULL;
	NewNode->right = NULL;
	return NewNode;
}


void add(int data)
{
	BinTree* NewNode = CreateNewNode(data);

	if (Head == NULL)
	{
		Head = NewNode;
		return;
	}
	BinTree* pCur = Head;

	while (true)
	{
		if (pCur->data_field > data)
		{
			if (pCur->left == NULL)
			{
				pCur->left = NewNode;
				break;
			}
			pCur = pCur->left;
		}
		else
		{
			if (pCur->right == NULL)
			{
				pCur->right = NewNode;
				break;
			}
			pCur = pCur->right;
		}
	}
}
BinTree* search(int data)
{
	BinTree* pCur = Head;
	while (pCur!=NULL)
	{
		if (pCur->data_field == data)
		{
			return pCur;
		}
		else
		{
			if (pCur->data_field > data)
			{
				pCur = pCur->left;
			}
			else
				pCur = pCur->right;
		}
	}
	return NULL;
}
BinTree* findparent(int data)
{
	BinTree* pCur = Head;
	BinTree* pCur5 = NULL;
	BinTree* pCur6 = NULL;
	while (pCur != NULL)
	{
		
			if (pCur->data_field > data)
			{
				pCur5 = pCur;
				pCur = pCur->left;
				if (pCur != NULL && pCur->data_field == data)
				{
					return pCur5;
				}

			}
			else
			{
				pCur6 = pCur;
				pCur = pCur->right;
				if (pCur != NULL && pCur->data_field == data)
				{
					return pCur6;
				}
			}
		
	}
	return NULL;
	
}
void Delete(BinTree* deletable)
{
	BinTree* pCur = Head;
	BinTree* ParentOfpCur8 = NULL;
	
		if (deletable->left == NULL && deletable->right == NULL)
		{
			BinTree* pCur3 = findparent(deletable->data_field);
			if (pCur3 == NULL) {
				free(deletable);
				return;
			}
			if (pCur3 != NULL && pCur3->left==deletable)
			{
				pCur3->left = NULL;
				free(deletable);
				return;
			}
			if (pCur3 != NULL && pCur3->right == deletable)
			{
				pCur3->right = NULL;
				free(deletable);
				return;
			}

		}
		if (deletable->left == NULL && deletable->right != NULL)
		{
			BinTree* pCur4 = findparent(deletable->data_field);
			if (pCur4 == NULL)
			{
				Head = deletable->right;
				deletable->right = NULL;
				free(deletable);
				return;
			}
			if (pCur4 != NULL && pCur4->right==deletable)
			{
				
				pCur4->right = deletable->right;
				deletable->right = NULL;
				free(deletable);
				return;
			}
			if (pCur4 != NULL && pCur4->left == deletable)
			{
				pCur4->left = deletable->right;
				deletable->right = NULL;
				free(deletable);
				return;
			}
		}
		if (deletable->left != NULL && deletable->right == NULL)
		{
			BinTree* pCur5 = findparent(deletable->data_field);
			if (pCur5 == NULL)
			{
				Head = deletable->left;
				deletable->left = NULL;
				free(deletable);
				return;
			}
			if (pCur5 != NULL && pCur5->right==deletable)
			{
				pCur5->right = deletable->left;
				deletable->left = NULL;
				free(deletable);
				return;
			}
			if (pCur5 != NULL && pCur5->left == deletable)
			{
				pCur5->left = deletable->left;
				deletable->left = NULL;
				free(deletable);
				return;
			}

		}
		BinTree* pCur7 = findparent(deletable->data_field);
		if (deletable->left != NULL && deletable->right != NULL)
		{
			if (pCur7 == NULL)
			{
				BinTree* pCur8 = pCur->right;
				while (pCur8->left != NULL)
				{
					pCur8 = pCur8->left;
				}
				if (pCur8->right != NULL)
				{
					ParentOfpCur8 = findparent(pCur8->data_field);
					ParentOfpCur8->left = pCur8->right;
					pCur8->right = NULL;
				}
				pCur8->left = pCur->left;
				pCur8->right = pCur->right;
				Head = pCur8;
				free(deletable);
				return;
			}
			if (pCur7 != NULL && pCur7->left == deletable)
			{
				
				BinTree* pCur8 =search(Head->data_field);
				pCur8 = search(deletable->right->data_field);
				if (pCur8->left == NULL)
				{
					BinTree* pCur9 = findparent(deletable->data_field);
					if (pCur9->left == deletable)
					{
						pCur8 = deletable->right;
						pCur9->left = pCur8;
						pCur8->left = deletable->left;
						free(deletable);
						return;
					}
					if (pCur9->right == deletable)
					{
						pCur8 = deletable->right;
						pCur9->right = pCur8;
						pCur8->left = deletable->left;
						free(deletable);
						return;
					}
				}
				while (pCur8->left != NULL)
				{
					pCur8 = pCur8->left;
				}
				if (pCur8->right != NULL)
				{
					BinTree* ParentOfpCur8 = findparent(pCur8->data_field);
					ParentOfpCur8->left = pCur8->right;
					pCur8->right = NULL; 
				}
				else
				{
					BinTree* ParentOfpCur8 = findparent(pCur8->data_field);
					ParentOfpCur8->left = NULL;
				}
				pCur8->left = deletable->left;
				pCur8->right = deletable->right;
				deletable->right = NULL;
				deletable->left = NULL;
				pCur7->left = pCur8;
				BinTree* connect = search(pCur7->data_field);
				BinTree* connect2 = connect;
				while (1)
				{
					if (connect != NULL)
					{
						connect2 = connect;
					}
					else break;
					connect = findparent(connect->data_field);
				}
				Head = connect2;
				free(deletable);
				return;
			}
			if (pCur7 != NULL && pCur7->right == deletable)
			{
				BinTree* pCur8 = search(Head->data_field);
				pCur8 = search(deletable->right->data_field);
				if (pCur8->left == NULL)
				{
					BinTree* pCur9 = findparent(deletable->data_field);
					if (pCur9->left == deletable)
					{
						pCur8 = deletable->right;
						pCur9->left = pCur8;
						pCur8->left = deletable->left;
						free(deletable);
						return;
					}
					if (pCur9->right == deletable)
					{
						pCur8 = deletable->right;
						pCur9->right = pCur8;
						pCur8->left = deletable->left;
						free(deletable);
						return;
					}
				}
				while (pCur8->left != NULL)
				{
					pCur8 = pCur8->left;
				}
				if (pCur8->right != NULL)
				{
					BinTree* ParentOfpCur8 = findparent(pCur8->data_field);
					ParentOfpCur8->left = pCur8->right;
					pCur8->right = NULL;
				}
				else
				{
					BinTree* ParentOfpCur8 = findparent(pCur8->data_field);
					ParentOfpCur8->left = NULL;
				}
				pCur8->left = deletable->left;
				pCur8->right = deletable->right;
				deletable->right = NULL;
				deletable->left = NULL;
				pCur7->right = pCur8;
				BinTree* connect = search(pCur7->data_field);
				BinTree* connect2 = connect;
				while (1)
				{
					
					connect = findparent(connect->data_field);
					if (connect != NULL)
					{
						connect2 = connect;
					}
					else break;
				}
				Head = connect2;
				free(deletable);
				return;

			}
			
		}



		
	
	
}
void traverse(BinTree *p) 
{
	if (p == NULL)
		return;
	traverse(p->left);
	printf("%d ", p->data_field);
	traverse(p->right);
}
void delete2(BinTree *tree) {
	if (tree != NULL) {
		delete2(tree->left);
		delete2(tree->right);
		delete tree;
	}
}
int main()
{
	//srand(time(NULL));
	BinTree* JustTree = NULL;
	int *p = NULL;
	int j = 20;
	int i = 0;
	p = (int*)malloc(j * sizeof(int));
	while (j--)
	{
		*(p + i) = rand() % 121;
		printf("%d ", *(p + i));
		i++;
	}
	
	for (i = 0; i < 20; i++)
		add(p[i]);
	add(107);
	add(106);
	add(105);
	//traverse(Head);
	putchar('\n');
	traverse(Head);
	BinTree* LookFor = search(75);
	//findparent(41);
	Delete(LookFor);
//	traverse(Head);
	putchar('\n');
	traverse(Head);
	LookFor = search(41);
	Delete(LookFor);
	putchar('\n');
	traverse(Head);
	LookFor = search(104);
	Delete(LookFor);
	putchar('\n');
	traverse(Head);
	LookFor = search(22);
	Delete(LookFor);
	putchar('\n');
	traverse(Head);
	LookFor = search(76);
	Delete(LookFor);
	putchar('\n');
	traverse(Head);
	_getch();
	return 0;
}