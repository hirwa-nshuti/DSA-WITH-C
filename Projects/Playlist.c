#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct node
{
  char song[100];
  struct node *next;
  struct node *previous;
  unsigned int song_time;
};

char temp[100];
unsigned int song_time;
struct node *head = NULL;
struct node *current_node = NULL;
int song_count;

void insert();
void delete_song();
void display();
void count_songs();
void time_delay(unsigned int song_time);
void play();

int main()
{
  int select;
selection:
  printf("\n\n--------MENU--------\n");
  printf("\n1. ADD A SONG\n");
  printf("\n2. REMOVE A SONG\n");
  printf("\n3. DISPLAY PLAYLIST\n");
  printf("\n4. PLAY ALL SONGS\n");
  printf("\n5. COUNT ALL SONGS\n");
  printf("\n6. EXIT\n");
  printf("---------\n");

  scanf("%d", &select);

  if (select == 1)
    insert();

  else if (select == 2)
    delete_song();

  else if (select == 3)
    display();

  else if (select == 4)
    play();
  else if (select == 5)
  {  
    count_songs();
    printf("\n TOTAL SONGS - %d ", song_count);
  }
  else
    exit(0);

  goto selection;
}

// Inserting a song to the playlist
void insert()
{
  printf("Enter name of the song: \n");
  while (getchar() != '\n')
    ;
  scanf("%[^\n]%*c", temp);
  printf("\nEnter the song duration: ");
  scanf("%u", &song_time);
  struct node *new_node = (struct node *)malloc(sizeof(struct node)); // Allocate memory for new node
  strcpy(new_node->song, temp);
  new_node->song_time = song_time;
  // Adding the new node to current node
  if (head == NULL)
  {
    new_node->next = new_node->previous = new_node;
    head = current_node = new_node;
    return;
  }
  struct node *last = head->previous;
  new_node->previous = last;
  last->next = new_node;
  new_node->next = head;
  head->previous = new_node;
}

// Deleting song from the playlist
void delete_song()
{
  if (head == NULL)
  {
    printf("There is no in this playlist!!\n");
    return;
  }
  printf("\nAvailable songs in the playlist\n");
  display();
  printf("\nEnter name of the song need to be deleted: ");
  while (getchar() != '\n')
    ;
  scanf("%[^\n]%*c", temp);
  struct node *ptr = head;
  // check the song from the playlist
  do
  {
    if (ptr->next == ptr && strcmp(ptr->song, temp) == 0)
    {
      printf("ONE SONG DELETED\n");
      printf("PLAYLIST IS EMPTY NOW.");
      head == NULL;
      free(ptr);
      return;
    }
    else if (strcmp(ptr->song, temp) == 0)
    {
      struct node *previous = ptr->previous;
      struct node *next = ptr->next;
      previous->next = next;
      next->previous = previous;
      head = next;
      free(ptr);
      printf("SONG IS DELETED SUCCESSFULLY\n");
      return;
    }
    ptr = ptr->next;
  } while (ptr != head);
  printf("The indicated song is not present\n");
}

// Displaying the playlist
void display()
{
  if (head == NULL)
  {
    printf("THE PLAYLIST IS EMPTY!!\n");
    return;
  }
  struct node *display_ptr = head;
  int i = 1;
  printf("DISPLAYING PLAYLIST: \n");
  printf("\nSr.No| SONG NAME | Duration\n");
  printf("------------------------------\n");
  do
  {
    printf(" %d       %s             %u\n", i, display_ptr->song, display_ptr->song_time);
    i++;
    display_ptr = display_ptr->next;
  } while (display_ptr != head);
}

// Delay for playing the song
void time_delay(unsigned int song_time)
{
  unsigned int retTime = time(0) + song_time;
  while (time(0) < retTime)
    ;
}

// Playing the song from the playlist
void play()
{
  if (head == NULL)
  {
    printf("THE PLAYLIST IS EMPTY!!\n");
    return;
  }
  struct node *play_song = head;
  int i = 1;
  printf("\nPlaying the songs from the playlist\n\n");
  printf("Current Playing|  Duration\n");
  printf("---------------------------\n");
  do
  {
    printf(" %s               %u\n", play_song->song, play_song->song_time);
    time_delay(play_song->song_time);
    i++;
    play_song = play_song->next;
  } while (play_song != head);
}

// total songs on the playlist
void count_songs()
{
    if (head == NULL)
    {
      printf("THE PLAYLIST IS EMPTY!!\n");
      return;
    }
    struct node *songs = head;
    int i = 1;
    do
    {
      i++;
      songs = songs->next;
    } while (songs != head);
    song_count = i-1;
}