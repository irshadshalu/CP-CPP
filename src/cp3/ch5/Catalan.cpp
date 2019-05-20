/*
 * Catalan Number ==>
 * Cat(N) = (2N)C(N) / (N+1); Cat(0) = 1;
 * 
 * cat(m) = (2(2m-1)/(m+1)) * cat(m-1)
 * 
 * Applications:
 * 1. Cat(n) counts the number of distinct binary trees with n vertices
 * 2. Cat(n) counts the number of expressions containing n pairs of parentheses which are
 *    correctly matched, e.g. for n = 3, we have: ()()(), ()(()), (())(), ((())), and (()())
 * 3. Cat(n) counts the number of monotonic paths along the edges of an n×n grid, which
 *    do not pass above the diagonal. A monotonic path is one which starts in the lower
 *    left corner, finishes in the upper right corner, and consists entirely of edges pointing
 *    rightwards or upwards
 * 
 */ 