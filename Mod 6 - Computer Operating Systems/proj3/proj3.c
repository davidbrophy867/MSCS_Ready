/* 
 * Project 3
 * a bounded buffer
 */
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <pthread.h>

#define BNUM 4               /* number of lines in the buffer */
#define BSIZE 256            /* length of each line */

/* shared_buffer_t is used as a cyclic buffer.
   The indices next_in and next_out chase one another around the
   buffer, in a cyclic fashion (modulo BNUM).
*/
typedef struct shared_buffer {
  pthread_mutex_t lock;      /* protects the buffer */
  pthread_cond_t             /* the POSIX condition variable type */
    new_data_cond,           /* to wait when the buffer is empty */
    new_space_cond;          /* to wait when the buffer is full */
  char c[BNUM][BSIZE];       /* an array of lines, to hold the text */
  int next_in,               /* next available line for input */
      next_out,              /* next available line for output */
      count;                 /* the number of lines occupied */
} shared_buffer_t;

/* sb_init should be called to initialize each shared_buffer_t.
   It initializes the state of the buffer to empty.
   It MUST be called before other operations are performed on the object.
   It must NOT be called more than once per object.
 */
void sb_init(shared_buffer_t *sb)
{
  sb->next_in = sb->next_out = sb->count = 0;   
  pthread_mutex_init(&sb->lock, NULL);           
  pthread_cond_init(&sb->new_data_cond, NULL);  
  pthread_cond_init(&sb->new_space_cond, NULL);
}

/* producer is intended to be the body of a thread.
   It repeatedly reads the next line of text from the standard input,
   and puts it into the buffer pointed to by the parameter sb.
   It terminates when it encounters an EOF character in input.
   The EOF character is passed on to the consumer.
 */
void * producer(void * arg)
{ int i,k = 0;
  shared_buffer_t *sb = (shared_buffer_t *) arg;

  pthread_mutex_lock(&sb->lock);                           
  for (;;) {
    while (sb->count == BNUM)                             
      pthread_cond_wait(&sb->new_space_cond, &sb->lock);
    pthread_mutex_unlock(&sb->lock);                       
    k = sb->next_in;
    i = 0;
    do {  /* read one line of data into the buffer slot */
      if ((sb->c[k][i++] = getc(stdin)) == EOF) {
        sb->next_in = (sb->next_in + 1) % BNUM;
        pthread_mutex_lock(&sb->lock);
        sb->count++;
        pthread_mutex_unlock(&sb->lock);
        pthread_cond_signal(&sb->new_data_cond);          
        pthread_exit(NULL);                                
      }
    } while ((sb->c[k][i-1] != '\n') && (i < BSIZE));
    sb->next_in = (sb->next_in + 1) % BNUM;
    pthread_mutex_lock(&sb->lock);
    sb->count++;
    pthread_cond_signal(&sb->new_data_cond);              
  }
}

/* consumer is intended to be the body of a thread.
   It repeatedly takes a line of text from the buffer which
   is pointed to by sb, converts it to upper case, and writes it to
   standard output.
   It terminates when it encounters an EOF character.
 */
void * consumer(void *arg)
{ int i, k = 0;
  shared_buffer_t *sb = (shared_buffer_t *) arg;

  pthread_mutex_lock(&sb->lock);         
  for (;;) {                                                
    while (sb->count == 0)                                   
      pthread_cond_wait(&sb->new_data_cond, &sb->lock);     
    pthread_mutex_unlock(&sb->lock);                       
    k = sb->next_out;
    i = 0;
    do { /* process next line of text from the buffer */
      if (sb->c[k][i] == EOF) {
         pthread_exit(NULL);
       }
      putc(toupper(sb->c[k][i++]), stdout);
    } while ((sb->c[k][i-1] != '\n') && (i < BSIZE));
    sb->next_out = (sb->next_out + 1) % BNUM;
    pthread_mutex_lock(&sb->lock);                           
    sb->count--;                                            
    pthread_cond_signal(&sb->new_space_cond);                
  }                                                          
}

/* the main program
 */
int main()
{ pthread_t th1, th2;  /* the two thread objects */
  shared_buffer_t sb;  /* the buffer */

  sb_init(&sb);
  pthread_create(&th1, NULL, producer, &sb);  				
  pthread_create(&th2, NULL, consumer, &sb);
  pthread_join(th1, NULL); pthread_join(th2, NULL);        
  return 0;
}

