#ifndef GSAMPLE_BASE_H
#define GSAMPLE_BASE_H

#include <glib-object.h>
#include <gobject/gtype.h>

G_BEGIN_DECLS

#define GSAMPLE_TYPE_BASE (gsample_base_get_type ())
G_DECLARE_DERIVABLE_TYPE(GSampleBase, gsample_base, GSAMPLE, BASE, GObject)

typedef struct _GSampleBaseClass
{
    GObjectClass parent_class;

    void(*func) (GSampleBase *obj, GError     **error);
} GSampleBaseClass;

void
gsample_base_func(GSampleBase *obj, GError **error);

G_END_DECLS

#endif /* GSAMPLE_BASE_H */

/* ex:set ts=4 et: */
