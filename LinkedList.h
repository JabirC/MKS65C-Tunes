#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

void print_list(struct song_node * node);

struct song_node * insert_front(struct song_node * node, char * song, char *  creator);

struct song_node * free_list(struct song_node * node);

struct song_node * insert_alpha(struct song_node * node, char * song, char * creator);

struct song_node * searchSong(struct song_node * firstNode, char * song, char * creator);

struct song_node * findFirst(struct song_node * firstNode, char * creator);

int len(struct song_node * list);

struct song_node * randElem(struct song_node * list);

struct song_node * removeSong(struct song_node * list, char * song , char * creator);
