#include "LinkedList.h"

void print_list(struct song_node * node){
  struct song_node * cur = node;
  while (cur) {
    if (cur == node )
         printf("[ %s: %s]", cur -> artist, cur -> name);
    else printf("-->[ %s: %s]", cur -> artist, cur -> name);
    cur = cur -> next;
  }
  if(node) printf("\n");
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

struct song_node * insert_alpha(struct song_node * node, char * song, char * creator){
    struct song_node * pointer = malloc(sizeof(struct song_node));
    strcpy(pointer -> name, song);
    strcpy(pointer -> artist, creator);
    if(!node
      || strcmp(pointer -> artist, node -> artist) < 0
      || (!strcmp(pointer -> artist, node -> artist ) && strcmp(pointer -> name, node -> name) < 0)){
            pointer -> next = node;
            return pointer;
    }
    struct song_node * previousNode = node;
    struct song_node * curNode = node -> next;
    while(curNode){
         if(strcmp(pointer -> artist, curNode -> artist) < 0){
             pointer -> next = curNode;
             previousNode -> next = pointer;
             break;
         }
         else if(strcmp(pointer -> artist, curNode -> artist) > 0){
             previousNode = curNode;
             curNode = curNode -> next;
             continue;
         }
         else if(!strcmp(pointer -> artist, curNode -> artist)){
             if(strcmp(pointer -> name, node -> name) < 0){
                   previousNode -> next = pointer;
                   pointer -> next = curNode;
                   break;
             }
             else{
                   previousNode = curNode;
                   curNode = curNode -> next;
                   continue;
             }
         }
    }
    if(!curNode){
         previousNode -> next = pointer;
         pointer -> next = NULL;
    }
    return node;
}

struct song_node * searchSong(struct song_node * firstNode, char * song, char * creator){
      struct song_node * curNode = firstNode;
      while(curNode){
        if(!strcmp(creator , curNode -> artist)  && !strcmp(song , curNode -> name)){
            return curNode;
        }
        curNode = curNode -> next;
      }
      return NULL;
}

struct song_node * findFirst(struct song_node * firstNode, char * creator){
      struct song_node * curNode = firstNode;
      while(curNode){
        if(!strcmp(creator , curNode -> artist)){
            return curNode;
        }
        curNode = curNode -> next;
      }
      return NULL;
}

int len(struct song_node * list){
      struct song_node * curNode = list;
      int retval = 0;
      while(curNode){
         retval++;
         curNode = curNode -> next;

      }
      return retval;
}


struct song_node * randElem(struct song_node * list){
       struct song_node * curNode= list;
       int length = len(list);
       int random = 0;
       if(length){random = rand()%length;}
       while(random && curNode){
            random--;
            curNode = curNode -> next;
       }
       return curNode;
}

struct song_node * removeSong(struct song_node * list, char * song , char * creator){
        struct song_node * curNode = list;
        struct song_node * prev = NULL;
        while(curNode){
              if(!strcmp(curNode -> artist, creator ) && !strcmp(curNode -> name, song)){
                   break;
                }
              else{
                   prev = curNode;
                   curNode = curNode -> next;
                }
        }
        if(!curNode){
            return list;
        }
        else if(!prev){
            struct song_node * retPointer = curNode -> next;
            free(curNode);
            return retPointer;
        }
        else if(!(curNode -> next)){
            prev -> next = NULL;
            free(curNode);
            return list;
        }
        else{
            prev -> next = curNode -> next;
            free(curNode);
            return list;
          }
}
