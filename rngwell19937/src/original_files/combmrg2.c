
 #define norm 2.328306549295728e-10
 #define m1   4294967087.0
 #define m2   4294944443.0
 #define a12     1403580.0
 #define a13n     810728.0
 #define a21      527612.0
 #define a23n    1370589.0

 double  s10, s11, s12, s20, s21, s22;

 double MRG32k3a ()
    {
    long   k;
    double p1, p2;
    /* Component 1 */
    p1 = a12 * s11 - a13n * s10;
    k = p1 / m1;   p1 -= k * m1;   if (p1 < 0.0) p1 += m1;
    s10 = s11;   s11 = s12;   s12 = p1;
    /* Component 2 */
    p2 = a21 * s22 - a23n * s20;
    k  = p2 / m2;  p2 -= k * m2;   if (p2 < 0.0) p2 += m2;
    s20 = s21;   s21 = s22;   s22 = p2;
    /* Combination */
    if (p1 <= p2) return ((p1 - p2 + m1) * norm);
    else return ((p1 - p2) * norm);
    }

######################

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

double MRG32k5a ()
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
    if (p1 <= p2)  return ((p1 - p2 + m1) * norm);
    else  return ((p1 - p2) * norm);
    }

######################

 #define norm  1.0842021724855052e-19
 #define m1    9223372036854769163
 #define m2    9223372036854754679
 #define a12   1754669720
 #define q12   5256471877
 #define r12   251304723
 #define a13n  3182104042
 #define q13   2898513661
 #define r13   394451401
 #define a21   31387477935
 #define q21   293855150
 #define r21   143639429
 #define a23n  6199136374
 #define q23   1487847900
 #define r23   985240079

 long long s10, s11, s12, s20, s21, s22;

 double MRG63k3a ()
    {
    long long h, p12, p13, p21, p23;
    /* Component 1 */
    h = s10 / q13;   p13 = a13n * (s10 - h * q13) - h * r13;
    h = s11 / q12;   p12 = a12  * (s11 - h * q12) - h * r12;
    if (p13 < 0) p13 += m1;    
    if (p12 < 0) p12 += m1 - p13;  else p12 -= p13;
    if (p12 < 0) p12 += m1;    
    s10 = s11;  s11 = s12;  s12 = p12;
    /* Component 2 */
    h = s20 / q23;   p23 = a23n * (s20 - h * q23) - h * r23;
    h = s22 / q21;   p21 = a21  * (s22 - h * q21) - h * r21;
    if (p23 < 0) p23 += m2;
    if (p21 < 0) p21 += m2 - p23;  else p21 -= p23;
    if (p21 < 0) p21 += m2;    
    s20 = s21;  s21 = s22;  s22 = p21;
    /* Combination */
    if (p12 > p21) return ((p12 - p21) * norm);
    else return ((p12 - p21 + m1) * norm);
    }

