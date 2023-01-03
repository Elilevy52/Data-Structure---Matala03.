#include <stdio.h>
typedef int queueinfo;
typedef struct node
{
	queueinfo value;
	struct node * next;
} QueueNode;
QueueNode * createQueue()
{
	return NULL;
 }
int isEmptyQueue(QueueNode * Q)
{
	if (Q->value == NULL) return 1;
	return 0;
}
void insert(QueueNode **Q, queueinfo x)
{
	QueueNode *p;
	p = (QueueNode *)malloc(sizeof(QueueNode));
	p->value = x;
	if (isEmptyQueue(*Q)) *Q = p;
		else p->next=(*Q)->next;
	(*Q)->next = p;
	(*Q) = p;
}
void delafter(QueueNode *p, queueinfo *x)
{
	QueueNode*q;
	if (p == NULL) {
		printf("ERROR!!! - Empty list.");
		return 0;
	}
	else if (p == p->next) {
		printf("ERROR!!! - There is no node after the node.");
		return 0;
	}
	else {
		q = p->next;
		*x = q->value;
		p->next = q->next;
		free(q);
	}
}
void PrintQueue(QueueNode *Q)
{
	QueueNode *p = Q->next;
	printf("\n");
	while (p != Q)
	{
		printf("%d", p->value);
		p = p->next;
	}
	printf("%d\n", p->value);

}
void pickLeader() {
	int name;
	int n;
	int k;
	printf("Enter group size: ");
	scanf("%d", &n);
	printf("Enter skipping value: ");
	scanf("%d", &k);
	QueueNode *head = NULL;

	for (int i = 1; i <= n; i++)
	{
		insert(&head, i);
	}
	printf("Order of elimination: ");
	while (head->next != head)
	{
		for (int i = 1; i < k; i++)
		{
			head = head->next;
		}
		delafter(head, &name);
		printf("%d", name);
	}
	printf("\nLeader: %d\n", head->value);
	free(head);
}

int main()
{
	pickLeader();
	return 0;
}
