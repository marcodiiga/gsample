#include "src/gsamplebase.h"
#include "src/gsamplederived.h"
#include <stdio.h>

int main() {
	GSampleBase *base = (GSampleBase*)g_object_new(GSAMPLE_TYPE_DERIVED, 0);
	GError *error = NULL;

	gsample_base_func(base, &error);

	g_clear_object(&base);
	return 0;
}

/* ex:set ts=4 et: */