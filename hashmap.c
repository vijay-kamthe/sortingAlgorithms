
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashmap.h"

// Building blocks for a hash map

struct node;

struct node{
    char * key;
    DATATYPE * value;
    struct node * next;
};

struct hashmap {
    struct node * buckets[NUM_BUCKETS];
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

struct hashmap * hashmap_new() {
    struct hashmap * h = calloc(1, sizeof(struct hashmap));
    return h;
}

void hashmap_insert(struct hashmap * h, const char * key, DATATYPE value) {
    unsigned int bucket_idx = hash(key) % NUM_BUCKETS;
    if(!hashmap_lookup(h, key)) { // insert value
        struct node * n = malloc(sizeof(struct node));
        n->key = strdup(key);
        n->value = malloc(sizeof(DATATYPE));
        *(n->value) = value;
        n->next = h->buckets[bucket_idx];
        h->buckets[bucket_idx] = n;
    } else { // overwrite value
        struct node * n;
        for(n = h->buckets[bucket_idx]; n != NULL; n = n->next) {
            if(!strcmp(key, n->key)) {
                *(n->value) = value;
                break;
            }
        }
    }
}

DATATYPE * hashmap_lookup(struct hashmap *h, const char * key) {
    unsigned int bucket_idx = hash(key) % NUM_BUCKETS;
    struct node * n;
    for(n = h->buckets[bucket_idx]; n != NULL; n = n->next) {
        if(!strcmp(key, n->key)) {
            return n->value;
        }
    }
    return NULL;
}

DATATYPE * hashmap_delete(struct hashmap * h, const char * key) {
    unsigned int bucket_idx = hash(key) % NUM_BUCKETS;
    struct node ** n;
    for(n = &h->buckets[bucket_idx]; *n != NULL; n = &((*n)->next)) {
        if(!strcmp(key, (*n)->key)) {
            struct node * tmp = *n;
            DATATYPE * val = tmp->value;
            *n = (*n)->next;
            free(tmp->key);
            free(tmp->value);
            free(tmp);
            return val;
        }
    }
    return NULL;
}

static void delete_list(struct node * n) {
    if(n==NULL) { //end of the list
        return;
    } else {
        delete_list(n->next);
        free(n->key);
        free(n->value);
        free(n);
    }
}

void hashmap_destroy(struct hashmap * h) {
    unsigned int i;
    for(i=0; i<NUM_BUCKETS; ++i) {
        delete_list(h->buckets[i]);
    }
    free(h);
}

