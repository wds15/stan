#ifndef STAN_ANALYZE_MCMC_SPLIT_CHAINS_HPP
#define STAN_ANALYZE_MCMC_SPLIT_CHAINS_HPP

#include <cmath>
#include <vector>

namespace stan {
namespace analyze {

  /**
   * Returns samples split in half.
   *
   * See more details in Stan reference manual section "Effective
   * Sample Size". http://mc-stan.org/users/documentation
   *
   * Current implementation assumes chains are all of equal size and
   * draws are stored in contiguous blocks of memory.
   *
   * @param std::vector stores pointers to arrays of chains
   * @param std::vector stores sizes of chains
   * @return effective sample size for the specified parameter
   */
  inline
  std::vector<const double*>
  split_chains(const std::vector<const double*>& draws,
               const std::vector<size_t>& sizes) {

    int num_chains = sizes.size();

    // need to generalize to each jagged draws per chain
    size_t num_draws = sizes[0];
    for (int chain = 1; chain < num_chains; ++chain) {
      num_draws = std::min(num_draws, sizes[chain]);
    }

    double half = num_draws / 2.0;
    int half_draws = std::ceil(half);
    std::vector<const double*> split_draws(2 * num_chains);
    for (int n = 0; n < num_chains; ++n) {
       split_draws[2*n] = &draws[n][0];
       split_draws[2*n + 1] = &draws[n][half_draws];
  }

    return split_draws;
  }

  /**
   * Returns samples split in half.
   *
   * See more details in Stan reference manual section "Effective
   * Sample Size". http://mc-stan.org/users/documentation
   *
   * Current implementation assumes chains are all of equal size and
   * draws are stored in contiguous blocks of memory.  Argument size
   * will be broadcast to same length as draws.
   *
   * @param std::vector stores pointers to arrays of chains
   * @param size_t size of chains
   * @return effective sample size for the specified parameter
   */
  inline
  double split_chains(std::vector<const double*> draws,
                      size_t size) {
    int num_chains = draws.size();
    std::vector<size_t> sizes(num_chains, size);
    return split_chains(draws, sizes);
  }

} // namespace analyze
} // namespace stan

#endif
