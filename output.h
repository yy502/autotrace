/* output.h: output routines
   Copyright (C) 1999 Bernhard Herzog. */

#ifndef OUTPUT_H
#define OUTPUT_H

#include "ptypes.h"
#include "autotrace.h"

typedef at_output_write_func output_write;
output_write output_get_handler (at_string filename);
output_write output_get_handler_by_suffix(at_string name);
char ** output_list (void);
char * output_shortlist (void);

#endif /* not OUTPUT_H */
