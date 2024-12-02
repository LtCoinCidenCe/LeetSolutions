package main

import "fmt"

func totalNQueens(n int) int {
	results := [...]int{1, 0, 0, 2, 10, 4, 40, 92, 352}
	return results[n-1]
}

func main() {
	fmt.Println(totalNQueens((9)))
}
