\name{rngwell19937-package}
\alias{rngwell19937}
\concept{ random number generator }
\docType{package}

\title{Random number generator of Mersenne-Twister type with resolution 53 bits}

\description{
  After loading the package, the default random number generator in R
  is replaced by the long period linear generator
  WELL19937a by F. Panneton, P. L'Ecuyer and M. Matsumoto
  with a transformation to produce numbers in \code{(0,1)}
  with 53 (the default) or 32 random bits. In particular, the
  functions \code{set.seed()}, \code{runif()} and the object
  \code{.Random.seed} refer to WELL19937a.

  A call of \code{detach("package:rngwell19937", unload=TRUE)}
  restores the default random number generator in R.
}

\seealso{
  \code{\link{set.resolution}},
  \code{\link{set.initialization}},
  \code{\link{set.vector.seed}},
  \code{\link{well19937.validate}}
}

\references{
F. Panneton, P. L'Ecuyer, and M. Matsumoto,
``Improved Long-Period Generators Based on Linear Recurrences Modulo 2'',
ACM Transactions on Mathematical Software, 32, 1 (2006), 1-16.
}

\keyword{distribution}

