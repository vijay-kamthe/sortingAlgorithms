
#ifndef HASHMAP
#define HASHMAP

// new insert lookup delete destroy

struct hashmap;

struct hashmap * hashmap_new();
void hashmap_insert(struct hashmap *, const char *, void *);
void * hashmap_lookup(const char *);
void * hashmap_delete(struct hashmap *, const char *);
void hashmap_destroy(struct hashmap *);

#endif 

