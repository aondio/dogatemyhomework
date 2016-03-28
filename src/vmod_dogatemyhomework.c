#include <stdio.h>
#include <stdlib.h>

#include "vrt.h"
#include "cache/cache.h"

#include "vcc_if.h"

static const char *crap[] = {
		"I’d just put a casserole in the oven",
		"My plastic surgery (for enhancement purposes) needed some \"tweaking\" to get it just right",
		"I was sitting in the bathroom and my feet and legs fell asleep. When I stood, up I fell and broke my ankle ",
};


int
init_function(struct vmod_priv *priv, const struct VCL_conf *conf)
{
	return (0);
}

VCL_STRING
vmod_dogatemyhomework(const struct vrt_ctx *ctx)
{
	int len;
	len = (sizeof(crap)/ sizeof(crap[0])) - 1;

	char *p;
	unsigned u, v;
	int i;

	u = WS_Reserve(ctx->ws, 0); /* Reserve some work space */
	p = ctx->ws->f;		/* Front of workspace area */

	i = rand()%len;
	v = snprintf(p, u, "I can't come to work because %s", crap[i]);
	v++;
	if (v > u) {
		/* No space, reset and leave */
		WS_Release(ctx->ws, 0);
		return (NULL);
	}
	/* Update work space with what we've used */
	WS_Release(ctx->ws, v);
	return (p);
}
