\name{deformula.moneone}
\alias{deformula.moneone}
\title{Integration of one-dimensitonal functions over finite iterval 
with the double exponential formula.}

\description{
  Numerical quadrature of functions of one variable over
  [lower, upper] with the double exponential formula.
}
\usage{
deformula.moneone(f, upper, lower, ...,
  zero.eps = 1.0e-12, rel.tol = 1.0e-8,
  start.divisions = 8, max.iter = 12)
}
\arguments{
  \item{f}{an integrand function for integral.}
  \item{lower, upper}{the limits of integration.}
  \item{\dots}{additional arguments to be passed to ‘f’.}
  \item{zero.eps}{a threshold value to be zero.}
  \item{rel.tol}{a value for relative tolerance.}
  \item{start.divisions}{the initial number of divides.}
  \item{max.iter}{an integer for the maximum number of iterations to increase divides.}
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
  \code{\link{deformula.zeroinf}}
}
\examples{

f <- function(x, a) exp(-a*x)

deformula.moneone(f, 1, 0, a=0.1)

}
