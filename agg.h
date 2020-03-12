#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <string.h>


#include <search.h>

#include <immintrin.h>

void* node2stat(void** node){
  switch(NULL == node){
    case 1:  return NULL;
    default: return *node;
  }
}

void* initstat(const void* key, void* map, int (*cmp)(const void* a, const void* b)){
  void* stat = malloc(8*4);
  switch(NULL == stat){
    case 1:  return NULL;
    default: break;
  }
  memset(stat, 0, 32);
  void* searched = tsearch(key, &map, cmp);
  return node2stat(searched);
}

const double min_f64(const double a, const double b){ return a < b ? a : b; }
const double max_f64(const double a, const double b){ return a < b ? b : a; }

void reduce_f64(void* stat, const void* key, const double value){
  switch(NULL == stat){
    case 1:  return;
    default: break;
  }
  switch(NULL == key){
    case 1:  return;
    default: break;
  }
  const char** keys = (const char**)stat;
  double* p = (double*)stat;
  keys[0] = key;
  return;
  p[1] += value;
  p[2] = min_f64(p[2], value);
  p[3] = max_f64(p[2], value);
}

int compute_agg_f64(
  const void** keys,
  const double* values,
  const uint16_t size,
  void* map,
  int (*cmp)(const void* a, const void* b)
){
  static uint16_t i = 0;
  for(i=0; i<size; i++){
    const void*  key = keys[i];
    const double val = values[i];
    void* found = tfind(key, &map, cmp);
    void* stat = found ? node2stat(found) : initstat(key, map, cmp);
    switch(NULL == stat){
      case 1:  continue;
      default: break;
    }
    reduce_f64(stat, key, val);
  }
  return 0;
}
