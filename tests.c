#include "LinkedList.h"

int main(){
  struct song_node * start;
  printf("------Empty Linked list Before Modification------\n\n");
  print_list(start);
  printf("\n");

  start = insert_front(start, "Power" , "Eminem");
  printf("------Linked list after insertion of node with int val [5]------\n\n");
  print_list(start);
  printf("\n");

  start = insert_front(start, "Hello" , "Adele");
  printf("------Linked list after insertion of node with int val [11]------\n\n");
  print_list(start);
  printf("\n");

  start = insert_front(start, "Oh my" , "Jabir");
  printf("------Linked list after insertion of node with int val [98]------\n\n");
  print_list(start);
  printf("\n");

  start = free_list(start);
  printf("------Freed Linked List------\n\n");
  print_list(start);
  return 0;
}
