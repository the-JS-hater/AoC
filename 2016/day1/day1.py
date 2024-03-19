def rotate_right(point):
    return point[1], -point[0]


def rotate_left(point):
    return -point[1], point[0]


def taxicab_dist(point):
    return abs(point[0]) + abs(point[1])


def part_one():
    file = open("input.txt", "r")
    movements = [move.strip() for line in file for move in line.split(",")] 
    file.close()
    direction = (0, 1)
    position = [0, 0]   

    for move in movements:
        if move[0] == "R":
            direction = rotate_right(direction)
            
        if move[0] == "L":
            direction = rotate_left(direction)
        
        dist = int(move[1:])
        position[0] += dist * direction[0]
        position[1] += dist * direction[1]
    
    return taxicab_dist(position)
    
    
def part_two():
    file = open("input.txt", "r")
    movements = [move.strip() for line in file for move in line.split(",")] 
    file.close()
    
    
    direction = (0, 1)
    position = [0, 0]  
    visited = set()

    for move in movements:
        if move[0] == "R":
            direction = rotate_right(direction)
            
        if move[0] == "L":
            direction = rotate_left(direction)
            
        dist = int(move[1:])
        
        for i in range(dist):
            position[0] += direction[0]
            position[1] += direction[1]
            if (position[0], position[1]) in visited:
                return taxicab_dist(position)
            visited.add((position[0], position[1]))     
            
            
if __name__ == "__main__":
    print(part_one())
    print(part_two())
