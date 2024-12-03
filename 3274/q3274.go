package main

import (
	"fmt"
	"unicode/utf8"
)

func checkTwoChessboards(coordinate1 string, coordinate2 string) bool {
	c11 := coordinate1[0]
	c12 := coordinate1[1]
	c21 := coordinate2[0]
	c22 := coordinate2[1]
	fmt.Println(c11, c12, c21, c22)
	r1, width := utf8.DecodeRuneInString(coordinate1)
	r2, ww := utf8.DecodeRuneInString(coordinate2)
	fmt.Printf("%c %d", r1, width)
	fmt.Println()
	fmt.Printf("%c %d", r2, ww)
	point1 := c11 + c12
	point2 := c21 + c22
	if point1%2 == point2%2 {
		return true
	}
	return false
}

func main() {
	coordinate1 := "a1"
	coordinate2 := "c3"
	checkTwoChessboards(coordinate1, coordinate2)
}
