#include "Library.h"
char str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ#";



int findIndex(char letter){
    const char *position = strchr(str, letter);
    if (position){
       int index = position - str + 1;
       return index;
    }
    return 0;
}
struct library * add (struct library * lib , char song[100] , char creator[100]){
      struct library * curLib = lib;
      if(!lib){
         curLib = calloc(1 , sizeof(struct library));
      }
      char firstLet = *creator;
      int index = findIndex(firstLet);
      if (findIndex){
        *((curLib -> tables) + index -1) = insert_alpha(*((curLib -> tables) + index - 1), song, creator);
        return curLib;
      }
      else{
        *((curLib -> tables) + 26) = insert_alpha(*((curLib -> tables) + 26), song, creator);
        return curLib;
      }
}

struct song_node * song_search(struct library * lib, char song[100], char creator[100]){
      char firstLet = *creator;
      int index = findIndex(firstLet);
      if(index){
          return  searchSong(*((lib -> tables) + index - 1), song, creator);
      }
      else{
          return  searchSong(*((lib -> tables) + 26), song, creator);
      }
}

struct song_node * artist_search(struct library * lib, char creator[100]){
      char firstLet = *creator;
      int index = findIndex(firstLet);
      if(index){
          return  findFirst(*((lib -> tables) + index - 1), creator);
      }
      else{
          return  findFirst(*((lib -> tables) + 26), creator);
      }
}

void  list_letter(struct library * lib, char * letter){
      char firstLet = *letter;
      int index = findIndex(firstLet);
      if(index){
        print_list(*((lib -> tables) + index - 1));
      }
      else{
        print_list(*((lib -> tables) + 26));
      }
}

void list_artist(struct library * lib, char creator[100]) {
  printf("looking for [%s]\n", creator);
  struct song_node * node = artist_search(lib, creator);
  if (!node) {
    printf("was not found!\n");
  }
  else {
    while(node && !strcmp(node-> artist, creator)) {
      printf("[%s : %s]\n", node->artist, node ->name);
      node = node ->next;
    }
  }
  printf("\n");
}

void list_lib(struct library * lib){
     int index;
     printf("Printing Entire Library: \n");
     for(index = 0; index <27; index++){
       print_list(*((lib -> tables) + index));
     }
}

void shuffle(struct library * lib){
     int i;
     printf("Printing random songs out of Library(may repeat based on size of Library)\n");
     for(i = 0; i <10; i++){
         int arrayIndex = rand()%27;
         while(!(*((lib -> tables) + arrayIndex)) && arrayIndex < 26){
           arrayIndex++;
         }
         struct song_node * node = randElem(*((lib -> tables) + arrayIndex));
         if(node)printf("[%s : %s]\n", node-> artist, node-> name);
     }
}

void delete_song(struct library * lib, char song[100], char creator[100]){
     char firstLet = *creator;
     int index = findIndex(firstLet);
     *((lib -> tables) + index - 1) = removeSong(*((lib -> tables) + index - 1), song, creator);
}

void clear_lib(struct library * lib){
     int index;
     for(index = 0; index < 26 ; index ++){
        *((lib -> tables) + index) = free_list(*((lib -> tables) + index));
     }
}
