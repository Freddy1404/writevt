#ifndef _LCT_LOCAL_H
#define _LCT_LOCAL_H

#define _GNU_SOURCE

#include <locale.h>


# include <libintl.h>
# define _(String) gettext (String)
# ifdef gettext_noop
#  define N_(String) gettext_noop (String)
# else
#  define N_(String) (String)
# endif


#endif /* _LCT_LOCAL_H */
