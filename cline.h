#ifndef _LCT_CLINE_H
#define _LCT_CLINE_H

#include "local.h"

/* required by some macros defined here */
#include <sysexits.h>
#include <stdio.h>
#include <locale.h>

#define LOCALEDIR "/usr/share/locale"

#define badusage(ERRMSG) do { \
  if (ERRMSG) \
    fprintf (stderr, "%s: %s\n", progname, ERRMSG); \
  usage(); \
  exit(EX_USAGE); \
} while(0)

/* setup localization for a program */
#define miscsetup() do { \
  setlocale (LC_ALL, ""); \
  bindtextdomain (PACKAGE, LOCALEDIR); \
  textdomain (PACKAGE); \
  utils_init(argv); \
} while (0)

#define OPT(option, desc) printf("\t" option "%s\n", desc)

#define OPTIONS_ARE() printf(_("valid options are:\n"))
#define COMMANDS_ARE() printf(_("valid commands are:\n"))
#define HELPDESC _("display this help text and exit")
#define VERSIONDESC _("display version information and exit")


/* miscutils.c */
typedef void (*UsageFunc) (void);

extern char* progname;

void utils_init(char* argv[]);
void simple_options(int argc, char **argv, UsageFunc usage);
char* strip_path (const char* name);
void version();

#endif /* _LCT_CLINE_H */
