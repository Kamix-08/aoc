package main

import "fmt"

func main() {
	bytes := ReadData()

	count := 1
	var pos [2]int

	for y, line := range bytes {
		for x, cell := range line {
            if cell == '^' {
				pos = [2]int{y,x}
				break
            }
        }

		if(pos[0] != 0 && pos[1] != 0) {
			break
		}
	}

	dir := 0
	directions := [4][2]int{ {-1,0}, {0,1}, {1,0}, {0,-1} }

	for {
		if(bytes[pos[0]][pos[1]] == '.') {
			bytes[pos[0]][pos[1]] = 'X'
			count++
		}

		new_pos := [2]int{pos[0] + directions[dir][0], pos[1] + directions[dir][1]}

		if(new_pos[0] >= len(bytes) || new_pos[1] >= len(bytes[0]) || new_pos[0] < 0 || new_pos[1] < 0) {
			break
		}

		if(bytes[new_pos[0]][new_pos[1]] == '#') {
			dir = (dir+1)%4
			continue
		}

		pos = new_pos
	}

	fmt.Println(count)
}