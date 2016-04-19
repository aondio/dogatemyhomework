#include <stdio.h>
#include <stdlib.h>

#include "vrt.h"
#include "cache/cache.h"

#include "vcc_if.h"

int i;
const char *crap[] = {
	"Constipation has made me a walking time bomb.",
	"I super-glued my eye thinking it was contact solution.",
	"My left turn signal was out so I had to make all right turns to get to work.",
	"I made the mistake of letting in some Jehovah's Witnesses and they wouldn't leave.",
	"I was sitting in the bathroom and my feet and legs fell asleep. When I stood, up I fell and broke my ankle",
	"I won't be coming in to work today. My wife informed me that she is going to conceive today, and I really want to be there when it happens.",
	NULL
};

int
init_function(struct vmod_priv *priv, const struct VCL_conf *conf)
{
	i = rand()%6;
	return (0);
}

VCL_STRING
vmod_dogatemyhomework(const struct vrt_ctx *ctx)
{

	char *p;
	unsigned u, v;

	u = WS_Reserve(ctx->ws, 0);
	p = ctx->ws->f;
	v = snprintf(p, u, "I can't come to work because %s", crap[i]);
	v++;
	if (v > u) {
		WS_Release(ctx->ws, 0);
		return (NULL);
	}
	WS_Release(ctx->ws, v);
	return (p);
}
