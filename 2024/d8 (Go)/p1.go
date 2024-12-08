package main

import "fmt"

func main() {
	data, dim := ReadData()
	counter := 0

	antinodes := make(map[[2]int]bool)

	for _, list := range data {
		for i, iv := range list {
			for j, jv := range list {
				if i == j {
					continue
				}

				// p1
				// ry := 2 * iv[0] - jv[0]
				// rx := 2 * iv[1] - jv[1]

				// p2
				n := 0
				
				for {
					ry := iv[0] + (iv[0] - jv[0]) * n
					rx := iv[1] + (iv[1] - jv[1]) * n

					n++

					if ry >= 0 && ry < dim[0] && rx >= 0 && rx < dim[1] {
						if (antinodes[[2]int{ry, rx}]) {
							continue
						}
	
						antinodes[[2]int{ry, rx}] = true
						counter++
						continue
					}

					break
				}


			}
		}
	}

	fmt.Println(counter)
}