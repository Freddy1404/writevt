#ifndef _LCT_UTILS_H
#define _LCT_UTILS_H

#include <stdio.h>
#include <linux/kd.h>
#include <lct/unicode.h>

#if 0
/* just an idea ... */
typedef enum { LCT_OK, LCT_ERRNO, LCT_ENOTYET } lct_errcode;
#endif

/* from sfm-utils.c */
unicode sgetunicode(char **p0);
void unimapdesc_addpair(int fp, unicode un, struct unimapdesc *list, int *listsz);
void unimapdesc_adjust(struct unimapdesc* list);

unicode sfm_lookup (struct unimapdesc *sfm,
		    unsigned short fontpos, unsigned short start);

/* sfm-fallback */
int sfm_fallback_read (FILE* f, unicode** *sfmf, unsigned *size);
int sfm_fallback_add (unicode** sfmf, unsigned size,
		      struct unimapdesc* ilist,
		      struct unimapdesc* olist);

/* from saveunimap.c */
void sfm_save(int fd, char *oufil, int verbose, int no_act);

#endif /* _LCT_UTILS_H */
