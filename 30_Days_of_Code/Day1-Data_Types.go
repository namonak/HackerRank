package main

import (
	"bufio"
	"fmt"
	"os"
	_ "strconv"
)

func main() {
	//var _ = strconv.Itoa // Ignore this comment. You can still use the package "strconv".

	var i uint64 = 4
	var d float64 = 4.0
	var s string = "HackerRank "

	scanner := bufio.NewScanner(os.Stdin)

	// Declare second integer, double, and String variables.
	var inputUint64 uint64
	var inputFloat64 float64
	var inputString string

	// Read and save an integer, double, and String to your variables.
	fmt.Scan(&inputUint64)
	fmt.Scan(&inputFloat64)
	scanner.Scan()
	inputString = scanner.Text()

	// Print the sum of both integer variables on a new line.
	fmt.Println(i + inputUint64)

	// Print the sum of the double variables on a new line.
	fmt.Printf("%.1f\n", d+inputFloat64)

	// Concatenate and print the String variables on a new line
	// The 's' variable above should be printed first.
	fmt.Printf("%s%s", s, inputString)
}
