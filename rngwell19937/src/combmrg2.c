/******************************************************/
/*  MRG32k5a generator by P. L'Ecuyer.                */
/*  Modifications by P. Savicky, 2009                 */
/*  Outputs numbers in [0, m1-1]                       */
/*  See ../original_files for unmodified version      */
/******************************************************/

 double  s10, s11, s12, s13, s14, s20, s21, s22, s23, s24;

 #define norm 2.3283163396834613e-10
 #define m1   4294949027.0
 #define m2   4294934327.0
 #define a12     1154721.0
 #define a14     1739991.0
 #define a15n    1108499.0
 #define a21     1776413.0
 #define a23      865203.0
 #define a25n    1641052.0

unsigned int MRG32k5a ()
    {
    long   k;
    double p1, p2;
    /* Component 1 */
    p1 = a12 * s13 - a15n * s10;
    if (p1 > 0.0) p1 -= a14 * m1;
    p1 += a14 * s11;   k = p1 / m1;    p1 -= k * m1;
    if (p1 < 0.0) p1 += m1;
    s10 = s11;   s11 = s12;   s12 = s13;  s13 = s14;  s14 = p1;
    /* Component 2 */
    p2 = a21 * s24 - a25n * s20;
    if (p2 > 0.0) p2 -= a23 * m2;
    p2 += a23 * s22;    k  = p2 / m2;   p2 -= k * m2;
    if (p2 < 0.0) p2 += m2;
    s20 = s21;   s21 = s22;   s22 = s23;  s23 = s24;  s24 = p2;
    /* Combination */
    if (p1 < p2)  return ((unsigned int) (p1 - p2 + m1));
    else  return ((unsigned int) (p1 - p2));
    }

