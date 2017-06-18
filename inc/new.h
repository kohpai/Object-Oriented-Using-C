#ifndef NEW_H
#define NEW_H

#include <stddef.h>

void *new(const void *type, ...);
void delete(void *item);
void *clone(const void *self); /* selector function */
int differ(const void *self, const void *b); /* selector function */
size_t sizeOf(const void *self);

#endif /* ifndef NEW_H */
