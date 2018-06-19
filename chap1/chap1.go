package chap1

import (
	"fmt"
	"sort"
	"strings"
)

var q = `
Implement an algo.  to determine if a string has all unique characters.
What if you cannot use addl. data structures?
`

func Q1() {
	fmt.Printf("%s:\n", "question 1")
	ss := []string{"asd123", "qweqwe", "dfsW"}
	for _, s := range ss {
		fmt.Printf("%s unique-chars?: %v\n", s, UniqueChars1(s))
	}
}

func UniqueChars1(s string) bool {
	chars := make(map[string]bool)
	for _, c := range s {
		_, prs := chars[string(c)]
		if prs {
			return false
		}
		chars[string(c)] = true
	}
	return true
}

func Q2() {
	fmt.Println("question 2:")

	ss1 := []string{"asd123", "qweqwe", "dfsW"}
	ss2 := []string{"123dsa", "123123", "dXsW"}
	for i := 0; i < len(ss1); i++ {
		fmt.Printf("%s - %s is-perm:%v\n", ss1[i], ss2[i], IsPermutation(ss1[i], ss2[i]))
	}
}

func SortString(s string) string {
	ss := strings.Split(s, "")
	sort.Strings(ss)
	return strings.Join(ss, "")
}

func IsPermutation(s1, s2 string) bool {
	if SortString(s1) == SortString(s2) {
		return true
	}
	return false
}

func Q3() {
	fmt.Println("question 3:")
	ss := []string{"asd 1 23    ", "q  weq  we        ", "d fsW  "}
	for _, s := range ss {
		s_ := s
		URLify(s)
		fmt.Printf("[%s] [%s]\n", s, s_)
	}

}
func URLify(s string) {
	//s[1] = "x"
}
