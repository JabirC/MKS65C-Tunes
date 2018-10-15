#include "LinkedList.h"

void print_list(struct song_node * node){
  struct song_node * cur = node;
  while (cur) {
    if (cur == node )
         printf("[ %s  By  %s]", cur -> name, cur -> artist);
    else printf("-->[ %s  By  %s]", cur -> name, cur -> artist);
    cur = cur -> next;
  }
  printf("\n");
}

struct song_node * insert_front(struct song_node * node, char * song, char * creator){
   struct song_node *pointer = malloc(sizeof(struct song_node));
   pointer -> next = node;
   strcpy(pointer -> name, song);
   strcpy(pointer -> artist, creator);
   return pointer;
}

struct song_node * free_list(struct song_node * node){
    struct song_node * cur = node;
    struct song_node * nextSong;
    while(cur){
      nextSong = cur -> next;
      free(cur);
      cur = nextSong;
    }
    return cur;
}

struct song_node * insert_alpha(struct song_node * node, char * song, char * creator)(
    struct song_node * pointer = malloc(sizeof(struct song_node));
    strcpy(pointer -> name, song);
    strcpy(pointer -> artist, creator);
    if(!node){
         pointer -> next = node;
         return pointer
    }
    else if(strcmp(pointer -> artist, node -> artist) < 0){
         pointer -> next = node;
         return pointer
    }
    else if(strcmp(pointer -> artist, node -> artist) = 0){
         if(strcmp(pointer -> name, node -> name) < 0){
            pointer -> next = node;
            return pointer
         }
    }
    curNode = node -> next;
    while(curNode){
         if(strcmp(pointer -> artist, curNode -> artist) < 0){
             pointer -> next
         }
    }

    return node;
)
