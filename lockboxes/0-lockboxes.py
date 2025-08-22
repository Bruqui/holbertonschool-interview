#!/usr/bin/python3

def canUnlockAll(boxes):
    n = len(boxes)
    visited = set()
    stack = [0]  # start with box 0

    while stack:
        current = stack.pop()
        if current not in visited:
            visited.add(current)
            for key in boxes[current]:
                if 0 <= key < n and key not in visited:
                    stack.append(key)

    return len(visited) == n
