#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {

	char name[50];
	char sex;
	int age;
	float bmi;

	struct Node* link;

}Node;


typedef struct {

	Node *head;
	int length;

}linkedList;



linkedList* initList() {

	linkedList *L;
	L = (linkedList*)malloc(sizeof(linkedList));
	
	L->head = NULL;
	L->length = 0;

	return L;
}


void displayList(linkedList* L) {

	Node* p;
	p = L->head;

	if (p == NULL) {
		printf("The list is empty. Quit!\n");
	}
	else {
		printf("\nname    age   BMI\n");

		while (p != NULL) {

			printf("%s  %3d  %.1f\n", p->name, p->age, p->bmi);
			p = p->link;
		}
	}
}


/* �Լ� ������ �Ʒ��� ���� ������ ���� ������ */

/*
void insertFirst(linkedList* L, Node* N) {

}

void insertLastNode(linkedList* L, Node* N) {

}


Node* deleteNode(linkedList* L, Node* p) {

}

void insert(linkedList* L, Node* pre, Node* N) {

}

*/




int main(void)
{

	FILE *fp;
	char buf[40];
	
	fp = fopen("patientdata.txt", "r");



	

	/*
		Q1: ����Ʈ�� �ִ� �� ����� �����͸� ����ϱ�
	*/ 

	// list1 �ʱ�ȭ


	// ������ �о�鿩 ���������� ��� ����
	int i;
	for (i = 0; i < 3; i++) {
		fscanf(fp, "%s", buf); // skip the first line in the text file.
	}

	while ((fscanf(fp, "%s", buf)) != EOF) {
		
		Node* newNode;
		newNode = (Node*)malloc(sizeof(Node)); // ���ο� ��� ����
		
		// ���ο� ��忡 ������ ����
		strcpy(newNode->name, buf);
		fscanf(fp, "%d", &newNode->age);
		fscanf(fp, "%f", &newNode->bmi);

		// insertFirst �Լ��� �� �ڸ��� �ֱ�.

	}


	
	printf("\n1. ����Ʈ�� �ִ� �� ����� �����͸� ����ϱ� \n");

	displayList(list1);
	printf("\nlist1�� ���� = % d\n", list1->length);


	/*
		Q2: ������ ��°� �ݴ�� ������ �Ųٷ� ����ϱ�.
	*/
	
	printf("\n\n2. ����Ʈ ������ �Ųٷ� ����ϱ� \n");

	// list2 �ʱ�ȭ

	rewind(fp);

	for (i = 0; i < 3; i++) {
		fscanf(fp, "%s", buf); // skip the first line in the text file.
	}

	while ((fscanf(fp, "%s", buf)) != EOF) {

		Node* newNode;
		newNode = (Node*)malloc(sizeof(Node)); // ���ο� ��� ����

		// ���ο� ��忡 ������ ����
		strcpy(newNode->name, buf);
		fscanf(fp, "%d", &newNode->age);
		fscanf(fp, "%f", &newNode->bmi);

		// insertLastNode �Լ��� �� �ڸ��� �ֱ�

	}

	displayList(list2);
	printf("\nlist2�� ���� = % d\n", list2->length);


	/* 
		Q3: list1�����Ϳ��� BMI�� 25�̸��� ȯ�ڴ� ������ �� ����Ʈ �� ��� ������ ����ϱ�. 
	*/

	printf("\n\n3. list1�����Ϳ��� BMI�� 25�̸��� ȯ�ڴ� ������ �� ����Ʈ �� ��� ������ ����ϱ�. \n");


	printf("\n ���� �� list1\n");
	displayList(list1);


	// ����Ʈ���� BMI�� 25�̸��� ȯ�� �����ϵ��� �ڵ��ϱ�. 


	printf("\n ���� �� list1\n");
	displayList(list1);
	printf("\n���� �� list1�� ���� = % d\n", list1->length);


	/* 
		Q4: Age ������������ ������ ����Ʈ ����ϱ�. 
	*/

	printf("\n\n4. Age ������������ ������ ����Ʈ ����ϱ�. \n");
	
	// list4 �ʱ�ȭ

	rewind(fp);

	for (i = 0; i < 3; i++) {
		fscanf(fp, "%s", buf); // skip the first line in the text file.
	}

	while ((fscanf(fp, "%s", buf)) != EOF) {

		Node* newNode;
		newNode = (Node*)malloc(sizeof(Node)); // ���ο� ��� ����

		// ���ο� ��忡 ������ ����
		strcpy(newNode->name, buf);
		fscanf(fp, "%d", &newNode->age);
		fscanf(fp, "%f", &newNode->bmi);


		// Age ������������ �����ϵ��� �ڵ��ϱ�.


		
		displayList(list4);

	}

	


	fclose(fp);



}

