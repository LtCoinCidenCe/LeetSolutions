package main

import "fmt"

func checkTwoChessboards(coordinate1 string, coordinate2 string) bool {
	c11 := coordinate1[0]
	c12 := coordinate1[1]
	c21 := coordinate2[0]
	c22 := coordinate2[1]
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
	fmt.Println(checkTwoChessboards(coordinate1, coordinate2))
}
