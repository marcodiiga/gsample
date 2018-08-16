#include "gsamplederived.h"
#include <stdio.h>

typedef struct _GSampleDerived
{
    GSampleBase parent_instance;
} GSampleDerived;

typedef struct _GSampleDerivedPrivate
{
    int dpriv;
} GSampleDerivedPrivate;

G_DEFINE_TYPE_WITH_PRIVATE(GSampleDerived, gsample_derived, GSAMPLE_TYPE_BASE)

static void
gsample_derived_func_impl(GSampleBase *obj, 
                          GError **error) {
    printf("Derived func impl\n");
    /*
     * Chaining up
     * GSAMPLE_BASE_CLASS(gsample_derived_parent_class)->func(obj, error);
    */
}

static void
gsample_derived_class_init(GSampleDerivedClass *klass)
{
    //GObjectClass *object_class = G_OBJECT_CLASS(klass);
    GSampleBaseClass *reader_class = GSAMPLE_BASE_CLASS(klass);

    printf("Derived class init\n");
	reader_class->func = gsample_derived_func_impl;
}

#define GET_PRIV(o) (GSampleDerivedPrivate *) gsample_derived_get_instance_private(o)

static void
gsample_derived_init(GSampleDerived *obj)
{
    GSampleDerivedPrivate *d = GET_PRIV(obj);
    printf("Derived init\n");
    d->dpriv = 22;
}

/* ex:set ts=4 et: */