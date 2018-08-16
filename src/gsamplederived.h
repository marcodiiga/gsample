#ifndef GSAMPLE_DERIVED_H
#define GSAMPLE_DERIVED_H

#include <glib-object.h>
#include "gsamplebase.h"

G_BEGIN_DECLS

#define GSAMPLE_TYPE_DERIVED (gsample_derived_get_type ())
G_DECLARE_FINAL_TYPE(GSampleDerived, gsample_derived,
		             GSAMPLE, DERIVED, GSampleBase)

G_END_DECLS

#endif /* GSAMPLE_DERIVED_H */

/* ex:set ts=4 et: */
