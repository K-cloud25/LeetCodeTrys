def twoSum( nums: list[int], target: int) -> list[int]:
    values = {}
    for idx, value in enumerate(nums):
        if target - value in values:
            return [values[target - value], idx]
        else:
            values[value] = idx

t = twoSum([3,2,4],6)
print(t)


