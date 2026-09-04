# Rain

Given a list of non-negative integers representing the heights of walls with
unit width 1, calculate how many square units of water will be retained after
it rains.

## Task

* `0-rain.py` — `def rain(walls)`: returns an integer, the total amount of
  rainwater retained. The ends of the list are open, so no water is retained
  past them. An empty list returns `0`.

## Approach

Water above a wall is bounded by the tallest wall on each side:
`min(max_left, max_right) - height`. Two pointers walk inward from both ends
while tracking those maxima, which gives an O(n) time, O(1) space solution.

## Example

```
$ cat 0_main.py
#!/usr/bin/python3
"""
0_main
"""
rain = __import__('0-rain').rain

if __name__ == "__main__":
    walls = [0, 1, 0, 2, 0, 3, 0, 4]
    print(rain(walls))
    walls = [2, 0, 0, 4, 0, 0, 1, 0]
    print(rain(walls))

$ ./0_main.py
6
6
```
