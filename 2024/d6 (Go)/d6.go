package main

import (
	"os"
	"strings"
)

func ReadData() [][]byte {
	data, _ := os.ReadFile("./d6.in")

	lines := strings.Split(string(data), "\n")
	bytes := make([][]byte, len(lines))

	for i, line := range lines {
		bytes[i] = []byte(line)
	}

	return bytes
}