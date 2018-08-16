#include "gsamplebase.h"
#include <stdio.h>

typedef struct _GSampleBasePrivate {
	int bpriv;
} GSampleBasePrivate;

G_DEFINE_ABSTRACT_TYPE_WITH_PRIVATE(GSampleBase, gsample_base, G_TYPE_OBJECT)

static void 
gsample_base_func_base_impl(GSampleBase *obj,
                            GError ** error)
{
    printf("Base func impl\n");
}

static void
gsample_base_class_init(GSampleBaseClass *klass)
{
    printf("Base class init & vtable setup\n");
	klass->func = gsample_base_func_base_impl;
}

#define GET_PRIV(o) (GSampleBasePrivate *) gsample_base_get_instance_private(o)

static void
gsample_base_init(GSampleBase *obj)
{
    GSampleBasePrivate *d = GET_PRIV(obj);
    printf("Base init\n");
	d->bpriv = 22;
}


void gsample_base_func(GSampleBase *obj,
	                   GError ** error)
{
    printf("Base vtable func forwarding\n");
	GSAMPLE_BASE_GET_CLASS(obj)->func(obj, error);
}

/* ex:set ts=4 et: */