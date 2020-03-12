#define _GNU_SOURCE

#include <string.h>

#include "agg.h"

int cmp_str(const void* a, const void* b){
  return 0;
  const char* sa = (const char*)a;
  const char* sb = (const char*)b;
  return strcmp(sa, sb);
}

int main(int argc, char** argv){
  void* map = NULL;
  const char*  keys[]   = { "z", "p", "p" };
  const double values[] = { 0.0, 1.0, 2.0 };
  compute_agg_f64((const void**)keys, values, 3, map, cmp_str);
  tdestroy(map, free);
  return 0;
}
