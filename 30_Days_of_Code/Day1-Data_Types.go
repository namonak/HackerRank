package main


import (
  "fmt"
  "os"
  "bufio"
  "strconv"
)

func main() {
  	var _ = strconv.Itoa // Ignore this comment. You can still use the package "strconv".
  
    var i uint64 = 4
    var d float64 = 4.0
    var s string = "HackerRank "

    scanner := bufio.NewScanner(os.Stdin)
    
    // Declare second integer, double, and String variables.
    var _i uint64
    var _d float64
    var _s string
    
    // Read and save an integer, double, and String to your variables.
    fmt.Scan(&_i)
    fmt.Scan(&_d)
    scanner.Scan()
    _s = scanner.Text()

    // Print the sum of both integer variables on a new line.
    fmt.Println(i + _i)

    // Print the sum of the double variables on a new line.
    fmt.Printf("%.1f\n", d + _d)

    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.
    fmt.Printf("%s%s", s, _s)
}
