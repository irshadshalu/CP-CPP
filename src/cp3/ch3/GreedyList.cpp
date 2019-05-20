/*
 * Coin Change (Greedy) ==>
 * Make amount V from given coins for some coin denomination can choose largest possible first greedily and so on
 * 
 * Some denomitions where it works;
 * {1, 2, 4, 8, 16}
 * {1, 5, 10, 25}
 * 
 * But wont work for:
 * {1, 3, 4} and V = 6
 */

/*
 * Load balancing ==>
 * Only of S <= 2C? where s are no of specimens and c is no containers
 * Add 0 weight dummies, S - 2C
 */ 

/*
 * Interval Covering ==>
 * Sort intervals by increasing start point and decreasing end point to select largest possible interval first (as far as right)
 */ 

/*
 * Dragon of loowater ==>
 * P: knight with height H can kill dragon with head width D only if D <= H. A knight can kill only 1 dragon
 * Greedy: Each dragon head should be chopped by a knight with the shortest height that is at least as tall 
 *         as the diameter of the dragon’s head
 */

/*
 * Other ==>
 * > Huffman Codes
 * > Fractional Knapsack
 * > Certain Job Scheduling 
 */ 