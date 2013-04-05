
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"

#define NUM_BUCKETS 100

// Building blocks for a hash map

struct node;

struct node{
    char * key;
    void * value;
    struct node * next;
};

//Fowler-Noll-Vo hash function (FNV-1a)
static unsigned int hash(const char * key){
    unsigned int hash = 2166136261;
    unsigned int i;
    for(i=0; key[i]!='\0'; ++i) {
        hash = hash ^ key[i];
        hash = hash * 16777619;
    }

    return hash;
}


struct hashmap {
    struct node * buckets[NUM_BUCKETS];
};

struct hashmap * hashmap_new() {
    struct hashmap * h = calloc(1, sizeof(struct hashmap));
    return h;
}

void hashmap_insert(struct hashmap * h, const char * key, void * value) {
    unsigned int bucket_idx = hash(key) % NUM_BUCKETS;
    struct node * n = malloc(sizeof(struct node));
    n->key = strdup(key);
    n->value = value;
    n->next = h->buckets[bucket_idx];
    h->buckets[bucket_idx] = n;
}

void * hashmap_delete(struct hashmap * h, const char * key) {
    unsigned int bucket_idx = hash(key) % NUM_BUCKETS;
    struct node ** n;
    for(n = &h->buckets[bucket_idx]; *n != NULL; n = &((*n)->next)) {
        if(!strcmp(key, (*n)->key)) {
            struct node * tmp = *n;
            *n = (*n)->next;
            free(tmp->key);
            void * v = tmp->value;
            free(tmp);
            return v;
        }
    }
    return NULL;
}


// move elsewhere later:

int main(){
//    printf("hash(\"abc\", 3) = %u\n", hash("abc"));
//    printf("hash(\"HELLO\", 5) = %u\n", hash("HELLO"));
//    printf("hash(\"FoObAr\", 6) = %u\n", hash("FoObAr"));
    struct hashmap * my_hm = hashmap_new();
    hashmap_insert(my_hm, "marek", (void *) 23);
    hashmap_insert(my_hm, "alex", (void *) 2);
    hashmap_insert(my_hm, "marek", (void *) 344343);
    hashmap_insert(my_hm, "marek", (void *) 234);
    hashmap_insert(my_hm, "marek", (void *) 34234);
    hashmap_insert(my_hm, "marek", (void *) 399393);
    hashmap_insert(my_hm, "marek", (void *) 34);
    hashmap_delete(my_hm, "marek");
    hashmap_delete(my_hm, "marek");
    hashmap_delete(my_hm, "marek");
    hashmap_delete(my_hm, "marek");
    hashmap_delete(my_hm, "marek");
    hashmap_delete(my_hm, "marek");
    hashmap_delete(my_hm, "marek");
    hashmap_delete(my_hm, "marek");
    hashmap_delete(my_hm, "marek");
    hashmap_delete(my_hm, "alex");

    return 0;
}

