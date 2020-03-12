#define _GNU_SOURCE

#include <string.h>

#include "agg.h"

void free_verbose(void* p){
  printf("trying to free: %p\n", p);
  fflush(stdout);
  free(p);
}

int cmp_str(const void* a, const void* b){
  const char* sa = (const char*)a;
  const char* sb = (const char*)b;
  printf("trying to cmp...\n");
  printf("a: %p\n", sa);
  printf("b: %p\n", sb);
  fflush(stdout);
  return strcmp(sa, sb);
}

int main(int argc, char** argv){
  void* map = NULL;
  const char*  keys[]   = { "z", "p", "p" };
  const double values[] = { 0.0, 1.0, 2.0 };
  printf("m: %p\n", map);
  printf("k0: %p\n", keys[0]);
  compute_agg_f64((const void**)keys, values, 3, &map, cmp_str);
  printf("removing...\n");
  printf("m: %p\n", map);
  fflush(stdout);
  tdestroy(map, free_verbose);
  printf("removed.\n");
  fflush(stdout);
  return 0;
}
