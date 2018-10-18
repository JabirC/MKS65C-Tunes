#include "Library.h"

int main(){
  srand(time(NULL));

  struct song_node *first;
  first=NULL;

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
  first = insert_front(first, "Apolize" ,"Timbaland");
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
  printf("MUSIC LIBRARY TESTS (COMING SOON)\n\n");
  printf("==================================\n\n");
  return 0;
}
