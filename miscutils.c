#include "local.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#include "cline.h"

char* progname;					  /* exported global holding the
                                                     running program's invocation name */

void version()
{
  /* Same format as GNU utils: dump to stdout, not stderr */
  printf ("%s: (%s) %s\n", progname, PACKAGE, VERSION);
}

char* strip_path (const char* name)
{
  char* strippedname;
  
  if (NULL == (strippedname = strrchr(name, '/')))
    strippedname = (char*)name;
  else
    strippedname++;					  /* forget last '/' */

  return strippedname;
}

void utils_init(char* argv[])
{
  progname = strip_path(argv[0]);
}

void simple_options(int argc, char **argv, UsageFunc usage)
{
  /* Simple getopt handling for programs that don't have any options.
   * Depends on a locally-defined usage function in each program.
   */
     
  const struct option long_opts[] = {
    { "help", no_argument, NULL, 'h' },
    { "version", no_argument, NULL, 'V' },
    { NULL, 0, NULL, 0 }
  };
  int c;

  while ( (c = getopt_long (argc, argv, "Vh", long_opts, NULL)) != EOF) {
    switch (c) {
    case 'h':
      usage();
      exit(0);
    case 'V':
      version();
      exit(0);
    case '?':
      usage();
      exit(1);
    }
  }
  if (argc != optind) {
    fprintf(stderr, _("%s: Unexpected arguments.\n"), 
	    progname);
    exit(1);
  }       
}
      
  
