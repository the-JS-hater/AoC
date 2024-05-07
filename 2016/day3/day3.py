def part_one():
    file = open("input.txt", "r")
    sum = 0
    lines = file.readlines()
    
    for line in lines:
        nums = sorted([int(str_int.strip()) for str_int in line.split()])
        if nums[0] + nums[1] > nums[2]:
            sum += 1
    
    print("Solution to part one: {}".format(sum))


def part_two():
    file = open("input.txt", "r")
    sum = 0
    lines = file.readlines()
    matrix = []

    for line in lines:
        nums = [int(str_int.strip()) for str_int in line.split()]
        matrix.append(nums)

    for i in range(0, len(matrix), 3):
        line_1 = matrix[i]
        line_2 = matrix[i + 1]
        line_3 = matrix[i + 2]
        for i in range(3): 
            if line_1[i] + line_2[i] > line_3[i] \
                and line_2[i] + line_3[i] > line_1[i] \
                and line_3[i] + line_1[i] > line_2[i]: 
                sum += 1

    print("Solution to part two: {}".format(sum))


if __name__ == "__main__":
    part_one()
    part_two()
