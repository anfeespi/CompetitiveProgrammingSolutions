package main

import "fmt"

func main() {
	var t, x int

	fmt.Scan(&t)

	for ; t > 0; t-- {
		fmt.Scan(&x)
		fmt.Println((x - 1) * 2)
	}
}
