#include "Library.h"

int main(){
  srand(time(NULL));

  struct song_node *first;
  first=NULL;
  printf("==================================\n\n");
  printf("LINKED LIST TESTS\n");
  printf("==================================\n\n");

  printf("Testing insert_front:\n");
  first = insert_front(first, "Venom" , "Eminem" );
  print_list(first);
  first = insert_front(first, "Hello" , "Adele");
  print_list(first);
  first = insert_front(first, "Another Night", "Real McCoy" );
  print_list(first);
  first = insert_front(first, "Smooth", "Santana" );
  print_list(first);
  first = insert_front(first, "Apologize" ,"Timbaland");
  print_list(first);

  printf("Testing print_list:\n");
  print_list(first);
  printf("==================================\n\n");


  printf("Testing insert_alpha:\n");
  first = free_list(first);
  first = insert_alpha(first, "Venom" , "Eminem" );
  print_list(first);
  first = insert_alpha(first, "Hello" , "Adele");
  print_list(first);
  first = insert_alpha(first, "Another Night", "Real McCoy" );
  print_list(first);
  first = insert_alpha(first, "Smooth", "Santana" );
  print_list(first);
  first = insert_alpha(first, "Apologize" ,"Timbaland");

  printf("==================================\n\n");
  printf("Testing searchSong:\n");
  struct song_node * search = NULL;
  search = searchSong(first, "Smooth", "Santana");
  printf("Found [ Santana , Smooth]: ");
  print_list(search);
  search = searchSong(first, "Apologize", "Timbaland");
  printf("Found [ Timbaland , Apologize]: ");
  print_list(search);
  search = searchSong(first, "Hello", "Adele");
  printf("Found [ Adele , Hello]: ");
  print_list(search);
  search = searchSong(first, "No Way", "George");
  printf("Did not find [ George , No Way]: ");
  print_list(search);
  printf("\n");
  printf("==================================\n\n");
  printf("Testing findFirst:\n");
  search = NULL;
  printf("List: \n");
  first = insert_alpha(first, "Elevenn" , "Eminem" );
  first = insert_alpha(first, "rappp" , "Eminem" );
  first = insert_alpha(first, "Noooo" , "Eminem" );
  print_list(first);
  printf("Found first of Eminem: \n");
  search = findFirst(first, "Eminem");
  print_list(search);
  printf("\n" );

  printf("==================================\n\n");
  printf("Testing len   :\n");
  printf("List: \n");
  print_list(first);
  printf("length: ");
  printf("%d\n", len(first) );
  printf("\n" );

  printf("==================================\n\n");
  printf("Testing randElem  :\n");
  printf("List: \n");
  print_list(first);
  printf("\n");
  search = randElem(first);
  printf("random: [ %s , %s ]\n" , search -> artist, search -> name);
  search = randElem(first);
  printf("random: [ %s , %s ]\n" , search -> artist, search -> name);
  search = randElem(first);
  printf("random: [ %s , %s ]\n" , search -> artist, search -> name);
  printf("\n" );

  printf("==================================\n\n");
  printf("Testing removeSong :\n");
  printf("List: \n");
  print_list(first);
  printf("\n");
  printf("Removing [ Eminem : Elevenn]  :\n");
  first = removeSong(first, "Elevenn" , "Eminem");
  print_list(first);
  printf("\n" );
  printf("Removing [ Real McCoy : Another Night]  :\n");
  first = removeSong(first, "Another Night" , "Real McCoy");
  print_list(first);

  printf("==================================\n\n");
  printf("Testing free_list  :\n");
  printf("List: \n");
  print_list(first);
  printf("\n");
  printf("Freed List: ");
  first = free_list(first);
  print_list(first);
  printf("\n\n" );

  printf("==================================\n\n");
  printf("MUSIC LIBRARY TESTS \n\n");
  printf("==================================\n\n");
  printf("Testing findIndex\n");
  printf("Index of 'E' in alphabet : ");
  char alpha[] = "E";
  printf("%d\n" , findIndex(*alpha) - 1);
  strcpy(alpha, "T");
  printf("Index of 'T' in alphabet : ");
  printf("%d\n" , findIndex(*alpha) - 1);
  strcpy(alpha, "Z");
  printf("Index of 'Z' in alphabet : ");
  printf("%d\n" , findIndex(*alpha) - 1);

  printf("==================================\n\n");
  printf("Testing add    +   list_lib\n");
  struct library * libra = NULL;
  printf("Adding [ Eminem : Venom ]    : \n");
  libra = add(libra, "Venom", "Eminem");
  list_lib(libra);
  printf("Adding [ Adele : Hello ]    : \n");
  libra = add(libra, "Hello", "Adele");
  list_lib(libra);
  printf("Adding [ Real McCoy  : Another Night ]    : \n");
  libra = add(libra, "Another Night", "Real McCoy");
  list_lib(libra);
  printf("Adding [ Santana  : Smooth ]    : \n");
  libra = add(libra, "Smooth", "Santana");
  list_lib(libra);
  printf("Adding [ Timbaland  : Apologize ]    : \n");
  libra = add(libra, "Apologize", "Timbaland");
  list_lib(libra);

  printf("==================================\n\n");
  printf("Testing song_search\n");
  printf("Searching for [ Real McCoy  : Another Night ] : ");
  search = song_search(libra, "Another Night" , "Real McCoy");
  printf("Found : " );
  print_list(search);
  printf("Searching for [ Adele : Hello ] : ");
  search = song_search(libra, "Hello" , "Adele");
  printf("Found : " );
  print_list(search);
  printf("Searching for [ Timbaland  : Apologize ] : ");
  search = song_search(libra, "Apologize" , "Timbaland");
  printf("Found : " );
  print_list(search);
  printf("Searching for [ Chain Smoker  : Closer ] : ");
  search = song_search(libra, "Closer" , "Chain Smoker");
  printf("Nothing Found : \n" );
  print_list(search);


  printf("==================================\n\n");
  printf("Testing artist_search\n");
  printf("Searching for [ Real McCoy ] : ");
  search = artist_search(libra, "Real McCoy");
  printf("Found : " );
  print_list(search);

  printf("Searching for [ Eminem ] : ");
  search = artist_search(libra, "Eminem");
  printf("Found : " );
  print_list(search);


  printf("Searching for [ Santana ] : ");
  search = artist_search(libra, "Santana");
  printf("Found : " );
  print_list(search);

  printf("Searching for [ Demi Lovato ] : ");
  search = artist_search(libra, "Demi Lovato");
  printf("Nothing Found : \n" );
  print_list(search);

  printf("==================================\n\n");
  printf("Testing list_letter\n");
  libra = add(libra , "What do You mean" , "Alfonse");
  printf("Listing all under A\n");
  list_letter(libra, "A");

  printf("Listing all under S\n");
  list_letter(libra, "S");

  printf("Listing all under T\n");
  list_letter(libra, "T");

  printf("==================================\n\n");
  printf("Testing list_artist\n\n");
  libra = add(libra, "Not Afraid" , "Eminem");
  libra = add(libra, "Rap God", "Eminem");
  libra = add(libra, "All I Ask", "Adele");
  libra = add(libra, "Skyfall", "Adele");
  printf("Entire Library: \n");
  list_lib(libra);
  printf("Listing all songs by Eminem : \n");
  list_artist(libra, "Eminem");
  printf("Listing all songs by Adele : \n");
  list_artist(libra, "Adele");

  printf("==================================\n\n");
  printf("Testing list_lib\n");
  list_lib(libra);

  printf("==================================\n\n");
  printf("Testing shuffle\n");
  printf("Printing at most 10 random songs  : \n");
  shuffle(libra);


  printf("==================================\n\n");
  printf("Testing delete_song\n");
  printf("Current state of Library :\n");
  list_lib(libra);
  printf("Deleting [ Eminem : Rap God ]\n");
  delete_song(libra , "Rap God" , "Eminem");
  printf("Deleting [ Adele : Hello ]\n");
  delete_song(libra , "Hello" , "Adele");
  printf("Deleting [ Timbaland : Apologize ]\n");
  delete_song(libra , "Apologize" , "Timbaland");
  printf("Library after deletions  :\n");
  list_lib(libra);


  printf("==================================\n\n");
  printf("Testing clear_lib\n");
  list_lib(libra);
  printf("Clearing Library \n");
  clear_lib(libra);
  list_lib(libra);
  return 0;
}
