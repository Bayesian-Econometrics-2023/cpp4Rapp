#include <RcppArmadillo.h>

using namespace Rcpp;
using namespace arma;

// [[Rcpp::export]]
Rcpp::List nicelr (vec y, mat x) {
  mat xx_inv = inv_sympd(x.t() * x);
  vec beta_hat = xx_inv * x.t() * y;
  double sigma2 = as_scalar( (y - x * beta_hat).t() * (y - x * beta_hat) / y.n_elem );
  mat cov_beta_hat = sigma2 * xx_inv;
  return List::create(
    _["beta_hat"] = beta_hat,
    _["cov_beta_hat"] = cov_beta_hat
  );
}
