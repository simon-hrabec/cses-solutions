# # Binomial Coefficients - solution

[Link to code - implementation (extended Euclidean algorithm)](https://github.com/simon-hrabec/cses-solutions/blob/master/mathematics/binomial-coefficients/binomial-coefficients-eea.cpp)
[Link to code - implementation (Fermat's little theorem)](https://github.com/simon-hrabec/cses-solutions/blob/master/mathematics/binomial-coefficients/binomial-coefficients-flt.cpp)

This problem is either medium or hard difficulty depending on your knowledge of certain field of mathematics. This problem asks for a binomial coefficient. It has quite straigtfoward formula to calculate

`C(n, k) = n!/(k!(n-k)!)`

However the issue arrises from the bounds - `a` and `b` can be up to as large as `10^6` and also the result is requested to be submited in the `10^9+7` (famous prime number used in CP) modulo form. This substantionally changes this problem. We need to employ several techniques/formulas and combine them to solve this task.

## Precompute the factorials
We are asked to solve up to `10^5` queries (`n`) and in each we should calculate 3 factorials. Hence, it might be much easier to just precompute all possible factorials (modulo `10^9+7`). We could copy paste the array into the source code but this takes approx 10 MB and CSES does not accept files of such sizes. Another way is to make the whole array `constexpr`, but this takes too long to compile (at least for my implementation). Hence, we need to run this calculation once at the beginning.

## Division in modular arithmetic
Normally when computing the binomial coefficient we would first calculate the factorials and then divide them, having the guarantee that they will be divisible. But we cannot do a simple division once we have taken the modulo. Here the [modular multiplicative inverse](https://en.wikipedia.org/wiki/Modular_multiplicative_inverse) comes to the rescue. If the number and the modulo are [relatively prime (coprime)](https://en.wikipedia.org/wiki/Coprime_integers), we can use the [extended Euclidean algorithm](https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Computing_multiplicative_inverses_in_modular_structures). However, since the modulo is a prime number (this is good to remember for `10^9+7`, since it is always used in CP when the output should be too large), we can also use the [Fermat's little theorem](https://en.wikipedia.org/wiki/Fermat%27s_little_theorem).

## Putting it together
The result can be calculated by the following steps:
 1. Precompute all possible factorials (modulo)
 2. For each input pair compute the 2 modular multiplicative inverses.
 3. Multiply the factorial with the 2 inverses (while doing modulo in each step).

## Catches
Having the modulo as an unsigned integer (`constexpr uint64_t MOD = 1'000'000'007;`) rather than signed can lead to bugs when using the extended Euclidean algorithm.
