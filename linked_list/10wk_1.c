#include<stdio.h>
#include<malloc.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link; //ListNode Ÿ���� link������ ���� ListNode�� �����ؾ� ������ ���? ���� Ÿ���� �����ϰ� ��
}ListNode;

//���� ó�� �Լ�
void error(char* message) {
	printf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode* head, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

//��� pre �ڿ� ���ο� ��� ����
ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //�ϳ� �Ҵ�
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* delete_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

ListNode* delete(ListNode* head, ListNode* pre) {
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;

}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
	{
		printf("%d->", p->data);
	}
	printf("NULL\n");
}

int main() {
	ListNode* head = NULL;
	printf("\n");
	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i);
		print_list(head);
	}
	for (int i = 0; i < 5; i++) {
		head = delete_first(head);
		print_list(head);
	}
	return 0;
}  