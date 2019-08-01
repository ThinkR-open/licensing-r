\name{set.resolution}
\alias{set.resolution}
\title{Set the resolution of the output numbers}

\description{
  The function allows to choose between resolution 53 and 32 bits.
  The resolution is the number of random bits in the numbers
  produced by \code{runif()}.
}

\usage{
  set.resolution(resolution)
}

\arguments{
  \item{resolution}{ Numeric, 53 or 32. The required number of bits.}
}

\details{
  The new setting of the resolution is valid for the next calls to \code{runif()}.

  Generating a random number with the resolution 53 requires two iterations
  of the internal 32 bit generator and
  their outputs are combined to a single number. The slow down of 53 bit
  resolution compared to 32 bit resolution is about 20 percent, since
  an R call to \code{runif()} performs also other actions besides calling
  the internal generator and these actions are run only once.
}

\value{
  \code{NULL} invisibly.
}

