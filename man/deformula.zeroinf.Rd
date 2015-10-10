\name{deformula.zeroinf}
\alias{deformula.zeroinf}
\title{Integration of one-dimensitonal functions over infinite iterval 
with the double exponential formula.}

\description{
  Numerical quadrature of functions of one variable over
  [0, infinity) with the double exponential formula.
}
\usage{
deformula.zeroinf(f, ...,
  zero.eps = 1.0e-12, rel.tol = 1.0e-8,
  start.divisions = 8, max.iter = 12)
}
\arguments{
  \item{f}{an R function taking a numeric first argument.}
  \item{\dots}{additional arguments to be passed to ‘f’.}
  \item{zero.eps}{a threshold value to be zero.}
  \item{rel.tol}{relative accuracy requested.}
  \item{start.divisions}{the initial number of subintervals.}
  \item{max.iter}{an integer for the maximum number of iterations to increase
  subintervals.}
}
\value{
  returns a list with components;
  \item{value}{an value for integral.}
  \item{x}{a vector of subintervals.}
  \item{w}{a vector of weights.}
  \item{t}{a vector of subintervals for trapezoid integral.}
  \item{h}{a value of subinterval.}
  \item{message}{OK or a string for the error message.}
}
\seealso{
  \code{\link{deformula.moneone}}
}
\examples{

f <- function(x, a) exp(-a*x)

deformula.zeroinf(f, a=0.1)

}
