#include <stdio.h>
// To use time library of C
#include <time.h>

void main()
{
  unsigned int tim;
  tim = time(0);
  printf("%u", tim);
}
// void insert_pos(int pos)
// {
//   printf("Enter name of the song: \n");
//   while (getchar() != '\n')
//     ;
//   scanf("%[^\n]%*c", temp);
//   printf("\nEnter the song duration: ");
//   scanf("%u", &song_time); 
//   struct node *new_node = (struct node *)malloc(sizeof(struct node)); // Allocate memory for new node
//   strcpy(new_node->song, temp);
//   new_node->song_time = song_time;
//   count_songs();
//   if(pos < 1 || pos > song_count+1)
//   {  
//     printf("Invalid position!");
//     return;
//   }
//   while(pos --)
//   {
//     if(pos == 0)
//     {
//       new_node->next = head;
//       head = new_node;
//     }
//     else
//       new_node = head->next;
//   }
//   song_count++;
// }