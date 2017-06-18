#include <assert.h>
#include <stdlib.h>

#include "new.prv.h"

void *new(const void *_class, ...)
{
    const struct Class *class = _class;
    void *p = calloc(1, class->size);

    assert(p);
    /* p -> object -> class
     * The following statement assumes that the pointer
     * of class of an object is placed at the top.
     * This means that struct keeps its data in order and
     * no overhead at all.*/
    *(const struct Class**)p = class;

    if (class->ctor) {
        va_list ap;

        va_start(ap, _class);
        p = class->ctor(p, &ap);
        va_end(ap);
    }

    return p;
}

void delete(void *self)
{
    const struct Class **cp = self;

    if (self && *cp && (*cp)->dtor)
        self = (*cp)->dtor(self);
    free(self);
}

int differ(const void *self, const void *b)
{
    const struct Class *const *cp = self;

    assert(self && *cp && (*cp)->differ);
    return (*cp)->differ(self, b);
}

void *clone(const void *self)
{
    const struct Class *const *cp = self;

    assert(self && *cp && (*cp)->clone);
    return (*cp)->clone(self);
}

size_t sizeOf(const void *self)
{
    const struct Class *const *cp = self;

    assert(self && *cp);
    return (*cp)->size;
}

