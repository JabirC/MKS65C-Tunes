#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct song_node { char name[100]; char artist[100]; struct song_node *next;};

void print_list(struct song_node * node);

struct song_node * insert_front(struct song_node * node, char * song, char * creator);

struct song_node * free_list(struct song_node * node);
