package chap1

import (
	"fmt"
)

var q = `
Implement an algo.  to determine if a string has all unique characters.
What if you cannot use addl. data structures?
`

func Q1() {
	fmt.Printf("%s:\n", "question 1")
	ss := []string{"asd123", "qweqwe", "dfsW"}
	for _, s := range ss {
		fmt.Printf("%s unique-chars?: %v\n", s, UniqueChars(s))
	}

}

func UniqueChars(s string) bool {
	chars := make(map[string]bool)
	for _, c := range s {
		//fmt.Printf("%s_", string(c))
		_, prs := chars[string(c)]
		if prs {
			return false
		}
		chars[string(c)] = true
	}
	//fmt.Println()
	return true
}
