
#ifndef HASHMAP
#define HASHMAP

#define NUM_BUCKETS 100
#define DATATYPE float

struct hashmap;

struct hashmap * hashmap_new();
void hashmap_insert(struct hashmap *, const char *, DATATYPE);
DATATYPE * hashmap_lookup(struct hashmap *, const char *);
DATATYPE * hashmap_delete(struct hashmap *, const char *);
void hashmap_destroy(struct hashmap *);

#endif 

