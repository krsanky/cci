package main

import (
	"fmt"

	"oldcode.org/cci/chap1"
)

func main() {
	fmt.Println("cci")
	chap1.Q1()
	chap1.Q2()
	chap1.Q3()

	s := "asdd"
	s[1] = '0'
	fmt.Println(s)
}
