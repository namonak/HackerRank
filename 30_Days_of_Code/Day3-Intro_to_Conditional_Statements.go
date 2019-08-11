package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 1024*1024)

	NTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	N := int32(NTemp)

	c0 := N%2 == 1
	c1 := (N%2 == 0) && (2 <= N) && (N <= 5)
	c2 := (N%2 == 0) && (6 <= N) && (N <= 20)
	c3 := (N%2 == 0) && (20 <= N)

	switch {
	case c0 || c2:
		fmt.Println("Weird")
	case c1 || c3:
		fmt.Println("Not Weird")
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
	if err != nil {
		panic(err)
	}
}
