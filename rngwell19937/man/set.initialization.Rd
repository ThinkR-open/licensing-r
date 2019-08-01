\name{set.initialization}
\alias{set.initialization}
\title{Set initialization algorithm}

\description{
  The function allows to specify the initialization algorithm used by the
  function \code{set.seed()}.
}

\usage{
  set.initialization(initialization)
}

\arguments{
  \item{initialization}{ Character, either "mrg32k5a" or "sfmt". The required
   initialization algorithm.}
}

\details{
  Initialization "mrg32k5a" uses the generator MRG32k5a by P. L'Ecuyer, see
  the citation below.
  Initialization "sfmt" is the same as in SFMT generator by 
  Mutsuo Saito (Hiroshima University) and
  Makoto Matsumoto (Hiroshima University).
}

\value{
  \code{NULL} invisibly.
}

\references{
  P. L'Ecuyer, ``Good Parameter Sets for Combined Multiple Recursive Random Number Generators'',
  Shorter version in Operations Research, 47, 1 (1999), 159--164.
}

