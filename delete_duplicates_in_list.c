#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
      int value;
      struct Node* next;
}Node;

Node* new_node(int value, Node* next) {
    Node* node = calloc(1, sizeof(struct Node));
    node->value = value; 
    node->next = next;
    return node;
} 

void print_list(Node* node){
	while(node != NULL){
		printf("[%d]", node->value);
		printf("->");
		if(node->next == NULL){
			printf("NULL");
		}
		
		node = node->next;
	}
}

Node* delete_duplicate(Node* list){ 
	Node* node = list; 
	Node* pointer = list->next;
	while(pointer != NULL) {
		if(list->value == pointer->value) {
			list->next = pointer->next;
			pointer = pointer->next;
		} else {
			list = list->next;
			pointer = pointer->next;
		}
	}
	return node;
}

void test_equals_list(Node* result, Node* expected, int line){
	while(expected != NULL) {
		if(result->value != expected->value){
			printf("expected [%d] differs from [%d] in Line %d.\n", expected, result, line);
		}
		
		result = result->next;
		expected = expected->next;
	}
	
	printf("Test pass in Line %d.\n", line);
}

int main() {
	Node* list = new_node(1,new_node(1,new_node(2, new_node(3, new_node(3, NULL)))));
	Node* result = delete_duplicate(list);
	Node* expected = new_node(1,new_node(2, new_node(3, NULL)));
	
	test_equals_list(result, expected, __LINE__);
	return 0;
}