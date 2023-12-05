#!/usr/bin/env python3

def count_m_ary_partitions(base, n):
    # Memoization table where dp[i] will store the number of partitions for i
    dp = [0] * (n + 1)

    # There is always one way to partition 0
    dp[0] = 1

    # Iterate through powers of the base less than or equal to n
    power = 1
    while power <= n:
        # Update the ways to partition numbers from 'power' to 'n'
        for i in range(power, n + 1):
            dp[i] += dp[i - power]

        # Next power of the base
        power *= base

    return dp[n]

def main():
    # Read the number of data sets
    num_data_sets = int(input())

    for _ in range(num_data_sets):
        # Read data set number, base, and the integer
        data_set_num, base, n = map(int, input().split())
        # Calculate the number of m-ary partitions
        partitions_count = count_m_ary_partitions(base, n)
        # Output the result
        print(f"{data_set_num} {partitions_count}")

if __name__ == "__main__":
    main()
