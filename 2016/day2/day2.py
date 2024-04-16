def part_one():
    file = open("input.txt", "r")
    keypad = [
        ['1', '2', '3'],
        ['4', '5', '6'],
        ['7', '8', '9']
    ]

    initial_pos = [1, 1] #y, x
    code = ""

    for line in file:
        for char in line:
            dir = [0, 0]

            match char:
                case 'U':
                    dir = [-1, 0]
                case 'D':
                    dir = [1, 0]
                case 'L':
                    dir = [0, -1]
                case 'R':
                    dir = [0, 1]
            
            initial_pos[0] += dir[0]
            initial_pos[1] += dir[1]

            if initial_pos[0] < 0 or initial_pos[0] > 2:
                initial_pos[0] -= dir[0]
            if initial_pos[1] < 0 or initial_pos[1] > 2:
                initial_pos[1] -= dir[1]
        
        y, x = initial_pos
        code += keypad[y][x]

    return code


def part_two():
    file = open("input.txt", "r")
    keypad = [
        ['', '', '1', '', ''],
        ['', '2', '3', '4', ''],
        ['5', '6', '7', '8', '9'],
        ['', 'A', 'B', 'C', ''],
        ['', '', 'D', '', ''],
    ]

    initial_pos = [2, 0] #y, x
    code = ""

    for line in file:
        for char in line:
            dir = [0, 0]

            match char:
                case 'U':
                    dir = [-1, 0]
                case 'D':
                    dir = [1, 0]
                case 'L':
                    dir = [0, -1]
                case 'R':
                    dir = [0, 1]
            
            initial_pos[0] += dir[0]
            initial_pos[1] += dir[1]

            if initial_pos[0] < 0 or initial_pos[0] >= len(keypad):
                initial_pos[0] -= dir[0]
            if initial_pos[1] < 0 or initial_pos[1] >= len(keypad[0]):
                initial_pos[1] -= dir[1]
            
            y, x = initial_pos
            if keypad[y][x] == '':
                initial_pos[0] -= dir[0]
                initial_pos[1] -= dir[1]


        
        y, x = initial_pos
        code += keypad[y][x]

    return code



if __name__ == "__main__":
    print(part_one())
    print(part_two())
