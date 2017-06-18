#ifndef NEW_PRV_H
#define NEW_PRV_H

#include <stddef.h>
#include <stdarg.h>

struct Class {
    /* the size must also includes size of an object which contains
     * the pointer of class */
    size_t size;
    void * (*ctor) (void *self, va_list *app);
    void * (*dtor) (void *self);
    void * (*clone) (const void *self);
    int (*differ) (const void *self, const void *b);
};

#endif /* ifndef NEW_PRV_H */
