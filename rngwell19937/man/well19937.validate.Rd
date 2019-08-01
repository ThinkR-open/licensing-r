\name{well19937.validate}
\alias{well19937.validate}
\title{Checking the installation of the generator}

\description{
  The generator is run with a fixed seed and its output is compared to
  stored precomputed values.
}

\usage{
  well19937.validate()
}

\details{
  Loading the package \code{rngwell19937} sets \code{RNGkind("user-supplied")}.
  If this setting is changed by the user before calling \code{well19937.validate()},
  the function resets \code{RNGkind("user-supplied")}.
}

\value{
  The function prints the result of the test.
  The output value is \code{NULL} invisibly.
}

\examples{
	well19937.validate()
}

