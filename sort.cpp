#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

// int
int num[100];
int cmp ( const void *a , const void *b )
{
  return *(int *)a - *(int *)b;
}
qsort(num,100,sizeof(num[0]),cmp);

// char
char word[100];
Sample:
int cmp( const void *a , const void *b )
{
  return *(char *)a - *(char *)b;
}
qsort(word,100,sizeof(word[0]),cmp);

// double
double in[100];
int cmp( const void *a , const void *b )
{
  return *(double *)a > *(double *)b ? 1 : -1;
}
qsort(in,100,sizeof(in[0]),cmp)；

// struct, one dimension
struct In
{
  double data;
  int other;
}s[100];
// based on the value of data
int cmp( const void *a ,const void *B)
{
  return (*(In *)a)->data > (*(In *)B)->data ? 1 : -1;
}
qsort(s,100,sizeof(s[0]),cmp);

// struct, two dimension
struct In
{
  int x;
  int y;
}s[100];
// based on the value of x, if x is equal, then y
int cmp( const void *a , const void *b )
{
  struct In *c = (In *)a;
  struct In *d = (In *)b;
  if(c->x != d->x) return c->x - d->x;
  else return d->y - c->y;
}
qsort(s,100,sizeof(s[0]),cmp);

// string
struct In
{
  int data;
  char str[100];
}s[100];
// alphabetical
int cmp ( const void *a , const void *b )
{
  return strcmp( (*(In *)a)->str , (*(In *)B)->str );
}
qsort(s,100,sizeof(s[0]),cmp);


int main () {

  return 0;
}
