package main

import (
	"os"
	"strings"
)

func ReadData() (map[rune][][2]int, [2]int) {
	dat, _ := os.ReadFile("./d8.in")
	lines := strings.Split(string(dat), "\n")

	res := make(map[rune][][2]int)

	for y := range len(lines) {
		for x, v := range lines[y] {
			if v == '.' {
				continue
			}

			res[v] = append(res[v], [2]int{y, x})
		}
	}

	return res, [2]int{len(lines), len(lines[0])}
}