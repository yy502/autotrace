/* spline.h: manipulate the spline representation. */

#ifndef SPLINE_H
#define SPLINE_H

#include <stdio.h>
#include "autotrace.h"
#include "ptypes.h"

typedef at_polynomial_degree polynomial_degree;
typedef at_spline_type spline_type;

#define LINEARTYPE          AT_LINEARTYPE
#define QUADRATICTYPE       AT_QUADRATICTYPE
#define CUBICTYPE           AT_CUBICTYPE
#define PARALLELELLIPSETYPE AT_PARALLELELLIPSETYPE
#define ELLIPSETYPE         AT_ELLIPSETYPE
#define CIRCLETYPE          AT_CIRCLETYPE

#define START_POINT(spl)	((spl).v[0])
#define CONTROL1(spl)		((spl).v[1])
#define CONTROL2(spl)		((spl).v[2])
#define END_POINT(spl)		((spl).v[3])
#define SPLINE_DEGREE(spl)	((spl).degree)
#define SPLINE_LINEARITY(spl)	((spl).linearity)

#ifndef _IMPORTING
/* Print a spline on the given file.  */
extern void print_spline (FILE *, spline_type);

/* Evaluate SPLINE at the given T value.  */
extern real_coordinate_type evaluate_spline (spline_type spline, real t);
#endif

/* Each outline in a character is typically represented by many
   splines.  So, here is a list structure for that:  */
typedef at_spline_list_type spline_list_type;


/* An empty list will have length zero (and null data).  */
#define SPLINE_LIST_LENGTH(s_l) ((s_l).length)

/* The address of the beginning of the array of data.  */
#define SPLINE_LIST_DATA(s_l) ((s_l).data)

/* The element INDEX in S_L.  */
#define SPLINE_LIST_ELT(s_l, index) (SPLINE_LIST_DATA (s_l)[index])

/* The last element in S_L.  */
#define LAST_SPLINE_LIST_ELT(s_l) \
  (SPLINE_LIST_DATA (s_l)[SPLINE_LIST_LENGTH (s_l) - 1])

/* The previous and next elements to INDEX in S_L.  */
#define NEXT_SPLINE_LIST_ELT(s_l, index)				\
  SPLINE_LIST_ELT (s_l, ((index) + 1) % SPLINE_LIST_LENGTH (s_l))
#define PREV_SPLINE_LIST_ELT(s_l, index)				\
  SPLINE_LIST_ELT (s_l, index == 0					\
                        ? SPLINE_LIST_LENGTH (s_l) - 1			\
                        : index - 1)

#ifndef _IMPORTING
/* Construct and destroy new `spline_list_type' objects.  */
extern spline_list_type *new_spline_list (void);
extern spline_list_type *init_spline_list (spline_type);
extern void free_spline_list (spline_list_type);

/* Append the spline S to the list S_LIST.  */
extern void append_spline (spline_list_type *s_list, spline_type s);

/* Append the elements in list S2 to S1, changing S1.  */
extern void concat_spline_lists (spline_list_type *s1, spline_list_type s2);
#endif

typedef at_spline_list_array_type spline_list_array_type;

/* Turns out we can use the same definitions for lists of lists as for
   just lists.  But we define the usual names, just in case.  */
#define SPLINE_LIST_ARRAY_LENGTH SPLINE_LIST_LENGTH
#define SPLINE_LIST_ARRAY_DATA SPLINE_LIST_DATA
#define SPLINE_LIST_ARRAY_ELT SPLINE_LIST_ELT
#define LAST_SPLINE_LIST_ARRAY_ELT LAST_SPLINE_LIST_ELT

#ifndef _IMPORTING
/* The usual routines.  */
extern spline_list_array_type new_spline_list_array (void);
extern void append_spline_list (spline_list_array_type *, spline_list_type);
#endif

#ifdef _EXPORTING
extern void __declspec(dllexport) __stdcall free_spline_list_array (spline_list_array_type *);
#elif _IMPORTING
extern void __declspec(dllimport) __stdcall free_spline_list_array (spline_list_array_type *);
#else
extern void free_spline_list_array (spline_list_array_type *);
#endif

#endif /* not SPLINE_H */

