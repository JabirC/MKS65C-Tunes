#include "LinkedList.h"


struct library {struct song_node* tables[27];};

struct library * add (struct library * lib , char song[100] , char creator[100]);

int findIndex(char letter);

struct song_node * song_search(struct library * lib,char song[100], char creator[100]);

struct song_node * artist_search(struct library * lib, char creator[100]);
//
void list_letter(struct library * lib, char * letter);

void list_artist(struct library * lib, char creator[100]);

void list_lib(struct library * lib);

void shuffle(struct library * lib);

void delete_song(struct library * lib, char song[100],char  creator[100]);

void clear_lib(struct library * lib);
