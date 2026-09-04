#!/usr/bin/python3
"""
Module that computes how much rainwater is retained between walls.

Given a list of non-negative integers representing wall heights of
unit width 1, each position can hold water up to the lower of the
tallest wall to its left and the tallest wall to its right, minus
its own height. The two-pointer approach below tracks those running
maxima from both ends, so the total is found in a single pass with
constant extra space.
"""


def rain(walls):
    """Return the total units of rainwater retained between walls.

    Args:
        walls (list): list of non-negative integers (wall heights).

    Returns:
        int: total amount of rainwater retained, 0 if walls is empty.
    """
    if not walls:
        return 0

    left, right = 0, len(walls) - 1
    left_max, right_max = walls[left], walls[right]
    water = 0

    while left < right:
        if left_max <= right_max:
            left += 1
            if walls[left] > left_max:
                left_max = walls[left]
            else:
                water += left_max - walls[left]
        else:
            right -= 1
            if walls[right] > right_max:
                right_max = walls[right]
            else:
                water += right_max - walls[right]

    return water
